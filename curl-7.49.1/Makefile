#****************************************************************************
#
#****************************************************************************

CURDIR			 := ${shell pwd}
TOPDIR 			 := ${CURDIR}/../../../

TOOLCHAIN		 ?= hisiv100
TOOLCHAIN_FILES  := $(shell find "$(TOPDIR)/xbuild/toolchain" -name "$(TOOLCHAIN)\.mk")
TOOLCHAIN_FILE   := $(firstword $(TOOLCHAIN_FILES))
-include $(TOOLCHAIN_FILE)

CFLAGS=$(RELEASE_CFLAGS)
CXXFLAGS=$(RELEASE_CFLAGS)
CPPFLAGS=$(RELEASE_CFLAGS)
LDFLAGS=$(RELEASE_LDFLAGS) $(RELEASE_LDLIBS)

CC=$(PREFIX)gcc
CXX=$(PREFIX)g++
LD=$(PREFIX)ld
AR=$(PREFIX)ar
NM=$(PREFIX)nm
RANLIB=$(PREFIX)ranlib
STRIP=$(PREFIX)strip

export	CC CXX LD AR NM RANLIB STRIP
export	CFLAGS CXXFLAGS CPPFLAGS LDFLAGS

ARESDIR=${CURDIR}/../c-ares-1.10.0
WOLFSSLDIR=${CURDIR}/../wolfssl-3.9.6
ZLIBDIR=${CURDIR}/../zlib-1.2.8
NGHTTP2DIR=${CURDIR}/../nghttp2-1.11.1



#****************************************************************************
# Makefile code common to all platforms
#****************************************************************************

all:
	cd $(MODULE_SRCPATH);	\
	./configure --host=$(HOST) --build=i686-pc-linux	\
		--prefix=$(OUTDIR)	\
		--enable-static --disable-shared	\
		--enable-http --without-libssh2 --without-librtmp --without-ca-bundle	\
		--disable-rtsp --disable-ftp --disable-ldap --disable-ldaps	\
		--disable-telnet --disable-tftp --disable-pop3 --disable-imap --disable-smtp	\
		--disable-gopher --without-libpsl --without-winidn --without-libidn --disable-smb	\
		--enable-ares="$(ARESDIR)"	\
		--without-ssl --with-cyassl="$(WOLFSSLDIR)"	\
		--with-zlib="$(ZLIBDIR)"	\
		--with-nghttp2="$(NGHTTP2DIR)"	\
		&&	\
	sed -i "s/#define USE_ALARM_TIMEOUT/ /g" lib/hostip.c	&&	\
	sed -i '166,173s/^/\/\//' lib/vtls/cyassl.c				&&	\
	make -j4

install:
	cd $(MODULE_SRCPATH);	\
	make install;	\
	mv $(OUTDIR)/lib $(OUTDIR)/libtmp;	\
	mkdir -p $(OUTDIR)/lib/$(TOOLCHAIN_PATH);	\
	cp $(OUTDIR)/libtmp/libcurl.a $(OUTDIR)/lib/$(TOOLCHAIN_PATH)/

clean:
	cd $(MODULE_SRCPATH);	\
	make clean;	\
	-rm -f Makefile

.PHONY: all install clean

