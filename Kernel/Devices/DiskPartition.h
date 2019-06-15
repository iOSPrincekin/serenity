#pragma once

#include <AK/RetainPtr.h>
#include <Kernel/Devices/DiskDevice.h>

class DiskPartition final : public DiskDevice {
public:
    static Retained<DiskPartition> create(Retained<DiskDevice>&& device, unsigned block_offset);
    virtual ~DiskPartition();

    virtual unsigned block_size() const override;
    virtual bool read_block(unsigned index, byte* out) const override;
    virtual bool write_block(unsigned index, const byte*) override;
    virtual bool read_blocks(unsigned index, word count, byte*) override;
    virtual bool write_blocks(unsigned index, word count, const byte*) override;

private:
    virtual const char* class_name() const override;

    DiskPartition(Retained<DiskDevice>&&, unsigned);

    Retained<DiskDevice> m_device;
    unsigned m_block_offset;
};
