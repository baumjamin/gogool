package board;
// Test
import player.Player;
import views.MainView;

/**
 * Klasse Board
 *
 * @author Benny
 *
 */
public class Board {

	private Piece[][] board = new Piece[8][8];

	//Baut das Feld auf

	public Board() {
		/**
		 * i |  	j ->
		 *   v
		 */
		for (int i = 0; i< 8; i++){ 
			for (int j = 0; j < 8; j++){
				if (((i + j) % 2 == 0) && i < 2)
					board[i][j] = Piece.PAWN_WHITE;
				else if (((i + j) % 2 == 0) && i > 5)
					board[i][j] = Piece.PAWN_BLACK;
				else if ((i + j) % 2 == 1)
					board[i][j] = Piece.BLOCKED;
				else
					board[i][j] = Piece.FREE;
			}
		}

	}

	/**
	 * Copy Constructor
	 * @param board2
	 */
	public Board(Board board2) {
		for (int i = 0; i< 8; i++){ 
			for (int j = 0; j < 8; j++){
				board[i][j] = board2.getBoard()[i][j];
			}
		}

	}


	public Board(boolean isEmpty) {
		if (isEmpty){
			for (int i = 0; i< 8; i++){ 
				for (int j = 0; j < 8; j++){
					if ((i + j) % 2 == 1)
						board[i][j] = Piece.BLOCKED;
					else
						board[i][j] = Piece.FREE;
				}

			}
		}
		else {
			for (int i = 0; i< 8; i++){ 
				for (int j = 0; j < 8; j++){
					if (((i + j) % 2 == 0) && i < 2)
						board[i][j] = Piece.PAWN_WHITE;
					else if (((i + j) % 2 == 0) && i > 5)
						board[i][j] = Piece.PAWN_BLACK;
					else if ((i + j) % 2 == 1)
						board[i][j] = Piece.BLOCKED;
					else
						board[i][j] = Piece.FREE;
				}
			}
		}
	}

	public boolean isMoveValid(Player player, Move move){
		//TODO When is a move valid? Is there a correct piece at the position?

		if (MainView.getCurrentPlayer().equals(player)){
			if ((0<=move.getToX() && move.getToX()<8) && (move.getToY() >=0 && move.getToY() < 8) && (0<=move.getFromX() && move.getFromX()<8) && (move.getFromY() >=0 && move.getFromY() < 8))
				return true;
			else 
				return false;
		}
		else
			return false;
	}

	
	//TODO Testing!
	public boolean setMove(Player player, Move move){
		if (isMoveValid(player, move)){
			Piece selectedPiece = board[move.getFromX()][move.getFromY()];
			board[move.getFromX()][move.getFromY()] = Piece.FREE;
			if (selectedPiece == Piece.PAWN_WHITE || selectedPiece == Piece.PAWN_BLACK){
				int toX = move.getToX();
				int toY = move.getToY();
				int fromX = move.getFromX();
				int fromY = move.getFromY();
				int deltaX = fromX-toX;
				int deltaY = fromY-toY;
				int dx = fromX-deltaX/2;
				int dy = fromY-deltaY/2;
				System.out.println( "DELTA :" + dx + " " +  dy + " " + board[dx][dy].getPieceName() + " DELETED");
				board[dx][dy] = Piece.FREE;
			}
			board[move.getToX()][move.getToY()] = selectedPiece;
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
		System.out.println("   --------------------------------------------------------------");
		for (int i = 0; i< 8; i++){

			for (int j = 0; j < 8; j++){
				if (j == 0)
					System.out.print(i +" |\t");
				System.out.print(board[i][j].getPieceName() + "\t");
			}
			System.out.println();
		}
	}


	public Piece[][] getBoard() {
		return board;
	}


	public void setBoard(Piece[][] board) {
		this.board = board;
	}

}
