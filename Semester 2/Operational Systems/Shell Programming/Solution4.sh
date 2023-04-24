#!/bin/bash

if (($# == 1))
then
	directory=$1
else
	directory='./'
fi

paths=($(find $directory))

for path in ${paths[@]}
do
	if test -L $path
	then
		if ! test -e $path
		then
			echo $path
		fi
	fi

done
