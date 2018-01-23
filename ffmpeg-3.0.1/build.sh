

THISDIR=`dirname $0`

source ${THISDIR}/module.env


BUILD_PLATFORM=`${THISDIR}/../build/hostos.sh`


echo "build start ..."

echo "-------------------------------"
if [ ! -f ${THISDIR}/${MODULE_PACKAGE} ]; then
	echo "downloading ..."
	curl ${MODULE_URL} > ${THISDIR}/${MODULE_PACKAGE} || exit 3
fi

echo "-------------------------------"
if [ ! -d ${THISDIR}/${MODULE_SRCPATH} ]; then
	echo "unpack ..."
	tar Jxvf ffmpeg-3.0.1.tar.xz
fi

cd ${THISDIR}/${MODULE_SRCPATH}

if [ x"${BUILD_PLATFORM}" = x"mingw32" ]; then
	PLATFORM_OPTIONS=--disable-asm
elif [ x"${BUILD_PLATFORM}" = x"macos" ]; then
	PLATFORM_OPTIONS=--disable-yasm
fi 

echo "-------------------------------"
echo "configure ..."
./configure --prefix=`pwd`/../tmp-bin/	\
	--disable-static	\
	--enable-shared		\
	--enable-memalign-hack	\
	--disable-programs	\
	--disable-doc	\
	--disable-avdevice	\
	--disable-swresample	\
	--disable-swscale 	\
	--disable-postproc	\
	--disable-avfilter	\
	--disable-network	\
	--disable-everything	\
	--enable-decoder=h264	\
	--enable-demuxer=avi	\
	--enable-protocol=file	\
	${PLATFORM_OPTIONS}

echo "-------------------------------"
echo "making ..."
make -j4 || exit 1
make install || exit 2


echo "-------------------------------"
cd ..
echo "install platform files ..."

mkdir -p include
mkdir -p lib/${BUILD_PLATFORM}
cp -dprf tmp-bin/include/* include/
if [ x"${BUILD_PLATFORM}" = x"mingw32" ]; then
	cp -f tmp-bin/bin/*.dll lib/${BUILD_PLATFORM}/
	cp -f tmp-bin/bin/*.lib lib/${BUILD_PLATFORM}/
	cp -f tmp-bin/lib/*.a lib/${BUILD_PLATFORM}/
elif [ x"${BUILD_PLATFORM}" = x"linux64" ]; then
	cp -f tmp-bin/lib/libavformat.so.57 lib/${BUILD_PLATFORM}/
	cp -f tmp-bin/lib/libavcodec.so.57 lib/${BUILD_PLATFORM}/
	cp -f tmp-bin/lib/libavutil.so.55 lib/${BUILD_PLATFORM}/
elif [ x"${BUILD_PLATFORM}" = x"macos" ]; then
	cp -f tmp-bin/lib/libavformat.dylib lib/${BUILD_PLATFORM}/
	cp -f tmp-bin/lib/libavcodec.dylib lib/${BUILD_PLATFORM}/
	cp -f tmp-bin/lib/libavutil.dylib lib/${BUILD_PLATFORM}/
fi

