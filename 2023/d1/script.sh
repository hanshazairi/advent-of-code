#!/bin/bash

trim_alpha () {
	cat - | tr -d '[a-z]'
}

get_cal_val () {
	INPUT=`cat -`
	TERM_1=`echo "$INPUT" | grep '^.$' | sed 's|\(.\)|\1\1|' | paste -s -d+ - | bc`
	TERM_2=`echo "$INPUT" | grep '..$' | sed 's|\(.\).*\(.\)|\1\2|' | paste -s -d+ - | bc`
	
	echo "${TERM_1}+${TERM_2}" | bc
}

parse () {
	cat - | sed 's/one/o1e/g' | \
		sed 's/two/t2o/g' | \
		sed 's/three/t3e/g' | \
		sed 's/four/f4r/g' | \
		sed 's/five/f5e/g' | \
		sed 's/six/s6x/g' | \
		sed 's/seven/s7n/g' | \
		sed 's/eight/e8t/g' | \
		sed 's/nine/n9e/g'
}

p1 () {
	cat - | trim_alpha | get_cal_val
}

p2 () {
	cat - | parse | trim_alpha | get_cal_val
}

p1 < input.txt
p2 < input.txt
