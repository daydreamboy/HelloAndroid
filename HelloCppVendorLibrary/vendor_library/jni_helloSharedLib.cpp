#include <jni.h>
#include <string>
#include "helloSharedLib.hpp"

using namespace HelloNativeLib;

extern "C" JNIEXPORT jstring JNICALL
Java_com_wc_hellocppvendorlibrary_MainActivity_stringFromHelloSharedLib(JNIEnv* env, jobject /* this */) {
    std::shared_ptr<HelloSharedLib> helloWorld = HelloSharedLib::create();
    std::string hello = helloWorld->fromCpp();
    return env->NewStringUTF(hello.c_str());
}