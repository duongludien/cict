package vn.edu.ctu.bai01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Bai01_Client {

	public static void main(String[] args) {
		try {
			Socket s = new Socket("localhost", 2017);
			InputStream is = s.getInputStream();
			OutputStream os = s.getOutputStream();
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(os));
			BufferedReader br = new BufferedReader(new InputStreamReader(is));
			
			while(true) {
				// Input full name
				System.out.print("Nhap vao ho ten (nhap exit de thoat): ");
				String str = new Scanner(System.in).nextLine();
			
				// Send to server
				bw.write(str);
				bw.newLine();
				bw.flush();
				System.out.println("Da gui: " + str);

				// Check exit
				if(str.equals("exit"))
					break;
				
				// Receive result from server
				String result = br.readLine();
				System.out.println("Ket qua: " + result);
			}
			
			s.close();
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

}