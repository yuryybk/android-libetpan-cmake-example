#include <jni.h>
#include <string>
#include "libetpan/build-android/include/libetpan/mailmime_decode.h"

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_libetpan_sandbox_libetpancharsettest_MainActivity_stringFromJNI(JNIEnv *env, jobject) {

    size_t cur_token = 0;
    const char* phraze = "=?iso-8859-8?b?7eXs+SDv4SDp7Oj08A==?=";

    /* More strings to check

      const char* phraze = "=?ISO-8859-2?Q?=DATIA_AV_=C8R=3B_Pod_vod=E1renskou_v=EC=BE=ED?=\\n =?ISO-8859-2?Q?_4=3B_182_08__Praha_8-Libe=F2=3B_Czech_Rep?=\\n =?ISO-8859-2?Q?ublic?=";
      const char* phraze = "=?ISO-8859-2?Q?Vladim=EDr_Solnick=FD?=";
    */

    char* decoded = NULL;
    mailmime_encoded_phrase_parse("iso-8859-1", phraze, strlen(phraze), &cur_token, "utf-8", &decoded);
    std::string hello;
    if (decoded != NULL) {
        return env->NewStringUTF(decoded);
    } else {
        std::string res = "String is null";
        return env->NewStringUTF(res.c_str());
    }
}
