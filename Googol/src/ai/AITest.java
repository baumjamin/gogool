package ai;

import static org.junit.Assert.*;

import java.util.HashSet;
import java.util.Iterator;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import player.Player;
import views.MainView;
import board.Board;
import board.Move;
import board.Piece;

public class AITest {

	@Before
	public void setUp() throws Exception {

	}

	@Test
	public void testGetPossibleMoves(){
		System.out.println("@testGetPossibleMoves@testGetPossibleMoves@testGetPossibleMoves@testGetPossibleMoves");
		Board board = new Board(true);

		board.getBoard()[1][3] = Piece.PAWN_WHITE;
		board.getBoard()[2][4] = Piece.PAWN_BLACK;
		board.getBoard()[2][2] = Piece.PAWN_BLACK;
		
		board.getBoard()[4][4] = Piece.PAWN_WHITE;
		
		
		board.printBoard();
		

		Player player = new Player(Player.WHITE, "KI");
		AI ai = new AI(player,AI.RANDOM);
		MainView.setCurrentPlayer(player);
		assertTrue(ai.getColor()==Player.WHITE);
		assertTrue(ai.getDifficulty() == AI.RANDOM);
		assertTrue(ai.getCurrentDame() == Piece.DAME_WHITE);
		assertTrue(ai.getCurrentPawn() == Piece.PAWN_WHITE);
		HashSet<Move> moves = ai.getPossibleMoves(board);
		assertTrue(moves.size()==4);
		System.out.println(moves);
		
		
		Iterator<Move> movesIt = moves.iterator();
		while(movesIt.hasNext()){
			Board testBoard = new Board(board);
			Move next = movesIt.next();
			System.out.println("NEXT MOVE" + next.toString());
			testBoard.setMove(player, next);
//			testBoard.printBoard();
		}
	System.out.println();
	System.out.println("BLACK");
System.out.println();
	player = new Player(Player.BLACK, "KI");
		ai = new AI(player,AI.RANDOM);
		MainView.setCurrentPlayer(player);
		assertTrue(ai.getColor()==Player.BLACK);
		assertTrue(ai.getDifficulty() == AI.RANDOM);
		assertTrue(ai.getCurrentDame() == Piece.DAME_BLACK);
		assertTrue(ai.getCurrentPawn() == Piece.PAWN_BLACK);
		moves = ai.getPossibleMoves(board);
//		assertTrue(moves.size()==4);
		System.out.println(moves);
		
		
		movesIt = moves.iterator();
		while(movesIt.hasNext()){
			Board testBoard = new Board(board);
			Move next = movesIt.next();
			System.out.println("NEXT MOVE" + next.toString());
			testBoard.setMove(player, next);
			testBoard.printBoard();
		}
		
		
		
		System.out.println("@testGetPossibleMoves@testGetPossibleMoves@testGetPossibleMoves@testGetPossibleMoves");
	}

	@Test
	public void testEvaluateBoard() throws Exception {
		System.out.println("@testEvaluateBoard@testEvaluateBoard@testEvaluateBoard@testEvaluateBoard");
		Board board = new Board();
		Player player = new Player(Player.WHITE, "KI");

		AI ai = new AI(player,AI.RANDOM);

		//nichts passiert, board ist gleichwertig
		assertTrue(ai.evaluateBoard(board)==0);

		//weiﬂ bekommt dame, also +300
		board.getBoard()[3][1] = Piece.DAME_WHITE; //+300
		assertTrue(ai.evaluateBoard(board)==300);

		//schwarz bekommt dame, also -300 (insgs == 0)
		board.getBoard()[5][5] = Piece.DAME_BLACK; //-300
		assertTrue(ai.evaluateBoard(board)==0);

		//weiﬂ verliert dame, also -300
		board.getBoard()[3][1] = Piece.FREE;
		assertTrue(ai.evaluateBoard(board)==-300);
		System.out.println("@testEvaluateBoard@testEvaluateBoard@testEvaluateBoard@testEvaluateBoard");
	}

	@Test
	public void testGetMove() {
		System.out.println("@testGetMove@testGetMove@testGetMove@testGetMove");
		Board board = new Board();

		board.getBoard()[3][1] = Piece.DAME_WHITE;
		board.getBoard()[5][5] = Piece.DAME_BLACK;
		board.getBoard()[2][4] = Piece.PAWN_BLACK;
		
		board.printBoard();
		
		

		Player player = new Player(Player.WHITE, "KI");
		AI ai = new AI(player,AI.RANDOM);
		MainView.setCurrentPlayer(player);
		assertTrue(ai.getColor()==Player.WHITE);
		assertTrue(ai.getDifficulty() == AI.RANDOM);
		assertTrue(ai.getCurrentDame() == Piece.DAME_WHITE);
		assertTrue(ai.getCurrentPawn() == Piece.PAWN_WHITE);
		//		assertTrue(move.equals(ai.getMove(board.getBoard(), aiPlayer)));
		ai.getMove(board);



		System.out.println();
		System.out.println();
		player = new Player(Player.BLACK, "KI");
		ai = new AI(player,AI.RANDOM);


		assertTrue(ai.getColor()==Player.BLACK);
		assertTrue(ai.getDifficulty() == AI.RANDOM);
		assertTrue(ai.getCurrentDame() == Piece.DAME_BLACK);
		assertTrue(ai.getCurrentPawn() == Piece.PAWN_BLACK);
		//		assertTrue(move.equals(ai.getMove(board.getBoard(), aiPlayer)));
		ai.getMove(board);
		System.out.println("@testGetMove@testGetMove@testGetMove@testGetMove");
	}

	@Test
	@After
	public void testGetBestMoves() throws Exception {
		//		System.out.println("------------");
		//		Board board = new Board();
		//		Player player = new Player(Player.WHITE, "KI");
		//		AI ai = new AI(player,AI.HARD);
		//		MainView.setCurrentPlayer(player);
		//		System.out.println("END: " + ai.getMove(board));
		//		
		//		
		//		
		//		System.out.println("------------");
	}
}
