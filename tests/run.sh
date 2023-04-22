#!/bin/sh

CXX="gcc -xc++"

RED=$(printf "\033[31m")
GREEN=$(printf "\033[32m")
YELLOW=$(printf "\033[33m")
PINK=$(printf "\033[35m")
NONE=$(printf "\033[39m")

compile() {
	if $CXX $1 -o /tmp/nekoxxtest.exec -xnone ../src/libnekoxx.a	\
		-fno-exceptions -fno-rtti -nostdinc++ -I ../include
	then
		return 1;
	fi

}

check_run() {
	if /tmp/nekoxxtest.exec > /tmp/nekoxxtest.output
	then
		echo -n $GREEN"[AC]" $NONE "$1\n"
	else
		echo -n $PINK"[RE]" $NONE "$1\n"
		cat /tmp/nekoxxtest.output
	fi
}

run_and_cmp() {
	if ! /tmp/nekoxxtest.exec > /tmp/nekoxxtest.output
	then
		echo -n $PINK"[RE]" $NONE "$1\n"
		ERR=1;
	else
		if diff /tmp/nekoxxtest.output $1.expect > /tmp/nekoxxtest.diff
		then
			echo -n $GREEN"[AC]" $NONE "$1\n"
		else
			echo -n $RED"[WA]" $NONE "$1\n"
			cat /tmp/nekoxxtest.diff
		fi
	fi
}

run_test() {
	if compile $1
	then
		echo "${YELLOW}[CE]${NONE} $1"
		cat /tmp/nekoxxtest.complier
		return 1;
	fi

	case $1 in
		*.run.cpp)
			check_run $1;
			;;
		*.cmp.cpp)
			run_and_cmp $1;
			;;
		*)
			;;
	esac
}

if [ $1x = x ]
then
	for test in `ls *.cpp`
	do
		run_test $test;
	done
else
	run_test $1
fi
