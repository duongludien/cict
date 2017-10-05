package vn.edu.ctu.controller;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

public class SignInController {
	private String username;
	private String password;
	
	public SignInController(String username, String password) {
		super();
		this.username = username;
		this.password = password;
	}
	
	public Socket check() {
		try {
			Socket s = new Socket("localhost", 2018);
			BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
			
			bw.write("signin:" + username + ":" + password);
			bw.newLine();
			bw.flush();
			
			int signal = br.read();
			
			return signal == 1 ? s : null;
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
	}
}
