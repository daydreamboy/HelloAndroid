#include <jni.h>
#include <string>
#include "helloNativeLib.hpp"

using namespace HelloNativeLib;

extern "C" JNIEXPORT jstring JNICALL
Java_com_wc_hellocppfromscratch_MainActivity_stringFromJNI(JNIEnv* env, jobject /* this */) {
    std::shared_ptr<HelloWorld> helloWorld = HelloWorld::create();
    std::string hello = helloWorld->fromCpp();
    return env->NewStringUTF(hello.c_str());
}