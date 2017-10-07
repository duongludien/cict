<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Thêm Đơn Vị</title>
	<?php
		include "dbconnect.php";

		if(isset($_POST['donvi'])) {
			$sql = "INSERT INTO dinh_dien_donvi(donvi) VALUES('" . $_POST['donvi'] . "');";

			if ($conn->query($sql)) {
				echo "Them thanh cong!";
				echo '<meta http-equiv="REFRESH" content="0;URL=hienthi_donvi.php" />';
			} else {
				echo "Loi: " . $sql . "" . $conn->error;
			}
		}
	?>
</head>

<body>
	<h1>Them don vi</h1>
	<form action="" method="POST">
		Ten don vi: <input type="text" name="donvi" required="true">
		<input type="submit" name="submit" value="Them"> <br>
		<input type="button" name="back" value="Tro ve" onClick="window.location='hienthi_donvi.php'">
	</form>
</body>
</html>
