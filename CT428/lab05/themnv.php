
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Thêm nhân viên</title>
	<?php
		include "dbconnect.php";

		if(isset($_POST['submit'])) {
		    $image = addslashes(file_get_contents($_FILES['avatar']['tmp_name'])); //SQL Injection defence
		    
			$sql = "INSERT INTO dinh_dien_nhanvien(hoten, namsinh, gioitinh, madv, macv, luong, avatar) VALUES(" . 
				"'" . $_POST['hoten'] . "', " .
				"'" . $_POST['namsinh'] . "', " .
				"'" . $_POST['gioitinh'] . "', " .
				$_POST['madv'] . ", " .
				$_POST['macv'] . ", " .
				$_POST['luong'] . ", " .
				"'{$image}'" .
				");";

			//echo $sql;

			if ($conn->query($sql)) {
				echo "Them thanh cong!";
				echo '<meta http-equiv="REFRESH" content="0;URL=themnv.php" />';
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
	<h2><a href='lab05.html'>Trở lại trang chính</a></h2>
	<hr />

	<form action="" method="POST" enctype="multipart/form-data">
		<table>
			<tr>
				<td colspan="2"><h1>Thêm nhân viên</h1></td>
			</tr>
			<tr>
				<td>Họ tên nhân viên:</td>
				<td><input name="hoten" type="text" required></td>
			</tr>
			<tr>
				<td>Ngày sinh:</td>
				<td><input name="namsinh" type="date" required></td>
			</tr>
			<tr>
				<td>Giới tính:</td>
				<td>
					<input name="gioitinh" value="Nam" checked type="radio"> Nam
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
				<td>Ảnh đại diện:</td>
				<td>
					<input type="file" name='avatar' />
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
		$sql = "SELECT nv.manv, nv.hoten, nv.namsinh, nv.gioitinh, dv.donvi, cv.chucvu, nv.luong, nv.avatar " . 
					"FROM dinh_dien_nhanvien AS nv, dinh_dien_donvi AS dv, dinh_dien_chucvu AS cv " . 
					"WHERE nv.madv = dv.madv AND nv.macv = cv.macv;";
	
		$result = $conn->query($sql);
		
		if($result->num_rows > 0) {
			echo "<table border='1' cellspacing='0' cellpadding='10px'>";
			while ($row = $result->fetch_assoc()) {
				echo "<tr>";
				
				// Image cell
				echo '<td><img src="data:image/jpeg;base64,' . base64_encode($row['avatar']) . '" height="160px" width="160px" alt="Ảnh đại diện" /></td>';
    			
				// Information cell
				echo "<td>";
    			
    			// Infomation table
    		    echo "<table>";
    		    
    		    // Row hoten
    		    echo "<tr>";
    		    echo "<td><strong>Họ tên:</strong></td>";
    		    echo "<td>" . $row['hoten'] . "</td>";
    		    echo "</tr>";
    		    
    		    // Row chucvu
    		    echo "<tr>";
    		    echo "<td><strong>Chức vụ:</strong></td>";
    		    echo "<td>" . $row['chucvu'] . "</td>";
    		    echo "</tr>";
    		    
    		    // Row donvi
    		    echo "<tr>";
    		    echo "<td><strong>Đơn vị:</strong></td>";
    		    echo "<td>" . $row['donvi'] . "</td>";
    		    echo "</tr>";
    		    
    		    // Row namsinh
    		    echo "<tr>";
    		    echo "<td><strong>Ngày sinh:</strong></td>";
    		    echo "<td>" . $row['namsinh'] . "</td>";
    		    echo "</tr>";
    		    
    		    // Row gioitinh
    		    echo "<tr>";
    		    echo "<td><strong>Giới tính:</strong></td>";
    		    echo "<td>" . $row['gioitinh'] . "</td>";
    		    echo "</tr>";
    		    
    		    // Row luong
    		    echo "<tr>";
    		    echo "<td><strong>Lương:</strong></td>";
    		    echo "<td>$" . $row['luong'] . "</td>";
    		    echo "</tr>";
    		    
    		    echo "</table>";
    			echo "</td>";
				echo "</tr>";
			}
			echo "</table>";

		    
		}
	?>
</body>
</html>

<?php
	$conn->close();
?>
