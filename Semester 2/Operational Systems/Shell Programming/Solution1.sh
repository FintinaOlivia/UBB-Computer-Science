#!/bin/bash

#Creating the array of users
users=($(awk '{print $1}' who.fake))

#Iterating through the array of users
for user in ${users[@]} ; do

	#Checking the frequency of each user
	frequency=($(grep -c -e ^$user ps.fake))
	
	#Printing to the console each user
	echo "$user" $frequency
done
