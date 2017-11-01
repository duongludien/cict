package vn.edu.ctu;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class MainClass {

	private static Scanner kb;
	
	private static int indexOfSlash(String str, int position) {
		int count = 0;
		int len = str.length();
		for(int i=0; i<len; ++i) {
			if(str.charAt(i) == '/')
				++count;
			if(count == position)
				return i;
		}
		return -1;
	}

	public static void main(String[] args) {
		kb = new Scanner(System.in);
		System.out.print("Nhap vao URL: ");
		String url = kb.nextLine();
		
		int secondIndex = indexOfSlash(url, 2);
		int thirdIndex = indexOfSlash(url, 3);
		
		String server = url.substring(secondIndex+1, thirdIndex);
		
		System.out.println(server);
		
		String request = "GET " + url + " HTTP/1.0\n";
		try {
			Socket s = new Socket(InetAddress.getByName(server), 80);
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
			BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			
			System.out.println("Request: " + request);
			
			bw.write(request);
			bw.newLine();
			bw.flush();
			
			String line;
			FileOutputStream fos = new FileOutputStream("data.html");
			while((line = br.readLine()) != null) {
				fos.write(line.getBytes());
				System.out.println(line);
			}
			fos.close();
			
			s.close();
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
