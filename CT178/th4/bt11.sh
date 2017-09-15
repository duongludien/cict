#!/bin/bash
trap 'kill $pid' 2
for i in $*
do
	# echo Noi dung file $i
	cat $i
	sleep 10 &
	pid=$!
	wait $pid
done
trap 2
