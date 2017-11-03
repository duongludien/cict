<?php
    $dbhost     = 'localhost';
    $dbuser     = 'user';
    $password   = 'pwd';
    $dbname     = 'db';

    $conn = new mysqli($dbhost, $dbuser, $password, $dbname);
    if($conn->connect_error) {
        die("Lỗi khi kết nối đến MySQL: " . $conn->connect_error);
    }
?>