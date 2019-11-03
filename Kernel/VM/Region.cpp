#include <Kernel/FileSystem/Inode.h>
#include <Kernel/Process.h>
#include <Kernel/Thread.h>
#include <Kernel/VM/AnonymousVMObject.h>
#include <Kernel/VM/InodeVMObject.h>
#include <Kernel/VM/MemoryManager.h>
#include <Kernel/VM/Region.h>

//#define MM_DEBUG

Region::Region(const Range& range, const String& name, u8 access)
    : m_range(range)
    , m_vmobject(AnonymousVMObject::create_with_size(size()))
    , m_name(name)
    , m_access(access)
{
    MM.register_region(*this);
}

Region::Region(const Range& range, NonnullRefPtr<Inode> inode, const String& name, u8 access)
    : m_range(range)
    , m_vmobject(InodeVMObject::create_with_inode(*inode))
    , m_name(name)
    , m_access(access)
{
    MM.register_region(*this);
}

Region::Region(const Range& range, NonnullRefPtr<VMObject> vmo, size_t offset_in_vmo, const String& name, u8 access)
    : m_range(range)
    , m_offset_in_vmo(offset_in_vmo)
    , m_vmobject(move(vmo))
    , m_name(name)
    , m_access(access)
{
    MM.register_region(*this);
}

Region::~Region()
{
    // Make sure we disable interrupts so we don't get interrupted between unmapping and unregistering.
    // Unmapping the region will give the VM back to the RangeAllocator, so an interrupt handler would
    // find the address<->region mappings in an invalid state there.
    InterruptDisabler disabler;
    if (m_page_directory) {
        unmap(ShouldDeallocateVirtualMemoryRange::Yes);
        ASSERT(!m_page_directory);
    }
    MM.unregister_region(*this);
}

NonnullOwnPtr<Region> Region::clone()
{
    ASSERT(current);

    // NOTE: Kernel-only regions should never be cloned.
    ASSERT(is_user_accessible());

    if (m_shared || (is_readable() && !is_writable())) {
#ifdef MM_DEBUG
        dbgprintf("%s<%u> Region::clone(): sharing %s (V%p)\n",
            current->process().name().characters(),
            current->pid(),
            m_name.characters(),
            vaddr().get());
#endif
        // Create a new region backed by the same VMObject.
        return Region::create_user_accessible(m_range, m_vmobject, m_offset_in_vmo, m_name, m_access);
    }

#ifdef MM_DEBUG
    dbgprintf("%s<%u> Region::clone(): cowing %s (V%p)\n",
        current->process().name().characters(),
        current->pid(),
        m_name.characters(),
        vaddr().get());
#endif
    // Set up a COW region. The parent (this) region becomes COW as well!
    ensure_cow_map().fill(true);
    remap();
    auto clone_region = Region::create_user_accessible(m_range, m_vmobject->clone(), m_offset_in_vmo, m_name, m_access);
    clone_region->ensure_cow_map();
    return clone_region;
}

int Region::commit()
{
    InterruptDisabler disabler;
#ifdef MM_DEBUG
    dbgprintf("MM: commit %u pages in Region %p (VMO=%p) at V%p\n", vmobject().page_count(), this, &vmobject(), vaddr().get());
#endif
    for (size_t i = 0; i < page_count(); ++i) {
        auto& vmobject_physical_page_entry = vmobject().physical_pages()[first_page_index() + i];
        if (!vmobject_physical_page_entry.is_null())
            continue;
        auto physical_page = MM.allocate_user_physical_page(MemoryManager::ShouldZeroFill::Yes);
        if (!physical_page) {
            kprintf("MM: commit was unable to allocate a physical page\n");
            return -ENOMEM;
        }
        vmobject_physical_page_entry = move(physical_page);
        remap_page(i);
    }
    return 0;
}

size_t Region::amount_resident() const
{
    size_t bytes = 0;
    for (size_t i = 0; i < page_count(); ++i) {
        if (m_vmobject->physical_pages()[first_page_index() + i])
            bytes += PAGE_SIZE;
    }
    return bytes;
}

size_t Region::amount_shared() const
{
    size_t bytes = 0;
    for (size_t i = 0; i < page_count(); ++i) {
        auto& physical_page = m_vmobject->physical_pages()[first_page_index() + i];
        if (physical_page && physical_page->ref_count() > 1)
            bytes += PAGE_SIZE;
    }
    return bytes;
}

NonnullOwnPtr<Region> Region::create_user_accessible(const Range& range, const StringView& name, u8 access)
{
    auto region = make<Region>(range, name, access);
    region->m_user_accessible = true;
    return region;
}

