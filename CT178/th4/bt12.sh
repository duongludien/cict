#!/bin/bash
trap 'continue' 2
for i in 5 4 3 2 1
do
	echo "Shutdown in $i minutes"
	sleep 10
done
trap 2
