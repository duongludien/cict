package vn.edu.ctu.controller;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

import javax.swing.JTextArea;

public class ShowMessagesController extends Thread {
	private Socket s;
	private JTextArea textFieldMessages;
	
	public ShowMessagesController(Socket s, JTextArea textFieldMessages) {
		this.s = s;
		this.textFieldMessages = textFieldMessages;
	}
	
	@Override
	public void run() {
		super.run();
		
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			
			while(true) {
				if(br.ready()) {
					String str = br.readLine();
					String username = str.substring(0, str.indexOf(':'));
					String message = str.substring(str.indexOf(':') + 1);
					
					textFieldMessages.append(username + ": " + message);
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
}
