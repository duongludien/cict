package bai1;
import java.io.*;

public class Bai1 {
	public static void main(String[] args) {
		try {
			System.out.print("Nhap chuoi: ");
			byte[] b = new byte[100];
			int n = System.in.read(b);
			String s = new String(b, 0, n-2);
			
			FileOutputStream out = new FileOutputStream("data.txt");
			for(int i=0; i<s.length(); i++) { 
				out.write(s.charAt(i));
			}
			out.close();
			System.out.print("Da in file thanh cong!");
		}
		catch(IOException e) {
			System.out.print("Loi!");
		}
	}
}