#!/bin/bash

#Take the command line arguments as users
users=($(echo $@))

first=0

#Iterating through the users
for user in ${users[@]}
do
	if ((first == 0))
	then
	  #Concatenating the results
		generated="${generated}${user}@scs.ubbcluj.ro"
		first=1
	else
		generated="${generated}, ${user}@scs.ubbcluj.ro"
	fi
done

echo $generated
