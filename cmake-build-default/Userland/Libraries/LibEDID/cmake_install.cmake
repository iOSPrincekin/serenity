# Install script for directory: /Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibEDID

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibEDID" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibEDID/DMT.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibEDID" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibEDID/Definitions.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibEDID" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibEDID/EDID.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibEDID" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibEDID/VIC.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibEDID" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibEDID/DMT.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibEDID" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibEDID/DMT.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibEDID" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibEDID/Definitions.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibEDID" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibEDID/EDID.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibEDID" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibEDID/EDID.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibEDID" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibEDID/VIC.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibEDID" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibEDID/VIC.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/lib" TYPE SHARED_LIBRARY OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibEDID/libedid.so.serenity")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libedid.so.serenity" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libedid.so.serenity")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libedid.so.serenity")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/lib" TYPE SHARED_LIBRARY OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibEDID/libedid.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libedid.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libedid.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libedid.so")
    endif()
  endif()
endif()

