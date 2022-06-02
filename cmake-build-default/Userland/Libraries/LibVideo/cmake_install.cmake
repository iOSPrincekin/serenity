# Install script for directory: /Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibVideo" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/MatroskaDocument.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibVideo" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/MatroskaReader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/BitStream.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/Decoder.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/Enums.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/LookupTables.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/MV.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/Parser.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/ProbabilityTables.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/Symbols.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/SyntaxElementCounter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/TreeParser.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/Utilities.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/MatroskaDocument.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/MatroskaReader.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/MatroskaReader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/BitStream.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/BitStream.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/Decoder.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/Decoder.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/Enums.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/LookupTables.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/MV.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/MV.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/Parser.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/Parser.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/ProbabilityTables.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/ProbabilityTables.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/Symbols.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/SyntaxElementCounter.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/SyntaxElementCounter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/TreeParser.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/TreeParser.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/Utilities.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibVideo/VP9" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibVideo/VP9/Utilities.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/lib" TYPE SHARED_LIBRARY OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibVideo/libvideo.so.serenity")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libvideo.so.serenity" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libvideo.so.serenity")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libvideo.so.serenity")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/lib" TYPE SHARED_LIBRARY OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibVideo/libvideo.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libvideo.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libvideo.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libvideo.so")
    endif()
  endif()
endif()

