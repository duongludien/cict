#!/bin/bash
read n
for (( i = 1 ; i <= $n ; i++ ))
do
	mkdir user_$i
done
