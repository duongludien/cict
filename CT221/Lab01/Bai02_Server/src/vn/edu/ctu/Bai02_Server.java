package vn.edu.ctu;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Bai02_Server {

	public static void main(String[] args) {
		try {
			// Khoi tao Server
			ServerSocket ss = new ServerSocket(2018);
			System.out.println("Khoi tao Server thanh cong!");
			
			
			while(true) {
				try {
					// Chap nhan noi ket
					Socket s = ss.accept();
					System.out.println("Da chap nhan ket noi tu: " + s.getInetAddress() + ":" + s.getPort());
					InputStream is = s.getInputStream();
					OutputStream os = s.getOutputStream();
					BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(os));
					BufferedReader br = new BufferedReader(new InputStreamReader(is));
					
					String c = null;
					while(true) {
						// Nhan du lieu tu Client
						c = br.readLine();
						System.out.println("Nhan duoc: " + c);
						
						// Xu ly
						if(c.equals("exit")) break;
						String result = chuyenSangNhiPhan(c);
						
						// Tra ket qua cho Client
						bw.write(result);
						bw.newLine();
						bw.flush();
						System.out.println("Da tra ve: " + result);
					}
						
					s.close();
					System.out.println("Da dong ket noi tu: " + s.getInetAddress() + ":" + s.getPort());
				}
				catch(IOException ex) {
					ex.printStackTrace();
				}
				
				
			}
			
		} catch (IOException e) {
			e.printStackTrace();
		}		
	}

	private static String chuyenSangNhiPhan(String c) {
		try {
			long n = Long.parseLong(c);
			return Long.toBinaryString(n);
		}
		catch(NumberFormatException ex) {
			return "Khong phai la so nguyen";
		}
	}

}
