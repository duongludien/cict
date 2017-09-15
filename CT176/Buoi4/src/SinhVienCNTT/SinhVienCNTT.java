package SinhVienCNTT;

import java.util.Scanner;

public class SinhVienCNTT extends SinhVien {
	private Scanner s;
	private String taiKhoan, matKhau, email;
	
	public void doiMatKhau(String matKhau) {
		this.matKhau = matKhau;
	}

	public String getEmail() {
		return email;
	}

	SinhVienCNTT() {
		super();
		taiKhoan = matKhau = email = null;
	}
	
	SinhVienCNTT(String ms, String ht, int d, int m, int y, int shp, String []thp, String []dhp, String taiKhoan, String matKhau, String email) {
		super(ms, ht, d, m, y, shp, thp, dhp);
		this.taiKhoan = taiKhoan;
		this.matKhau = matKhau;
		this.email = email;
	}
	
	@Override
	public void nhapThongTin() {
		s = new Scanner(System.in);
		
		super.nhapThongTin();
		
		System.out.print("\nNhap vao tai khoan: ");
		taiKhoan = s.nextLine();
		System.out.print("\nNhap vao mat khau: ");
		matKhau = s.nextLine();
		System.out.print("\nNhap vao email: ");
		email = s.nextLine();
	}
	
	@Override
	public String toString() {
		String result = "";
		
		result += super.toString();
		result += "\n+ Tai khoan: " + taiKhoan;
		result += "\n+ Mat khau: " + matKhau;
		result += "\n+ Email: " + email;
		
		return result;
	}
	/*
	public String xuatKetQuaHocTap() {
		String result = "";
		
		for(int i=0; i<this.getSoHocPhan(); i++) {
			result += "\n+ " + this.getTenHocPhan().get(i) + ": " + this.getDiemHocPhan().get(i);
		}
		
		return result;
	}
	*/
}
