package ai;

import java.util.HashSet;
import java.util.Iterator;

import player.Player;
import board.Board;
import board.Move;
import board.Piece;
import board.Position;

public class AI {

	public static final int RANDOM = -1;
	public static final int EASY = 0;
	public static final int MEDIUM = 1;
	public static final int HARD = 2;

	public static final int PAWN_VALUE = 100;
	public static final int DAME_VALUE = 300;

	private Move bestMove = null;
	private int bestValue = -1;
	private int iterationsLeft = 4;

	private int difficulty = 0;
	private int color;
	private int currentColor;
	private Player player;

	private Piece currentPawn;
	private Piece currentDame;
	private Piece enemyPawn;
	private Piece enemyDame;



	public AI(Player player, int difficulty) {
		this(player);
		this.difficulty = difficulty;
		System.out.println("Difficulty = " + this.difficulty);
	}

	public AI(Player player) {
		this.color = player.getColor();
		this.player = player;
		if (color == Player.WHITE){
			this.currentPawn = Piece.PAWN_WHITE;
			this.currentDame = Piece.DAME_WHITE;

			this.enemyPawn = Piece.PAWN_BLACK;
			this.enemyDame = Piece.DAME_BLACK;
		}
		else {
			this.currentPawn = Piece.PAWN_BLACK;
			this.currentDame = Piece.DAME_BLACK;

			this.enemyPawn = Piece.PAWN_WHITE;
			this.enemyDame = Piece.DAME_WHITE;
		}
		System.out.println("Color: " + (color==Player.BLACK?"Black":"White"));
	}

	public int getBestMove(Board board, int color){
		HashSet<Move> possibleMoves = getPossibleMoves(board);
		System.out.println("@GetBestMoves All Moves:" );
		System.out.println(possibleMoves.toString());

		Board testBoard = new Board(board);
		Iterator<Move> possibleMovesIterator = possibleMoves.iterator();
		while (possibleMovesIterator.hasNext()){
			testBoard = new Board(board);
			Move next = possibleMovesIterator.next();
			System.out.println("NEXT: " + next.toString() + " -- " + board.getBoard()[next.getFromX()][next.getFromY()].getPieceName());
			testBoard.setMove(this.player,next);
			int value = test(testBoard,changeColor(color),3);
			System.out.println(value);



			int currentValue = value;
			if (bestValue < currentValue){
				bestValue = currentValue;
				bestMove = next;
			}

		}
		return evaluateBoard(testBoard); 
	}

	private int test(Board board, int color, int iterations){
		System.out.println("@test " + iterations);
		HashSet<Move> possibleMoves = getPossibleMoves(board);
		Iterator<Move> possibleMovesIterator = possibleMoves.iterator();
		Board testBoard;
		while (possibleMovesIterator.hasNext() && iterations>0){
			System.out.println("while " + iterations);
			Move next = possibleMovesIterator.next();
			testBoard = new Board(board);
			testBoard.setMove(player, next);
			
			test(testBoard,changeColor(color),iterations);
			
			iterations--;
			
		}
		return evaluateBoard(board);
	}

	private int changeColor(int oldColor){

		switch (oldColor) {
		case Player.WHITE:
			return Player.BLACK;
		case Player.BLACK:
			return Player.WHITE;
		default:
			return -1;
		}
	}

	public HashSet<Move> getPossibleMoves(Board board){
		HashSet<Position> positions = new HashSet<Position>();

		for (int i = 0; i< 8; i++){ 
			for (int j = 0; j < 8; j++){
				if (board.getBoard()[i][j].equals(this.currentPawn)){
					positions.add(new Position(i, j));
				}
				else if (board.getBoard()[i][j].equals(this.currentDame)){
					positions.add(new Position(i, j));
				}
			}
		}
		//System.out.println("POSITIONS: " +positions.toString());
		Iterator<Position> pawnsIt = positions.iterator();
		HashSet<Move> possibleMoves = new HashSet<Move>();
		while(pawnsIt.hasNext()){
			Position next = pawnsIt.next();
			//			System.out.println("NEXT: " + next);

			possibleMoves.addAll(next.getPossibleMoves(color, board));
			//			System.out.println("possiblemove: " + possibleMoves.toString());
		}


		return possibleMoves;
	}

	public int evaluateBoard(Board board){
		int value = 0;
		for (int i = 0; i< 8; i++){ 
			for (int j = 0; j < 8; j++){
				if (board.getBoard()[i][j].equals(this.currentPawn)){
					value+=PAWN_VALUE;
				}
				else if (board.getBoard()[i][j].equals(this.currentDame)){
					value+=DAME_VALUE;
				}
				else if (board.getBoard()[i][j].equals(this.enemyPawn)){
					value-=PAWN_VALUE;
				}
				else if (board.getBoard()[i][j].equals(this.enemyDame)){
					value-=DAME_VALUE;
				}
			}
		}
		System.out.println("BOARD VALUE: "  + value);

		return value;
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



	public Move getMove(Board board){
		Board testBoard = new Board(board);

		switch (this.difficulty) {
		case RANDOM: 
			return getRandomMove(testBoard);
		case EASY:
			return getWorstMove(testBoard);
		case MEDIUM:
			return getAverageMove(testBoard);
		case HARD:
			currentColor = this.color;
			getBestMove(testBoard, this.color);
			return this.bestMove;
		}
		return null;

	}


	private Move getRandomMove(Board board) {

		HashSet<Move> possibleMoves = getPossibleMoves(board);

		int rand = randBetween(0, possibleMoves.size());
		Iterator<Move> possibleMovesIt = possibleMoves.iterator();
		Move selectedMove = null;
		int counter = 0;
		while(possibleMovesIt.hasNext() && counter < rand){
			selectedMove = possibleMovesIt.next();
			counter++;
		}
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


	public Move getWorstMove(Board board){
		return new Move(-1,-1,-1,-1);
	}

	public Move getAverageMove(Board board){
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
