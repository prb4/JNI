#CC=/home/paul/android-ndk-r15c/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/bin/aarch64-linux-android-gcc
CC=/home/paul/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android21-clang
CFLAGS=
LDFLAGS=

libwrapper.so: wrapper.c
	$(CC) -o libwrapper.so -shared wrapper.c
