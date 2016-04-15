
BUILD_PLATFORM=mingw32

THISDIR=`dirname $0`

source ${THISDIR}/module.env


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
	--disable-asm

echo "-------------------------------"
echo "making ..."
make -j4 || exit 1
make install || exit 2


echo "-------------------------------"
cd ..
echo "install platform files ..."

mkdir -p include
mkdir -p lib/${BUILD_PLATFORM}
cp -dpr tmp-bin/include/* include/
cp tmp-bin/bin/*.dll lib/${BUILD_PLATFORM}/
cp tmp-bin/bin/*.lib lib/${BUILD_PLATFORM}/
cp tmp-bin/lib/*.a lib/${BUILD_PLATFORM}/


