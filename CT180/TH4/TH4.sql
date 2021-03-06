USE CT;

-- 1. Tìm sự thông thương giữa các bảng trong CSDL --
-- 2. Mở các bảng dữ liệu để xem kiểu dữ liệu của từng trường và quan sát dữ liệu của từng bảng --
-- 3. Hãy cho biết thông tin về các kiến trúc sư có họ là Lê và sinh năm 1956 --
SELECT * 
	FROM KTRUCSU
	WHERE HOTEN_KTS LIKE 'le%'
		AND NAMS_KTS = 1956;

-- 4. Hãy cho biết tên các công trình bắt đầu trong khoảng 1/9/1994 đến 20/10/1994 --
SELECT TEN_CTR
	FROM CGTRINH
	WHERE NGAY_BD BETWEEN'19940901' AND '19941020';
	
-- 5. Hãy cho biết tên và địa chỉ các công trình do chủ thầu công ty xây dựng số 6 thi công --
-- (chú ý: xem dữ liệu để lấy đúng tên công ty xây dựng số 6) --
SELECT TEN_CTR, DIACHI_CTR
	FROM CGTRINH
	WHERE TEN_THAU = 'cty xd so 6';
	
-- 6. Tìm tên và địa chỉ liên lạc của các chủ thầu thi công công trình ở Cần Thơ do kiến trúc sư Lê Kim Dung thiết kế --
SELECT DISTINCT ct.TEN_THAU, ct.DCHI_THAU
	FROM CHUTHAU AS ct, THIETKE AS tk, CGTRINH AS ctr
	WHERE tk.HOTEN_KTS = 'le kim dung'
		AND tk.STT_CTR = ctr.STT_CTR
		AND ctr.TINH_THANH = 'can tho'
		AND ctr.TEN_THAU = ct.TEN_THAU;
		
-- 7. Hãy cho biết nơi tốt nghiệp của các kiến trúc sư đã thiết kế công trình Khách sạn quốc tế ở Cần Thơ --
SELECT kts.NOI_TN
	FROM KTRUCSU AS kts, CGTRINH AS ctr, THIETKE AS tk
	WHERE ctr.TEN_CTR = 'khach san quoc te'
		AND ctr.TINH_THANH = 'can tho'
		AND ctr.STT_CTR = tk.STT_CTR
		AND tk.HOTEN_KTS = kts.HOTEN_KTS;
		
-- 8. Cho biết họ tên, năm sinh và năm vào nghề của các công nhân có chuyên môn hàn --
-- hoặc điện đã tham gia các công trình mà chủ thầu Lê Văn Sơn đã trúng thầu --
SELECT CN.HOTEN_CN, CN.NAMS_CN, CN.NAM_VAO_N
	FROM CONGNHAN AS CN, THAMGIA AS TG, CGTRINH AS CTR
	WHERE CN.CH_MON IN ('han', 'dien')
		AND CN.HOTEN_CN = TG.HOTEN_CN
		AND TG.STT_CTR = CTR.STT_CTR
		AND CTR.TEN_THAU = 'le van son';

-- 9. Những công nhân đã bắt đầu tham gia công trình Khách sạn Quốc tế ở Cần Thơ --
-- trong giai đoạn từ 15/12/1994 đến 31/12/1994 --
SELECT CN.HOTEN_CN
	FROM CONGNHAN AS CN JOIN THAMGIA AS TG ON CN.HOTEN_CN = TG.HOTEN_CN
	JOIN CGTRINH AS CTR ON TG.STT_CTR = CTR.STT_CTR
	WHERE CTR.TEN_CTR = 'khach san quoc te'
		AND CTR.TINH_THANH = 'can tho'
		AND TG.NGAY_TGIA BETWEEN '19941215' AND '19941231';

-- 10. Cho biết tên và địa chỉ của các công trình mà công nhân Nguyễn Hồng Vân đang tham gia
-- vào ngày 18/12/1994
SELECT CTR.TEN_CTR, CTR.DIACHI_CTR
	FROM CGTRINH AS CTR JOIN THAMGIA AS TG ON CTR.STT_CTR = TG.STT_CTR
	WHERE TG.HOTEN_CN = 'nguyen hong van'
		AND DATEADD(DAY, TG.SO_NGAY, TG.NGAY_TGIA) > '19941218';

