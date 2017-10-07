package vn.edu.ctu.controller;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.Socket;

public class SendController {
	public SendController(String username1, String username2, String message, Socket s) {
		try {
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
		
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
