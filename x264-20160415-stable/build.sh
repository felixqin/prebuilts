
THISDIR=`dirname $0`

BUILD_PLATFORM=`${THISDIR}/../build/hostos.sh`

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
	tar jxvf ${MODULE_PACKAGE}
fi

cd ${THISDIR}/${MODULE_SRCPATH}

echo "-------------------------------"
echo "configure ..."
./configure --prefix=`pwd`/../tmp-bin/	\
	--disable-cli	\
	--enable-shared

echo "-------------------------------"
echo "making ..."
make -j4 || exit 1
make install || exit 2


echo "-------------------------------"
cd ..
echo "install platform files ..."

mkdir -p include
mkdir -p lib/${BUILD_PLATFORM}
cp -prf tmp-bin/include/* include/
#cp -f tmp-bin/bin/*.dll lib/${BUILD_PLATFORM}/
#cp -f tmp-bin/bin/*.lib lib/${BUILD_PLATFORM}/
cp -f tmp-bin/lib/*.a lib/${BUILD_PLATFORM}/
cp -f tmp-bin/lib/*.so lib/${BUILD_PLATFORM}/
cp tmp-bin/lib/*.dylib lib/${BUILD_PLATFORM}/


