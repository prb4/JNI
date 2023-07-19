#include "mylib.h"

char * sayHello() {
    __android_log_print(ANDROID_LOG_DEBUG, "MY_JNI", "in sayHello");
    return "Hello from sayHello\n";
}
