# HelloAndroid
[TOC]



## 1、第一个Android应用

### (1) 下载Android Studio

在官方网址(https://developer.android.com/studio)下载Android Studio，它是一个专门适用于Android开发的IDE。



### (2) 创建Android工程

打开Android Studio，选择File > New > New Project...，在弹出提示框中选择“Empty Activity”，Android Studio会创建一个带部分代码的工程。可以参考这篇Android官方文档[^1]，创建个HelloWorld应用。

> 示例代码，见HelloWorld

这里主要介绍Android应用的工程结构。

工程根目录下面主要是下面文件夹和文件

```shell
$ tree . -L 1
.
├── app
├── build
├── build.gradle
├── gradle
├── gradle.properties
├── gradlew
├── gradlew.bat
├── local.properties
└── settings.gradle
```

主要开发的代码在app文件夹下，如下

```shell
$ tree app -L 1
app
├── build
├── build.gradle
├── libs
├── proguard-rules.pro
└── src
```

上面src放源码，而libs放依赖库。

再看看src下面的内容，如下

```shell
$ tree app/src -L 1 
app/src
├── androidTest
├── main
└── test
```

Android Studio默认创建三个部分的代码

* main文件是app的开发代码所放位置
* test文件是单元测试代码的所放位置。它的测试代码运行在本机上
* androidTest文件是app测试代码的所放位置。它的测试代码运行在android设备上。

更详细看下src的结构，如下

```shell
$ tree app/src     
app/src
├── androidTest
│   └── java
│       └── com
│           └── wc
│               └── helloworld
│                   └── ExampleInstrumentedTest.kt
├── main
│   ├── AndroidManifest.xml
│   ├── java
│   │   └── com
│   │       └── wc
│   │           └── helloworld
│   │               ├── MainActivity.kt
│   │               └── ui
│   │                   └── theme
│   │                       ├── Color.kt
│   │                       ├── Theme.kt
│   │                       └── Type.kt
│   └── res
│       ├── ...
└── test
    └── java
        └── com
            └── wc
                └── helloworld
                    └── ExampleUnitTest.kt
```

在上面三个文件夹下面，代码都放在java文件夹下面，并以java文件夹为根目录，按照java包的方式（例如com/wc/../xxx.kt）管理kt源文件。

说明

> 如果还有其他语言，和java同级，还有其他文件夹，例如cpp，用于Android的JNI



## 2、使用C++代码

### (1) Android应用编译C++源码

新建工程，在Phonen and Tablet下面选择Native C++，C++ Standard选择Toolchain Default。创建好的工程，默认已经有C++代码和使用C++ JNI接口的kotlin代码。



NDK开发

https://developer.android.com/ndk/guides?hl=zh-cn



关联Gradle

https://developer.android.com/studio/projects/gradle-external-native-builds?hl=zh-cn#groovy





## 3、常用文档地址

### (1) 下载Android Studio

https://developer.android.com/studio



### (2) Kotlin学习官网

https://kotlinlang.org/docs/getting-started.html



### (3) Android Kotlin 基础知识

https://developer.android.com/courses/kotlin-android-fundamentals/overview?hl=zh-cn





## References

[^1]:https://developer.android.com/codelabs/basic-android-kotlin-compose-first-app?continue=https%3A%2F%2Fdeveloper.android.com%2Fcourses%2Fpathways%2Fandroid-basics-compose-unit-1-pathway-2%23codelab-https%3A%2F%2Fdeveloper.android.com%2Fcodelabs%2Fbasic-android-kotlin-compose-first-app&%3Bhl=zh-cn&hl=zh-cn#0
