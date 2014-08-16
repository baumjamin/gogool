package board;


/**
 * Piece hat alle 5 m�glichen Figuren
 * FREE: Feld ist leer
 * PAWN_WHITE: Wei�er Bauer
 * PAWN_BLACK: Schwarzer Bauer
 * KING_WHITE: Wei�er K�nig
 * KING_BLACK: Schwarzer K�nig
 * @author Benny
 */
public class Piece {
	public static Piece FREE = new Piece (-1);
	public static Piece PAWN_WHITE = new Piece (0);
	public static Piece PAWN_BLACK = new Piece (1);
	public static Piece KING_WHITE = new Piece (2);
	public static Piece KING_BLACK = new Piece (3);

	private int piece;
	
	public int getPiece() {
		return piece;
	}
	public void setPiece(int piece) {
		this.piece = piece;
	}


/**
 * 
 * @param piece Integer der Figur
 * FREE: Feld ist leer == -1
 * PAWN_WHITE: Wei�er Bauer == 0
 * PAWN_BLACK: Schwarzer Bauer == 1
 * KING_WHITE: Wei�er K�nig == 2
 * KING_BLACK: Schwarzer K�nig ==3
 */
	public Piece(int piece) {
		this.piece = piece;
	}


/**
 * 
 * @return Die Bezeichnung des Feldes f�r die Darstellung des Arrays:
 * F, PB, KB, PW, KW
 */
	public String getPieceName(){
		switch (getPiece()) {
		case -1:
			return "F"; 
		case 0:
			return "PW"; 
		case 1:
			return "PB"; 

		case 2:
			return "KW"; 
		case 3:
			return "KB"; 
		default:
			return "?";
		}
	}

}
