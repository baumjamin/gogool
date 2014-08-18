package board;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import player.Player;
import views.MainView;

public class BoardTest {

	@Before
	public void setUp() throws Exception {
	}

	@Test
	public void testSetKingWhite() {
//		fail("Not yet implemented");
	}

	@Test
	public void testSetKingBlack() {
//		fail("Not yet implemented");
	}

	@Test
	public void testSetKing() {
//		fail("Not yet implemented");
	}

	@Test
	public void testIsMoveValid() {
		Board board = new Board();
		Player player = new Player(Player.WHITE, "Name");
		Player falsePlayer = new Player(Player.BLACK,"FalseName");
		MainView.setCurrentPlayer(player);
		assertFalse(board.isMoveValid(player, new Move(9,8,0,1)));
		assertFalse(board.isMoveValid(player, new Move(1,1,10,1)));
		assertFalse(board.isMoveValid(falsePlayer, new Move(2,4,3,1)));
		
		
		assertTrue(board.isMoveValid(player, new Move(0,0,0,1)));
		assertTrue(board.isMoveValid(player, new Move(2,4,3,1)));
	}

	@Test
	public void testSetMove() {
//		fail("Not yet implemented");
	}

}
