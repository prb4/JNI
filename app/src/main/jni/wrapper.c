//#include "include/loader64.h"
#include <string.h>
//#include "mylib.h"
#include <stdio.h>
#include <android/log.h>
#include <jni.h>
#include <dlfcn.h>  // For dynamically loading the shared object

void logger(char *str);
char * callSayHello();
char * testCallSayHello();

JNIEXPORT jstring JNICALL Java_com_jni_HelloJni_nativeFunction(JNIEnv* env, jobject obj) {
//    sayHello();
    char msg[100] = {'0'};
    memcpy(msg, callSayHello(), 100);
    logger("---------");
    logger(msg);
    return (*env)->NewStringUTF(env, msg);
//    return (*env)->NewStringUTF(env, sayHello());
}

void logger(char *str) {
    __android_log_print(ANDROID_LOG_DEBUG, "MY_JNI", "%s", str);
}

char* callSayHello() {
    // Load the shared object dynamically
    char c_msg[100] = {'0'};

    logger("[-] Starting...");
    void* sharedObject = dlopen("libmylib.so", RTLD_NOW);
    
    if (sharedObject != NULL) {
        // Define the function signature of the actual function in the shared object
        typedef char* (*OriginalFunction)();
        OriginalFunction originalFunction = (OriginalFunction)dlsym(sharedObject, "sayHello");
        logger("[-] dlsym complete!");

        if (originalFunction != NULL) {
            // Call the actual function in the shared object
            logger("[-] Calling original function");
            memcpy(c_msg, originalFunction(), 100);
            logger("[-] Returned from original function");
        } else {
            // Handle error: Unable to find the actual function in the shared object
            logger("[-] No originalFunction found");
        }

        // Close the shared object
        dlclose(sharedObject);
        logger("[-] Closed shared object");
    } else {
        // Handle error: Unable to load the shared object
        logger("[!] Unable to load the shared object");
        char msg[100] = {'0'};
        sprintf(msg, "[!] %s", dlerror());
        logger(msg);
    }

    return c_msg;
}

char * testCallSayHello() {
    char msg[100] = {'0'};
    logger("[-] In testCallSayHello");

    memcpy(msg, "AAAAAAAAAAA", 20);
    logger(msg);
    return msg;
}
