LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cpython

LOCAL_C_INCLUDES := $(LOCAL_PATH)/Include

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)

LOCAL_SRC_FILES := \
	$(wildcard $(LOCAL_PATH)/Objects/*.c) \
	$(wildcard $(LOCAL_PATH)/Parser/*.c) \
	$(wildcard $(LOCAL_PATH)/Python/*.c) \
	$(wildcard $(LOCAL_PATH)/Modules/*.c) \

include $(BUILD_SHARED_LIBRARY)

