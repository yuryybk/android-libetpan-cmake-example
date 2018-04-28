# android-libetpan-cmake-example
Simple Android project to debug libetpan (https://github.com/dinhviethoa/libetpan) with CMake 

## How to use?

- Just download, add some native code to [etpan-test](https://github.com/yuryybk/android-libetpan-cmake-example/blob/master/app/src/main/cpp/etpan-test.cpp), build, run and debug.  

## How to update?

* Update third-party libraries in [third-party folder](https://github.com/yuryybk/android-libetpan-cmake-example/tree/master/app/src/main/cpp/third-party). You might find some libs [here](http://d.etpan.org/mailcore2-deps/).
* Update source code:
  * Download and run build [libetpan](https://github.com/dinhviethoa/libetpan) for Android. It will generate some config headers which will be used in current project.
  * Copy sources from libetpan build folder to this project to appropriate directories: 
    * Use [Android.mk](https://github.com/dinhviethoa/libetpan/blob/master/build-android/jni/Android.mk) sources list to copy sources to [/main/cpp/libetpan/src](https://github.com/yuryybk/android-libetpan-cmake-example/tree/master/app/src/main/cpp/libetpan/src) folder.
    * Copy headers from previously built libetpan from [/include/libetpan](https://github.com/dinhviethoa/libetpan/tree/master/include) folder to this project to [/main/cpp/libetpan/include/libetpan](https://github.com/yuryybk/android-libetpan-cmake-example/tree/master/app/src/main/cpp/libetpan/include) folder.
    * Copy headers from previously built libetpan from [/build-android/include/](https://github.com/dinhviethoa/libetpan/tree/master/build-android/include) to this project to [/main/cpp/libetpan/build-android/include/](https://github.com/yuryybk/android-libetpan-cmake-example/tree/master/app/src/main/cpp/libetpan/build-android/include).
    
## TODO

- Script to update sources.
