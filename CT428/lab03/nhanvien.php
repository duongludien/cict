
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Thêm nhân viên</title>

	<style>
		body {font-family: sans-serif;}
	</style>
</head>

<body>
	<h3><a href="index.php">Trở lại trang chính</a></h3>
	<hr />
	<?php
		include "dbconnect.php";

		$sql = "SELECT nv.manv, nv.hoten, nv.namsinh, nv.gioitinh, dv.donvi, cv.chucvu, nv.luong " . 
					"FROM dinh_dien_nhanvien AS nv, dinh_dien_donvi AS dv, dinh_dien_chucvu AS cv " . 
					"WHERE nv.madv = dv.madv AND nv.macv = cv.macv;";
	
		$result = $conn->query($sql);

		if($result->num_rows > 0) {
			echo "<table border='1' cellspacing='0' cellpadding='1'>";
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
</body>
</html>
