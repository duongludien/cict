package vn.edu.ctu.controller;

public class SignInController {
	private String username;
	private String password;
	
	public SignInController(String username, String password) {
		super();
		this.username = username;
		this.password = password;
	}
	
	public boolean check() {
		if(username.equals("user") && password.equals("user"))
			return true;
		return false;
	}
}
