package Networking;

import java.sql.Connection;
import java.sql.DriverManager;

public class MySqlConnection {

	
	String url = "jdbc:mysql://localhost:3306/Launcher";
	String username = "root";
	String password = "tigernav";
	public static Connection connection;
	
	public MySqlConnection() {
		
		try{
			connection = DriverManager.getConnection(url, username, password);
			
			System.out.println("Connected");
		}catch(Exception e) {
			e.printStackTrace();
		}
		
	}

}
