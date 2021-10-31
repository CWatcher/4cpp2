#!/bin/sh

make > /dev/null		\
	&& echo make ok! 	\
	|| exit 1

valgrind -q aa | diff subject.out - && echo ok!
aa --extended
