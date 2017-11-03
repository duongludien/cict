<!DOCTYPE html>
<html lang="vi">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Nhập sản phẩm</title>

    <?php
        require('connect.php');

        if(isset($_POST['submit'])) {
            $image = addslashes(file_get_contents($_FILES['hinhanh']['tmp_name']));
            $sql = "INSERT INTO maytinh VALUES('" . 
                $_POST['maso'] . "', '" . 
                $_POST['mota'] . "', '" . 
                "{$image}" . "', '" . 
                $_POST['ngaynhaphang'] . "', " . 
                $_POST['giatien'] . ", " . 
                $_POST['soluong'] . ");";

            if ($conn->query($sql)) {
                echo '<meta http-equiv="REFRESH" content="0;URL=themsp.php" />';
            } else {
                echo "Lỗi: " . $conn->error;
            }
        }
    ?>
</head>
<body>
    <form action="" method="POST" enctype="multipart/form-data">
        Mã số:
        <input type="text" name="maso">
        <br>
        Mô tả:
        <input type="text" name="mota">
        <br>
        Hình ảnh:
        <input type="file" name="hinhanh">
        <br>
        Ngày nhập hàng:
        <input type="date" name="ngaynhaphang">
        <br>
        Giá tiền:
        <input type="number" name="giatien">
        <br>
        Số lượng:
        <input type="number" name="soluong">
        <br>
        <input type="submit" name="submit" value="Thêm">
    </form>
</body>
</html>

<?php
    $conn->close();
?>