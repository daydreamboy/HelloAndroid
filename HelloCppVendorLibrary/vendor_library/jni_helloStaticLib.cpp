#include <jni.h>
#include <string>
#include "helloStaticLib.hpp"

using namespace HelloNativeLib;

extern "C" JNIEXPORT jstring JNICALL
Java_com_wc_hellocppvendorlibrary_MainActivity_stringFromHelloStaticLib(JNIEnv* env, jobject /* this */) {
    std::shared_ptr<HelloStaticLib> helloWorld = HelloStaticLib::create();
    std::string hello = helloWorld->fromCpp();
    return env->NewStringUTF(hello.c_str());
}