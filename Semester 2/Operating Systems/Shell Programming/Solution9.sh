#!/bin/bash

#Check if there are arguments
if (($# == 0)) ; then
	echo "We need some arguments there"

#Check if there is one argument and if it is a directory
elif (($# == 1)) ; then
	if (test -d "$@") ; then
		directory=$1
	else
		echo "We need a directory!"
	fi
else
	directory='./'
fi

#Find directories and files
files=($(find $directory))

echo "Files that have duplicates"

#Check for duplicates
# shellcheck disable=SC2068
for file in ${files[@]} ; do
	# shellcheck disable=SC2068
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

