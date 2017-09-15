#!/bin/bash
read a 
read b
if test $a -eq 0
then
	if test $b -eq 0
	then
		echo Vo so nghiem
	else
		echo Vo nghiem
	fi
else
	# x=`expr -1 \* $b / $a`
	# echo $x
	x=`echo "scale=4; (-($b))/$a"|bc`
	echo Nghiem: $x
fi

