package ai;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import player.Player;
import board.Board;
import board.Piece;

public class AITest {

	@Before
	public void setUp() throws Exception {
	}

	@Test
	public void testGetMove() {

		Board board = new Board();
		
		board.getBoard()[3][1] = Piece.DAME_WHITE;
		board.getBoard()[5][5] = Piece.DAME_BLACK;
		board.printBoard();
		
		
		Player aiPlayer = new Player(Player.KI, "KI");
		AI ai = new AI(Player.WHITE,AI.RANDOM);

		assertTrue(ai.getColor()==Player.WHITE);
		assertTrue(ai.getDifficulty() == AI.RANDOM);
		assertTrue(ai.getCurrentDame() == Piece.DAME_WHITE);
		assertTrue(ai.getCurrentPawn() == Piece.PAWN_WHITE);
//		assertTrue(move.equals(ai.getMove(board.getBoard(), aiPlayer)));
		ai.getMove(board.getBoard(), aiPlayer);
		
		
		
		System.out.println();
		System.out.println();
		aiPlayer = new Player(Player.KI, "KI");
		ai = new AI(Player.BLACK,AI.RANDOM);
		

		assertTrue(ai.getColor()==Player.BLACK);
		assertTrue(ai.getDifficulty() == AI.RANDOM);
		assertTrue(ai.getCurrentDame() == Piece.DAME_BLACK);
		assertTrue(ai.getCurrentPawn() == Piece.PAWN_BLACK);
//		assertTrue(move.equals(ai.getMove(board.getBoard(), aiPlayer)));
		ai.getMove(board.getBoard(), aiPlayer);
		
		
		
	}

//	@Test
//	public void testGetWorstMove() {
//		fail("Not yet implemented");
//	}

//	@Test
//	public void testGetAverageMove() {
//		fail("Not yet implemented");
//	}
//
//	@Test
//	public void testGetBestMove() {
//		fail("Not yet implemented");
//	}

}
