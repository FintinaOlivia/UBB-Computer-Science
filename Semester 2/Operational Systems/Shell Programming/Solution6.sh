#!/bin/bash

files=($(find -perm -o=w))

for file in ${files[@]}
do
	ls -l $file
	chmod o-w $file
	ls -l $file
done
