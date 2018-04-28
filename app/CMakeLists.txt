# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

cmake_minimum_required(VERSION 3.4.1)

# Update versions if need here
# Dependencies OPENSS and CYRUS_SASL was taken here http://d.etpan.org/mailcore2-deps/
# Iconv should be rebuild personally, you can take scripts here https://github.com/yuryybk/libetpan/blob/master/build-android/dependencies/iconv/build-android/jni/Android.mk
set(ICONV_VERSION 1.15)
set(OPENSSL_VERSION 3)
set(CYRUS_SASL_VERSION 4)


set(LIBETPAN_SRC_PATH src/main/cpp/libetpan/src)

file(GLOB LIBETPAN_SOURCE_FILES ${LIBETPAN_SRC_PATH}/*.c ${LIBETPAN_SRC_PATH}/*/*.c ${LIBETPAN_SRC_PATH}/*/*/*.c)

add_library( # Sets the name of the library.
             etpan

             # Sets the library as a shared library.
             STATIC

             # Provides a relative path to your source file(s).
             ${LIBETPAN_SOURCE_FILES}
             ${LIBETPAN_SRC_PATH}/driver/implementation/data-message/data_message_driver.c
           )


include_directories(src/main/cpp/libetpan/build-android/include
                    src/main/cpp/libetpan/build-android/include/libetpan
                    src/main/cpp/third-party/openssl-${OPENSSL_VERSION}/include
                    src/main/cpp/third-party/cyrus-sasl-${CYRUS_SASL_VERSION}/include
                    src/main/cpp/third-party/iconv-${ICONV_VERSION}/include
                    src/main/cpp/libetpan/include
                    src/main/cpp/libetpan/src/data-types
                    src/main/cpp/libetpan/src/driver/interface)


ADD_LIBRARY( etpan-test
             SHARED
             src/main/cpp/etpan-test.cpp)

set (THIRD_PARTY_LIBS_PATH ${CMAKE_SOURCE_DIR}/src/main/cpp/third-party)

target_link_libraries( # Specifies the target library.
                       etpan-test

                       etpan
                       ${THIRD_PARTY_LIBS_PATH}/iconv-${ICONV_VERSION}/libs/${ANDROID_ABI}/libiconv.a
                       ${THIRD_PARTY_LIBS_PATH}/openssl-${OPENSSL_VERSION}/libs/${ANDROID_ABI}/libssl.a
                       ${THIRD_PARTY_LIBS_PATH}/openssl-${OPENSSL_VERSION}/libs/${ANDROID_ABI}/libcrypto.a
                       ${THIRD_PARTY_LIBS_PATH}/cyrus-sasl-${CYRUS_SASL_VERSION}/libs/${ANDROID_ABI}/libsasl2.a)
