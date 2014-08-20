package player;

import board.Position;
/**
 * Klasse Player, Weiﬂ == 0, Schwarz == 1, KI == 3
 * @author Benny
 * 
 */
public class Player {
	
	public final static int WHITE = 0;
	public final static int BLACK = 1;
	public final static int KI = 2;
	
	private int color;
	
	
	public int getColor() {
		return color;
	}

	public void setColor(int color) {
		this.color = color;
	}

	private String name;
	private Position king;
	
	/**
	 * 
	 * @param color Farbe des Spielers
	 * @param name Name des Spielers
	 */
	public Player(int color, String name) {
		
		this.color = color;
		this.name = name;
//		System.out.println("Creating " + this.getName() + " as " + this.getColorName());
	}

	private String getName(){
		return this.name;
	}
	
	public void setKingPosition(Position pos){
		this.king = pos;
	}
	
	public Position getKingPosition(){
		return this.king;
	}
	
	/**
	 * 
	 * @return Der Name der Farbe (White/Black)
	 */
	private String getColorName(){
		
		switch (this.color) {
		case 0:
			return "White";
		case 1:
			return "Black";
		default:
			return "WRONG COLOR";
		}
	}
}
