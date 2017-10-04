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
			DatagramSocket ds = new DatagramSocket();
			
			try {
				DatagramPacket sentPacket = new DatagramPacket(new byte[1], 1, InetAddress.getByName("localhost"), 13);
				try {
					ds.send(sentPacket);
					byte b[] = new byte[60000];
					DatagramPacket receivedPacket = new DatagramPacket(b, 60000);
					ds.receive(receivedPacket);
					String result = new String(receivedPacket.getData());
					System.out.println(result);
				} catch (IOException e) {
					e.printStackTrace();
				}
			} catch (UnknownHostException e) {
				e.printStackTrace();
			}
		} catch (SocketException e) {
			e.printStackTrace();
		}
	}

}
