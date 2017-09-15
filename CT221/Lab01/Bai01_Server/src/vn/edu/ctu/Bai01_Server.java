package vn.edu.ctu;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Bai01_Server {

	public static void main(String[] args) {
		
		try {
			// Khoi tao Server
			ServerSocket ss = new ServerSocket(2016);
			System.out.println("Khoi tao Server thanh cong!");
			
			
			while(true) {
				try {
					// Chap nhan noi ket
					Socket s = ss.accept();
					System.out.println("Da chap nhan ket noi tu: " + s.getInetAddress() + ":" + s.getPort());
					InputStream is = s.getInputStream();
					OutputStream os = s.getOutputStream();
					BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(os));
					
					int c = 0;
					while(true) {
						// Nhan du lieu tu Client
						c = is.read();
						System.out.println("Nhan duoc: " + (char)c);
						
						// Xu ly
						if(c == '@') break;
						String result = docSo(c);
						
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

	private static String docSo(int c) {
		switch(c) {
		case '0':
			return "Khong";
		case '1':
			return "Mot";
		case '2':
			return "Hai";
		case '3':
			return "Ba";
		case '4':
			return "Bon";
		case '5':
			return "Nam";
		case '6':
			return "Sau";
		case '7':
			return "Bay";
		case '8':
			return "Tam";
		case '9':
			return "Chin";
		default:
			return "Khong phai so nguyen";
		}
	}

}
