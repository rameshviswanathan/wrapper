include ./../../../build/linux/Makefile.inc

CFLAGS = $(COMMON_CFLAGS) -fPIC -D_GNU_SOURCE

LDFLAGS = -lpthread -ldl

TARGET_PATH = ./../../../build/linux/out

SHARED_OBJECT =$(TARGET_PATH)/os_test


LIBS = \
	$(TARGET_PATH)/libos.so

INCLUDES = \
	-I ./../../../inc

OBJS = \
	./../../src/os_test.o

SOURCES = \
	./../../src/os_test.cpp

all:$(OBJS)
	mkdir -p $(TARGET_PATH)
	$(CC) $(OBJS) $(LIBS) -o $(SHARED_OBJECT) $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $(INCLUDES) -o $@ $< $(CFLAGS)

clean:
	rm -f $(SHARED_OBJECT) $(OBJS)

