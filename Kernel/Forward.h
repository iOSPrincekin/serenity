/*
 * Copyright (c) 2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/DistinctNumeric.h>

namespace Kernel {

class BlockDevice;
class CharacterDevice;
class CoreDump;
class Custody;
class DevFSDeviceInode;
class DevFSDirectoryInode;
class DevFSInode;
class DevFSPtsDirectoryInode;
class DevFSRootDirectoryInode;
class Device;
class DiskCache;
class DoubleBuffer;
class File;
class FileDescription;
class FileSystem;
class FutexQueue;
class IPv4Socket;
class Inode;
class InodeIdentifier;
class InodeWatcher;
class KBuffer;
class KResult;
class LocalSocket;
class Mutex;
class MasterPTY;
class Mount;
class PerformanceEventBuffer;
class ProcFS;
class ProcFSDirectoryInode;
class ProcFSExposedComponent;
class ProcFSExposedDirectory;
class ProcFSInode;
class ProcFSProcessInformation;
class ProcFSRootDirectory;
class ProcFSSystemBoolean;
class ProcFSSystemDirectory;
class Process;
class ProcessGroup;
class RecursiveSpinlock;
class Scheduler;
class Socket;
class SysFS;
class SysFSDirectory;
class SysFSBusDirectory;
class SysFSDirectoryInode;
class SysFSInode;
class TCPSocket;
class TTY;
class Thread;
class ThreadTracer;
class UDPSocket;
class UserOrKernelBuffer;
class VirtualFileSystem;
class WaitQueue;
class WorkQueue;

namespace Memory {
class AddressSpace;
class AnonymousVMObject;
class InodeVMObject;
class MappedROM;
class MemoryManager;
class PageDirectory;
class PhysicalPage;
class PhysicalRegion;
class PrivateInodeVMObject;
class Region;
class SharedInodeVMObject;
class VMObject;
class VirtualRange;
class VirtualRangeAllocator;
}

template<typename BaseType>
class Spinlock;
template<typename LockType>
class ScopedSpinlock;
template<typename T>
class KResultOr;

struct InodeMetadata;
struct TrapFrame;

TYPEDEF_DISTINCT_ORDERED_ID(pid_t, ProcessID);
TYPEDEF_DISTINCT_ORDERED_ID(pid_t, ThreadID);
TYPEDEF_DISTINCT_ORDERED_ID(pid_t, SessionID);
TYPEDEF_DISTINCT_ORDERED_ID(pid_t, ProcessGroupID);

}
