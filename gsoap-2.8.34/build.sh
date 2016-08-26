
THISDIR=`dirname $0`

cd ${THISDIR}
rm -fr gsoap-2.8
unzip gsoap_2.8.34.zip

cd gsoap-2.8
./configure --prefix=`pwd`/../tmpbin
make && make install

