package bai3;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class SinhVien implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private Scanner s;
	private String maSo, hoTen;
	private Date ngaySinh;
	private int soHocPhan;
	private ArrayList<String> tenHocPhan;
	private ArrayList<String> diemHocPhan;
	
	SinhVien() {
		maSo = hoTen = null;
		ngaySinh = new Date();
		soHocPhan = 0;
		tenHocPhan = null;
		diemHocPhan = null;
	}
	
	SinhVien(String ms, String ht, int d, int m, int y, int shp, String []thp, String []dhp) {
		maSo = ms;
		hoTen = ht;
		ngaySinh = new Date(d, m, y);
		soHocPhan = shp;
		tenHocPhan = new ArrayList<String>();
		diemHocPhan = new ArrayList<String>();
		for(int i=0; i<shp; i++) {
			tenHocPhan.add(thp[i]);
			diemHocPhan.add(dhp[i]);
		}
	}
	
	public void nhapThongTin() {
		s = new Scanner(System.in);
		//s.nextLine();
		System.out.print("\nNhap vao ma so: ");
		maSo = s.nextLine();
		System.out.print("\nNhap vao ho ten: ");
		hoTen = s.nextLine();
		System.out.println("\nNhap vao ngay sinh: ");
		ngaySinh.nhapNgay();
		System.out.print("\nNhap vao so luong hoc phan dang ky: ");
		soHocPhan = s.nextInt();
		tenHocPhan = new ArrayList<String>();
		for(int i=0; i<soHocPhan; i++) {
			s.nextLine();
			System.out.print("\nNhap vao ten hoc phan " + (i+1) + ": ");
			tenHocPhan.add(s.nextLine());
		}
	}
	
	public void nhapDiem() {
		diemHocPhan = new ArrayList<String>();
		for(int i=0; i<soHocPhan; i++) {
			s.nextLine();
			System.out.print("\nNhap vao diem hoc phan " + (i+1) + ": ");
			diemHocPhan.add(s.nextLine());
		}
	}
	
	public void hienThi() {
		System.out.print("\n- Ma so: " + maSo);
		System.out.print("\n- Ho ten: " + hoTen);
		System.out.print("\n- Ngay sinh: ");
		ngaySinh.hienThi();
		System.out.print("\n- So luong hoc phan da dang ky: " + soHocPhan);
		System.out.print("\n- Cac hoc phan va diem tung hoc phan:");
		for(int i=0; i<soHocPhan; i++) {
			System.out.print("\n+ " + tenHocPhan.get(i) + ": " + diemHocPhan.get(i));
		}
	}
	
	@Override
	public String toString() {
		String result = "";
		
		result += "\n- Ma so: " + maSo;
		result += "\n- Ho ten: " + hoTen;
		result += "\n- Ngay sinh: " + ngaySinh.getNgay() + "/" + ngaySinh.getThang() + "/" + ngaySinh.getNam();
		result += "\n- So luong hoc phan da dang ky: " + soHocPhan;
		result += "\n- Cac hoc phan va diem tung hoc phan:";
		for(int i=0; i<soHocPhan; i++) {
			result += "\n+ " + tenHocPhan.get(i) + ": " + diemHocPhan.get(i);
		}
		
		return result;
	}
	
	public double diemTrungBinh() {
		double sum = 0;
		
		for(int i=0; i<soHocPhan; i++) {
			if(diemHocPhan.get(i).equals("A")) {
				sum += 4.0;
			}
			else if(diemHocPhan.get(i).equals("B+")) {
				sum += 3.5;
			}
			else if(diemHocPhan.get(i).equals("B")) {
				sum += 3.0;
			}
			else if(diemHocPhan.get(i).equals("B")) {
				sum += 2.5;
			}
			else if(diemHocPhan.get(i).equals("C+")) {
				sum += 2.0;
			}
			else if(diemHocPhan.get(i).equals("C")) {
				sum += 1.5;
			}
			else if(diemHocPhan.get(i).equals("D+")) {
				sum += 1.0;
			}
			else if(diemHocPhan.get(i).equals("D")) {
				sum += 0.5;
			}
		}
		
		return sum / soHocPhan;
	}
	
	public void themMotHocPhan() {
		s = new Scanner(System.in);
		String thp, dhp;
		System.out.print("\nNhap ten hoc phan: ");
		thp = s.nextLine();
		tenHocPhan.add(thp);
		System.out.print("\nNhap vao diem hoc phan: ");
		dhp = s.nextLine();
		diemHocPhan.add(dhp);
		soHocPhan++;
	}
	
	public void xoaHocPhan() {
		s = new Scanner(System.in);
		String thp;
		System.out.print("\nNhap vao ten hoc phan can xoa: ");
		thp = s.nextLine();
		for(int i=0; i<soHocPhan; i++) {
			if(tenHocPhan.get(i).equals(thp)) {
				tenHocPhan.remove(i);
				diemHocPhan.remove(i);
				soHocPhan--;
			}
		}
	}
	
	public void writeToFile(FileOutputStream f) {
		try {
			ObjectOutputStream out = new ObjectOutputStream(/*new BufferedOutputStream(f)*/f);
			out.writeObject(this);
			out.flush();
			out.close();
			System.out.println("Da ghi file thanh cong!");
		}
		catch (IOException e) {
			System.out.println("Loi: " + e);
		}
	}
	
	public SinhVien readFromFile(FileInputStream f) {
		try {
			ObjectInputStream in = new ObjectInputStream(f/*new BufferedInputStream(f)*/);
			SinhVien sv = (SinhVien)in.readObject();
			in.close();
			System.out.println("Da ghi file thanh cong");
			return sv;
		}
		catch (IOException | ClassNotFoundException e) {
			System.out.println("Loi: " + e);
			return null;
		}
		
	}
}