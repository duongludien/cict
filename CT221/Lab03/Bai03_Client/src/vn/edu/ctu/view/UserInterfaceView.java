package vn.edu.ctu.view;

import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;


public class UserInterfaceView extends JFrame {
	private static final long serialVersionUID = 1L;
	
	private JTextArea textAreaMessages;
	private JTextArea textAreaTyping;
	private JButton buttonSend;
	private String username;
	
	public UserInterfaceView(String username) {
		super();
		this.username = username;
		this.setTitle("Chat App - " + username);
		addControls();
		addEvents();
	}

	public void showWindow() {
		this.setSize(520, 550);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setLocationRelativeTo(null);
		this.setResizable(false);
		
		textAreaMessages.setEditable(false);
		
		this.setVisible(true);
	}

	private void addEvents() {
		
	}

	private void addControls() {
		Container container = this.getContentPane();
		
		JPanel panelMain = new JPanel();
		panelMain.setLayout(new BoxLayout(panelMain, BoxLayout.Y_AXIS));
		
		JPanel panelMessages = new JPanel(new FlowLayout());
		textAreaMessages = new JTextArea(30, 45);
		JScrollPane scrollPaneTextMessages = new JScrollPane(textAreaMessages);
		panelMessages.add(scrollPaneTextMessages);
		
		JPanel panelTyping = new JPanel(new FlowLayout());
		textAreaTyping = new JTextArea(5, 38);
		JScrollPane scrollPaneTyping = new JScrollPane(textAreaTyping);
		buttonSend = new JButton("Send");
		buttonSend.setPreferredSize(new Dimension(75, 77));
		panelTyping.add(scrollPaneTyping);
		panelTyping.add(buttonSend);
		
		panelMain.add(panelMessages);
		panelMain.add(panelTyping);
		
		container.add(panelMain);
	}
}
