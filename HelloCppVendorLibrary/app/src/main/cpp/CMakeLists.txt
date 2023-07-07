# Sets the minimum version of CMake required to build your native library.
# This ensures that a certain set of CMake features is available to
# your build.
cmake_minimum_required(VERSION 3.22.1)

project("import vendor library")

## Step1: Add target helloStaticLib for placeholder

add_library(
        # Specifies the name of the library.
        helloStaticLib

        # Sets the library as a shared library.
        SHARED

        # Note: add a dummy cpp
        dummy.cpp)

## Step2: Add target importedSharedLib for shared library

add_library(
        # Specifies the name of the library.
        importedSharedLib

        # Sets the library as a shared library.
        SHARED

        # Note: Indicates the library file outside our project
        IMPORTED)

set_target_properties(
        importedSharedLib
        PROPERTIES
        IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../../../../vendor_library/out/libhelloSharedLib.so
)

## Step3: Add target importedStaticLib for static library

add_library(
        # Specifies the name of the library.
        importedStaticLib

        # Sets the library as a shared library.
        STATIC

        # Note: Indicates the library file outside our project
        IMPORTED)

set_target_properties(
        importedStaticLib
        PROPERTIES
        IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../../../../vendor_library/out/libhelloStaticLib.a
)

## Step4: Add rest targets dependency to dest target

target_link_libraries(
        helloStaticLib
        importedSharedLib
)

find_library( # Defines the name of the path variable that stores the
        # location of the NDK library.
        log-lib

        # Specifies the name of the NDK library that
        # CMake needs to locate.
        log )

target_link_libraries( # Specifies the target library.
        helloStaticLib
        # Links the log library to the target library.
        ${log-lib}
)

# @see https://stackoverflow.com/a/52952274
target_link_libraries(
        helloStaticLib -Wl,--whole-archive importedStaticLib -Wl,--no-whole-archive
)

