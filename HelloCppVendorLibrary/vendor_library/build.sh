set -x
set -e

CMAKE_HOME=~/Library/Android/sdk/cmake/3.22.1/bin
NDK=~/Library/Android/sdk/ndk/25.1.8937393
MINSDKVERSION=33
BUILD_TYPE=Debug
OTHER_ARGS=
OUT_HOME=$(pwd)/out

if [[ $1 = "device" ]]; then
  ABI=arm64-v8a
elif [[ $1 = "simulator" ]]; then
  ABI=x86_64
elif [[ $1 = "armeabi-v7a" ]]; then
  ABI=armeabi-v7a
elif [[ $1 = "x86" ]]; then
  ABI=x86
elif [[ $1 = "all" ]]; then
  echo "Not support now"
  exit 1
elif [[ $1 = "clean" ]]; then
  if [[ -x "$(command -v trash)" ]]; then
    trash ${OUT_HOME}
  else
    rm -rf ${OUT_HOME}
  fi
  exit 0
else
  echo "Must support a parameter"
  exit 1
fi

rm -rf ${OUT_HOME}
mkdir ${OUT_HOME}

$CMAKE_HOME/cmake \
    -B${OUT_HOME} \
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
