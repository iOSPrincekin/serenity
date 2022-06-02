# Install script for directory: /Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/AffineTransform.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/AntiAliasingPainter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/BMPLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/BMPWriter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Bitmap.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/BitmapMixer.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/CharacterBitmap.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/ClassicStylePainter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/ClassicWindowTheme.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Color.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/CursorParams.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/DDSLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/DisjointRectSet.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/FillPathImplementation.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/BoxBlurFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/ColorBlindnessFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/ColorFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/FastBoxBlurFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/Filter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/GenericConvolutionFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/GrayscaleFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/InvertFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/LaplacianFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/LumaFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/SepiaFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/SharpenFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/SpatialGaussianBlurFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/BitmapFont.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/Emoji.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/Font.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/FontDatabase.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/FontStyleMapping.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/ScaledFont.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Font/TrueType" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/TrueType/Cmap.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Font/TrueType" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/TrueType/Font.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Font/TrueType" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/TrueType/Glyf.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Font/TrueType" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/TrueType/Tables.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/Typeface.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/VectorFont.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx/Font/WOFF" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/WOFF/Font.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Forward.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/GIFLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Gamma.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/ICOLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/ImageDecoder.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/JPGLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Line.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Matrix.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Matrix3x3.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Matrix4x4.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Orientation.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PBMLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PGMLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PNGLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PNGWriter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PPMLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Painter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Palette.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Path.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Point.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PortableImageLoaderCommon.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PortableImageMapLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/QOILoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/QOIWriter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Quad.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Rect.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/ShareableBitmap.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Size.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/StandardCursor.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Streamer.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/StylePainter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/SystemTheme.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/TextAlignment.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/TextAttributes.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/TextDirection.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/TextElision.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/TextLayout.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/TextWrapping.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Triangle.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Vector2.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Vector3.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Vector4.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/VectorN.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/include/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/WindowTheme.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/AffineTransform.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/AffineTransform.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/AntiAliasingPainter.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/AntiAliasingPainter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/BMPLoader.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/BMPLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/BMPWriter.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/BMPWriter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Bitmap.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Bitmap.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/BitmapMixer.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/BitmapMixer.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/CharacterBitmap.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/ClassicStylePainter.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/ClassicStylePainter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/ClassicWindowTheme.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/ClassicWindowTheme.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Color.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Color.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/CursorParams.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/CursorParams.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/DDSLoader.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/DDSLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/DisjointRectSet.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/DisjointRectSet.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/FillPathImplementation.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/BoxBlurFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/ColorBlindnessFilter.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/ColorBlindnessFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/ColorFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/FastBoxBlurFilter.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/FastBoxBlurFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/Filter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/GenericConvolutionFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/GrayscaleFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/InvertFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/LaplacianFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/LumaFilter.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/LumaFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/SepiaFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/SharpenFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Filters" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Filters/SpatialGaussianBlurFilter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/BitmapFont.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/BitmapFont.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/Emoji.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/Emoji.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/Font.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/FontDatabase.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/FontDatabase.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/FontStyleMapping.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/ScaledFont.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/ScaledFont.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font/TrueType" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/TrueType/Cmap.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font/TrueType" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/TrueType/Cmap.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font/TrueType" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/TrueType/Font.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font/TrueType" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/TrueType/Font.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font/TrueType" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/TrueType/Glyf.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font/TrueType" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/TrueType/Glyf.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font/TrueType" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/TrueType/Tables.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/Typeface.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/Typeface.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/VectorFont.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font/WOFF" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/WOFF/Font.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx/Font/WOFF" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Font/WOFF/Font.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Forward.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/GIFLoader.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/GIFLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Gamma.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/ICOLoader.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/ICOLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/ImageDecoder.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/ImageDecoder.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/JPGLoader.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/JPGLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Line.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Matrix.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Matrix3x3.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Matrix4x4.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Orientation.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PBMLoader.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PBMLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PGMLoader.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PGMLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PNGLoader.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PNGLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PNGWriter.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PNGWriter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PPMLoader.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PPMLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Painter.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Painter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Palette.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Palette.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Path.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Path.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Point.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Point.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PortableImageLoaderCommon.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/PortableImageMapLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/QOILoader.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/QOILoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/QOIWriter.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/QOIWriter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Quad.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Rect.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Rect.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/ShareableBitmap.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/ShareableBitmap.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Size.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Size.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/StandardCursor.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Streamer.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/StylePainter.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/StylePainter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/SystemTheme.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/SystemTheme.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/TextAlignment.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/TextAttributes.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/TextDirection.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/TextDirection.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/TextElision.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/TextLayout.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/TextLayout.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/TextWrapping.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Triangle.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Triangle.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Vector2.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Vector3.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/Vector4.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/VectorN.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/WindowTheme.cpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/src/serenity/Userland/Libraries/LibGfx" TYPE FILE OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/Userland/Libraries/LibGfx/WindowTheme.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/lib" TYPE SHARED_LIBRARY OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibGfx/libgfx.so.serenity")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libgfx.so.serenity" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libgfx.so.serenity")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libgfx.so.serenity")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/lib" TYPE SHARED_LIBRARY OPTIONAL MESSAGE_NEVER FILES "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Libraries/LibGfx/libgfx.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libgfx.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libgfx.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/lee/Desktop/Computer_Systems/serenity/Toolchain/Local/i686/bin/i686-pc-serenity-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/usr/lib/libgfx.so")
    endif()
  endif()
endif()

