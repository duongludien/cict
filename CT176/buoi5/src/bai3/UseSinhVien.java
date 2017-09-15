package bai3;

import java.io.*;

public class UseSinhVien {
	public static void main(String[] args) {
		/*
		SinhVien a = new SinhVien("B1401133", "Duong Lu Dien", 26, 11, 1996, 4, new String[] {"TRR", "CTDL", "VTPA2", "OOP"}, new String[] {"A", "A", "A", "A"});
		try {
			FileOutputStream out = new FileOutputStream("sv.txt");
			a.writeToFile(out);
		}
		catch(IOException e) {
			
		}
		*/
		
		try {
			FileInputStream in = new FileInputStream("sv.txt");
			SinhVien a = new SinhVien();
			a = a.readFromFile(in);
			a.hienThi();
		}
		catch (IOException e) {
			
		}
		
	}
}
