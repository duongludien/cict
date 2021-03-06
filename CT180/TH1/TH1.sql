CREATE DATABASE TH1;
USE TH1;

/* Yêu cầu 1: Tạo bảng */

CREATE TABLE Khuvuc (
	IP char(10) PRIMARY KEY,
	tenKhuvuc varchar(10) NOT NULL,
	tang int
);

CREATE TABLE Phong (
	MP char(3) PRIMARY KEY,
	tenphong varchar(8) NOT NULL,
	somay smallint,
	IP char(10),
	CONSTRAINT fk_Phong_IP FOREIGN KEY(IP) REFERENCES Khuvuc(IP)
);

CREATE TABLE Loai (
	idloai varchar(4) PRIMARY KEY,
	tenloai varchar(20) NOT NULL,
);

CREATE TABLE May (
	idMay varchar(3) PRIMARY KEY,
	tenmay  varchar(8) NOT NULL,
	IP char(10),
	ad int CHECK(ad >=0 AND ad <=255),
	idloai varchar(4),
	MP char(3),
	CONSTRAINT fk_May_IP FOREIGN KEY(IP) REFERENCES Khuvuc(IP),
	CONSTRAINT fk_May_idloai FOREIGN KEY(idloai) REFERENCES Loai(idloai),
	CONSTRAINT fk_May_MP FOREIGN KEY(MP) REFERENCES Phong(MP)
);

CREATE TABLE Phanmem (
	idPM char(4) PRIMARY KEY,
	tenPM varchar(15) NOT NULL,
	ngaymua date,
	version varchar(3),
	idloai varchar(4),
	gia bigint CHECK(gia >= 0),
	CONSTRAINT fk_Phanmem_idloai FOREIGN KEY(idloai) REFERENCES Loai(idloai)
);

CREATE TABLE Caidat (
	id int PRIMARY KEY,
	idMay varchar(3),
	idPM char(4),
	ngaycai date DEFAULT getdate(),
	CONSTRAINT fk_Caidat_idMay FOREIGN KEY(idMay) REFERENCES May(idMay),
	CONSTRAINT fk_Caidat_idPM FOREIGN KEY(idPM) REFERENCES Phanmem(idPM)
);

/* Yêu cầu 2: Thêm dữ liệu */

/* Insert data into table Khuvuc */
INSERT INTO Khuvuc
	VALUES('130.120.80', 'Can Tho', 1);
INSERT INTO Khuvuc
	VALUES('130.120.81', 'Can Tho', 0);
INSERT INTO Khuvuc
	VALUES('130.120.82', 'Can Tho', 2);

/* Insert data into table Phong */
INSERT INTO Phong
	VALUES('a01', 'Phong 1', 3, '130.120.80');
INSERT INTO Phong
	VALUES('a02', 'Phong 2', 2, '130.120.80');
INSERT INTO Phong
	VALUES('a03', 'Phong 3', 2, '130.120.80');
INSERT INTO Phong
	VALUES('a11', 'Phong 11', 2, '130.120.81');
INSERT INTO Phong
	VALUES('a12', 'Phong 12', 2, '130.120.81');
INSERT INTO Phong
	VALUES('a21', 'Phong 21', 2, '130.120.82');
INSERT INTO Phong
	VALUES('a22', 'Phong 22', 2, '130.120.82');
INSERT INTO Phong
	VALUES('a23', 'Phong 23', 2, '130.120.82');
	
/* Insert data into table Loai */
INSERT INTO Loai
	VALUES('TX', 'Terminal X-Window');
INSERT INTO Loai
	VALUES('UNIX', 'System Unix');
INSERT INTO Loai
	VALUES('PCNT', 'PC Windows NT');
INSERT INTO Loai
	VALUES('PCWS', 'PC Windows');
INSERT INTO Loai
	VALUES('NC', 'Network Computer');
	
/* Insert data into table May */
INSERT INTO May
	VALUES('m1', 'Asus 1', '130.120.80', 01, 'TX', 'a01');
INSERT INTO May
	VALUES('m2', 'Asus 2', '130.120.80', 01, 'UNIX', 'a01');
INSERT INTO May
	VALUES('m3', 'Asus 3', '130.120.80', 01, 'TX', 'a01');
INSERT INTO May
	VALUES('m4', 'Asus 4', '130.120.80', 01, 'PCWS', 'a02');
INSERT INTO May
	VALUES('m5', 'Asus 5', '130.120.80', 01, 'PCWS', 'a02');
INSERT INTO May
	VALUES('m6', 'Asus 6', '130.120.80', 01, 'UNIX', 'a03');
INSERT INTO May
	VALUES('m7', 'Asus 7', '130.120.80', 01, 'TX', 'a03');
INSERT INTO May
	VALUES('m8', 'Asus 8', '130.120.81', 01, 'UNIX', 'a21');
INSERT INTO May
	VALUES('m9', 'Asus 9', '130.120.81', 01, 'TX', 'a21');
INSERT INTO May
	VALUES('m10', 'Asus 10', '130.120.81', 01, 'UNIX', 'a22');
INSERT INTO May
	VALUES('m11', 'Asus 11', '130.120.82', 01, 'PCWS', 'a22');
INSERT INTO May
	VALUES('m12', 'Asus 12', '130.120.80', 01, 'PCWS', 'a22');

/* Insert data into table Phanmem */
INSERT INTO Phanmem
	VALUES('log1', 'Oracle 6', '19950513', '6.2', 'UNIX', 3000);
INSERT INTO Phanmem
	VALUES('log2', 'Oracle 8', '19990915', '8', 'UNIX', 5600);
INSERT INTO Phanmem
	VALUES('log3', 'SQL Server', '19980412', '7', 'PCNT', 2700);
