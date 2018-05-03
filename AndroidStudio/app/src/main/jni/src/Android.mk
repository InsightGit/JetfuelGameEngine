LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

# Add your application source files here...
LOCAL_SRC_FILES := main.cpp

# SDL2 stuff
SDL_PATH := ../SDL

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include 

LOCAL_SHARED_LIBRARIES := SDL2
LOCAL_SHARED_LIBRARIES += SDL2_mixer
LOCAL_SHARED_LIBRARIES += SDL2_ttf
#LOCAL_SHARED_LIBRARIES += cpython

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

# Boost stuff

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../boost/include/boost-1_66
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../../windowsdependencies/rapidjson-master/include

LOCAL_CPPFLAGS += -frtti

# Jetfuel stuff
LOCAL_CFLAGS += -I$(LOCAL_PATH)/../../../../../include

LOCAL_SHARED_LIBRARIES += JetfuelGameEngine

include $(BUILD_SHARED_LIBRARY)
