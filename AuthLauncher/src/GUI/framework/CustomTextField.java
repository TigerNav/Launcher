package GUI.framework;

import java.awt.*;

import javax.swing.BorderFactory;
import javax.swing.JTextField;
import javax.swing.border.Border;

import GUI.Gui;



public class CustomTextField extends JTextField{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 4672013060911223233L;
	private Border border;
	
	public CustomTextField() {
		
		setForeground(Color.WHITE);
		setBorderColor(new Color(0, 0, 0));
		setFill(new Color(70, 70, 70));
		setSelectedColor(new Color(50, 50, 50));
		getCaret().setBlinkRate(500);
		setCaretColor(Color.WHITE);
		setFont(Gui.font);
		border = BorderFactory.createLineBorder(BorderColor, 2);
		setBorder(border);
	}
	
	private Color fill;
	private Color SelectedColor;
	private Color BorderColor;
	

	public Color getBorderColor() {
		return BorderColor;
	}
	public void setBorderColor(Color borderColor) {
		BorderColor = borderColor;
	}
	public Color getFill() {
		return fill;
	}
	public void setFill(Color fill) {
		this.fill = fill;
		setBackground(fill);
	}
	public Color getSelectedColor() {
		return SelectedColor;
	}
	public void setSelectedColor(Color selectedColor) {
		SelectedColor = selectedColor;
	}

	

	@Override
	protected void paintComponent(Graphics g) { 
		 Graphics2D g2d = (Graphics2D) g;
		 
		 g2d.setColor(fill);
		 g2d.fillRoundRect(0, 0, getWidth(), getHeight(), 0, 0);
		 g2d.setColor(getBackground());
		 setBorderColor(BorderColor);
		 
		 super.paintComponent(g);
		 
	}
	
}
