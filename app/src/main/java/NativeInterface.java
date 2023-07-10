import android.util.Log;

public class NativeInterface {
    static String TAG = "NativeInterface";

    static {
        Log.d(TAG, "Loading library...");
        System.loadLibrary("hello_aarch64_static.so");
        Log.d(TAG, "Library should be loaded");
    }

    public native void executeSharedObject();
}
