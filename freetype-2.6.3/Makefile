
TOOLCHAIN ?= linux64

include ${TOPDIR}/xbuild/toolchain/$(TOOLCHAIN).mk


CFLAGS   := $(RELEASE_CFLAGS)
CXXFLAGS := $(RELEASE_CXXFLAGS)
LDFLAGS  := $(RELEASE_LDFLAGS)


export CC CXX CFLAGS CXXFLAGS LDFLAGS LD AR RANLIB STRIP


.PHONY: all install


all:
	cd ${MODULE_SRCPATH};	\
	./configure --host=arm-linux --prefix=`pwd`/../tmp-bin/;	\
	make -j4 && make install


install:
	mkdir -p include
	cp -dprf tmp-bin/include/* include/
	mkdir -p lib/$(TOOLCHAIN_PATH)
	cp -dprf tmp-bin/lib/*.a lib/$(TOOLCHAIN_PATH)/


