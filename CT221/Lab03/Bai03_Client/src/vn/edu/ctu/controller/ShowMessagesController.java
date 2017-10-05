package vn.edu.ctu.controller;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class ShowMessagesController extends Thread {
	private Socket s;
	
	public ShowMessagesController(Socket s) {
		this.s = s;
	}
	
	@Override
	public void run() {
		super.run();
		
		try {
			InputStream is = s.getInputStream();			
			BufferedReader br = new BufferedReader(new InputStreamReader(is));
			
			while(true) {
				if(br.ready()) {
					String str = br.readLine();
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
}
