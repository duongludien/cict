import java.awt.*;
import javax.swing.*;

public class GUI {
	public static void main(String args[]) {
		JFrame f = new JFrame("Test GUI");
		f.setSize(400, 200);
		JPanel p = new JPanel(new FlowLayout());
		JLabel lbl = new JLabel("My label");
		JButton btn = new JButton("Press me!");
		p.add(lbl);
		p.add(btn);
		f.setContentPane(p);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setVisible(true);
	}
}