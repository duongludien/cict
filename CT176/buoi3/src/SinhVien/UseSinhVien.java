package SinhVien;

import java.util.Scanner;

public class UseSinhVien {
	private static Scanner s;

	public static void main(String args[]) {
		/*
		SinhVien a = new SinhVien();
		a.nhapThongTin();
		a.themHocPhan();
		System.out.print("Thong tin sinh vien a:\n" + a.toString());
		*/
		
		s = new Scanner(System.in);
		int n;
		
		System.out.print("Nhap vao so sinh vien: ");
		n = s.nextInt();
		SinhVien SV[] = new SinhVien[n];
		for(int i=0; i<n; i++) {
			SV[i] = new SinhVien();
			System.out.println("Nhap thong tin cho sinh vien thu " + (i+1) + ": ");
			SV[i].nhapThongTin();
			SV[i].nhapDiem();
		}
		
		System.out.println("Cac sinh vien bi canh bao hoc vu:");
		
		double max = Double.MIN_VALUE;
		for(int i=0; i<n; i++) {
			if(SV[i].diemTB() < 0.8) {
				System.out.println("+ " + SV[i].getHoTen());
			}
			if(SV[i].diemTB() > max)
				max = SV[i].diemTB();
		}
		
		System.out.println("Cac sinh vien co diem trung binh cao nhat: ");
		for(int i=0; i<n; i++) 
			if(SV[i].diemTB() == max)
				System.out.println("+ " + SV[i].getHoTen());
		
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if(SV[i].getHoTen().compareTo(SV[j].getHoTen()) > 0) {
					SinhVien tmp = SV[i];
					SV[i] = SV[j];
					SV[j] = tmp;
				}
			}
		}
		
		System.out.println("Danh sach sinh vien da sap xep:");
		for(int i=0; i<n; i++) {
			System.out.print("Thong tin sinh vien thu " + (i+1) + ":\n" + SV[i].toString());
		}
	}
}
