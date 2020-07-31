/*
 * Copyright (c) 2018-2020, Andreas Kling <kling@serenityos.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <Kernel/FileSystem/FileDescription.h>
#include <Kernel/Process.h>

namespace Kernel {

ssize_t Process::sys$read(int fd, Userspace<u8*> buffer, ssize_t size)
{
    REQUIRE_PROMISE(stdio);
    if (size < 0)
        return -EINVAL;
    if (size == 0)
        return 0;
    if (!validate_write(buffer, size))
        return -EFAULT;
#ifdef DEBUG_IO
    dbg() << "sys$read(" << fd << ", " << (const void*)buffer << ", " << size << ")";
#endif
    auto description = file_description(fd);
    if (!description)
        return -EBADF;
    if (!description->is_readable())
        return -EBADF;
    if (description->is_directory())
        return -EISDIR;
    if (description->is_blocking()) {
        if (!description->can_read()) {
            if (Thread::current()->block<Thread::ReadBlocker>(*description).was_interrupted())
                return -EINTR;
            if (!description->can_read())
                return -EAGAIN;
        }
    }
    // FIXME: We should have a read() that takes a Userspace<u8*>
    return description->read(buffer.unsafe_userspace_ptr(), size);
}

}
