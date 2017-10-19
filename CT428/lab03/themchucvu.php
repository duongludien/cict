<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Thêm chức vụ</title>
	<?php
		include "dbconnect.php";

		if(isset($_POST['chucvu'])) {
			$sql = "INSERT INTO dinh_dien_chucvu(chucvu) VALUES('" . $_POST['chucvu'] . "');";

			if ($conn->query($sql)) {
				echo "Them thanh cong!";
				echo '<meta http-equiv="REFRESH" content="0;URL=themchucvu.php" />';
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
	<h1>Thêm chức vụ</h1>
	<form action="themchucvu.php" method="POST">
		Tên chức vụ: <input type="text" name="chucvu" required="true">
		<input type="submit" name="submit" value="Thêm"> <br>
	</form>
	<br /><hr /><br />
	<?php
		$sql = "SELECT * FROM dinh_dien_chucvu;";
		$result = $conn->query($sql);

		if($result->num_rows > 0) {
			echo "<table border='1' cellspacing='0' cellpadding='1'>";
			echo "<tr><th>Mã chức vụ</th><th>Chức vụ</th></tr>";
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
</body>
</html>
