package vn.edu.ctu.bai01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

class TachTen extends Thread {
	private Socket s;
	
	public TachTen(Socket s) {
		this.s = s;
	}
	
	@Override
	public void run() {
		super.run();
		try {
			InputStream is = s.getInputStream();
			OutputStream os = s.getOutputStream();
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(os));
			BufferedReader br = new BufferedReader(new InputStreamReader(is));
			
			while(true) {
				// Receive data and process
				String fullname = br.readLine();
				System.out.println("Da nhan: " + fullname);

				// Check exit
				if(fullname.equals("exit"))
					break;

				fullname = fullname.trim();
				System.out.println("Da toi uu: " + fullname);
				int index = fullname.lastIndexOf(' ');
				String name = fullname.substring(index + 1);
				
				// Send result to client
				bw.write(name);
				bw.newLine();
				bw.flush();
				System.out.println("Da gui: " + name);
			}

			String ip = s.getInetAddress().toString();
			s.close();
			System.out.println("Da ngat ket noi tu: " + ip);
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}

public class Bai01_Server {
	public static void main(String[] args) {
		try {
			// Initialize server
			ServerSocket ss = new ServerSocket(2017);
			System.out.println("Khoi tao server thanh cong!");
			
			// Accept connection
			while(true) {
				Socket s = ss.accept();
				System.out.println("Co noi ket tu: " + s.getInetAddress());
				
				TachTen tt = new TachTen(s);
				tt.start();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

}