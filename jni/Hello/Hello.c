#include <jni.h>
#include "Hello.h"
#include <stdio.h>

JNIEXPORT void JNICALL Java_Hello_sayHello
  (JNIEnv *env, jobject obj) {
	printf("Hello world!\n");
	return;
}

JNIEXPORT void JNICALL Java_Hello_greetMe
  (JNIEnv *env, jobject obj, jstring text) {
	const char * name = (*env)->GetStringUTFChars(env, text, 0);
	printf("Hello %s", name);
	(*env)->ReleaseStringUTFChars(env, text, name);
}
