#include <jni.h>
#include "Math.h"
#include <math.h>

JNIEXPORT jdouble JNICALL Java_Math_sqrt
  (JNIEnv *env, jobject obj, jdouble d) {
	return sqrt(d);
}
