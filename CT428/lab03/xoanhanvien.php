<?php
	$manv = $_GET['manv'];

	include "dbconnect.php";

	$sql = "DELETE FROM dinh_dien_nhanvien WHERE manv=" . $manv . ";";
	//echo $sql;
	$conn->query($sql);

	echo "<meta http-equiv='refresh' content='0;url=themnhanvien.php' >";
?>
