package board;

/**
 * Klasse Position
 * @author Benny
 *
 */
public class Position {
	private int x;
	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	private int y;
	
	
	
	/**
	 * 
	 * @param x x-Wert der Position
	 * @param y y-Wert der Position
	 */
	public Position(int x, int y) {
		this.x = x;
		this.y = y;
		}
	
	/**
	 * 
	 * @return true wenn die Position innerhalb des Feldes ist, sonst false
	 */
	@SuppressWarnings("unused")
	private boolean isPositionValid(){
		return (0<this.x && this.x<8)&&(this.y>0 && this.y < 8); 
	}
}
