package vn.edu.ctu.bai03;

import java.io.*;
import java.net.*;

class Calculate extends Thread {
	private Socket s;

	public Calculate(Socket s) {
		this.s = s;
	}

	public void run() {
		try {
			InputStream is = s.getInputStream();
			OutputStream os = s.getOutputStream();
			BufferedReader br = new BufferedReader(new InputStreamReader(is));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(os));

			while(true) {
				try {
					String str = br.readLine();

					if(str.equals("exit")) {
						System.out.println("Da ngat ket noi tu " + s.getInetAddress());
						break;
					}

					String strList[] = str.split(" ");
					long a = Long.parseLong(strList[1]);
					long b = Long.parseLong(strList[2]);
					double result;

					switch(strList[0]) {
					case "+":
						result = a + b;
						break;
					case "-":
						result = a - b;
						break;
					case "*":
						result = a * b;
						break;
					case "/":
						result = (double)a / b;
						break;
					default:
						result = Double.MIN_VALUE;
					}

					bw.write(Double.toString(result));
					bw.newLine();
					bw.flush();
				}
				catch(NullPointerException e) {
					System.out.println("Phat sinh loi tu client");
					break;
				}
				
			}
			s.close();
		}
		catch(IOException e) {
			System.out.println("Loi: " + e);
		}
	}
}

public class Bai03_Server {
	public static void main(String[] args) {
		try {
			ServerSocket ss = new ServerSocket(2019);
			System.out.println("Khoi tao server thanh cong!");

			while(true) {
				Socket s = ss.accept();
				System.out.println("Co noi ket tu " + s.getInetAddress());

				Calculate cal = new Calculate(s);
				cal.start();
			}
		}
		catch(IOException e) {
			System.out.println("Loi: " + e);
		}
	}
}