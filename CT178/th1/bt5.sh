#!/bin/bash
while [ true ]
do
	echo 1. +
	echo 2. -
	echo 3. \*
	echo 4. \/
	echo q. quit
	echo -n Moi ban lua chon \(1\-4\/q\)?\ 
	read choice
	if [ $choice = q ]
	then
		exit 1
	else
		echo -n Moi ban nhap so thu nhat:\ 
		read a
		echo -n Moi ban nhap so thu hai:\ 
		read b
		case $choice in
			1) echo $a + $b = `expr $a + $b`;;
			2) echo $a - $b = `expr $a - $b`;;
			3) echo $a \* $b = `expr $a \* $b`;;
			4) echo $a / $b = `expr $a / $b`;;
		esac
	fi
done
