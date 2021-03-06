package Networking;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import org.json.JSONObject;

import GUI.framework.CustomLabel;

public class Authentication {

	public String error = "";
	String gmail, Password, username;
	Statement stmt;
	ResultSet result;
	PreparedStatement pstmt;
	boolean CheckIfUserExist;
	CustomLabel ErrorLabel;
	JSONObject jsonObject;
	boolean Error;

	public Authentication(CustomLabel ErrorLabel) {
		this.ErrorLabel = ErrorLabel; 
	}
	
	public void AuthLogin(String email, String password) {
		CheckIfUserExist = false;
		CheckIfAlive(email, password);

	}

	public void CheckIfAlive(String email, String password) {
		try {
			stmt = MySqlConnection.connection.createStatement();
			result = stmt.executeQuery("select * from UserData");
			while (result.next()) {
				gmail = result.getString("email");
				Password = result.getString("Password");

				if (CheckIfUserExist) {
					if (gmail.equals(email)) {
						Error = true;
						ErrorLabel.setText("User already exists");
						return;
					}
				}
				
				jsonObject = new JSONObject();
				jsonObject.put("email", email);
				jsonObject.put("password", password);
				Statement stmt2 = MySqlConnection.connection.createStatement();
				ResultSet result2 = stmt2.executeQuery("select * from UserData where email ='"+email+"';");
				while (result2.next()) {
					username = result2.getString("Username");
				}
				
				jsonObject.put("username", username);
				
				if (gmail.equals(email) && Password.equals(password)) {
					
					File file = new File(System.getProperty("user.dir")+"/temp/data.json");
					
					file.getParentFile().mkdir();
					try {
						file.createNewFile();
					} catch (IOException e1) 
					{e1.printStackTrace();}
					
					FileWriter filewriter;
					try {		
						filewriter = new FileWriter(file);
						filewriter.write(jsonObject.toString());
						filewriter.close();
						
						if(file.mkdir()) 
							System.exit(0);
						
					} catch (IOException e) {
						e.printStackTrace();
					}			
				}	else {
					ErrorLabel.setText("Login credentials not found in the database");
				}
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	public void AuthSignIn(String email, String username, String password) {
		
		CheckIfUserExist = true;
		try {
			CheckIfAlive(email, password);
			if (!Error) {
				pstmt = MySqlConnection.connection
						.prepareStatement("INSERT INTO UserData (Username,Password,email) VALUES " + "('" + username
								+ "','" + password + "','" + email + "');");
				pstmt.execute();

			}
		} catch (SQLException e) {
			e.printStackTrace();

		}

	}

}
