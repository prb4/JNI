# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := wrapper
LOCAL_SRC_FILES := wrapper.c
LOCAL_C_INCLUDES := $(LOCAL_PATH)
#LOCAL_CFLAGS := -I$(LOCAL_PATH)
#LOCAL_SHARED_LIBRARIES := loader-prebuilt
#LOCAL_SHARED_LIBRARIES := mylib
LOCAL_LDLIBS += -llog
LOCAL_LDLIBS += -ldl
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := mylib
LOCAL_SRC_FILES := $(LOCAL_PATH)/../jniLibs/arm64-v8a/libmylib.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)
include $(PREBUILT_SHARED_LIBRARY)

#include $(CLEAR_VARS)
#LOCAL_MODULE := loader-prebuilt
#LOCAL_SRC_FILES := libloader64.so
#LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
#include $(PREBUILT_SHARED_LIBRARY)
