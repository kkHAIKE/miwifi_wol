BUILDDIR := ./build/
BINARY = $(BUILDDIR)wol

all :dir wol package

ROOTDIR = $(CURDIR)/../

toolchain := $(ROOTDIR)toolchain/
xqlibs := $(ROOTDIR)/
CXX = $(toolchain)/bin/mipsel-xiaomi-linux-uclibc-g++
CC =$(toolchain)/bin/mipsel-xiaomi-linux-uclibc-gcc


LIB_DIR = -L$(xqlibs)/lib/ -Wl,-rpath-link,$(toolchain)/lib/
CXXFLAGS += -I$(xqlibs)/include/
LDFLAGS = -Wall -O2 -lxmrouter \
 -lthrift -lssl -lcrypto -lconfig++ -ljson-c -lboost_atomic \
 -lboost_system -lboost_filesystem -lthriftnb -levent -lmbedtls -lcurl -lz -lboost_thread -lpthread \
 -lroutermain

dir :
	mkdir -p $(BUILDDIR)

wol :
	$(CXX) $(CXXFLAGS) TaskWatcher.h  TaskWatcher.cpp $(LIB_DIR) $(LDFLAGS) -g -gdwarf-2 -o $(BINARY)

clean:
	rm -r build

package:
	cp start_script build/
	../plugin_packager_x64
