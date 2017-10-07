<?php
	$dbhost = "localhost";
	$dbuser = "user_s6";
	$dbpass = "puser_s6";
	$dbname = "db_s6";

	$conn = new mysqli($dbhost, $dbuser, $dbpass, $dbname);

	if ($conn->connect_error) {
		die("Loi ket noi: " . $conn->connect_error);
	}

	// $sql = "INSERT INTO dinh_dien_nhanvien(hoten, namsinh, gioitinh, madv, macv, luong) VALUES(" . 
	// "'" . $_POST['hoten'] . "', " .
	// "'" . $_POST['namsinh'] . "', " .
	// "'" . $_POST['gioitinh'] . "', " .
	// $_POST['madv'] . ", " .
	// $_POST['macv'] . ", " .
	// $_POST['luong'] .
	// ");";

	// echo $sql;

	// if ($conn->query($sql)) {
	// 	echo "Them thanh cong!";
	// } else {
	// 	echo "Loi: " . $sql . "" . $conn->error;
	// }

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
