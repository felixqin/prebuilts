
TOOLCHAIN ?= linux64

include ../../../xbuild/toolchain/$(TOOLCHAIN).mk


STATICLIB := libsqlite.a
SHAREDLIB := libsqlite.so
OBJS      := sqlite3.o

CFLAGS   := $(RELEASE_CFLAGS)
CXXFLAGS := $(RELEASE_CFLAGS)
LDFLAGS  := $(RELEASE_LDFLAGS)

.PHONY: all clean


all: $(STATICLIB) $(SHAREDLIB)

$(STATICLIB): $(OBJS)
	$(AR) -crv $@ $^

$(SHAREDLIB): $(OBJS)
	$(CXX) -shared -fPIC -o $@ $^ $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

%.o : %.cc
	$(CXX) $(CXXFLAGS) -o $@ -c $<

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm $(STATICLIB) $(SHAREDLIB)
	rm $(OBJS)
