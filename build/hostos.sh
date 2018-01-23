
OSNAME=`uname`

if [ x"${OSNAME}" = x"Darwin" ]; then
    echo macos
elif [ x"${OSNAME}" = x"Linux" ]; then
    echo linux64
else
    echo unknown
fi


