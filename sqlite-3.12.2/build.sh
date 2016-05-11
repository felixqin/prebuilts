
BUILD_PLATFORM=mingw32

THISDIR=`dirname $0`

source ${THISDIR}/module.env


echo "build start ..."
cd ${THISDIR}

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

cd ${MODULE_SRCPATH}

echo "-------------------------------"
echo "making ..."
cp ../Makefile ./
make TOOLCHAIN=${BUILD_PLATFORM} || exit 1

echo "-------------------------------"
cd ..
echo "install platform files ..."

mkdir -p include/sqlite
mkdir -p lib/${BUILD_PLATFORM}
cp ${MODULE_SRCPATH}/sqlite3.h include/sqlite
cp ${MODULE_SRCPATH}/sqlite3ext.h include/sqlite
cp ${MODULE_SRCPATH}/*.a lib/${BUILD_PLATFORM}/
cp ${MODULE_SRCPATH}/*.so lib/${BUILD_PLATFORM}/

rm -fr ${MODULE_SRCPATH}
