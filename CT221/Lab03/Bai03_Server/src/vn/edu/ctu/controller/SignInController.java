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
		if((username.equals("user1") && password.equals("user1")) || (username.equals("user2") && password.equals("user2")))
			return true;
		return false;
	}
}
