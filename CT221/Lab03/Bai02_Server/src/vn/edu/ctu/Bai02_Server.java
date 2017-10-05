package vn.edu.ctu;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
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
						try {
							FileInputStream fis = new FileInputStream(path);
							
							byte sentBuffer1[] = new byte[1];
							sentBuffer1[0] = 1;
							DatagramPacket sentPacket1 = new DatagramPacket(sentBuffer1, 1, receivedPacket.getAddress(), receivedPacket.getPort());
							ds.send(sentPacket1);
							
							byte sentBuffer2[] = new byte[fis.available()];
							fis.read(sentBuffer2);
							DatagramPacket sentPacket2 = new DatagramPacket(sentBuffer2, sentBuffer2.length, receivedPacket.getAddress(), receivedPacket.getPort());
							ds.send(sentPacket2);
							System.out.println("Gui thanh cong den: " + receivedPacket.getAddress() + ":" + receivedPacket.getPort());
							fis.close();
						}
						catch(FileNotFoundException e) {
							e.printStackTrace();
							byte sentBuffer1[] = new byte[1];
							sentBuffer1[0] = 0;
							DatagramPacket sentPacket1 = new DatagramPacket(sentBuffer1, 1, receivedPacket.getAddress(), receivedPacket.getPort());
							ds.send(sentPacket1);
						}
						break;
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
