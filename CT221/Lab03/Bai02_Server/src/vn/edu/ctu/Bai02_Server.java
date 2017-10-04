package vn.edu.ctu;

import java.io.FileInputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

public class Bai02_Server {

	public static void main(String[] args) {
		try {
			DatagramSocket ds = new DatagramSocket(2017);
			System.out.println("Da khoi tao thanh cong server!");
			
			byte buf[] = new byte[60000];
			DatagramPacket receivedPacket = new DatagramPacket(buf, 60000);
			
			while(true) {
				try {
					ds.receive(receivedPacket);
					
					String cmd = new String(receivedPacket.getData());
					String path = cmd.substring(cmd.lastIndexOf(' ') + 1);
					
					System.out.println(path);
					
					FileInputStream fis = new FileInputStream(path);
					int len = fis.available();
					byte buffer[] = new byte[len];
					fis.read(buffer);
					fis.close();
					
					DatagramPacket sentPacket = new DatagramPacket(buffer, len, receivedPacket.getAddress(), receivedPacket.getPort());
					
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
