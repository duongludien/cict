<?php
    $dbhost = 'localhost';
    $dbuser = 'user_s6';
    $dbpass = 'puser_s6';
    $dbname = 'db_s6';
    
    $conn = new mysqli($dbhost, $dbuser, $dbpass, $dbname);
    
    if($conn->connect_error) {
        die("Lỗi khi kết nối đến CSDL: " . $conn->connect_error);
    }
?>