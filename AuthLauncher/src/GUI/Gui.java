package GUI;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;
import GUI.framework.CustomButton;
import Networking.MySqlConnection;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Gui {

	JFrame window;
	public static Font font;
	CustomButton SwitchSignIn;
	CustomButton SwitchLogin;
	LogInPage loginpage;
	SignInPage signinpage;
	
	public Gui() {
		window = new JFrame("Nav Launcher");
		window.setSize(500, 600);
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window.setVisible(true);	
		window.setLayout(null);
		window.getContentPane().setBackground(new Color(90, 90, 90));
		
		new MySqlConnection();   
		
		font = new Font(Font.SANS_SERIF, Font.BOLD, 15);
		
		loginpage = new LogInPage();
		signinpage = new SignInPage();
		
		SwitchLogin = new CustomButton("Sign In");
		SwitchLogin.setFont(font.deriveFont(12));
		SwitchLogin.setSize(90, 20);
		SwitchLogin.setLocation(50, 20);
		
		SwitchLogin.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				loginpage.getPanel().setVisible(false);
				signinpage.getPanel().setVisible(true);
			}	
		});
		
		SwitchSignIn = new CustomButton("Log In");
		SwitchSignIn.setFont(font.deriveFont(12));
		SwitchSignIn.setSize(90, 20);
		SwitchSignIn.setLocation(350, 20);
		loginpage.getPanel().setVisible(false);
		SwitchSignIn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				signinpage.getPanel().setVisible(false);
				loginpage.getPanel().setVisible(true);
			}	
		});
		
		SwingUtilities.updateComponentTreeUI(window);
		
		window.add(SwitchLogin);
		window.add(SwitchSignIn);
		window.add(signinpage.getPanel());
		window.add(loginpage.getPanel());
		
		
	}
}