#!/bin/bash

CXX="gcc -xc++"

RED=$(printf "\033[31m")
GREEN=$(printf "\033[32m")
YELLOW=$(printf "\033[33m")
PINK=$(printf "\033[35m")
CYAN=$(printf "\033[36m")
NONE=$(printf "\033[39m")

compile() {
	if $CXX $1 $2	 -o /tmp/nekoxxtest.exec -xnone ../src/libnekoxx.a -fno-exceptions -fno-rtti -nostdinc++ -I ../include 
	then
		return 1;
	fi

}
stdcompile() {
	if $CXX $1 $2	 -o /tmp/nekoxxtest.std.exec -xnone ../src/libnekoxx.a -fno-exceptions -fno-rtti
	then
		return 1;
	fi

}
check_run() {
	if /tmp/nekoxxtest.exec > /tmp/nekoxxtest.output
	then
		echo -n $GREEN"[AC] $2	" $NONE "$1"
		echo

	else
		echo -n $PINK"[RE] $2	" $NONE "$1"
		echo

		cat /tmp/nekoxxtest.output
	fi
}
stdcheck_run() {
	if stdcompile $1 $2	
	then
		echo "${YELLOW}[STD_CE] $2	${NONE} $1"
		echo

		cat /tmp/nekoxxtest.complier
		return 1;
	fi

	if /tmp/nekoxxtest.std.exec > /tmp/nekoxxtest.std.output
	then
		std_passed=1
	else
		std_passed=0
	fi

	if /tmp/nekoxxtest.exec > /tmp/nekoxxtest.output
	then
		if (($std_passed > 0))
		then 
			echo -n $GREEN"[AC] $2	" $NONE "$1"
			echo
		else
			echo -n $CYAN"[INCONSISTENT_AC] $2	" $NONE "$1"
			echo
			diff -u  /tmp/nekoxxtest.output /tmp/nekoxxtest.std.output
		fi
	else
		if (($std_passed > 0))
		then 
			echo -n $CYAN"[INCONSISTENT_WA] $2	" $NONE "$1"
			echo
			diff -u /tmp/nekoxxtest.output /tmp/nekoxxtest.std.output
		else
			echo -n $RED"[WA] $2	" $NONE "$1"
			echo
			cat /tmp/nekoxxtest.output
		fi
	fi
}

stdrun_and_cmp() {
	if stdcompile $1 $2	
	then
		echo "${YELLOW}[STD_CE]${NONE} $1"
		echo

		cat /tmp/nekoxxtest.complier
		return 1;
	fi

	if ! /tmp/nekoxxtest.std.exec > /tmp/nekoxxtest.std.output
	then
		echo -n $PINK"[STD_RE] $2	" $NONE "$1\n"
	else
		if diff /tmp/nekoxxtest.std.output $1.expect > /tmp/nekoxxtest.std.diff
		then
			std_passed=1
		else
			std_passed=0
		fi
	fi

	if ! /tmp/nekoxxtest.exec > /tmp/nekoxxtest.output
	then
		echo -n $PINK"[RE] $2	" $NONE "$1\n"
	else
		if diff /tmp/nekoxxtest.output $1.expect > /tmp/nekoxxtest.diff
		then
			if diff /tmp/nekoxxtest.diff /tmp/nekoxxtest.std.diff
			then
				echo -n $GREEN"[AC] $2	" $NONE "$1"
				echo
				
			else
				echo -n $CYAN"[INCONSISTENT_AC] $2	" $NONE "$1"
				echo

				diff -u /tmp/nekoxxtest.diff /tmp/nekoxxtest.std.diff
			fi
		else
			if diff /tmp/nekoxxtest.diff /tmp/nekoxxtest.std.diff
			then
				echo -n $RED"[WA] $2	" $NONE "$1"
				echo
				cat /tmp/nekoxxtest.diff
			else
				
				echo -n $CYAN"[INCONSISTENT_WA] $2	" $NONE "$1"
				echo

				diff -u /tmp/nekoxxtest.diff /tmp/nekoxxtest.std.diff
			fi
		fi
	fi
}
run_and_cmp() {
	if ! /tmp/nekoxxtest.exec > /tmp/nekoxxtest.output
	then
		echo -n $PINK"[RE] $2	" $NONE "$1\n"
		ERR=1;
	else
		if diff /tmp/nekoxxtest.output $1.expect > /tmp/nekoxxtest.diff
		then
			echo -n $GREEN"[AC] $2	" $NONE "$1"
			echo

		else
			echo -n $RED"[WA] $2	" $NONE "$1"
			echo

			cat /tmp/nekoxxtest.diff
		fi
	fi
}
run_test() {
	if compile $1 $2	
	then
		echo "${YELLOW}[CE]${NONE} $1"
		cat /tmp/nekoxxtest.complier
		return 1;
	fi

	case $1 in
		*.run.cpp)
			check_run $1 -O0;
			check_run $1 -O1;
			check_run $1 -O2;
			check_run $1 -O3;
			check_run $1 -Os;
			check_run $1 -Ofast;
			check_run $1 -Og;
			;;
		*.cmp.cpp)
			run_and_cmp $1 -O0;
			run_and_cmp $1 -O1;
			run_and_cmp $1 -O2;
			run_and_cmp $1 -O3;
			run_and_cmp $1 -Os;
			run_and_cmp $1 -Ofast;
			run_and_cmp $1 -Os;
			;;
		*.cmpstd.cpp)
			stdrun_and_cmp $1 -O0;
			stdrun_and_cmp $1 -O1;
			stdrun_and_cmp $1 -O2;
			stdrun_and_cmp $1 -O3;
			stdrun_and_cmp $1 -Os;
			stdrun_and_cmp $1 -Ofast;
			stdrun_and_cmp $1 -Og;
			;;
		*.runstd.cpp)
			stdcheck_run $1 -O0;
			stdcheck_run $1 -O1;
			stdcheck_run $1 -O2;
			stdcheck_run $1 -O3;
			stdcheck_run $1 -Os;
			stdcheck_run $1 -Ofast;
			stdcheck_run $1 -Og;
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
