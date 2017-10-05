package vn.edu.ctu.test;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

import vn.edu.ctu.controller.ProcessRequest;

public class MainClass {

	public static void main(String[] args) {
		try {
			ServerSocket ss = new ServerSocket(2018);
			System.out.println("Server is initialized");
			
			while(true) {
				Socket s = ss.accept();
				ProcessRequest pr = new ProcessRequest(s);
				pr.start();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
