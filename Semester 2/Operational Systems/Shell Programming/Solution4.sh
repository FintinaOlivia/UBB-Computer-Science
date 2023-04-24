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

#Paths of all the files in the directory
paths=($(find $directory))

#Check if the path is a symbolic link and if it is broken
for path in ${paths[@]}
do
  #Check if the path is a symbolic link
	if test -L $path
	then
	      #Check if the path is broken
		if ! test -e $path
		then
			echo $path
		fi
	fi

done
