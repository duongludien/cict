package vn.edu.ctu;

import java.io.FileInputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.Date;

public class Bai03_Server {

	public static void main(String[] args) {
		try {
			// Create UDP Socket
			DatagramSocket s = new DatagramSocket();
			System.out.println("Khoi tao thanh cong server");
			
			try {
				// Read data from file to byte array
				FileInputStream fis = new FileInputStream("data.txt");
				int len = fis.available();
				byte b[] = new byte[len];
				fis.read(b);
				fis.close();
				
				// Create sent package
				InetAddress address = InetAddress.getByName("228.1.1.2");
				DatagramPacket sentPackage = new DatagramPacket(b, len, address, 5678);
				
				while(true) {
					s.send(sentPackage);
					System.out.println("Da gui mot goi tinh luc " + new Date().toString());
					try {
						Thread.sleep(3000);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		} catch (SocketException e) {
			e.printStackTrace();
		}
		
	}

}