-- 11. Cho biết họ tên và năm sinh của các kiến trúc sư đã tốt nghiệp ở TP HCM 
-- và đã thiết kế ít nhất một công trình có kinh phí đầu tư trên 400 triệu đồng
SELECT DISTINCT KTS.HOTEN_KTS, KTS.NAMS_KTS
	FROM KTRUCSU AS KTS JOIN THIETKE AS TK 
		ON KTS.HOTEN_KTS = TK.HOTEN_KTS
		JOIN CGTRINH AS CTR 
		ON TK.STT_CTR = CTR.STT_CTR 
	WHERE CTR.KINH_PHI >= 400
		AND KTS.NOI_TN = 'tp hcm';

-- 12. Cho biết họ tên kiến trúc sư vừa thiết kế các công trình do Phòng dịch vụ Sở Xây dựng thi công
-- vừa thiết kế các công trình do chủ thầu Lê Văn Sơn thi công --
SELECT HOTEN_KTS
	FROM THIETKE AS TK JOIN CGTRINH AS CTR ON TK.STT_CTR = CTR.STT_CTR
	WHERE CTR.TEN_THAU = 'phong dich vu so xd'
INTERSECT
SELECT HOTEN_KTS
	FROM THIETKE AS TK JOIN CGTRINH AS CTR ON TK.STT_CTR = CTR.STT_CTR
	WHERE CTR.TEN_THAU = 'le van son';

-- 13. Cho biết tên công trình có kinh phí cao nhất
SELECT TEN_CTR
	FROM CGTRINH
	WHERE KINH_PHI = (SELECT MAX(KINH_PHI) FROM CGTRINH);
	
-- 14. Cho biết họ tên kiến trúc sư trẻ tuổi nhất --
SELECT HOTEN_KTS
	FROM KTRUCSU
	WHERE NAMS_KTS = (SELECT MAX(NAMS_KTS) FROM KTRUCSU);
	
-- 15. Cho biết họ tên các công nhân tham gia các công trình ở Cần Thơ nhưng không tham gia các công trình ở Vĩnh Long --
SELECT CN.HOTEN_CN
	FROM CONGNHAN AS CN JOIN THAMGIA AS TG ON CN.HOTEN_CN = TG.HOTEN_CN
	JOIN CGTRINH AS CTR ON TG.STT_CTR = CTR.STT_CTR
	WHERE CTR.TINH_THANH = 'can tho'
EXCEPT
SELECT CN.HOTEN_CN
	FROM CONGNHAN AS CN JOIN THAMGIA AS TG ON CN.HOTEN_CN = TG.HOTEN_CN
	JOIN CGTRINH AS CTR ON TG.STT_CTR = CTR.STT_CTR
	WHERE CTR.TINH_THANH = 'vinh long';

-- 16. Cho biết tên của các chủ thầu đã thi công các công trình có kinh phí lớn hơn tất cả các công trình do
-- chủ thầu Phòng dịch vụ sở xây dựng thi công
SELECT MAX(KINH_PHI)
	FROM CGTRINH
	WHERE TEN_THAU = 'phong dich vu so xd';
SELECT TEN_THAU
	FROM CGTRINH
	WHERE KINH_PHI > (SELECT MAX(KINH_PHI)
						FROM CGTRINH
						WHERE TEN_THAU = 'phong dich vu so xd');

-- 17. Cho biết họ tên các kiến trúc sư có thù lao thiết kế dưới giá trị trung bình thù lao thiết kế --
SELECT DISTINCT HOTEN_KTS
	FROM THIETKE
	WHERE THU_LAO < (SELECT AVG(THU_LAO) FROM THIETKE);

-- 18. Tìm tên và địa chỉ của những chủ thầu đã trúng thầu công trình có chi phí thấp nhất --
SELECT CT.TEN_THAU, CT.DCHI_THAU
	FROM CHUTHAU AS CT
	JOIN CGTRINH AS CTR ON CT.TEN_THAU = CTR.TEN_THAU
	WHERE CTR.KINH_PHI = (SELECT MIN(KINH_PHI) FROM CGTRINH);

-- 19. Tìm họ tên và chuyên môn của các công nhân tham gia các công trình do kiến trúc sư Lê Thanh Tùng thiết kế --
SELECT CN.HOTEN_CN, CN.CH_MON
	FROM CONGNHAN AS CN
		JOIN THAMGIA AS TG ON CN.HOTEN_CN = TG.HOTEN_CN
		JOIN THIETKE AS TK ON TG.STT_CTR = TK.STT_CTR
	WHERE TK.HOTEN_KTS = 'le thanh tung';

