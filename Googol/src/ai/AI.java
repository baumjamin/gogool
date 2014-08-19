package ai;

import java.util.HashSet;
import java.util.Iterator;

import player.Player;
import board.Move;
import board.Piece;
import board.Position;

public class AI {

	public static final int RANDOM = -1;
	public static final int EASY = 0;
	public static final int MEDIUM = 1;
	public static final int HARD = 2;

	private int difficulty = 0;
	private int color;
	private Piece currentPawn;
	private Piece currentDame;

	public AI(int color, int difficulty) {
		this(color);
		this.difficulty = difficulty;
		System.out.println("Difficulty = " + this.difficulty);

	}
	public AI(int color) {
		this.color = color;
		if (color == Player.WHITE){
			this.currentPawn = Piece.PAWN_WHITE;
			this.currentDame = Piece.DAME_WHITE;
		}
		else {
			this.currentPawn = Piece.PAWN_BLACK;
			this.currentDame = Piece.DAME_BLACK;
		}


		System.out.println("Color: " + (color==Player.BLACK?"Black":"White"));
	}

	public int getDifficulty() {
		return difficulty;
	}

	public void setDifficulty(int difficulty) {
		this.difficulty = difficulty;
	}

	public int getColor() {
		return color;
	}

	public void setColor(int color) {
		this.color = color;
	}



	public Move getMove(Piece board [][], Player player){

		switch (this.difficulty) {
		case RANDOM: 
			return getRandomMove(board);
		case EASY:
			return getWorstMove(board);
		case MEDIUM:
			return getAverageMove(board);
		case HARD:
			return getBestMove(board);
		}
		return null;

	}


	private Move getRandomMove(Piece board [][]) {

		HashSet<Position> pawnPositions = new HashSet<Position>();

		for (int i = 0; i< 8; i++){ 
			for (int j = 0; j < 8; j++){
				if (board[i][j].equals(this.currentPawn)){
					pawnPositions.add(new Position(i, j));
				}
				else if (board[i][j].equals(this.currentDame)){
					pawnPositions.add(new Position(i, j));
				}
			}
		}

		Iterator<Position> pawnsIt = pawnPositions.iterator();
		HashSet<Move> possibleMoves = new HashSet<Move>();
		while(pawnsIt.hasNext()){
			possibleMoves.addAll(pawnsIt.next().getPossibleMoves(color, board));
		}

		int rand = randBetween(0, possibleMoves.size());

		Iterator<Move> possibleMovesIt = possibleMoves.iterator();
		//		System.out.println("POSSIBLE MOVES");
		//		System.out.println(possibleMoves.toString());
		Move selectedMove = null;
		int counter = 0;
		while(possibleMovesIt.hasNext() && counter < rand){
			selectedMove = possibleMovesIt.next();
			counter++;
		}
		System.out.println("MOVING @ RANDOM: " + selectedMove);
		return selectedMove;
	}


	/**
	 * @param positions Alle Positionen
	 * @return eine zufällige Position aller Positionen
	 */
	@Deprecated
	public Position getRandomPiecePosition(HashSet<Position> positions) {
		int i = randBetween(0, positions.size());
		Iterator<Position> posIt = positions.iterator();
		Position pos = null;
		while(posIt.hasNext() && i >= 0){
			i--;
			pos = posIt.next();
		}
		return pos;

	}


	public Move getWorstMove(Piece board [][]){
		return new Move(-1,-1,-1,-1);
	}

	public Move getAverageMove(Piece board [][]){
		return new Move(-1,-1,-1,-1);
	}

	public Move getBestMove(Piece board [][]){

		return new Move(-1,-1,-1,-1);
	}
	public Piece getCurrentPawn() {
		return currentPawn;
	}
	public void setCurrentPawn(Piece currentPawn) {
		this.currentPawn = currentPawn;
	}
	public Piece getCurrentDame() {
		return currentDame;
	}
	public void setCurrentDame(Piece currentDame) {
		this.currentDame = currentDame;
	}
	private int randBetween(int start, int end) {
		return start + (int)Math.round(Math.random() * (end - start));
	}

}
