#!/bin/bash
continue=1
while test $continue -eq 1
do
	echo -n "Nhap vao n: "
	read n
	for (( i = 1 ; i <= 10 ; i++ ))
	do
		echo $i x $n = `expr $i \* $n`
	done
	echo Ban co muon tiep tuc khong, muon 1, khong 0
	read continue
done
