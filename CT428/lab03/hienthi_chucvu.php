<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Hiển Thị Chức Vụ</title>
</head>

<body>

	<h3><a href="them_chucvu.php">Thêm mới</a></h3>

<?php

	include "dbconnect.php";

	$sql = "SELECT * FROM dinh_dien_chucvu;";
	$result = $conn->query($sql);

	if($result->num_rows > 0) {
		echo "<table border=1>";
		echo "<tr><th>Ma chuc vu</th><th>Ten chuc vu</th></tr>";
		while ($row = $result->fetch_assoc()) {
			echo "<tr>";
			echo "<td>". $row['macv'] ."</td>";
			echo "<td>". $row['chucvu'] ."</td>";
			echo "</tr>";
		}
		echo "</table>";
	}

	$conn->close();
?>

	<h3><a href="main.php">Trở về</a></h3>
</body>
</html>