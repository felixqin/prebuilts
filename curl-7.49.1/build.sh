
cd `dirname $0`
export TOPDIR=`pwd`/../../../
export NGHTTP2DIR="${TOPDIR}/prebuilts/thirdparty/nghttp2-1.11.1"
export OPENSSLDIR="${TOPDIR}/prebuilts/thirdparty/openssl-1.0.2h"
export WOLFSSLDIR="${TOPDIR}/prebuilts/thirdparty/wolfssl-3.9.6"
export ARESDIR="${TOPDIR}/prebuilts/thirdparty/c-ares-1.10.0"
export ZLIBDIR="${TOPDIR}/prebuilts/thirdparty/zlib-1.2.8"

source module.env
source ../../core/core.sh

export TOOLCHAIN=`listtoolchain ${TOPDIR}`
[ x${TOOLCHAIN} = x"" ] && exit 1
export TOOLCHAIN_PATH=`get_toolchain ${TOPDIR}/xbuild/toolchain/${TOOLCHAIN}.mk`


echo "build start ..."

echo "-------------------------------"
if [ ! -f ${MODULE_PACKAGE} ]; then
	echo "downloading ..."
	curl ${MODULE_URL} > ${MODULE_PACKAGE} || exit 2
fi

echo "-------------------------------"
if [ ! -d ${MODULE_SRCPATH} ]; then
	echo "unpack ..."
	tar zxvf ${MODULE_PACKAGE}
fi

echo "-------------------------------"
echo "prepare dependency ..."
./prepare.sh install || exit 5

echo "-------------------------------"
echo "building ..."
export MODULE_SRCPATH
export OUTDIR=`pwd`/out
make || exit 3
make install || exit 4

echo "-------------------------------"
echo "install platform files ..."
cp -a out/include ./
cp -a out/lib ./
rm -fr out

rm -fr ${MODULE_SRCPATH}
./prepare.sh clean || exit 6
