package vn.edu.ctu;

import java.io.FileOutputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Bai02_Client {

	public static void main(String[] args) {
		try {
			DatagramSocket ds = new DatagramSocket();
			
			System.out.print("Nhap vao lenh: ");
			String cmd = new Scanner(System.in).nextLine();
			
			try {
				DatagramPacket sentPacket = new DatagramPacket(cmd.getBytes(), cmd.length(), InetAddress.getByName("localhost"), 2017);
				try {
					ds.send(sentPacket);
					
					byte buf[] = new byte[60000];
					DatagramPacket receivedPacket = new DatagramPacket(buf, 60000);
					
					ds.receive(receivedPacket);
					
					FileOutputStream fos = new FileOutputStream("output.txt");
					fos.write(receivedPacket.getData());
					fos.close();
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
