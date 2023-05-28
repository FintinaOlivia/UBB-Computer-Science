#!/bin/bash

#Separate the arguments from the options

fileSystems=($(awk '{print $6}' df.fake | tail -n +2))
sizes=($(awk '{print $2}' df.fake | tail -n +2 | cut -d 'M' -f 1))
percentages=($(awk '{print $5}' df.fake | tail -n +2 | cut -d '%' -f 1))
count=$(wc -l df.fake | awk '{print $1}')
let count--

index=0

while ((index < count)) ; do
  #Check if the size is less than 1000
	if ((${sizes[index]} < 1000)) ; then
		echo ${fileSystems[index]}

  #Check if the percentage is greater than 80
	elif ((${percentages[index]} > 80)) ; then
		echo ${fileSystems[index]}
	fi
	let index++
done
