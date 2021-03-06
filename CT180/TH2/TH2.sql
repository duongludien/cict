USE th1;

-- 1) Loại của máy 'p8' --
SELECT l.tenloai
	FROM may AS m, loai AS l
	WHERE m.idloai = l.idloai
		AND m.idMay = 'p8';

-- 2) Tên của các phần mềm 'UNIX' --
SELECT tenPM
	FROM phanmem
	WHERE idloai = 'UNIX';
	
-- 3) Tên phòng, địa chỉ IP, mã phòng của các loại máy 'UNIX' và 'PCWS' --
SELECT DISTINCT p.tenphong, p.IP, p.MP
	FROM phong AS p, may AS m
	WHERE m.MP = p.MP
		AND m.idloai IN('UNIX', 'PCWS');

-- 4) Tên phòng, địa chỉ IP, mã phòng của các loại máy 'UNIX' và 'PCWS' ở khu vực '130.120.80'. Sắp xếp KQ tăng dần theo mã phòng --
SELECT DISTINCT p.tenphong, p.IP, p.MP
	FROM phong AS p, may AS m
	WHERE m.MP = p.MP
		AND m.idloai IN ('UNIX', 'PCWS')
		AND P.IP = '130.120.80'
	ORDER BY p.MP ASC;
	
-- 5) Số các phần mềm được cài trên máy 'p6' --
SELECT COUNT(idPM) AS sophanmem
	FROM caidat
	WHERE idMay = 'p6';
	
-- 6) Số các máy đã cài phần mềm 'log1' --
SELECT COUNT(idMay) AS somay
	FROM caidat
	WHERE idPM = 'log1';
	
-- 7) Tên và địa chỉ IP đầy đủ (VD: 130.120.80.1) của các loại máy 'TX' --
SELECT tenmay, IP + '.' + CONVERT(char(3), ad) AS IPdaydu
	FROM may
	WHERE idloai = 'TX';
	
-- 8) Tính số phần mềm đã cài đặt trên mỗi máy --
SELECT idMay, COUNT(idPM) AS soPMcaidat
	FROM caidat
	GROUP BY idMay;

-- 9) Tính số máy mỗi phòng --
SELECT MP, somay
	FROM phong;
	
-- 10) Tính số lần cài đặt của mỗi phần mềm trên các máy tính khác nhau --
SELECT idPM, COUNT(idMay) AS solancai
	FROM caidat
	GROUP BY idPM;

-- 11) Giá trung bình của các phần mềm 'UNIX' --
SELECT AVG(gia) AS giaTB
	FROM phanmem
	WHERE idloai = 'UNIX';
	
-- 12) Ngày mua phần mềm gần nhất --
SELECT MAX(ngaymua) AS ngaymua
	FROM phanmem;

-- 13) Số máy có ít nhất 2 phần mềm --
SELECT idMay, COUNT(idPM) AS soPMcaidat INTO #SoPM
	FROM caidat
	GROUP BY idMay;
SELECT idMay 
	FROM #soPM
	WHERE soPMcaidat >= 2;

-- 14) Số máy có ít nhất 2 phần mềm (sử dụng một SELECT con trong mệnh đề FROM) --
SELECT PMTM.idMay
	FROM (SELECT idMay, COUNT(idPM) AS soPM
			FROM caidat
			GROUP BY idMay) AS PMTM
	WHERE PMTM.soPM >= 2;

-- 15) Tìm các loại không thuộc máy --
-- Sử dụng SELECT con --
SELECT DISTINCT tenloai
	FROM loai
	WHERE idloai NOT IN (SELECT DISTINCT idloai FROM may);
-- Sử dụng OUTER JOIN --
SELECT L.tenloai
	FROM loai AS L
	LEFT JOIN may AS M ON L.idloai = M.idloai
	WHERE M.idloai IS NULL;

-- 16) Tìm các loại thuộc cả hai loại máy và phần mềm --
-- Sử dụng SELECT con --
SELECT tenloai
	FROM loai
	WHERE idloai IN (SELECT DISTINCT idloai FROM may)
		AND idloai IN (SELECT DISTINCT idloai FROM phanmem);
