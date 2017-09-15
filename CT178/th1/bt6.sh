#!/bin/bash
if [ $# -ne 2 ]
then
	exit 0
fi
n=$2
for (( i=0; i<n; i++ ))
do
	echo $1
done
