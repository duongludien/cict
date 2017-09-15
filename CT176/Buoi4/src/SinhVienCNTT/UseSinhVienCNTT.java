package SinhVienCNTT;

import java.util.Scanner;

public class UseSinhVienCNTT {
	public static void timKiem(SinhVienCNTT sv[], int n, String mail) {
		for(int i=0; i<n; i++) {
			if(sv[i].getEmail().equals(mail)) {
				
			}
		}
	}
	
	public static void main(String args[]) {
		Scanner s = new Scanner(System.in);
		
		int n;
		System.out.print("\nNhap vao so sinh vien: ");
		n = s.nextInt();
		SinhVienCNTT sv[] = new SinhVienCNTT[n];
		for(int i=0; i<n; i++) {
			System.out.print("\nNhap vao thong tin sinh vien thu " + (i+1) + ":");
			sv[i] = new SinhVienCNTT();
			sv[i].nhapThongTin();
		}
		
		String mail;
		System.out.print("\nNhap vao dia chi email: ");
		mail = s.nextLine();
		timKiem(sv, n, mail);
		
		s.close();
	}
}