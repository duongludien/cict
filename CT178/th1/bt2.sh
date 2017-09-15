#!/bin/bash
echo -n "Nhap ten cua ban vao day: " 
read first_name
echo -n "Nhap ho cua ban vao day: "
read last_name
if [ $first_name = Dien -a $last_name = Duong ]
then
	echo "Trung ten roi nha anh ban"
fi
