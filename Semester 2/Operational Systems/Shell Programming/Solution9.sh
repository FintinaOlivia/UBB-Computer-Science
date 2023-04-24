#!/bin/bash

if (($# == 1))
then
	directory=$1
else
	directory='./'
fi

files=($(find $directory))

echo "Files that have duplicates"

for file in ${files[@]} ; do
	for other in ${files[@]} ; do
		if test -e $file ; then
			if test $file != $other ; then
				if test -e $other ; then
					sum1=$(cksum $file | cut -d ' ' -f 1)
					sum2=$(cksum $other | cut -d ' ' -f 1)
					
					if test "$sum1" == "$sum2" ; then
						echo $other is duplicate of $file
					fi
				fi
			fi
		fi
	done
done

