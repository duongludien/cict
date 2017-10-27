<!DOCTYPE html>
<html>
<head>
	<title>Sửa, xóa nhân viên</title>
	<meta charset="utf-8">

	<?php
		include "dbconnect.php";

		// Xử lý xóa
		if(isset($_POST['xoa'])) {
			$check = $_POST['check'];

			foreach($check as $value) {
				$sql = "DELETE FROM dinh_dien_nhanvien WHERE manv='" . $value ."'";
				$conn->query($sql);
			}

			echo '<meta http-equiv="refresh" content="0;suaxoanv.php">';
		}
	?>

	<style>
		body {font-family: sans-serif;}
	</style>
</head>
<body>
	<h2><a href='lab05.html'>Trở lại trang chính</a></h2>
	<hr />

	<form method="POST" action="">
		<input type="submit" name="xoa" value="Xóa các nhân viên đã chọn" />
		<br><br>

		<table border="1" cellspacing="0">
			<tr>
				<th>CHỌN</th>
				<th>MÃ NHÂN VIÊN</th>
				<th>HỌ TÊN</th>
				<th>ẢNH ĐẠI DIỆN</th>
				<th>NĂM SINH</th>
				<th>GIỚI TÍNH</th>
				<th>ĐƠN VỊ</th>
				<th>CHỨC VỤ</th>
				<th>LƯƠNG</th>
				<th>CHỈNH SỬA</th>
			</tr>
			
			<?php
			$sql = "SELECT nv.manv, nv.hoten, nv.namsinh, nv.gioitinh, dv.donvi, cv.chucvu, nv.luong, nv.avatar " . 
						"FROM dinh_dien_nhanvien AS nv, dinh_dien_donvi AS dv, dinh_dien_chucvu AS cv " . 
						"WHERE nv.madv = dv.madv AND nv.macv = cv.macv;";
		
				$result = $conn->query($sql);

				while($row = $result->fetch_assoc()) {
					echo "<tr>";
					echo "<td align='center'><input type='checkbox' value='". $row['manv'] ."' name='check[]' /></td>";
					echo "<td>" . $row['manv'] . "</td>";
					echo "<td>" . $row['hoten'] . "</td>";
					echo '<td align="center"><img src="data:image/jpeg;base64,' . base64_encode($row['avatar']) . '" height="50px" width="50px" alt="Ảnh đại diện" /></td>';
					echo "<td>" . $row['namsinh'] . "</td>";
					echo "<td>" . $row['gioitinh'] . "</td>";
					echo "<td>" . $row['donvi'] . "</td>";
					echo "<td>" . $row['chucvu'] . "</td>";
					echo "<td>" . $row['luong'] . "</td>";
					echo "<td align='center'><a href='suanv.php?id=" . $row['manv'] . "'><img src='sua.png' height='32px' /></a></td>";
					echo "</tr>";
				}
			?>
		</table>
	</form>

	<?php
		$conn->close();
	?>
</body>
</html>
