cmake_minimum_required(VERSION 3.14)

project(AudioConverterLib LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(AudioConverterLib SHARED
  Converter_global.h
  converter.h
  converter.cpp
)

include(FetchContent)

FetchContent_Declare(
  AudioFile
  GIT_REPOSITORY https://github.com/adamstark/AudioFile.git
  GIT_TAG        1.1.0
)


if(NOT AudioFile_POPULATED)
    FetchContent_Populate(AudioFile)
    # Make subproject to use 'BUILD_SHARED_LIBS=ON' setting.
    set(BUILD_SHARED_LIBS ON CACHE INTERNAL "Build SHARED libraries")
    add_subdirectory(${AudioFile_SOURCE_DIR} ${AudioFile_BINARY_DIR})
endif()

target_link_libraries(AudioConverterLib PUBLIC
  Qt${QT_VERSION_MAJOR}::Core
  AudioFile
)

FetchContent_MakeAvailable(AudioFile)

#add_subdirectory(AudioFile)

target_compile_definitions(AudioConverterLib PUBLIC AUDIOCONVERTERLIB_LIBRARY)
