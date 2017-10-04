package vn.edu.ctu;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;
import java.util.Date;

public class Bai01_Server {

	public static void main(String[] args) {
		try {
			// Initialize server
			DatagramSocket ds = new DatagramSocket(13);
			System.out.println("Khoi tao server thanh cong!");
			
			// Receive data from client
			byte[] buf = new byte[60000];
			DatagramPacket receivedPacket = new DatagramPacket(buf, 60000);
			while(true) {
				try {
					ds.receive(receivedPacket);
					Date date = new Date();
					byte b[] = date.toString().getBytes();
					DatagramPacket sentPacket = new DatagramPacket(b, b.length, receivedPacket.getAddress(), receivedPacket.getPort());
					ds.send(sentPacket);
				} catch (IOException e) {
					e.printStackTrace();
				}				
			}

		} catch (SocketException e) {
			e.printStackTrace();
		}
	}

}
