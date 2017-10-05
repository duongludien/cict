package vn.edu.ctu;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

public class Bai01_Client {

	public static void main(String[] args) {
		try {
			// Create a socket UDP
			DatagramSocket ds = new DatagramSocket();
			
			try {
				// Create an empty packet to send
				DatagramPacket sentPacket = new DatagramPacket(new byte[1], 1, InetAddress.getByName("localhost"), 2017);
				
				try {
					// Send packet
					ds.send(sentPacket);
					
					// Receive packet from server
					byte b[] = new byte[60000];
					DatagramPacket receivedPacket = new DatagramPacket(b, 60000);
					ds.receive(receivedPacket);
					
					// Show result
					String result = new String(receivedPacket.getData());
					System.out.println(result);
				} catch (IOException e) {
					e.printStackTrace();
				}
				
			} catch (UnknownHostException e) {
				e.printStackTrace();
			}
			
			ds.close();
			
		} catch (SocketException e) {
			e.printStackTrace();
		}
	}

}
