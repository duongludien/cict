<!DOCTYPE html>
<html lang="vi">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Hiển thị sản phẩm</title>
    <meta http-equiv="Refresh" content="5;url=hienthi.php">

    <script>
        function mua(maso, soluong) {
            if(soluong == 0)
                alert("Hết hàng rồi má!");
            else
                window.location = 'xulymua.php?maso=' + maso;
        }
    </script>
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
                    echo '<input type="button" value="Mua" onclick="mua('. $row['maso'] . ', ' . $row['soluong'] .');">';
                    echo '</td>';
                }
            ?>
        </tr>
    </table>
</body>
</html>