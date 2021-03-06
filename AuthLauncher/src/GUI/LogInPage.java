package GUI;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JPanel;

import GUI.framework.CustomButton;
import GUI.framework.CustomLabel;
import GUI.framework.CustomTextField;
import Networking.Authentication;

public class LogInPage {

	CustomTextField gmail;
	CustomTextField password;
	CustomButton button;
	CustomLabel label;
	CustomLabel gmailLabel;
	CustomLabel PasswordLabel;
	CustomLabel ErrorLabel;
	Authentication auth;
	JPanel panel;
	
	public LogInPage() {
		
		panel = new JPanel();
		panel.setBounds(0, 60, 500, 500);
		panel.setLayout(null);
		panel.setBackground(new Color(70, 70, 70));
		
		gmail = new CustomTextField();
		gmail.setSize(200, 30);
		gmail.setLocation(150, 150);
		
		password = new CustomTextField();
		password.setSize(200, 30);
		password.setLocation(150, 200);
		
		ErrorLabel = new CustomLabel("");	
		ErrorLabel.setSize(400, 40);
		ErrorLabel.setLocation(70,400);
		ErrorLabel.setLabelColor(new Color(255,0,0));
		
		auth = new Authentication(ErrorLabel);
		
		button = new CustomButton("Log In!");
		button.setSize(150, 40);
		button.setLocation(170, 250);
		button.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				auth.AuthLogin(gmail.getText(), password.getText());
			}		
		});
		
		label = new CustomLabel("Log In");
		label.setSize(90, 40);
		label.setLocation(220, 70);
		
		gmailLabel = new CustomLabel("Gmail");
		gmailLabel.setSize(100, 40);
		gmailLabel.setLocation(225, 120);
		
		PasswordLabel = new CustomLabel("Password");
		PasswordLabel.setSize(100, 40);
		PasswordLabel.setLocation(210, 170);
		
		panel.add(gmail);
		panel.add(password);
		panel.add(button);
		panel.add(label);
		panel.add(gmailLabel);
		panel.add(PasswordLabel);
		panel.add(ErrorLabel);
	}
	
	public JPanel getPanel() {
		return panel;	
	}

}
