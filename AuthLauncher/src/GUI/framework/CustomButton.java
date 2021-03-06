package GUI.framework;

import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JButton;

import GUI.Gui;


public class CustomButton extends JButton{


	/**
	 * 
	 */
	private static final long serialVersionUID = 4427481589987851797L;

	public CustomButton(String title) {
		
		setText(title);
		setForeground(Color.WHITE);
		setColor(new Color (70, 70, 70));
		setColorOver(new Color(51, 51, 51));
		setColorClick(new Color(0, 0, 0));
		setBorderColor(new Color(0,0,0));
		setFont(Gui.font);
		
		setContentAreaFilled(false);
		setFocusPainted(false);
		setBorderPainted(false);
		
		addMouseListener(new MouseListener() {
			@Override
			public void mousePressed(MouseEvent e) {
				setBackground(colorClick);
			}
			@Override
			public void mouseReleased(MouseEvent e) {
				if(HoverOver) {
					setBackground(colorOver);
				}else {
					setBackground(color);
				}
			}
			@Override
			public void mouseEntered(MouseEvent e) {
				setBackground(colorOver);
				HoverOver = true;
			}
			@Override
			public void mouseExited(MouseEvent e) {
				setBackground(color);
				HoverOver = false;
			}
			@Override
			public void mouseClicked(MouseEvent e) {
				
			}
		});	
	}
	

	private boolean HoverOver;
	private Color color;
	private Color colorOver;
	private Color colorClick;
	private Color borderColor;
	private int raidius = 0;
	
	public boolean isHoverOver() {
		return HoverOver;
	}
	public void setHoverOver(boolean hoverOver) {
		HoverOver = hoverOver;
	}
	public Color getColor() {
		return color;
	}
	public void setColor(Color color) {
		this.color = color;
		setBackground(color);
	}
	public Color getColorOver() {
		return colorOver;
	}
	public void setColorOver(Color colorOver) {
		this.colorOver = colorOver;
	}
	public Color getColorClick() {
		return colorClick;
	}
	public void setColorClick(Color colorClick) {
		this.colorClick = colorClick;
	}
	public int getRaidius() {
		return raidius;
	}
	public void setRaidius(int raidius) {
		this.raidius = raidius;
	}
	public Color getBorderColor() {
		return borderColor;
	}
	public void setBorderColor(Color borderColor) {
		this.borderColor = borderColor;
	}
	
	
	@Override
	protected void paintComponent(Graphics g) {
		Graphics2D g2 = (Graphics2D) g;
		
		g2.setColor(borderColor);
		g2.fillRoundRect(0,0,getWidth(),getHeight(), raidius, raidius);
		g2.setColor(getBackground());
		g2.fillRoundRect(2,2, getWidth() - 4, getHeight() - 4, raidius, raidius);
		
		super.paintComponent(g);
		
	}
	
}
