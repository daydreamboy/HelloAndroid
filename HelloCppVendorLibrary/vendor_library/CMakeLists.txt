# Sets the minimum version of CMake required to build your native library.
# This ensures that a certain set of CMake features is available to
# your build.
cmake_minimum_required(VERSION 3.22.1)

# Declares and names the project.
project("vendor library")

add_library( # Specifies the name of the library.
        helloSharedLib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        helloSharedLib.cpp
        jni_helloSharedLib.cpp)

add_library( # Specifies the name of the library.
       helloStaticLib

       # Sets the library as a static library.
       STATIC

       # Provides a relative path to your source file(s).
       helloStaticLib.cpp
       jni_helloStaticLib.cpp
)

# Specifies a path to native header files.
include_directories(src/main/cpp/include/)

find_library( # Defines the name of the path variable that stores the
        # location of the NDK library.
        log-lib

        # Specifies the name of the NDK library that
        # CMake needs to locate.
        log )

## Links your native library against one or more other native libraries.
target_link_libraries( # Specifies the target library.
        helloSharedLib
        # Links the log library to the target library.
        ${log-lib} )