-- 20. Tìm các cặp tên chủ thầu có trúng thầu các công trình tại cùng một thành phố
SELECT DISTINCT A.TEN_THAU, B.TEN_THAU
	FROM CGTRINH AS A JOIN CGTRINH AS B
		ON A.TINH_THANH = B.TINH_THANH
	WHERE A.TEN_THAU < B.TEN_THAU;		--Sử dụng WHERE để cho tên thầu 2 bên khác nhau, sử dụng < để cho không lặp lại cặp (x;y) và (y,x)

-- 21. Tìm các cặp tên của các công nhân có làm việc chung với nhau trong ít nhất là 2 công trình
SELECT DISTINCT A.HOTEN_CN, B.HOTEN_CN
	FROM THAMGIA AS A JOIN THAMGIA AS B
		ON A.STT_CTR = B.STT_CTR
	WHERE A.HOTEN_CN < b.HOTEN_CN
	GROUP BY A.HOTEN_CN, B.HOTEN_CN HAVING COUNT(*) >= 2;

-- 22. Tổng kinh phí của tất cả các công trình theo từng chủ thầu --
SELECT CTR.TEN_THAU, SUM(CTR.KINH_PHI) AS TONG_KINH_PHI
	FROM CGTRINH AS CTR
	GROUP BY CTR.TEN_THAU;

-- 23. Cho biết họ tên các kiến trúc sư có tổng thù lao thiết kế các công trình lớn hơn 25 triệu
SELECT TTL.HOTEN_KTS INTO #TTL
	FROM (SELECT TK.HOTEN_KTS, SUM(TK.THU_LAO) AS TONG_THU_LAO
			FROM THIETKE AS TK
			GROUP BY TK.HOTEN_KTS) AS TTL
	WHERE TTL.TONG_THU_LAO > 25;

-- 24. Cho biết số lượng các kiến trúc sư có tổng thù lao > 25 triệu
SELECT COUNT(*) AS SOLUONG FROM #TTL;

-- 25. Tính số công trình mà mỗi kiến trúc sư đã thiết kế
SELECT HOTEN_KTS, COUNT(STT_CTR) AS SOLUONG_CTR
	FROM THIETKE
	GROUP BY HOTEN_KTS;

-- 26. Tính tổng số công nhân đã tham gia mỗi công trình --
SELECT STT_CTR, COUNT(*) AS SO_CN INTO #SOCN
	FROM THAMGIA
	GROUP BY STT_CTR;

-- 27. Tìm tên và địa chỉ công trình có tổng số công nhân tham gia nhiều nhất
SELECT CTR.TEN_CTR, DIACHI_CTR
	FROM CGTRINH AS CTR, #SOCN
	WHERE CTR.STT_CTR = #SOCN.STT_CTR 
		AND #SOCN.SO_CN = (SELECT MAX(SO_CN) FROM #SOCN);

-- 28. Cho biết tên các thành phố và kinh phí trung bình cho mỗi công trình của từng thành phố tương ứng
SELECT TINH_THANH, AVG(KINH_PHI) AS KINHPHI_TB
	FROM CGTRINH
	GROUP BY TINH_THANH;

-- 29. Cho biết họ tên các công nhân có tồng số ngày tham gia vào các công trình lớn hơn tồng số ngày
-- tham gia của công nhân Nguyễn Hồng Vân
SELECT HOTEN_CN, SUM(SO_NGAY) AS TONG_NGAY INTO #TONGNGAY
	FROM THAMGIA
	GROUP BY HOTEN_CN;
SELECT HOTEN_CN
	FROM #TONGNGAY
	WHERE TONG_NGAY > (SELECT TONG_NGAY FROM #TONGNGAY WHERE HOTEN_CN = 'nguyen hong van');

-- 30. Cho biết họ tên công nhân có tham gia tất cả công trình
SELECT HOTEN_CN, COUNT(STT_CTR) AS SO_CTR INTO #SO_CTR
	FROM THAMGIA
	GROUP BY HOTEN_CN;
SELECT HOTEN_CN
	FROM #SO_CTR
	WHERE SO_CTR =	--(SELECT MAX(SO_CTR) FROM #SO_CTR);
					(SELECT COUNT(*) FROM CGTRINH);