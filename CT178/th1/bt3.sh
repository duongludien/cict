#!/bin/bash
hour=23
#hour=`date +%H`
if [ $hour -ge 1 -a $hour -le 10 ]
then
	echo Good Morning
elif [ $hour -eq 11 -o $hour -eq 12 ]
then
	echo Good Afternoon
elif [ $hour -ge 13 -a $hour -le 21 ]
then
	echo Good Evening
else
	echo Good Night
fi
