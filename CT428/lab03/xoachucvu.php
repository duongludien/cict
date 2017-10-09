<?php
	$macv = $_GET['macv'];

	include "dbconnect.php";

	$sql = "DELETE FROM dinh_dien_chucvu WHERE macv=" . $macv . ";";
	//echo $sql;
	$conn->query($sql);

	echo "<meta http-equiv='refresh' content='0;url=themchucvu.php' >";
?>
