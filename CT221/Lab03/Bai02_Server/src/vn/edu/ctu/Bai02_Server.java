package vn.edu.ctu;

import java.io.FileInputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

public class Bai02_Server {

	public static void main(String[] args) {
		try {
			// Initialize UDP server
			DatagramSocket ds = new DatagramSocket(2018);
			System.out.println("Khoi tao server thanh cong!");
			
			// Create packet to receive data from client
			byte receivedBuffer[] = new byte[60000];
			DatagramPacket receivedPacket = new DatagramPacket(receivedBuffer, 60000);
			
			while(true) {
				try {
					// Receive packet from client
					ds.receive(receivedPacket);
					System.out.println("Yeu cau tu: " + receivedPacket.getAddress() + ":" + receivedPacket.getPort());
					
					// Process
					String request = new String(receivedPacket.getData(), 0, receivedPacket.getLength());
					System.out.println("request = " + request);
					String command = request.substring(0, request.indexOf(' ')).trim().toLowerCase();
					System.out.println("command = " + command);
					String path = request.substring(request.indexOf(' ') + 1).trim();
					System.out.println("path = " + path);
					
					switch(command) {
					case "read":
						FileInputStream fis = new FileInputStream(path);
						byte sentBuffer[] = new byte[fis.available()];
						fis.read(sentBuffer);
						
						DatagramPacket sentPacket = new DatagramPacket(sentBuffer, sentBuffer.length, receivedPacket.getAddress(), receivedPacket.getPort());
						ds.send(sentPacket);
						System.out.println("Gui thanh cong den: " + receivedPacket.getAddress() + ":" + receivedPacket.getPort());
						fis.close();
					}
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		} catch (SocketException e) {
			e.printStackTrace();
		}
		
	}

}
