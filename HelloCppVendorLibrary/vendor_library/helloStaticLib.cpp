#include "helloStaticLib.hpp"

#include <android/log.h>

using namespace HelloNativeLib;

class HelloStaticLibImpl : public HelloStaticLib {
public:
    // Note: should re-declare again for static member function
    static std::shared_ptr<HelloStaticLib> create();
    // Note: should re-declare again for pure virtual function
    std::string fromCpp() /*override*/;
};

std::shared_ptr<HelloStaticLib> HelloStaticLib::create() {
    __android_log_print(ANDROID_LOG_DEBUG, "NativeLibTag", "%s object created", "HelloStaticLibImpl");

    return std::make_shared<HelloStaticLibImpl>();
}

// Override the pure virtual function in super class
std::string HelloStaticLibImpl::fromCpp() {
    __android_log_print(ANDROID_LOG_DEBUG, "NativeLibTag", "%s function called", "HelloStaticLibImpl::fromCpp");

    return "Hello From C++ shared libary!";
}

