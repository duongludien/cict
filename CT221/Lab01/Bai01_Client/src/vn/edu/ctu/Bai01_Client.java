package vn.edu.ctu;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.Socket;

public class Bai01_Client {

	public static void main(String[] args) {
		// Ket noi den Server
		try {
			Socket s = new Socket("localhost", 2016);
			InputStream is = s.getInputStream();
			OutputStream os = s.getOutputStream();
			BufferedReader br = new BufferedReader(new InputStreamReader(is));
			
			int c;
			do {
				// Nhap du lieu
				System.out.print("Nhap vao mot ky tu: ");
				c = System.in.read();
				System.in.skip(2);
				
				// Gui du lieu len Server
				os.write(c);
				
				// Nhan du lieu tu Server
				String result = br.readLine();
				
				System.out.println("Ket qua: " + result);
			}
			while(c != '@');
			
			s.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}