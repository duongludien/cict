<!DOCTYPE html>
<html lang="vi">
<head>
    <meta charset="UTF-8">
    <title>Hiển thị sản phẩm</title>
    <meta http-equiv="Refresh" content="15;url=hienthi.php">

</head>
<body>
    <table cellspacing='50'>
        <tr>
            <?php
                require('connect.php');
                
                $sql = 'SELECT * FROM maytinh ORDER BY RAND() LIMIT 3';
                $result = $conn->query($sql);
                while($row = $result->fetch_assoc()) {
                    echo "<td>";
                    echo '<img src="data:image/jpeg;base64,' . base64_encode($row['hinhanh']) . '" height="160px" width="160px" alt="Hình ảnh" /><br>';
                    echo 'Mô tả: ' . $row['mota'] . '<br>';
                    echo 'Ngày nhập hàng: ' . $row['ngaynhaphang'] . '<br>';
                    echo 'Giá tiền: ' . $row['giatien'] . '<br>';
                    $status = '';
                    if($row['soluong'] > 0)
                        $status = 'Còn hàng';
                    else
                        $status = 'Hết hàng';
                    echo 'Tình trạng: ' . $status . '<br>';
                    echo '</td>';
                }
            ?>
        </tr>
    </table>
</body>
</html>

<?php
    $conn->close();
?>