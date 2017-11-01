package vn.edu.ctu;

import java.io.FileOutputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.SocketException;

public class Bai03_Client {

	public static void main(String[] args) {
		try {
			MulticastSocket multicastSocket = new MulticastSocket(5678);
			multicastSocket.joinGroup(InetAddress.getByName("228.1.1.2"));
			
			byte b[] = new byte[60000];
			DatagramPacket receivedPacket = new DatagramPacket(b, b.length);
			multicastSocket.receive(receivedPacket);
			System.out.println("Nhan duoc goi tin tu " + receivedPacket.getAddress());
			
			FileOutputStream fos = new FileOutputStream("out.txt");
			fos.write(b);
			fos.close();
			System.out.println("Ghi tap tin thanh cong");
			
			multicastSocket.close();
		} catch (SocketException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
