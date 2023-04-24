#!/bin/bash

#Find all the files with write permission for others
files=($(find -perm -o=w))

for file in ${files[@]}
do
  #Remove the write permission for others
	ls -l $file
	chmod o-w $file
	ls -l $file
done
