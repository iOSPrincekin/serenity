# Install script for directory: /Users/lee/Desktop/Computer_Systems/serenity/Tests/AK

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Root")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestFixedPoint")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestFixedPoint" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestFixedPoint")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestFixedPoint")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestAllOf")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestAllOf" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestAllOf")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestAllOf")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestAnyOf")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestAnyOf" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestAnyOf")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestAnyOf")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestArbitrarySizedEnum")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestArbitrarySizedEnum" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestArbitrarySizedEnum")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestArbitrarySizedEnum")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestArray")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestArray" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestArray")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestArray")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestAtomic")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestAtomic" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestAtomic")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestAtomic")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestBadge")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBadge" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBadge")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBadge")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestBase64")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBase64" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBase64")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBase64")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestBinaryHeap")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBinaryHeap" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBinaryHeap")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBinaryHeap")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestBinarySearch")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBinarySearch" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBinarySearch")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBinarySearch")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestBitCast")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBitCast" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBitCast")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBitCast")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestBitmap")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBitmap" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBitmap")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBitmap")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestBuiltinWrappers")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBuiltinWrappers" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBuiltinWrappers")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestBuiltinWrappers")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestByteBuffer")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestByteBuffer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestByteBuffer")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestByteBuffer")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestCharacterTypes")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestCharacterTypes" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestCharacterTypes")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestCharacterTypes")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestChecked")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestChecked" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestChecked")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestChecked")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestCircularDeque")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestCircularDeque" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestCircularDeque")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestCircularDeque")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestCircularDuplexStream")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestCircularDuplexStream" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestCircularDuplexStream")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestCircularDuplexStream")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestCircularQueue")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestCircularQueue" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestCircularQueue")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestCircularQueue")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestComplex")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestComplex" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestComplex")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestComplex")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestDisjointChunks")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestDisjointChunks" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestDisjointChunks")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestDisjointChunks")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestDistinctNumeric")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestDistinctNumeric" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestDistinctNumeric")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestDistinctNumeric")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestDoublyLinkedList")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestDoublyLinkedList" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestDoublyLinkedList")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestDoublyLinkedList")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestEndian")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestEndian" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestEndian")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestEndian")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestEnumBits")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestEnumBits" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestEnumBits")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestEnumBits")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestFind")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestFind" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestFind")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestFind")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestFixedArray")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestFixedArray" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestFixedArray")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestFixedArray")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestFormat")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestFormat" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestFormat")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestFormat")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestGenericLexer")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestGenericLexer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestGenericLexer")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestGenericLexer")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestHashFunctions")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestHashFunctions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestHashFunctions")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestHashFunctions")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestHashMap")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestHashMap" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestHashMap")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestHashMap")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestHashTable")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestHashTable" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestHashTable")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestHashTable")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestHex")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestHex" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestHex")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestHex")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestIPv4Address")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIPv4Address" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIPv4Address")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIPv4Address")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestIPv6Address")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIPv6Address" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIPv6Address")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIPv6Address")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestIndexSequence")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIndexSequence" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIndexSequence")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIndexSequence")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestIntegerMath")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIntegerMath" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIntegerMath")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIntegerMath")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestIntrusiveList")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIntrusiveList" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIntrusiveList")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIntrusiveList")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestIntrusiveRedBlackTree")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIntrusiveRedBlackTree" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIntrusiveRedBlackTree")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestIntrusiveRedBlackTree")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestJSON")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestJSON" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestJSON")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestJSON")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestLEB128")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestLEB128" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestLEB128")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestLEB128")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestLexicalPath")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestLexicalPath" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestLexicalPath")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestLexicalPath")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestMACAddress")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestMACAddress" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestMACAddress")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestMACAddress")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestMemory")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestMemory" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestMemory")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestMemory")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestMemoryStream")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestMemoryStream" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestMemoryStream")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestMemoryStream")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestNeverDestroyed")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestNeverDestroyed" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestNeverDestroyed")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestNeverDestroyed")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestNonnullRefPtr")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestNonnullRefPtr" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestNonnullRefPtr")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestNonnullRefPtr")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestNumberFormat")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestNumberFormat" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestNumberFormat")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestNumberFormat")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestOptional")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestOptional" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestOptional")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestOptional")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestPrint")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestPrint" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestPrint")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestPrint")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestQueue")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestQueue" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestQueue")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestQueue")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestQuickSort")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestQuickSort" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestQuickSort")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestQuickSort")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestRedBlackTree")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestRedBlackTree" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestRedBlackTree")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestRedBlackTree")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestRefPtr")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestRefPtr" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestRefPtr")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestRefPtr")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestSinglyLinkedList")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestSinglyLinkedList" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestSinglyLinkedList")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestSinglyLinkedList")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestSourceGenerator")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestSourceGenerator" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestSourceGenerator")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestSourceGenerator")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestSourceLocation")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestSourceLocation" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestSourceLocation")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestSourceLocation")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestSpan")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestSpan" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestSpan")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestSpan")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestStack")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestStack" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestStack")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestStack")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestStdLibExtras")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestStdLibExtras" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestStdLibExtras")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestStdLibExtras")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestString")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestString" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestString")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestString")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestStringUtils")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestStringUtils" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestStringUtils")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestStringUtils")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestStringView")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestStringView" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestStringView")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestStringView")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestTime")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestTime" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestTime")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestTime")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestTrie")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestTrie" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestTrie")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestTrie")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestTuple")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestTuple" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestTuple")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestTuple")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestTypeTraits")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestTypeTraits" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestTypeTraits")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestTypeTraits")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestTypedTransfer")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestTypedTransfer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestTypedTransfer")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestTypedTransfer")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestUFixedBigInt")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestUFixedBigInt" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestUFixedBigInt")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestUFixedBigInt")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestURL")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestURL" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestURL")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestURL")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestUtf16")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestUtf16" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestUtf16")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestUtf16")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestUtf8")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestUtf8" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestUtf8")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestUtf8")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestVariant")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestVariant" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestVariant")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestVariant")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestVector")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestVector" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestVector")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestVector")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/Tests/AK" TYPE EXECUTABLE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Tests/AK/TestWeakPtr")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestWeakPtr" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestWeakPtr")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/Tests/AK/TestWeakPtr")
    endif()
  endif()
endif()

