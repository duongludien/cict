
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Thêm nhân viên</title>
	<?php
		include "dbconnect.php";

		if(isset($_POST['hoten'])) {

			$sql = "INSERT INTO dinh_dien_nhanvien(hoten, namsinh, gioitinh, madv, macv, luong) VALUES(" . 
				"'" . $_POST['hoten'] . "', " .
				"'" . $_POST['namsinh'] . "', " .
				"'" . $_POST['gioitinh'] . "', " .
				$_POST['madv'] . ", " .
				$_POST['macv'] . ", " .
				$_POST['luong'] .
				");";

				// echo $sql;

			if ($conn->query($sql)) {
				echo "Them thanh cong!";
				echo '<meta http-equiv="REFRESH" content="0;URL=themnhanvien.php" />';
			} else {
				echo "Lỗi: " . $sql . "" . $conn->error;
			}
		}
	
	?>
	<style>
		body {font-family: sans-serif;}
	</style>
</head>

<body>
	<form action="" method="POST">
		<table>
			<tr>
				<td colspan="2"><h1>Thêm nhân viên</h1></td>
			</tr>
			<tr>
				<td>Họ tên nhân viên:</td>
				<td><input name="hoten" type="text" required="true"></td>
			</tr>
			<tr>
				<td>Ngày sinh:</td>
				<td><input name="namsinh" type="date" required></td>
			</tr>
			<tr>
				<td>Giới tính:</td>
				<td>
					<input name="gioitinh" value="Nam" checked="true" type="radio"> Nam
					<input name="gioitinh" value="Nu" type="radio"> Nu
				</td>
			</tr>
			<tr>
				<td>Đơn vị:</td>
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
				<td>Chức vụ:</td>
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
				<td>Lương:</td>
				<td><input name="luong" type="number" min="1001" required></td>
			</tr>
			<tr>
				<td colspan="2" align="center">
					<input name="submit" value="Thêm" type="submit">
					<input type="reset" name="reset" value="Nhập lại">
				</td>
			</tr>
		</table>
	</form>

	<br /><hr /><br />
	<?php
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

<?php
	$conn->close();
?>
