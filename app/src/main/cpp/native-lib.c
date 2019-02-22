#include <jni.h>
#include "patch/bspatch.h"
#include "android/log.h"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG,__VA_ARGS__) // 定义LOGD类型

JNIEXPORT jstring JNICALL
Java_com_example_user_apkinrementalupdate_1master_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject a,jstring oldfile_jstr, jstring newfile_jstr, jstring patchfile_jstr){
    int argc = 4;
	char* oldfile = (char*)(*env)->GetStringUTFChars(env,oldfile_jstr, NULL);
	char* newfile = (char*)(*env)->GetStringUTFChars(env,newfile_jstr, NULL);
	char* patchfile = (char*)(*env)->GetStringUTFChars(env,patchfile_jstr, NULL);
	//参数（第一个参数无效）
	char *argv[4];
	argv[0] = "bspatch";
	argv[1] = oldfile;
	argv[2] = newfile;
	argv[3] = patchfile;
    __android_log_print(ANDROID_LOG_DEBUG,"aaaalll","bspatch before");
  	bspatch_main(argc,argv);
    __android_log_print(ANDROID_LOG_DEBUG,"aaaalll","bspatch after");
	(*env)->ReleaseStringUTFChars(env,oldfile_jstr, oldfile);
	(*env)->ReleaseStringUTFChars(env,newfile_jstr, newfile);
	(*env)->ReleaseStringUTFChars(env,patchfile_jstr, patchfile);
    return (*env)->NewStringUTF(env,"ANC");
}
