#!/bin/bash

#Check if there are arguments
if (($# == 0)) ; then
	echo "We need some arguments there"

#Check if there is one argument and if it is a directory
elif (($# == 1)) ; then
	if (test -d $@) ; then
		directory=$1
	else
		echo "We need a directory!"
	fi
else
	directory='./'
fi

#Find all the files with .log extension
files=($(find $directory -name *.log))
echo $files

#Sort the files
for file in ${files[@]} ; do
	cat $file | sort -o $file
done
