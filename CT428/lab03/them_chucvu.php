<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Thêm Chức Vụ</title>
	<?php
		include "dbconnect.php";

		if(isset($_POST['chucvu'])) {
			$sql = "INSERT INTO dinh_dien_chucvu(chucvu) VALUES('" . $_POST['chucvu'] . "');";

			if ($conn->query($sql)) {
				echo "Them thanh cong!";
				echo '<meta http-equiv="REFRESH" content="0;URL=hienthi_chucvu.php" />';
			} else {
				echo "Loi: " . $sql . "" . $conn->error;
			}
		}

	?>
</head>

<body>
	<h3>Them chuc vu</h3>
	<form action="" method="POST">
		Ten chuc vu: <input type="text" name="chucvu" required="true">
		<input type="submit" name="submit" value="Them"> <br>
		<input type="button" name="back" value="Tro ve" onClick="window.location='hienthi_chucvu.php'">
	</form>
</body>
</html>
<?php
	$conn->close();
?>
