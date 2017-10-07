<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Hiển Thị Nhân Viên</title>
</head>

<body>

	<h3><a href="them_nhanvien.php">Thêm mới</a></h3>
	
<?php
	
	include "dbconnect.php";

	$sql = "SELECT nv.manv, nv.hoten, nv.namsinh, nv.gioitinh, dv.donvi, cv.chucvu, nv.luong " . "FROM dinh_dien_nhanvien AS nv, dinh_dien_donvi AS dv, dinh_dien_chucvu AS cv " . "WHERE nv.madv = dv.madv AND nv.macv = cv.macv;";
	
	$result = $conn->query($sql);

	if($result->num_rows > 0) {
		echo "<table border=1>";
		echo "<tr>";
		echo "<th>MANV</th>";
		echo "<th>HO TEN</th>";
		echo "<th>NGAY SINH</th>";
		echo "<th>GIOI TINH</th>";
		echo "<th>DON VI</th>";
		echo "<th>CHUC VU</th>";
		echo "<th>LUONG (Ngan VND)</th>";
		echo "<tr>";
		while ($row = $result->fetch_assoc()) {
			echo "<tr>";
			echo "<td>". $row['manv'] ."</td>";
			echo "<td>". $row['hoten'] ."</td>";
			echo "<td>". $row['namsinh'] ."</td>";
			echo "<td>". $row['gioitinh'] ."</td>";
			echo "<td>". $row['donvi'] ."</td>";
			echo "<td>". $row['chucvu'] ."</td>";
			echo "<td>". $row['luong'] ."</td>";
			echo "</tr>";
		}
		echo "</table>";
	}

	$conn->close();
?>

	<h3><a href="main.php">Trở về</a></h3>
</body>
</html>