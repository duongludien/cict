<?php
	$dbhost = "localhost";
	$dbuser = "user_s6";
	$dbpass = "puser_s6";
	$dbname = "db_s6";

	$conn = new mysqli($dbhost, $dbuser, $dbpass, $dbname);

	if ($conn->connect_error) {
		die("Loi ket noi: " . $conn->connect_error);
	}
?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Them nhan vien</title>
</head>

<body>
	<form action="them_nhanvien_xuly.php" method="POST">
		<table>
			<tr>
				<td colspan="2"><h1>Them nhan vien</h1></td>
			</tr>
			<tr>
				<td>Ho ten nhan vien:</td>
				<td><input name="hoten" type="text" required="true"></td>
			</tr>
			<tr>
				<td>Ngay sinh:</td>
				<td><input name="namsinh" type="date"></td>
			</tr>
			<tr>
				<td>Gioi tinh:</td>
				<td>
					<input name="gioitinh" value="Nam" checked="true" type="radio"> Nam
					<input name="gioitinh" value="Nu" type="radio"> Nu
				</td>
			</tr>
			<tr>
				<td>Don vi:</td>
				<td>
					<select name="madv">
						<?php
							$sql = "SELECT madv, donvi FROM dinh_dien_donvi;";
							$result = $conn->query($sql);
							while ($row = $result->fetch_assoc()) {
								echo "<option value='" . $row['madv'] . "'>" . $row['donvi'] ."</option>";
							}
						?>
					</select>
				</td>
			</tr>
			<tr>
				<td>Chuc vu:</td>
				<td>
					<select name="macv">
						<?php
							$sql = "SELECT * FROM dinh_dien_chucvu;";
							$result = $conn->query($sql);
							while ($row = $result->fetch_assoc()) {
								echo "<option value='" . $row['macv'] . "'>" . $row['chucvu'] ."</option>";
							}
						?>
					</select>
				</td>
			</tr>
			<tr>
				<td>Luong:</td>
				<td><input name="luong" type="number" min="1001"></td>
			</tr>
			<tr>
				<td colspan="2" align="center">
					<input name="submit" value="Them" type="submit">
					<input type="reset" name="reset" value="Nhap lai">
				</td>
			</tr>
		</table>
	</form>
</body>
</html>

<?php
	$conn->close();
?>
