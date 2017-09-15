package bai2;

import java.io.*;

public class Bai2 {
	public static void main(String[] args) {
		try {
			FileInputStream in = new FileInputStream("in.txt");
			FileOutputStream out = new FileOutputStream("out.txt");
			byte[] b = new byte[100];
			in.read(b);
			out.write(b);
			
			in.close();
			out.close();
			
			System.out.print("Da ghi chuyen du lieu tu file in.txt sang file out.txt thanh cong!");
		}
		catch(IOException e) {
			System.out.print("Loi nhap xuat: " + e);
		}
	}
	
}
