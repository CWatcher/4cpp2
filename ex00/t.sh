#!/bin/zsh

make > /dev/null		\
	&& echo make ok! 	\
	|| exit 1

valgrind -q aa
