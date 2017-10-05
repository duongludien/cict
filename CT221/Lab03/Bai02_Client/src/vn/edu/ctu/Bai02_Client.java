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
		Scanner sc = new Scanner(System.in);
		
		try {
			DatagramSocket ds = new DatagramSocket();
			
			while(true) {
				System.out.print("Nhap vao lenh: ");
				String cmd = sc.nextLine();
				
				if(cmd.toLowerCase().equals("exit"))
					break;
				
				try {
					DatagramPacket sentPacket = new DatagramPacket(cmd.getBytes(), cmd.length(), InetAddress.getByName("localhost"), 2018);
					
					try {
						ds.send(sentPacket);
						
						byte receivedBuffer1[] = new byte[1];
						DatagramPacket receivedPacket1 = new DatagramPacket(receivedBuffer1, 1);
						
						ds.receive(receivedPacket1);
						
						if(receivedPacket1.getData()[0] == 0) {
							System.out.println("Khong co file nay cha noi oi!");
							continue;
						}
						
						byte receivedBuffer2[] = new byte[60000];
						DatagramPacket receivedPacket2 = new DatagramPacket(receivedBuffer2, 60000);
						
						ds.receive(receivedPacket2);
						
						System.out.print("Nhap ten file can luu: ");
						String filename = sc.nextLine();
						
						FileOutputStream fos = new FileOutputStream(filename);
						byte b[] = receivedPacket2.getData();
						fos.write(b);
						fos.close();
						System.out.println("Ghi file thanh cong!");
					} catch (IOException e) {
						e.printStackTrace();
					}
				} catch (UnknownHostException e) {
					e.printStackTrace();
				}
			}
			ds.close();
		} catch (SocketException e) {
			e.printStackTrace();
		}
		
	}

}
