echo -n "Nhap vao ten thu muc can tao: "
read dname
mkdir $dname
if test $? -ne 0
then
echo "Khong the tao duoc thu muc"
fi


