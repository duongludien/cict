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
			DatagramSocket ds = new DatagramSocket(2017);
			System.out.println("Khoi tao server thanh cong!");
			
			// Create a DatagramPacket to receive packet from client
			byte[] buf = new byte[60000];
			DatagramPacket receivedPacket = new DatagramPacket(buf, 60000);
			
			// while loop for serving 
			while(true) {
				try {
					// Receive packet from client
					ds.receive(receivedPacket);
					
					// Processing
					Date date = new Date();
					byte b[] = date.toString().getBytes();
					
					// Create DatagramPacket and send it to client
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
