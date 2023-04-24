#!/bin/bash

fileSystems=($(awk '{print $6}' df.fake | tail -n +2))
sizes=($(awk '{print $2}' df.fake | tail -n +2 | cut -d 'M' -f 1))
percentages=($(awk '{print $5}' df.fake | tail -n +2 | cut -d '%' -f 1))
count=$(wc -l df.fake | awk '{print $1}')
let count--

index=0

while ((index < count))
do
	if ((${sizes[index]} < 1000))
	then
		echo ${fileSystems[index]}
	elif ((${percentages[index]} > 80))
	then
		echo ${fileSystems[index]}
	fi
	let index++
done
