#include "helloSharedLib.hpp"

#include <android/log.h>

using namespace HelloNativeLib;

class HelloWorldImpl : public HelloSharedLib {
public:
    // Note: should re-declare again for static member function
    static std::shared_ptr<HelloSharedLib> create();
    // Note: should re-declare again for pure virtual function
    std::string fromCpp() /*override*/;
};

std::shared_ptr<HelloSharedLib> HelloSharedLib::create() {
    __android_log_print(ANDROID_LOG_DEBUG, "NativeLibTag", "%s object created", "HelloWorldImpl");

    return std::make_shared<HelloWorldImpl>();
}

// Override the pure virtual function in super class
std::string HelloWorldImpl::fromCpp() {
    __android_log_print(ANDROID_LOG_DEBUG, "NativeLibTag", "%s function called", "HelloWorldImpl::fromCpp");

    return "Hello From C++ shared libary!";
}

