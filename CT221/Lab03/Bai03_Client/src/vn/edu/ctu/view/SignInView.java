package vn.edu.ctu.view;

import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.Socket;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

import vn.edu.ctu.controller.SignInController;

public class SignInView extends JFrame {
	private static final long serialVersionUID = 1L;
	private JTextField textFieldUsername;
	private JTextField textFieldPassword;
	private JButton buttonOK;
	private JButton buttonCancel;

	public SignInView() {
		super("Sign in");
		addControls();
		addEvents();
	}
	
	private void disposeWindow() {
		this.dispose();
	}
	
	private SignInView getWindow() {
		return this;
	}

	private void addEvents() {
		buttonCancel.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		
		buttonOK.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				String username = textFieldUsername.getText();
				String password = textFieldPassword.getText();
				
				SignInController sic = new SignInController(username, password);
				Socket s = sic.check();
				
				if(s != null) {
					UserInterfaceView ui = new UserInterfaceView(username);
					ui.showWindow();
					disposeWindow();
				}
				else {
					JOptionPane.showMessageDialog(getWindow(), "Invalid username or password!");
					textFieldUsername.setText("");
					textFieldPassword.setText("");
					textFieldUsername.requestFocus();
				}
			}
		});
	}

	private void addControls() {
		Container container = this.getContentPane();
		
		JPanel panelMain = new JPanel();
		panelMain.setLayout(new BoxLayout(panelMain, BoxLayout.Y_AXIS));
		
		JPanel panelUsername = new JPanel(new FlowLayout());
		JLabel labelUsername = new JLabel("Username:");
		textFieldUsername = new JTextField(20);
		panelUsername.add(labelUsername);
		panelUsername.add(textFieldUsername);
		
		JPanel panelPassword = new JPanel(new FlowLayout());
		JLabel labelPassword = new JLabel("Password:");
		textFieldPassword = new JTextField(20);
		panelPassword.add(labelPassword);
		panelPassword.add(textFieldPassword);
		
		
		JPanel panelButton = new JPanel(new FlowLayout());
		buttonOK = new JButton("OK");
		buttonCancel = new JButton("Cancel");
		panelButton.setAlignmentX(CENTER_ALIGNMENT);
		panelButton.add(buttonOK);
		panelButton.add(buttonCancel);
		
		panelMain.add(panelUsername);
		panelMain.add(panelPassword);
		panelMain.add(panelButton);
		
		container.add(panelMain);
	}
	
	public void showWindow() {
		this.setSize(350, 100);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);;
		this.setResizable(false);
		this.setLocationRelativeTo(null);
		this.setVisible(true);
	}
}
