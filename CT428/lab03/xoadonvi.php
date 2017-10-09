<?php
	$madv = $_GET['madv'];

	include "dbconnect.php";

	$sql = "DELETE FROM dinh_dien_donvi WHERE madv=" . $madv . ";";
	//echo $sql;
	$conn->query($sql);

	echo "<meta http-equiv='refresh' content='0;url=themdonvi.php' >";
?>
