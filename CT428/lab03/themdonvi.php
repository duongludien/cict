<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Thêm đơn vị</title>
	<?php
		include "dbconnect.php";

		// Insert data into database
		if(isset($_POST['donvi'])) {
			$sql = "INSERT INTO dinh_dien_donvi(donvi) VALUES('" . $_POST['donvi'] . "');";

			if ($conn->query($sql)) {
				echo "Them thanh cong!";
				echo '<meta http-equiv="REFRESH" content="0;URL=themdonvi.php" />';
			} else {
				echo "Loi: " . $sql . "" . $conn->error;
			}
		}
	?>

	<style>
		body {font-family: sans-serif;}
	</style>
</head>

<body>
	<h3><a href="index.php">Trở lại trang chính</a></h3>
	<hr />
	<h1>Thêm đơn vị</h1>
	<form action="themdonvi.php" method="POST">
		Tên đơn vị: <input type="text" name="donvi" required="true">
		<input type="submit" name="submit" value="Thêm"> <br>
	</form>
	<br />
	<hr />
	<br />
	
	<?php
		$sql = "SELECT * FROM dinh_dien_donvi;";
		$result = $conn->query($sql);

		if($result->num_rows > 0) {
			echo "<table border='1' cellspacing='0' cellpadding='1'>";
			echo "<tr><th>Mã đơn vị</th><th>Tên đơn vị</th></tr>";
			while($row = $result->fetch_assoc()) {
				echo "<tr>";
				echo "<td>". $row['madv'] ."</td>";
				echo "<td>". $row['donvi'] ."</td>";
				echo "</tr>";
			}
			echo "</table>";
		}

		$conn->close();
	?>
</body>
</html>
