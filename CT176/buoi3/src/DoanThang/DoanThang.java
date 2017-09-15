package DoanThang;

public class DoanThang {
	private Diem d1, d2;
	
	DoanThang() {
		d1 = new Diem();
		d2 = new Diem();
	}
	
	DoanThang(Diem D1, Diem D2) {
		d1 = new Diem(D1.giaTriX(), D1.giaTriY());
		d2 = new Diem(D2.giaTriX(), D2.giaTriY());
	}
	
	DoanThang(int ax, int ay, int bx, int by) {
		d1 = new Diem(ax, ay);
		d2 = new Diem(bx, by);
	}
	
	public void nhapDoanThang() {
		System.out.print("\nNhap vao diem dau:");
		d1.nhapDiem();
		System.out.print("\nNhap vao diem cuoi:");
		d2.nhapDiem();
	}
	
	public void hienThi() {
		System.out.print("\nDiem dau: ");
		d1.hienThi();
		System.out.print("\nDiem cuoi: ");
		d2.hienThi();
	}
	
	public DoanThang tinhTien(int dx, int dy) {
		DoanThang TinhTien = new DoanThang();
		
		TinhTien.d1.doiDiem(dx, dy);
		TinhTien.d2.doiDiem(dx, dy);
		
		return TinhTien;
	}
	
	public double tinhDoDai() {
		return Math.sqrt(Math.pow(d1.giaTriX() - d2.giaTriX(), 2) + Math.pow(d1.giaTriY() - d2.giaTriY(), 2));
	}
	
	public double tinhGoc() {
		return Math.acos(Math.abs(this.d2.giaTriX() - this.d1.giaTriX()) / this.tinhDoDai());
	}
}
