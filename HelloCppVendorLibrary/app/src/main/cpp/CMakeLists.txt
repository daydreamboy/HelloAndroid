# Sets the minimum version of CMake required to build your native library.
# This ensures that a certain set of CMake features is available to
# your build.
cmake_minimum_required(VERSION 3.22.1)

project("helloNativeLib")

## Step1: Add target helloNativeLib for placeholder

add_library(
        # Specifies the name of the library.
        helloNativeLib

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

## Step3: Add target importedSharedLib for shared library

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
        helloNativeLib
        importedSharedLib
        importedStaticLib
)

