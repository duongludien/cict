<?php
	$dbhost = "localhost";
	$dbuser = "user_s6";
	$dbpass = "puser_s6";
	$dbname = "db_s6";

	$conn = new mysqli($dbhost, $dbuser, $dbpass, $dbname);

	if ($conn->connect_error) {
		die("Loi ket noi: " . $conn->connect_error);
	}

	if(!empty($_POST[donvi])) {
		$sql = "INSERT INTO dinh_dien_donvi(donvi) VALUES('" . $_POST['donvi'] . "');";

		if ($conn->query($sql)) {
			echo "Them thanh cong!";
		} else {
			echo "Loi: " . $sql . "" . $conn->error;
		}
	}
	else {
		echo "Loi: Ten don vi rong. Xin kiem tra lai!";
	}

	$sql = "SELECT * FROM dinh_dien_donvi;";
	$result = $conn->query($sql);

	if($result->num_rows > 0) {
		echo "<table border=1>";
		echo "<tr><th>Ma don vi</th><th>Ten don vi</th></tr>";
		while ($row = $result->fetch_assoc()) {
			echo "<tr>";
			echo "<td>". $row['madv'] ."</td>";
			echo "<td>". $row['donvi'] ."</td>";
			echo "</tr>";
		}
		echo "</table>";
	}

	$conn->close();
?>