INSERT INTO Phanmem
	VALUES('log4', 'Front Page', '19970603', '5', 'PCWS', 500);
INSERT INTO Phanmem
	VALUES('log5', 'Winrar', '19970513', '5', 'PCWS', 750);
INSERT INTO Phanmem
	VALUES('log6', 'MySQL', '', '2.0', 'UNIX', 500);
INSERT INTO Phanmem
	VALUES('log7', 'T. T. S.', '20020412', '2', 'PCNT', 810);
INSERT INTO Phanmem
	VALUES('log8', 'Dreamweaver', '20030921', '2.0', 'PCWS', 1400);

/* Insert data into table Caidat */
INSERT INTO Caidat(idMay, idPM, id, ngaycai)
	VALUES('m2', 'log1', 1, '20030515');
INSERT INTO Caidat(idMay, idPM, id, ngaycai)
	VALUES('m2', 'log2', 2, '20030917');
INSERT INTO Caidat(idMay, idPM, id, ngaycai)
	VALUES('m4', 'log5', 3, null);
INSERT INTO Caidat(idMay, idPM, id, ngaycai)
	VALUES('m6', 'log6', 4, '20030520');
INSERT INTO Caidat(idMay, idPM, id, ngaycai)
	VALUES('m6', 'log1', 5, '20030520');
INSERT INTO Caidat(idMay, idPM, id, ngaycai)
	VALUES('m9', 'log2', 6, '20030519');
INSERT INTO Caidat(idMay, idPM, id, ngaycai)
	VALUES('m9', 'log6', 7, '20030520');
INSERT INTO Caidat(idMay, idPM, id, ngaycai)
	VALUES('m11', 'log3', 8, '20030420');
INSERT INTO Caidat(idMay, idPM, id, ngaycai)
	VALUES('m12', 'log4', 9, '20030420');
INSERT INTO Caidat(idMay, idPM, id, ngaycai)
	VALUES('m11', 'log7', 10, '20030420');
INSERT INTO Caidat(idMay, idPM, id, ngaycai)
	VALUES('m7', 'log7', 11, '20020401');

/* Yêu cầu 3: Sửa đổi dữ liệu - chỉnh sửa tầng cho đúng với IP */

SELECT * FROM Khuvuc;
UPDATE Khuvuc SET tang = 0
	WHERE IP = '130.120.80';
UPDATE Khuvuc SET tang = 1
	WHERE IP = '130.120.81';
UPDATE Khuvuc SET tang = 2
	WHERE IP = '130.120.82';
SELECT * FROM Khuvuc;

/* Yêu cầu 4: Giảm giá 10% cho phần mềm kiểu 'PCNT' */

SELECT * FROM Phanmem;
UPDATE Phanmem SET gia = 0.9 * gia
	WHERE idloai = 'PCNT';
SELECT * FROM Phanmem;

/* Yêu cầu 5: Thêm cột và cập nhật giá trị cột vừa thêm */

/* Add columns nbLog and nbInstall */
ALTER TABLE May ADD nbLog smallint;
SELECT * FROM May;
ALTER TABLE Phanmem ADD nbInstall smallint;
SELECT * FROM Phanmem;

/* Update data for nbLog */
SELECT * FROM May;
UPDATE May SET nbLog = 0
	WHERE idMay IN ('m1', 'm3', 'm5', 'm9', 'm10');
UPDATE May SET nbLog = 1
	WHERE idMay IN ('m4', 'm7', 'm12');
UPDATE May SET nbLog = 2
	WHERE idMay IN ('m2', 'm6', 'm8', 'm11');
SELECT * FROM May;

/*  Update data for nbInstall */
SELECT * FROM Phanmem;
UPDATE Phanmem SET nbInstall = 1
	WHERE idPM IN ('log3', 'log4', 'log5');
UPDATE Phanmem SET nbInstall = 2
	WHERE idPM IN ('log1', 'log2', 'log6', 'log7');
SELECT * FROM Phanmem;

/* Yêu cầu 6: Tạo bảng PhanmemUNIX */

CREATE TABLE PhanmemUNIX (
	idPM char(4),
	tenPM varchar(15),
	ngaymua date,
	version varchar(3)
);

/* Yêu cầu 7: Thêm khoá chính idPM cho PhanmemUNIX vừa tạo */

ALTER TABLE PhanmemUNIX ALTER COLUMN idPM CHAR(4) NOT NULL;
ALTER TABLE PhanmemUNIX ADD PRIMARY KEY(idPM);

/* Yêu cầu 8: Thêm cột giá */
SELECT * FROM PhanmemUNIX;
ALTER TABLE PhanmemUNIX ADD gia bigint;
SELECT * FROM PhanmemUNIX;

/* Yêu cầu 9: Thay đổi kiểu dữ liệu của version thành varchar(15) */

ALTER TABLE PhanmemUNIX ALTER COLUMN version varchar(15);

/* Yêu cầu 10: Thêm ràng buộc duy nhất cho tenPM */

ALTER TABLE PhanmemUNIX ADD UNIQUE(tenPM);

/* Yêu cầu 11: Thêm dữ liệu cho bảng PhanmemUNIX lấy từ Phanmem */

INSERT INTO PhanmemUNIX(idPM, tenPM, ngaymua, version, gia)
	SELECT idPM, tenPM, ngaymua, version, gia 
		FROM Phanmem;
SELECT * FROM PhanmemUNIX;

/* Yêu cầu 12: Xoá cột version khỏi PhanmemUNIX */

ALTER TABLE PhanmemUNIX	DROP COLUMN version;
SELECT * FROM PhanmemUNIX;

/* Yêu cầu 13 */