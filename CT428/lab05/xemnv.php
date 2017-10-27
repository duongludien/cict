
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Thêm nhân viên</title>
	<?php
		include "dbconnect.php";
	?>
	<style>
		body {font-family: sans-serif;}
	</style>
</head>

<body>
	<h2><a href='lab05.html'>Trở lại trang chính</a></h2>
	
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
