package board;

import player.Player;

/**
 * Klasse Board
 *
 * @author Benny
 *
 */
public class Board {

	private Position kingWhite = new Position(-1,-1);
	private Position kingBlack = new Position(-1,-1);

	public Position getKingWhite() {
		return kingWhite;
	}

	public void setKingWhite(Position kingWhite) {
		this.kingWhite = kingWhite;
	}

	public Position getKingBlack() {
		return kingBlack;
	}

	public void setKingBlack(Position kingBlack) {
		this.kingBlack = kingBlack;
	}

	//Baut das Feld auf
	Piece[][] board = new Piece[8][8];
	public Board() {
		for (int i = 0; i< 8; i++){
			for (int j = 0; j < 8; j++){
				board[i][j] = Piece.FREE;
			}
		}
		for (int i = 0; i < 8 ; i++){
			board[0][i] = Piece.PAWN_WHITE;
			board[7][i] = Piece.PAWN_BLACK;
		}


		System.out.println("Creating Board:");
	}

	public boolean setKing(Player player, Position pos){
		//TODO VALID?
		if (board[pos.getX()][pos.getY()] == Piece.FREE){
			board[pos.getX()][pos.getY()] = player.getColor()==Player.WHITE?Piece.KING_WHITE:Piece.KING_BLACK;
			if (player.getColor()==Player.WHITE)
				setKingWhite(pos);
			else if (player.getColor()==Player.BLACK)
				setKingBlack(pos);
			return true;
		}
		else {
			System.err.println("ERROR: Set King");
			return false;
		}
	}

	public boolean isMoveValid(Move move){
		//TODO When is a move valid? Is there a correct piece at the position?
		return true;
	}

	public boolean setMove(Move move){
		if (isMoveValid(move)){
			System.out.println(move.toString());
			//TODO Actually do the move
			Piece selectedPiece = board[move.getFromX()][move.getFromY()];
			System.out.println(selectedPiece.getPiece() + " " + selectedPiece.getPieceName());
			board[move.getFromX()][move.getFromY()] = Piece.FREE;
			board[move.getToX()][move.getToY()] = selectedPiece;
			printBoard();
			return true;
		}
		else
			return false;
	}

	public Piece getField (Position pos){
		return board[pos.getX()][pos.getY()];
	}

	public void printBoard() {
		System.out.print("\t");
		for (int i = 0; i< 8; i++){
			if (i == 0)
				System.out.print(i + " \t");
			else
				System.out.print(i + "\t");

		}
		System.out.println();
		System.out.println("   ---------------------------------------------------------");
		for (int i = 0; i< 8; i++){

			for (int j = 0; j < 8; j++){
				if (j == 0)
					System.out.print(i +" |\t");
				System.out.print(board[i][j].getPieceName() + "\t");
			}
			System.out.println();
		}
	}

}