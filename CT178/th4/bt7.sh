#!/bin/bash
trap 'continue' 2
for i in 6 5 4 3 2 1
do
	echo $i
	sleep 5
done
