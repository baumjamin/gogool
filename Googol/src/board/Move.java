package board;


/**
 * Klasse Move
 * @author Benny
 * 
 */
public class Move {

	int fromX, fromY, toX, toY;
	public int getFromX() {
		return fromX;
	}
	public void setFromX(int fromX) {
		this.fromX = fromX;
	}
	public int getFromY() {
		return fromY;
	}
	public void setFromY(int fromY) {
		this.fromY = fromY;
	}
	public int getToX() {
		return toX;
	}
	public void setToX(int toX) {
		this.toX = toX;
	}
	public int getToY() {
		return toY;
	}
	public void setToY(int toY) {
		this.toY = toY;
	}
	public Move(int fromX, int fromY, int toX, int toY) {
		this.fromX = fromX;
		this.fromY = fromY;
		this.toX = toX;
		this.toY = toY;
	}

	public Move(Position from, Position to) {
		this(from.getX(),from.getY(),to.getX(),to.getY());
	}

	public boolean equals(Move anotherMove) {

		return this.getFromX() == anotherMove.getFromX() && this.getFromY() == anotherMove.getFromY() && this.getToX() == anotherMove.getToX() && this.getToY() == anotherMove.getToY();
	}

	@Override
	public String toString() {
		return ("("+ fromX+","+fromY+")->("+toX+","+toY+")");
	}
}
