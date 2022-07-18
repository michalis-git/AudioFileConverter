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

FetchContent_MakeAvailable(AudioFile)


target_link_libraries(AudioConverterLib PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(AudioConverterLib PRIVATE AUDIOCONVERTERLIB_LIBRARY)
