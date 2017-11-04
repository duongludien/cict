<!DOCTYPE html>
<html lang="vi">
<head>
    <meta charset="UTF-8">
    <title>Mua máy tính</title>

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
        
        <?php
            require('connect.php');
            
            $sql = 'SELECT * FROM maytinh';
            $result = $conn->query($sql);
            while($row = $result->fetch_assoc()) {
                echo "<tr>";
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
                echo "</tr>";
            }
        ?>
        
    </table>
</body>
</html>

<?php
	$conn->close();
?>
