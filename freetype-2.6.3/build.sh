
cd `dirname $0`


TOPDIR=`pwd`/../../

source module.env
source ${TOPDIR}/xbuild/env/tools.env


TOOLCHAIN=`listtoolchain ${TOPDIR}`
[ x${TOOLCHAIN} = x"" ] && exit 1


echo "build start ..."

echo "-------------------------------"
if [ ! -f ${MODULE_PACKAGE} ]; then
	echo "downloading ..."
	curl "${MODULE_URL}" > ${MODULE_PACKAGE} || exit 3
fi

echo "-------------------------------"
if [ ! -d ${THISDIR}/${MODULE_SRCPATH} ]; then
	echo "unpack ..."
	tar jxvf ${MODULE_PACKAGE}
fi

echo "-------------------------------"
echo "making ..."
export TOPDIR TOOLCHAIN
make || exit 1
make install || exit 2


echo "==============================="
echo "build success!"


