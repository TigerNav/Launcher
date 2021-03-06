package GUI;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JPanel;

import GUI.framework.CustomButton;
import GUI.framework.CustomLabel;
import GUI.framework.CustomTextField;
import Networking.Authentication;

public class SignInPage {

	CustomTextField gmail;
	CustomTextField password;
	CustomTextField Username;
	CustomButton button;
	CustomLabel label;
	CustomLabel gmailLabel;
	CustomLabel UsernameLabel;
	CustomLabel PasswordLabel;
	CustomLabel ErrorLabel;
	CustomLabel SuccLabel;
	Authentication auth;
	JPanel panel;
	
	public SignInPage() {
		
		panel = new JPanel();
		panel.setBounds(0, 60, 500, 500);
		panel.setLayout(null);
		panel.setBackground(new Color(70, 70, 70));
		
		gmail = new CustomTextField();
		gmail.setSize(200, 30);
		gmail.setLocation(150, 150);
		
		Username = new CustomTextField();
		Username.setSize(200, 30);
		Username.setLocation(150, 200);
		
		password = new CustomTextField();
		password.setSize(200, 30);
		password.setLocation(150, 250);
		
		ErrorLabel = new CustomLabel("");	
		ErrorLabel.setSize(400, 40);
		ErrorLabel.setLocation(150,400);
		ErrorLabel.setLabelColor(new Color(255,0,0));
		
		auth = new Authentication(ErrorLabel);
		
		SuccLabel = new CustomLabel("Account Created!");
		SuccLabel.setSize(150, 40);
		SuccLabel.setLocation(170, 350);
		SuccLabel.setVisible(false);
		
		button = new CustomButton("Sign Me Up!");
		button.setSize(150, 40);
		button.setLocation(170, 300);
		button.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				
				if(gmail.getText().isEmpty() || Username.getText().isEmpty()|| password.getText().isEmpty()) {
					ErrorLabel.setText("Credentials not valid");
					return;
				}
				
				auth.AuthSignIn(gmail.getText(), Username.getText(), password.getText());
				SuccLabel.setVisible(true);
			}
		});
		
		label = new CustomLabel("Sign Up");
		label.setSize(90, 40);
		label.setLocation(220, 70);
		
		gmailLabel = new CustomLabel("Gmail");
		gmailLabel.setSize(100, 40);
		gmailLabel.setLocation(225, 120);
		
		UsernameLabel = new CustomLabel("Username");
		UsernameLabel.setSize(100, 40);
		UsernameLabel.setLocation(210, 170);
		
		PasswordLabel = new CustomLabel("Password");
		PasswordLabel.setSize(100, 40);
		PasswordLabel.setLocation(210, 220);
		
		panel.add(gmail);
		panel.add(password);
		panel.add(button);
		panel.add(label);
		panel.add(gmailLabel);
		panel.add(PasswordLabel);
		panel.add(Username);
		panel.add(UsernameLabel);
		panel.add(ErrorLabel);
		panel.add(SuccLabel);
		
	}
	
	public JPanel getPanel() {
		return panel;
	}

}
