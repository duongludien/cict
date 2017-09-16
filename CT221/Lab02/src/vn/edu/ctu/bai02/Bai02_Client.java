package vn.edu.ctu.bai02;

import java.util.*;
import java.io.*;
import java.net.*;

public class Bai02_Client {
	public static void main(String[] args) {
		try {
			System.out.print("Nhap vao dia chi server: ");
			String svr = new Scanner(System.in).nextLine();
			Socket s = new Socket(svr, 2018);
			InputStream is = s.getInputStream();
			OutputStream os = s.getOutputStream();
			BufferedReader br = new BufferedReader(new InputStreamReader(is));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(os));

			while(true) {
				System.out.print("Nhap vao lenh: ");
				String command = new Scanner(System.in).nextLine();

				bw.write(command + "\n");
				bw.flush();

				if(command.equals("exit")) break;
				
				String commandOnly = command.substring(0, command.indexOf(' '));
				switch(commandOnly) {
				case "list":
					listFile(br);
					break;
				default:
					continue;
				}
			}

			s.close();
		}
		catch(IOException e) {
			System.out.println("Loi: " + e);
		}
	}

	private static void listFile(BufferedReader br) {
		int flag;
		try {
			// Check file is a directory and exists
			flag = br.read();
			
			if(flag == 1) {
				int counter = br.read();
				System.out.println("counter = " + counter);
				
				for(int i = 0; i < counter; ++i) {
					String filename = br.readLine();
					System.out.println(filename);
				}
			}
			else {
				System.out.println("Ten thu muc khong hop le!");
			}
			
		}
		catch(IOException e) {
			System.out.println("Loi: " + e);
		}
	}
}