-- Sử dụng OUTER JOIN --
SELECT DISTINCT L.tenloai
	FROM loai AS L
	JOIN may AS M ON L.idloai = M.idloai
	JOIN phanmem AS P ON L.idloai = P.idloai
	WHERE L.idloai = M.idloai
		AND L.idloai = P.idloai;

-- 17) Tìm các loại máy không phải loại phần mềm --
-- Sử dụng SELECT con --
SELECT tenloai
	FROM loai
	WHERE idloai IN (SELECT DISTINCT idloai FROM may)
		AND idloai NOT IN (SELECT DISTINCT idloai FROM phanmem);
-- Sử dụng OUTER JOIN --
SELECT DISTINCT L.tenloai
	FROM loai AS L
	LEFT JOIN may AS M ON L.idloai = M.idloai
	LEFT JOIN phanmem AS P ON L.idloai = P.idloai
	WHERE L.idloai = M.idloai
		AND P.idloai IS NULL;

-- 18) Địa chỉ IP đầy đủ của các máy cài phần mềm 'log6' --
-- Sử dụng SELECT lồng nhau --
SELECT IP + '.' + CONVERT(char(3), ad) AS IPdaydu 
	FROM may
	WHERE idMay IN (SELECT idMay FROM caidat WHERE idPM = 'log6');
	
-- 19) Địa chỉ IP đầy đủ của các máy cài phần mềm 'Oracle 8' --
-- Sử dụng SELECT lồng nhau --
SELECT IP + '.' + CONVERT(char(3), ad) AS IPdaydu 
	FROM may
	WHERE idMay IN (SELECT idMay 
						FROM caidat 
						WHERE idPM IN (SELECT idPM 
										FROM phanmem 
										WHERE tenPM = 'Oracle 8'));

	
-- 20) Tên các khu vực có chính xác 3 máy loại 'TX' --
-- Sử dụng SELECT lồng nhau --


-- 21) Tên phòng có ít nhất một máy cài 'Oracle 6' --
SELECT tenphong 
	FROM phong
	WHERE MP IN (SELECT MP
						FROM may
						WHERE idMay IN (SELECT idMay
											FROM caidat
											WHERE idPM IN (SELECT idPM		
															FROM phanmem
															WHERE tenPM = 'Oracle 6')));

-- 22) Tên phần mềm được mua gần nhất --
SELECT tenPM 
	FROM phanmem
	WHERE ngaymua IN (SELECT MAX(ngaymua) AS ngaymua
						FROM phanmem);

-- 23) Địa chỉ IP đầy đủ của các máy cài phần mềm 'log6' --
-- Sử dụng JOIN --
SELECT m.IP + '.' + CONVERT(char(3), m.ad) AS IPdaydu
	FROM caidat AS c JOIN may AS m 
		ON c.idMay = m.idMay
	WHERE c.idPM = 'log6';
	
-- 24) Địa chỉ IP đầy đủ của các máy cài phần mềm 'Oracle 8' --
-- Sử dụng JOIN --
SELECT IP + '.' + CONVERT(char(3), ad) AS IPdaydu 
	FROM may AS m JOIN caidat AS c
		ON M.idMay = C.idMay 
		JOIN phanmem AS p
		ON p.idPM = c.idPM
	WHERE p.tenPM = 'Oracle 8';

-- 25) Tên các khu vực có chính xác 3 máy loại 'TX' --
-- Sử dụng JOIN --

	
-- 26) Tên phòng có ít nhất một máy cài 'Oracle 6' --
-- Sử dụng JOIN --
SELECT tenphong 
	FROM phong AS p JOIN may AS m
		ON p.MP = m.MP
		JOIN caidat AS c
		ON c.idMay = m.idMay
		JOIN phanmem AS pm
		ON pm.idPM = c.idPM
	WHERE pm.tenPM = 'Oracle 6';

-- 27) Tên của máy có ít nhất một phần mềm chung với máy 'p6' --
