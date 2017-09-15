use pizza;

-- Them khoa chinh
alter table nguoi_an add constraint pk_na_ten primary key(ten);
alter table lui_toi add constraint pk_lt_ten_quan primary key(ten, quanpizza);
alter table an add constraint pk_a_ten_pizza primary key(ten, pizza);
alter table phuc_vu alter column gia numeric(6,3) not null;
alter table phuc_vu add constraint pk_pv_quan_pizza_gia primary key(quanpizza, pizza, gia);

-- ten la khoa ngoai cua bang lui_toi va an
alter table lui_toi add constraint fk_lt_ten foreign key(ten) references nguoi_an(ten);
alter table an add constraint fk_a_ten foreign key(ten) references nguoi_an(ten);

-- Cho biết quán ‘Pizza Hut’ đã phục vụ các bánh pizza nào ?
select distinct pizza 
	from phuc_vu
	where quanPizza = 'Pizza Hut';

-- Danh sách các bánh pizza mà các quán có bán ?
select distinct pizza
	from phuc_vu;

-- Cho biết tên các quán có phục vụ các bánh pizza mà tên gồm chữ ‘m’
select quanpizza 
	from phuc_vu
	where pizza like 'm%';

-- Tìm tên và tuổi của người ăn đã đến quán ‘Dominos’, sắp xếp kết quả giảm dần theo tuổi?
select na.ten, na.tuoi
	from NGUOI_AN as na join LUI_TOI as lt on na.ten = lt.ten
	where quanPizza = 'Dominos'
	order by tuoi desc;

-- Tìm tên quán pizza và số bánh pizza mà mỗi quán phục vụ ?
select quanpizza, count(pizza) as soloaipizza
	from PHUC_VU
	group by quanPizza;

-- Tìm tên những quán pizza phục vụ pizza với giá cao nhất ?
select distinct quanpizza
	from phuc_vu
	where gia = (select max(gia) from PHUC_VU);

-- Tìm tên các quán có phục vụ ít nhất một bánh pizza mà “Ian” thích ăn ?
select distinct quanpizza 
	from PHUC_VU
	where pizza in (select pizza from an where ten = 'Ian');

-- Tìm tên các quán có phục vụ ít nhất một bánh mà “Eli” không thích ?
select pizza into #eli from an where ten = 'Eli';
select pizza into #nkhac from an where ten != 'Eli';
select distinct quanpizza from PHUC_VU
	where pizza in (select pizza
					from #nkhac except
						select pizza from #eli);

-- 