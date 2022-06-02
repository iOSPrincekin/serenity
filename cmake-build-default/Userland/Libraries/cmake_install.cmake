# Install script for directory: /Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibArchive/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibAudio/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibC/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibCards/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibChess/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibCompress/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibConfig/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibCore/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibCoredump/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibCpp/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibCrypt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibCrypto/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibDebug/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibDesktop/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibDeviceTree/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibDiff/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibDl/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibDNS/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibDSP/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibEDID/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibELF/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibFileSystemAccessClient/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibGemini/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibGfx/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibGL/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibGPU/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibGUI/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibHTTP/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibIMAP/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibImageDecoderClient/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibIPC/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibJS/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibKeyboard/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibLine/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibM/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibMain/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibMarkdown/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibPCIDB/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibPDF/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibProtocol/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibPthread/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibRegex/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibSanitizer/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibSoftGPU/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibSQL/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibSymbolication/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibSyntax/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibSystem/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibTest/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibTextCodec/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibThreading/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibTimeZone/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibTLS/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibUnicode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibUSBDB/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibVideo/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibVT/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibWasm/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibWeb/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibWebSocket/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibWebView/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibX86/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibXML/cmake_install.cmake")
endif()

