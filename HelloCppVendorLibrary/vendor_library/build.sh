set -x

CMAKE_HOME=~/Library/Android/sdk/cmake/3.22.1/bin
NDK=~/Library/Android/sdk/ndk/25.1.8937393
ABI=x86_64
MINSDKVERSION=33
BUILD_TYPE=Debug
OTHER_ARGS=
GEN_HOME=$(pwd)/out

rm -rf ${GEN_HOME}
mkdir ${GEN_HOME}

$CMAKE_HOME/cmake \
    -B${GEN_HOME} \
    -DANDROID_ABI=${ABI} \
    -DANDROID_PLATFORM=android-${MINSDKVERSION} \
    -DANDROID_NDK=${NDK} \
    -DCMAKE_ANDROID_ARCH_ABI=${ABI} \
    -DCMAKE_ANDROID_NDK=${NDK} \
    -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -DCMAKE_MAKE_PROGRAM=${CMAKE_HOME}/ninja \
    -DCMAKE_SYSTEM_NAME=Android \
    -DCMAKE_TOOLCHAIN_FILE=${NDK}/build/cmake/android.toolchain.cmake \
    -GNinja \
    -H. \
    ${OTHER_ARGS}

$CMAKE_HOME/ninja -C out
