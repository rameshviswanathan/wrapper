LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../inc

FINGERPRINT=$(shell bash $(LOCAL_PATH)/../scripts/build-fingerprint.sh $(LOCAL_C_INCLUDES))

LOCAL_CFLAGS += -Wall -Werror -Wno-missing-field-initializers -Wunused

LOCAL_CFLAGS += -DBUILD_FINGERPRINT=\"$(FINGERPRINT)\"

LOCAL_SRC_FILES :=  ../../src/linux/os_lib_linux.cpp

LOCAL_MODULE := libos

include $(BUILD_SHARED_LIBRARY)