NonnullOwnPtr<Region> Region::create_user_accessible(const Range& range, NonnullRefPtr<VMObject> vmobject, size_t offset_in_vmobject, const StringView& name, u8 access)
{
    auto region = make<Region>(range, move(vmobject), offset_in_vmobject, name, access);
    region->m_user_accessible = true;
    return region;
}

NonnullOwnPtr<Region> Region::create_user_accessible(const Range& range, NonnullRefPtr<Inode> inode, const StringView& name, u8 access)
{
    auto region = make<Region>(range, move(inode), name, access);
    region->m_user_accessible = true;
    return region;
}

NonnullOwnPtr<Region> Region::create_kernel_only(const Range& range, const StringView& name, u8 access)
{
    auto region = make<Region>(range, name, access);
    region->m_user_accessible = false;
    return region;
}

bool Region::should_cow(size_t page_index) const
{
    if (m_shared)
        return false;
    return m_cow_map && m_cow_map->get(page_index);
}

void Region::set_should_cow(size_t page_index, bool cow)
{
    ASSERT(!m_shared);
    ensure_cow_map().set(page_index, cow);
}

Bitmap& Region::ensure_cow_map() const
{
    if (!m_cow_map)
        m_cow_map = make<Bitmap>(page_count(), true);
    return *m_cow_map;
}

void Region::remap_page(size_t index)
{
    ASSERT(page_directory());
    InterruptDisabler disabler;
    auto page_vaddr = vaddr().offset(index * PAGE_SIZE);
    auto& pte = MM.ensure_pte(*page_directory(), page_vaddr);
    auto& physical_page = vmobject().physical_pages()[first_page_index() + index];
    ASSERT(physical_page);
    pte.set_physical_page_base(physical_page->paddr().get());
    pte.set_present(true);
    if (should_cow(index))
        pte.set_writable(false);
    else
        pte.set_writable(is_writable());
    pte.set_user_allowed(is_user_accessible());
    page_directory()->flush(page_vaddr);
#ifdef MM_DEBUG
    dbg() << "MM: >> region.remap_page (PD=" << page_directory()->cr3() << ", PTE=" << (void*)pte.raw() << "{" << &pte << "}) " << name() << " " << page_vaddr << " => " << physical_page->paddr() << " (@" << physical_page.ptr() << ")";
#endif
}

void Region::unmap(ShouldDeallocateVirtualMemoryRange deallocate_range)
{
    InterruptDisabler disabler;
    ASSERT(page_directory());
    for (size_t i = 0; i < page_count(); ++i) {
        auto vaddr = this->vaddr().offset(i * PAGE_SIZE);
        auto& pte = MM.ensure_pte(*page_directory(), vaddr);
        pte.set_physical_page_base(0);
        pte.set_present(false);
        pte.set_writable(false);
        pte.set_user_allowed(false);
        page_directory()->flush(vaddr);
#ifdef MM_DEBUG
        auto& physical_page = vmobject().physical_pages()[first_page_index() + i];
        dbgprintf("MM: >> Unmapped V%p => P%p <<\n", vaddr.get(), physical_page ? physical_page->paddr().get() : 0);
#endif
    }
    if (deallocate_range == ShouldDeallocateVirtualMemoryRange::Yes)
        page_directory()->range_allocator().deallocate(range());
    release_page_directory();
}

void Region::map(PageDirectory& page_directory)
{
    InterruptDisabler disabler;
    set_page_directory(page_directory);
#ifdef MM_DEBUG
    dbgprintf("MM: map_region_at_address will map VMO pages %u - %u (VMO page count: %u)\n", first_page_index(), last_page_index(), vmobject().page_count());
#endif
    for (size_t i = 0; i < page_count(); ++i) {
        auto page_vaddr = vaddr().offset(i * PAGE_SIZE);
        auto& pte = MM.ensure_pte(page_directory, page_vaddr);
        auto& physical_page = vmobject().physical_pages()[first_page_index() + i];
        if (physical_page) {
            pte.set_physical_page_base(physical_page->paddr().get());
            pte.set_present(true); // FIXME: Maybe we should use the is_readable flag here?
            if (should_cow(i))
                pte.set_writable(false);
            else
                pte.set_writable(is_writable());
        } else {
            pte.set_physical_page_base(0);
            pte.set_present(false);
            pte.set_writable(is_writable());
        }
        pte.set_user_allowed(is_user_accessible());
        page_directory.flush(page_vaddr);
#ifdef MM_DEBUG
        dbgprintf("MM: >> map_region_at_address (PD=%p) '%s' V%p => P%p (@%p)\n", &page_directory, name().characters(), page_vaddr.get(), physical_page ? physical_page->paddr().get() : 0, physical_page.ptr());
#endif
    }
}

void Region::remap()
{
    ASSERT(m_page_directory);
    map(*m_page_directory);
}
