#!/bin/bash

#Check if there are arguments
if (($# == 0)) ; then
	echo "There need to be some arguments!"

#Check if the first argument is a directory
elif (($# == 1)) ; then
	if (test -d $@) ; then
		directory=$1
	else
		echo "That doesn't seem to be a directory!"
	fi
else
	directory='./'
fi

#Find all the files in the directory
files=($(find $directory -name *.c | tac))

COUNT=0

#Iterate through the files
for file in ${files[@]} ; do
  #Check if the file is bigger than 500 lines
	SIZE=($(wc -l $file | cut -d ' ' -f 1))
	
	if(($SIZE > 500)) ; then
		((COUNT++))
		echo $file 

		#If there are more than 2 files bigger than 500 lines, exit
		if((COUNT == 2)) ; then
			exit 1
		fi
	fi
done
