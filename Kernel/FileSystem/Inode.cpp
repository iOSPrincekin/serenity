#include <AK/NonnullRefPtrVector.h>
#include <AK/StringBuilder.h>
#include <Kernel/FileSystem/Inode.h>
#include <Kernel/FileSystem/InodeWatcher.h>
#include <Kernel/Net/LocalSocket.h>
#include <Kernel/VM/InodeVMObject.h>
#include <Kernel/FileSystem/VirtualFileSystem.h>
#include <Kernel/FileSystem/Custody.h>

InlineLinkedList<Inode>& all_inodes()
{
    static InlineLinkedList<Inode>* list;
    if (!list)
        list = new InlineLinkedList<Inode>;
    return *list;
}

void Inode::sync()
{
    NonnullRefPtrVector<Inode, 32> inodes;
    {
        InterruptDisabler disabler;
        for (auto& inode : all_inodes()) {
            if (inode.is_metadata_dirty())
                inodes.append(inode);
        }
    }

    for (auto& inode : inodes) {
        ASSERT(inode.is_metadata_dirty());
        inode.flush_metadata();
    }
}

ByteBuffer Inode::read_entire(FileDescription* descriptor) const
{
    size_t initial_size = metadata().size ? metadata().size : 4096;
    StringBuilder builder(initial_size);

    ssize_t nread;
    u8 buffer[4096];
    off_t offset = 0;
    for (;;) {
        nread = read_bytes(offset, sizeof(buffer), buffer, descriptor);
        ASSERT(nread <= (ssize_t)sizeof(buffer));
        if (nread <= 0)
            break;
        builder.append((const char*)buffer, nread);
        offset += nread;
        if (nread < (ssize_t)sizeof(buffer))
            break;
    }
    if (nread < 0) {
        kprintf("Inode::read_entire: ERROR: %d\n", nread);
        return nullptr;
    }

    return builder.to_byte_buffer();
}

KResultOr<NonnullRefPtr<Custody>> Inode::resolve_as_link(Custody& base, RefPtr<Custody>* out_parent, int options, int symlink_recursion_level) const
{
    // The default implementation simply treats the stored
    // contents as a path and resolves that. That is, it
    // behaves exactly how you would expect a symlink to work.
    auto contents = read_entire();

    if (!contents) {
        if (out_parent)
            *out_parent = nullptr;
        return KResult(-ENOENT);
    }

    auto path = StringView(contents.data(), contents.size());
    return VFS::the().resolve_path(path, base, out_parent, options, symlink_recursion_level);
}

unsigned Inode::fsid() const
{
    return m_fs.fsid();
}

Inode::Inode(FS& fs, unsigned index)
    : m_fs(fs)
    , m_index(index)
{
    all_inodes().append(this);
}

Inode::~Inode()
{
    all_inodes().remove(this);
}

void Inode::will_be_destroyed()
{
    if (m_metadata_dirty)
        flush_metadata();
}

void Inode::inode_contents_changed(off_t offset, ssize_t size, const u8* data)
{
    if (m_vmobject)
        m_vmobject->inode_contents_changed({}, offset, size, data);
}

void Inode::inode_size_changed(size_t old_size, size_t new_size)
{
    if (m_vmobject)
        m_vmobject->inode_size_changed({}, old_size, new_size);
}

int Inode::set_atime(time_t)
{
    return -ENOTIMPL;
}

int Inode::set_ctime(time_t)
{
    return -ENOTIMPL;
}

int Inode::set_mtime(time_t)
{
    return -ENOTIMPL;
}

int Inode::increment_link_count()
{
    return -ENOTIMPL;
}

int Inode::decrement_link_count()
{
    return -ENOTIMPL;
}

void Inode::set_vmobject(VMObject& vmobject)
{
    m_vmobject = vmobject.make_weak_ptr();
}

bool Inode::bind_socket(LocalSocket& socket)
{
    ASSERT(!m_socket);
    m_socket = socket;
    return true;
}

bool Inode::unbind_socket()
{
    ASSERT(m_socket);
    m_socket = nullptr;
    return true;
}

void Inode::register_watcher(Badge<InodeWatcher>, InodeWatcher& watcher)
{
    LOCKER(m_lock);
    ASSERT(!m_watchers.contains(&watcher));
    m_watchers.set(&watcher);
}

void Inode::unregister_watcher(Badge<InodeWatcher>, InodeWatcher& watcher)
{
    LOCKER(m_lock);
    ASSERT(m_watchers.contains(&watcher));
    m_watchers.remove(&watcher);
}

void Inode::set_metadata_dirty(bool metadata_dirty)
{
    if (m_metadata_dirty == metadata_dirty)
        return;

    m_metadata_dirty = metadata_dirty;
    if (m_metadata_dirty) {
        // FIXME: Maybe we should hook into modification events somewhere else, I'm not sure where.
        //        We don't always end up on this particular code path, for instance when writing to an ext2fs file.
        LOCKER(m_lock);
        for (auto& watcher : m_watchers) {
            watcher->notify_inode_event({}, InodeWatcher::Event::Type::Modified);
        }
    }
}
