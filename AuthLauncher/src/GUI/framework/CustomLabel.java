package GUI.framework;

import java.awt.Graphics;
import java.awt.*;
import javax.swing.JLabel;

import GUI.Gui;


public class CustomLabel extends JLabel{

	/**
	 * 
	 */
	private static final long serialVersionUID = 9175563536219806676L;

	public CustomLabel(String text) {
		setLabelColor(new Color(255,255,255));
		setForeground(LabelColor);
		setText(text);
		setFont(Gui.font);
	} 
	
	public Color getLabelColor() {
		return LabelColor;
	}

	public void setLabelColor(Color labelColor) {
		LabelColor = labelColor;
		setBackground(LabelColor);
	}

	private Color LabelColor;
	
	@Override
	protected void paintComponent(Graphics g) {
		Graphics2D g2 = (Graphics2D)g;
		g2.setColor(LabelColor);
		super.paintComponent(g);
	}
}
