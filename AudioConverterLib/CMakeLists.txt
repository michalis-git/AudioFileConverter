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

#add_library(AudioConverterLib SHARED
#  Converter_global.h
#  converter.h
#  converter.cpp
#)
add_library (${PROJECT_NAME} INTERFACE)

target_include_directories (
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_compile_features (${PROJECT_NAME} INTERFACE cxx_std_11)

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

target_link_libraries(AudioConverterLib INTERFACE
  Qt${QT_VERSION_MAJOR}::Core
  AudioFile
)

FetchContent_MakeAvailable(AudioFile)

export(TARGETS AudioFile
        FILE "${CMAKE_CURRENT_BINARY_DIR}/AudioFileConfig.cmake")
export(TARGETS AudioConverterLib
        FILE "${CMAKE_CURRENT_BINARY_DIR}/AudioFileConverterConfig.cmake")

#add_subdirectory(AudioFile)

target_compile_definitions(AudioConverterLib INTERFACE AUDIOCONVERTERLIB_LIBRARY)
