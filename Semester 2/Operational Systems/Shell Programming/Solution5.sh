#!/bin/bash

if (($# == 1))
then
	danger=$1
else
	echo 'Give the name of the dangerous program as an argument'
	exit 1
fi

while ((1 > 0))
do
	processes=($(ps -ef | grep $danger | awk '{print $2}' | head -n -2))
	for proc in ${processes[@]}
	do
		if (($$ != $proc))
		then
			echo $danger was killed
			kill $proc
		fi
	done
	sleep 1
done

