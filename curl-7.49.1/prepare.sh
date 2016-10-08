
THISDIR=`dirname $0`

case $1 in
	install)
		# prepare pkgconfig of nghttp2, openssl and zlib
		${OPENSSLDIR}/lib/pkgconfig/build.sh ${TOOLCHAIN_PATH}
		${NGHTTP2DIR}/lib/pkgconfig/build.sh ${TOOLCHAIN_PATH}
		${ZLIBDIR}/lib/pkgconfig/build.sh ${TOOLCHAIN_PATH}

		# prepare wolfssl cares and zlib
		cp ${WOLFSSLDIR}/lib/${TOOLCHAIN_PATH}/libwolfssl.a ${WOLFSSLDIR}/lib/
		cp ${ARESDIR}/lib/${TOOLCHAIN_PATH}/libcares.a ${ARESDIR}/lib/
		cp ${ZLIBDIR}/lib/${TOOLCHAIN_PATH}/libz.a ${ZLIBDIR}/lib/
		;;

	clean)
		rm ${WOLFSSLDIR}/lib/libwolfssl.a
		rm ${ARESDIR}/lib/libcares.a
		rm ${ZLIBDIR}/lib/libz.a
		;;

	*)
		echo "invalid arguments"
		exit 1
		;;
esac

exit 0

