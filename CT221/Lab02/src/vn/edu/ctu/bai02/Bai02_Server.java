package vn.edu.ctu.bai02;

import java.io.*;
import java.net.*;

class ListFile extends Thread {
	private Socket s;

	public ListFile(Socket s) {
		this.s = s;
	}

	public void run() {
		try {
			InputStream is = s.getInputStream();
			OutputStream os = s.getOutputStream();
			BufferedReader br = new BufferedReader(new InputStreamReader(is));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(os));
			try {
				while(true) {
					String command = br.readLine();
	
					if(command.equals("exit")) break;
					
					String commandOnly = command.substring(0, command.indexOf(' '));
					switch(commandOnly) {
					case "list":
						String path = command.substring(command.indexOf(' ') + 1);
						listFileAndReturn(path, bw);
					}
					
				}
				String ip = s.getInetAddress().toString();
				s.close();
				System.out.println("Da ngat ket noi tu " + ip);
			}
			catch(NullPointerException e) {
				System.out.println("Xay ra loi tu phia client " + s.getInetAddress());
			}
		}
		catch(IOException e) {
			System.out.println("Loi: " + e);
		}
	}

	private void listFileAndReturn(String path, BufferedWriter bw) {
		try {
			File f = new File(path);
	
			if(f.isDirectory() && f.exists()) {
				// This file is a directory and exists
				bw.write(1);
				bw.flush();
				
				File[] fileList = f.listFiles();
	
				int counter = fileList.length;
				bw.write(counter);
	
				for(int i = 0; i < counter; ++i) {
					if(fileList[i].isDirectory())
						bw.write("[" + fileList[i].toString() + "]" + "\n");
					else
						bw.write(fileList[i].toString() + "\n");
					bw.flush();
				}
			}
			else {
				// This file is not a directory or doesn't exists
				bw.write(0);
				bw.flush();
			}
		}
		catch(IOException e) {
			System.out.println("Loi: " + e);
		}
	}
		
}

public class Bai02_Server {
	public static void main(String[] args) {
		try {
			ServerSocket ss = new ServerSocket(2018);
			System.out.println("Khoi tao server thanh cong!");

			while(true) {
				Socket s = ss.accept();
				System.out.println("Co ket noi tu " + s.getInetAddress());

				ListFile lf = new ListFile(s);
				lf.start();
			}
		}
		catch(IOException e) {
			System.out.println("Loi: " + e);
		}
	}
}