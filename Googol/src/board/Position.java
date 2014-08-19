package board;

import java.util.HashSet;

import player.Player;

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

	public HashSet<Move> getAcceptibleMoves(int color, Piece board [][]){

		HashSet<Move> moves = new HashSet<Move>();

		if (color == Player.WHITE){
			//Weiß spielt von oben nach unten

			if (board[this.getX()][this.getY()]==Piece.PAWN_WHITE){
				Position next = new Position(this.getX()+1, this.getY()+1);
				//			System.out.println("new pos: " + next.toString() + " " + next.isPositionValid());
				if (next.isPositionValid() && !next.isPositionOccupied(board,next)){
					moves.add(new Move(this, next));
				}

				next = new Position(this.getX()+1, this.getY()-1);
				//			System.out.println("new pos: " + next.toString() + " " + next.isPositionValid());
				if (next.isPositionValid() && !next.isPositionOccupied(board,next)){
					moves.add(new Move(this, next));
				}
			}
			else if (board[this.getX()][this.getY()]==Piece.DAME_WHITE){


				//Teste alle möglichen Züge				
				int counter = 1;
				while (counter < 10){
					Position next = new Position(this.getX()+1*counter, this.getY()+1*counter);
					if (next.isPositionValid() && !next.isPositionOccupied(board,next)){
						moves.add(new Move(this, next));
					}
					next = new Position(this.getX()+1*counter, this.getY()-1*counter);
					if (next.isPositionValid() && !next.isPositionOccupied(board,next)){
						moves.add(new Move(this, next));
					}
					counter++;
				}
			}

		}
		else {
			//Schwarz spielt von unten nach oben

			if (board[this.getX()][this.getY()]==Piece.PAWN_BLACK){
				Position next = new Position(this.getX()-1, this.getY()+1);
				if (next.isPositionValid() && !next.isPositionOccupied(board,next)){
					moves.add(new Move(this, next));
				}

				next = new Position(this.getX()-1, this.getY()-1);
				if (next.isPositionValid() && !next.isPositionOccupied(board,next)){
					moves.add(new Move(this, next));
				}
			}
			else if (board[this.getX()][this.getY()]==Piece.DAME_BLACK){

				//Teste alle möglichen Züge
				int counter = 1;
				while (counter < 10){
					Position next = new Position(this.getX()-1*counter, this.getY()+1*counter);
					if (next.isPositionValid() && !next.isPositionOccupied(board,next)){
						moves.add(new Move(this, next));
					}
					next = new Position(this.getX()-1*counter, this.getY()-1*counter);
					if (next.isPositionValid() && !next.isPositionOccupied(board,next)){
						moves.add(new Move(this, next));
					}
					counter++;
				}
			}
		}
		return moves;
	}

	private boolean isPositionOccupied(Piece[][] board, Position next) {
		if (board[next.getX()][next.getY()] == Piece.FREE)
			return false;
		else
			return true;
	}

	/**
	 * 
	 * @return true wenn die Position innerhalb des Feldes ist, sonst false
	 */
	public boolean isPositionValid(){
		return (0<=this.x && this.x<8)&&(this.y>=0 && this.y < 8); 
	}

	@Override
	public String toString() {
		return "("+this.getX()+","+this.getY()+")";
	}
}
