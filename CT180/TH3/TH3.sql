USE biblio;

-- 1) Các tác phẩm (NT, tựa) của tác giả 'Guy de Maupassant'. --
SELECT NT, tua 
	FROM TACPHAM
	WHERE tacgia = 'Guy de Maupassant';

-- 2) Các độc giả sống ở địa chỉ '32 rue des Alouettes, 75003 Paris' --
SELECT ND, ten + ' ' + ho AS hoten
	FROM DOCGIA
	WHERE dchi = '32 rue des Alouettes, 75003 Paris';
	
-- 3) Tìm tên nhà xuất bản các tác phẩm bao gồm từ 'Fleur' --
SELECT nxb 
	FROM SACH AS s, TACPHAM AS t
	WHERE t.NT = s.NT
		AND t.tua LIKE '%Fleur%';

-- 4) Tìm tên các tác phẩm bắt đầu bằng 'Le' --
SELECT tua
	FROM TACPHAM
	WHERE tua LIKE 'Le%';
	
-- 5) Tìm tên các độc giả có mượn sách trong trong khoảng thời gian từ ngày 15/9/2007 đến 20/09/2007 --
SELECT ten + ' ' + ho AS hoten
	FROM DOCGIA AS d, MUON AS m
	WHERE m.ND = d.ND
		AND m.ngaymuon BETWEEN '2007-09-15' AND '2007-09-20';

-- 6) Số tác phẩm có trong thư viện --
SELECT NT, COUNT(*) AS soquyen INTO #SQ
	FROM SACH
	GROUP BY NT;
SELECT COUNT(*) AS sotacpham
	FROM #SQ;
	
-- 7) Tính Số tác phẩm của mỗi tác giả --
SELECT tacgia, COUNT(NT) AS sotp
	FROM TACPHAM
	GROUP BY tacgia;
	
-- 8) Tính Số tác giả có ít nhất hai tác phẩm --
SELECT tacgia, COUNT(NT) AS sotp INTO #STP
	FROM TACPHAM
	GROUP BY tacgia;
SELECT COUNT(tacgia) AS sotacgia
	FROM #STP AS stp
	WHERE stp.sotp >= 2;

-- 9) Tính Số sách của mỗi tác phẩm --
SELECT NT, COUNT(*) AS sosach
	FROM SACH
	GROUP BY NT;

-- 10) Tìm tên tác phẩm có nhiều sách nhất
SELECT NT, COUNT(*) AS sosach INTO #SOSACH
	FROM SACH
	GROUP BY NT;
SELECT t.tua
	FROM TACPHAM AS t, #SOSACH
	WHERE t.NT = #SOSACH.NT
		AND sosach = (SELECT MAX(sosach) 
							FROM #SOSACH);

-- 11) Tên nhà xuất bản xuất bản nhiều sách nhất --
SELECT nxb, COUNT(*) AS sosach INTO #nhaxb
	FROM SACH
	GROUP BY nxb
SELECT nxb 
	FROM #nhaxb
	WHERE #nhaxb.sosach = (SELECT MAX(sosach) 
								FROM #nhaxb);

-- 12) Nhà xuất bản của tác phẩm tiêu đề 'Germinal' --
SELECT DISTINCT s.nxb
	FROM SACH AS s, TACPHAM AS t
	WHERE t.tua = 'Germinal'
		AND s.NT = t.NT;

-- 13) Tựa của tác phẩm mà có ít nhất hai quyển sách --
SELECT t.tua
	FROM TACPHAM AS t, #SOSACH
	WHERE t.NT = #SOSACH.NT
		AND sosach >= 2

-- 14) Tên độc giả đã mượn tác phẩm 'Poésie' --
SELECT d.ten + ' ' + d.ho AS hoten
	FROM DOCGIA AS d, MUON AS m, SACH AS s, TACPHAM as t
	WHERE t.tua = 'Poésie'
		AND t.NT = s.NT
		AND s.NS = m.NS
		AND m.ND = d.ND;

-- 15) Những độc giả nào đã mượn tác phẩm Les 'Fleurs du mal'
SELECT d.ten + ' ' + d.ho AS hoten
	FROM DOCGIA AS d, MUON AS m, SACH AS s, TACPHAM as t
	WHERE t.tua LIKE '%Fleurs du mal'
		AND t.NT = s.NT
		AND s.NS = m.NS
		AND m.ND = d.ND;

-- 16) Tìm số lần mượn sách của mỗi độc giả theo năm --
SELECT ND, YEAR(ngaymuon) AS nam, COUNT(*) solan
	FROM MUON
	GROUP BY ND, YEAR(ngaymuon)
	ORDER BY ND;

-- 17) Tìm tựa sách, tên độc giả của các độc giả chưa trả sách --
SELECT t.tua, d.ten + ' ' + d.ho AS hoten
	FROM TACPHAM AS t, DOCGIA AS d, MUON AS m, SACH AS s
	WHERE m.NS = s.NS
		AND s.NT = t.NT
		AND m.ND = d.ND
		AND m.ngaytra IS NULL;

-- 18) Tìm các tựa sách, tên độc giả của các độc giả trả sách quá thời hạn cho phép --
SELECT t.tua, d.ten + ' ' + d.ho AS hoten
	FROM TACPHAM AS t, DOCGIA AS d, MUON AS m, SACH AS s
	WHERE m.NS = s.NS
		AND s.NT = t.NT
		AND m.ND = d.ND
		AND m.ngaytra > m.hantra;

-- 19) Tìm các tựa sách, tên độc giả của các độc giả trả sách trước thời hạn --
SELECT t.tua, d.ten + ' ' + d.ho AS hoten
	FROM TACPHAM AS t, DOCGIA AS d, MUON AS m, SACH AS s
	WHERE m.NS = s.NS
		AND s.NT = t.NT
		AND m.ND = d.ND
		AND m.ngaytra < m.hantra;

-- 20) Tìm tựa tác phẩm có nhiều người mượn nhất --
SELECT NS, COUNT(*) AS songuoi INTO #PPB
	FROM MUON 
	GROUP BY NS;
SELECT DISTINCT t.tua
	FROM TACPHAM AS t, SACH AS s, MUON AS m
	WHERE t.NT = s.NT
		AND s.NS = m.NS
		AND s.NS = (SELECT NS 
						FROM #PPB
						WHERE songuoi = (SELECT MAX(songuoi)
											FROM #PPB));

-- 21) Tìm tựa tác phẩm có ít người mượn nhất --

-- 22) Tìm độc giả mượn nhiều tác phẩm nhất --

-- 23) Tìm độc giả mượn ít tác phẩm nhất --

-- 24) Tên độc giả đã mượn tác phẩm của 'Victor Hugo' --
SELECT d.ten + ' ' + d.ho AS hoten
	FROM DOCGIA AS d, MUON AS m
	WHERE m.ND = d.ND
		AND m.NS IN (SELECT NS
						FROM SACH
						WHERE NT IN (SELECT NT
										FROM TACPHAM
										WHERE tacgia = 'Victor Hugo'));

-- 25) Tên độc giả và các tác phẩm đã được mượn năm 2007 --
SELECT d.ten + ' ' + d.ho AS hoten, t.tua
	FROM TACPHAM AS t, DOCGIA AS d, SACH AS s, MUON AS m
	WHERE m.NS = s.NS
		AND s.NT = t.NT
		AND m.ND = d.ND
		AND YEAR(m.ngaymuon) = 2007;

-- 26) Tìm tên tác phẩm có ít nhất một quyển sách không ai mượn --