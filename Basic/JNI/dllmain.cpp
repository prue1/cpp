// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "jni_CppJni.h"
#include <cmath>
#include <iostream>

using namespace std;

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
) {
    srand(time(NULL));
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


/*
 * Class:     jni_CppJni
 * Method:    random
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_jni_CppJni_random
(JNIEnv*, jobject) {

    return ((double)rand()) / 100000;
}

/*
 * Class:     jni_CppJni
 * Method:    add
 * Signature: (II)J
 */
JNIEXPORT jlong JNICALL Java_jni_CppJni_add
(JNIEnv*, jobject, jint a, jint b) {
    return a + b;
}

/*
 * Class:     jni_CppJni
 * Method:    sort
 * Signature: ([D)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_jni_CppJni_sort
(JNIEnv* env, jobject, jdoubleArray a) {

    jsize size = env->GetArrayLength(a);
    double* d = env->GetDoubleArrayElements(a, 0);
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(d + i) > *(d + j)) {
                double t = *(d + i);
                *(d + i) = *(d + j);
                *(d + j) = t;
            }
        }
    }

    jdoubleArray output = env->NewDoubleArray(size);
    env->SetDoubleArrayRegion(output, 0, size, d);

    return output;
}

/*
 * Class:     jni_CppJni
 * Method:    getSimpleMath
 * Signature: ()Ljni/SimpleMath;
 */
JNIEXPORT jobject JNICALL Java_jni_CppJni_getSimpleMath
(JNIEnv* env, jobject) {

    jclass clazz = env->FindClass("jni/SimpleMath");
    jmethodID cid = env->GetMethodID(clazz, "max", "(II)I");
    jmethodID cid2 = env->GetMethodID(clazz, "min", "(II)I");

    return env->NewObject(clazz, cid, cid2);
}

