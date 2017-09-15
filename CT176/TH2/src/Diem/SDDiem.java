package Diem;

import java.io.*;

public class SDDiem {
	public static void main(String args[]) {
		Diem A = new Diem();
		
		try {
			FileInputStream f = new FileInputStream("diem.txt");
			Diem B = A.readFromFile(f);
			B.hienThi();
		}
		catch(IOException e) {
			System.out.print("\nLoi khi tao file!");
		}
		
		
	}
}