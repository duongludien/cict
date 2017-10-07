package vn.edu.ctu.controller;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

public class ProcessRequest extends Thread {
	private Socket s;
	
	public ProcessRequest(Socket s) {
		super();
		this.s = s;
	}
	
	@Override
	public void run() {
		super.run();
		
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			
			String request = br.readLine();
			String str[] = request.split(":");
			
			switch(str[0]) {
			case "signin":
				processSignIn(str[1], str[2]);
				break;
			case "send":
				processSend();
				break;
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void processSend() {
		
	}

	private void processSignIn(String username, String password) {
		SignInController sic = new SignInController(username, password);
		int signal = sic.check() ? 1 : 0;
		
		try {
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
			bw.write(signal);
			bw.newLine();
			bw.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
