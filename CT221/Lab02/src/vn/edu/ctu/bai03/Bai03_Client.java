package vn.edu.ctu.bai03;

import java.io.*;
import java.net.*;
import java.util.*;

public class Bai03_Client {
	public static void main(String[] args) {
		try {
			Socket s = new Socket("localhost", 2019);
			InputStream is = s.getInputStream();
			OutputStream os = s.getOutputStream();
			BufferedReader br = new BufferedReader(new InputStreamReader(is));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(os));

			while(true) {
				System.out.print("Nhap vao phep toan: ");
				String str = new Scanner(System.in).nextLine();

				if(str.equals("exit")) {
					bw.write(str);
					bw.newLine();
					bw.flush();
					break;
				}

				String strList[] = str.split(" ");

				if(strList.length == 3) {
					bw.write(strList[1] + " " + strList[0] + " " + strList[2]);
					bw.newLine();
					bw.flush();

					String result = br.readLine();
					System.out.println("Ket qua: " + result);
				}
				else {
					System.out.println("Phep toan khong hop le!");
					continue;
				}
				
			}

			s.close();
		}
		catch(IOException e) {
			System.out.println("Loi: " + e);
		}
	}
}