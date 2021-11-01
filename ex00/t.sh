#!/bin/sh

make > /dev/null							\
	&& printf "%-27s: %s\n" 'make' 'ok!' 	\
	|| exit 1

valgrind -q aa | diff subject.output.txt -	\
	&& echo Compare with subject output: ok!
printf "\n%-s:\n\n" "Extended test"
aa --extended
