#!/bin/bash
echo 1. Cafe den
echo 2. Cafe da
echo 3. Cafe sua
echo 4. Cafe cao
echo -n Ban chon thuc uong nao \(1\-4\)?\ 
read choice
if [ $choice -eq 1 ]
then
	echo Ban chon cafe den
elif [ $choice -eq 2 ]
then
	echo Ban chon cafe da
elif [ $choice -eq 3 ]
then
	echo Ban chon cafe sua
else
	echo Ban chon cafe cao
fi

