<!DOCTYPE html>
<html>
<head>
	<title>Sửa nhân viên</title>
	<meta charset="utf-8">


	<?php
		include "dbconnect.php";

		$sql = "SELECT nv.manv, nv.hoten, nv.namsinh, nv.gioitinh, dv.madv, dv.donvi, cv.macv, cv.chucvu, nv.luong, nv.avatar " . 
					"FROM dinh_dien_nhanvien AS nv, dinh_dien_donvi AS dv, dinh_dien_chucvu AS cv " . 
					"WHERE nv.madv = dv.madv AND nv.macv = cv.macv AND nv.manv=" . $_GET['id'] . ";";
	
		$result = $conn->query($sql);
		$row = $result->fetch_assoc();

		// Xử lý cập nhật
		if(isset($_POST['submit'])) {		    
		    
		    $insertImage = "";
		    if(!empty($_FILES['avatar']['tmp_name'])) {
		    	$image = addslashes(file_get_contents($_FILES['avatar']['tmp_name'])); //SQL Injection defence
		    	$insertImage .= "avatar=" . "'{$image}'" . ", ";
		    }

			
		    $sql = "UPDATE dinh_dien_nhanvien SET " .
		    	"hoten='" . $_POST['hoten'] . "', " .
		    	"namsinh='" . $_POST['namsinh'] . "', " .
		    	"gioitinh='" . $_POST['gioitinh'] . "', " .
		    	"madv=" . $_POST['madv'] . ", " .
		    	"macv=" . $_POST['macv'] . ", " .
		    	$insertImage .
		    	"luong=" . $_POST['luong'] .
		    	" WHERE manv=" . $row['manv'] . ";";

			// echo $sql;

			if ($conn->query($sql)) {
				echo '<meta http-equiv="REFRESH" content="0;URL=suaxoanv.php" />';
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
	<form action="" method="POST" enctype="multipart/form-data">
		<table>
			<tr>
				<td colspan="2"><h1>Sửa nhân viên</h1></td>
			</tr>
			<tr>
				<td>Họ tên nhân viên:</td>
				<td><input name="hoten" type="text" required value="<?php echo $row['hoten']; ?>"></td>
			</tr>
			<tr>
				<td>Ngày sinh:</td>
				<td><input name="namsinh" type="date" required value="<?php echo $row['namsinh']; ?>"></td>
			</tr>
			<tr>
				<td>Giới tính:</td>
				<td>
					<?php
						$checkedNam = "";
						$checkedNu = "";

						if($row['gioitinh'] === 'Nam')
							$checkedNam = "checked";
						else
							$checkedNu = "checked";
					?>
					<input name="gioitinh" value="Nam" type="radio" <?php echo $checkedNam; ?>> Nam
					<input name="gioitinh" value="Nu" type="radio" <?php echo $checkedNu; ?>> Nu
				</td>
			</tr>
			<tr>
				<td>Đơn vị:</td>
				<td>
					<select name="madv">
						<?php
							$sql = "SELECT madv, donvi FROM dinh_dien_donvi;";
							$result = $conn->query($sql);
							while ($rowdv = $result->fetch_assoc()) {
								$checked = "";
								if($rowdv['madv'] === $row['madv'])
									$checked .= "selected";
								echo "<option value='" . $rowdv['madv'] . "' " . $checked . ">" . $rowdv['donvi'] ."</option>";
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
							while ($rowcv = $result->fetch_assoc()) {
								$checked = "";
								if($rowcv['macv'] === $row['macv'])
									$checked .= "selected";
								echo "<option value='" . $rowcv['macv'] . "' " . $checked .">" . $rowcv['chucvu'] ."</option>";
							}
						?>
					</select>
				</td>
			</tr>
			<tr>
				<td>Ảnh đại diện:</td>
				<td>
					<?php
					echo '<img src="data:image/jpeg;base64,' . base64_encode($row['avatar']) . '" height="50px" width="50px" alt="Chưa đặt" />';
					?>
					<input type="file" name='avatar' />
				</td>
			</tr>
			<tr>
				<td>Lương:</td>
				<td><input name="luong" type="number" min="1001" required value="<?php echo $row['luong']; ?>"></td>
			</tr>
			<tr>
				<td colspan="2" align="center">
					<input name="submit" value="Cập nhật" type="submit">
					<input type="button" name="cancel" value="Hủy bỏ" onclick="window.location='suaxoanv.php'">
				</td>
			</tr>
		</table>
	</form>
</body>
</html>
