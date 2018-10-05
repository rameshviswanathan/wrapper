LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../inc

FINGERPRINT=$(shell bash $(LOCAL_PATH)/../scripts/build-fingerprint.sh $(LOCAL_C_INCLUDES))

LOCAL_CFLAGS += -Wall -Werror -Wno-missing-field-initializers -Wunused

LOCAL_CFLAGS += -DBUILD_FINGERPRINT=\"$(FINGERPRINT)\"

LOCAL_SRC_FILES :=  ../../src/os_test.cpp

# Put here any libraries that should be linked by system projects
LOCAL_SHARED_LIBRARIES += libos

# Binary name
LOCAL_MODULE := os_test

include $(BUILD_EXECUTABLE)
