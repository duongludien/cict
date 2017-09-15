package vn.edu.ctu;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.util.Scanner;

public class Bai02_Client {
	private static Scanner scanner;

	public static void main(String[] args) {
		// Ket noi den Server
		try {
			Socket s = new Socket("localhost", 2018);
			InputStream is = s.getInputStream();
			OutputStream os = s.getOutputStream();
			BufferedReader br = new BufferedReader(new InputStreamReader(is));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(os));
			
			String c;
			while(true) {
				// Nhap du lieu
				System.out.print("Nhap vao chuoi so: ");
				scanner = new Scanner(System.in);
				c = scanner.nextLine();
				
				// Gui du lieu len Server
				bw.write(c);
				bw.newLine();
				bw.flush();
				
				if(c.equals("exit")) break;
				
				// Nhan du lieu tu Server
				String result = br.readLine();
				
				System.out.println("Ket qua: " + result);
			}
			
			s.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		}		
	}
}
