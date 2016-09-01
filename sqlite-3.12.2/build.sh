
BUILD_PLATFORM=android15armeabiv7aneon

THISDIR=`dirname $0`
cd ${THISDIR}

TOPDIR=`pwd`/../../

source ${THISDIR}/module.env


echo "build start ..."

echo "-------------------------------"
if [ ! -f ${MODULE_PACKAGE} ]; then
	echo "downloading ..."
	curl ${MODULE_URL} > ${MODULE_PACKAGE} || exit 3
fi

echo "-------------------------------"
if [ ! -d ${MODULE_SRCPATH} ]; then
	echo "unpack ..."
	unzip ${MODULE_PACKAGE}
fi

rm -fr build-cmake
mkdir -p build-cmake
cd build-cmake
echo "-------------------------------"
echo "making ..."
export MODULE_SRCPATH
cmake -DCMAKE_TOOLCHAIN_FILE=${TOPDIR}/xbuild/cmake/${BUILD_PLATFORM}.toolchain.cmake ..
make || exit 1
exit 0

echo "-------------------------------"
cd ..
echo "install platform files ..."

mkdir -p include/sqlite
mkdir -p lib/${BUILD_PLATFORM}
cp ${MODULE_SRCPATH}/sqlite3.h include/sqlite
cp ${MODULE_SRCPATH}/sqlite3ext.h include/sqlite
#cp ${MODULE_SRCPATH}/*.a lib/${BUILD_PLATFORM}/
#cp ${MODULE_SRCPATH}/*.so lib/${BUILD_PLATFORM}/

rm -fr ${MODULE_SRCPATH}
