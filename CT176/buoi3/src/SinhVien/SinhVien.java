package SinhVien;

import java.util.ArrayList;
import java.util.Scanner;

public class SinhVien {
	private String MSSV;
	private String hoTen;
	private Date ngaySinh;
	private int soHocPhan;
	private ArrayList<String> tenHocPhan;
	private ArrayList<String> diemHocPhan;
	private Scanner s;
	
	SinhVien() {
		MSSV = null;
		hoTen = null;
		ngaySinh = new Date();
		soHocPhan = 0;
		tenHocPhan = new ArrayList<String>();
		diemHocPhan = new ArrayList<String>();
	}
	
	SinhVien(String MS, String Ten, Date NS, int SHP, String[] tenHP, String[] diemHP) {
		MSSV = MS;
		hoTen = Ten;
		ngaySinh = new Date(NS.getNgay(), NS.getThang(), NS.getNam());
		soHocPhan = SHP;
		tenHocPhan = new ArrayList<String>();
		diemHocPhan = new ArrayList<String>();
		for(int i=0; i<SHP; i++) {
			tenHocPhan.add(tenHP[i]);
			diemHocPhan.add(diemHP[i]);
		}
	}
	
	public String getHoTen() {
		return hoTen;
	}

	public void nhapThongTin() {
		s = new Scanner(System.in);
		System.out.print("Nhap vao MSSV: ");
		MSSV = s.nextLine();
		System.out.print("Nhap vao ho ten: ");
		hoTen = s.nextLine();
		System.out.println("Nhap vao ngay sinh:");
		ngaySinh.nhapNgay();
	}
	
	public void nhapDiem() {
		System.out.print("Nhap vao so hoc phan: ");
		soHocPhan = s.nextInt();
		String tmp1, tmp2;
		s.nextLine();
		for(int i=0; i<soHocPhan; i++) {
			System.out.print("Nhap vao ten hoc phan thu " + (i+1) + ": ");
			tmp1 = s.nextLine();
			System.out.print("Nhap vao diem hoc phan thu " + (i+1) + ": ");
			tmp2 = s.nextLine();
			tenHocPhan.add(tmp1);
			diemHocPhan.add(tmp2);
		}
	}
	
	public String toString() {
		String result = "";
		result += "+ MSSV: " + MSSV + "\n";
		result += "+ Ho ten: " + hoTen + "\n";
		result += "+ Ngay sinh: " + ngaySinh.getNgay() + "/" + ngaySinh.getThang() + "/" + ngaySinh.getNam() + "\n";
		result += "+ So hoc phan: " + soHocPhan + "\n";
		result += "+ Diem hoc phan:" + "\n";
		for(int i=0; i<soHocPhan; i++) {
			result += tenHocPhan.get(i) + ": " + diemHocPhan.get(i) + "\n";
		}
		return result;
	}
	
	public double diemTB() {
		double tongDiem = 0;
		for(int i=0; i<soHocPhan; i++) {
			if(diemHocPhan.get(i).equals("A"))
				tongDiem += 4;
			else if(diemHocPhan.get(i).equals("B+"))
				tongDiem += 3.5;
			else if(diemHocPhan.get(i).equals("B"))
				tongDiem += 3;
			else if(diemHocPhan.get(i).equals("C+"))
				tongDiem += 2.5;
			else if(diemHocPhan.get(i).equals("C"))
				tongDiem += 2;
			else if(diemHocPhan.get(i).equals("D+"))
				tongDiem += 1.5;
			else if(diemHocPhan.get(i).equals("D"))
				tongDiem += 1;
		}
		return tongDiem / soHocPhan;
	}
	
	public void themHocPhan() {
		String tmp1, tmp2;
		System.out.print("Ten hoc phan can them: ");
		tmp1 = s.nextLine();
		System.out.print("Diem hoc phan can them: ");
		tmp2 = s.nextLine();
		tenHocPhan.add(tmp1);
		diemHocPhan.add(tmp2);
		soHocPhan++;
	}
	
	public void xoaHocPhan() {
		String tenhp;
		System.out.print("Ten hoc phan can xoa: ");
		tenhp = s.nextLine();
		for(int i=0; i<soHocPhan; i++) {
			if(tenHocPhan.get(i).equals(tenhp)) {
				tenHocPhan.remove(i);
				diemHocPhan.remove(i);
				soHocPhan--;
			}
		}
	}
	
	
}