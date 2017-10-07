<?php
	$dbhost = "localhost";
	$dbuser = "user_s6";
	$dbpass = "puser_s6";
	$dbname = "db_s6";

	$conn = new mysqli($dbhost, $dbuser, $dbpass, $dbname);

	if ($conn->connect_error) {
		die("Loi ket noi: " . $conn->connect_error);
	}

	if(!empty($_POST[chucvu])) {
		$sql = "INSERT INTO dinh_dien_chucvu(chucvu) VALUES('" . $_POST['chucvu'] . "');";

		if ($conn->query($sql)) {
			echo "Them thanh cong!";
		} else {
			echo "Loi: " . $sql . "" . $conn->error;
		}
	}
	else {
		echo "Loi: Ten chuc vu rong. Xin kiem tra lai!";
	}

	$sql = "SELECT * FROM dinh_dien_chucvu;";
	$result = $conn->query($sql);

	if($result->num_rows > 0) {
		echo "<table border=1>";
		echo "<tr><th>Ma chuc vu</th><th>Ten chuc vu</th></tr>";
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