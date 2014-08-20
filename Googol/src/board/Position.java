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


	/**
	 * 
	 * @param color Farbe des Spielers
	 * @param board.getBoard() Das aktuelle Spielfeld
	 * @return Liefert eine Liste als HashSet<Move> mit allen möglichen Zügen des Spielers
	 */
	public HashSet<Move> getPossibleMoves(int color, Board board){

		HashSet<Move> moves = new HashSet<Move>();
		if (color == Player.WHITE){
			//Weiß spielt von oben nach unten

			if (board.getBoard()[this.getX()][this.getY()]==Piece.PAWN_WHITE){
				Position next = new Position(this.getX()+1, this.getY()+1);
				//			System.out.println("new pos: " + next.toString() + " " + next.isPositionValid());
				if (next.isPositionValid() && !next.isPositionOccupied(board.getBoard(),next)){
					moves.add(new Move(this, next));
				}
				else if (next.isPositionValid() && next.isPositionOccupied(board.getBoard(),next)){
					//Springen
					if (board.getBoard()[next.getX()][next.getY()]==Piece.PAWN_BLACK || board.getBoard()[next.getX()][next.getY()]==Piece.DAME_BLACK)
					{
						System.out.println("JUMPING PAWN");
						next = new Position(this.getX()+2, this.getY()+2);
						if (next.isPositionValid() && !next.isPositionOccupied(board.getBoard(),next)){
							moves.add(new Move(this,next));
						}
					}
				}

				next = new Position(this.getX()+1, this.getY()-1);
				//			System.out.println("new pos: " + next.toString() + " " + next.isPositionValid());
				if (next.isPositionValid() && !next.isPositionOccupied(board.getBoard(),next)){
					moves.add(new Move(this, next));
				}
				else if (next.isPositionValid() && next.isPositionOccupied(board.getBoard(),next)){
					//Springen
					if (board.getBoard()[next.getX()][next.getY()]==Piece.PAWN_BLACK || board.getBoard()[next.getX()][next.getY()]==Piece.DAME_BLACK)
					{
						System.out.println("JUMPING PAWN");
						next = new Position(this.getX()+2, this.getY()-2);
						if (next.isPositionValid() && !next.isPositionOccupied(board.getBoard(),next)){
							moves.add(new Move(this,next));
						}
					}
				}
				
			}
			else if (board.getBoard()[this.getX()][this.getY()]==Piece.DAME_WHITE){

				//Teste alle möglichen Züge				
				int counter = 1;
				while (counter < 10){
					Position next = new Position(this.getX()+1*counter, this.getY()+1*counter);
					if (next.isPositionValid() && !next.isPositionOccupied(board.getBoard(),next)){
						moves.add(new Move(this, next));
					}
					next = new Position(this.getX()+1*counter, this.getY()-1*counter);
					if (next.isPositionValid() && !next.isPositionOccupied(board.getBoard(),next)){
						moves.add(new Move(this, next));
					}
					counter++;
				}
			}

		}
		else {
			//Schwarz spielt von unten nach oben

			if (board.getBoard()[this.getX()][this.getY()]==Piece.PAWN_BLACK){
				Position next = new Position(this.getX()-1, this.getY()+1);
				if (next.isPositionValid() && !next.isPositionOccupied(board.getBoard(),next)){
					moves.add(new Move(this, next));
				}

				next = new Position(this.getX()-1, this.getY()-1);
				if (next.isPositionValid() && !next.isPositionOccupied(board.getBoard(),next)){
					moves.add(new Move(this, next));
				}
			}
			else if (board.getBoard()[this.getX()][this.getY()]==Piece.DAME_BLACK){

				//Teste alle möglichen Züge
				int counter = 1;
				while (counter < 10){
					Position next = new Position(this.getX()-1*counter, this.getY()+1*counter);
					if (next.isPositionValid() && !next.isPositionOccupied(board.getBoard(),next)){
						moves.add(new Move(this, next));
					}
					next = new Position(this.getX()-1*counter, this.getY()-1*counter);
					if (next.isPositionValid() && !next.isPositionOccupied(board.getBoard(),next)){
						moves.add(new Move(this, next));
					}
					counter++;
				}
			}
		}
		return moves;
	}


	/**
	 * 
	 * @param board Das aktuelle Spielfeld
	 * @param position Die zu prüfende Position
	 * @return True, wenn die gewünschte Position bereits belegt ist, sonst false.
	 */
	private boolean isPositionOccupied(Piece[][] board, Position position) {
		if (board[position.getX()][position.getY()] == Piece.FREE)
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
