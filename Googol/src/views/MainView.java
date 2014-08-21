package views;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;

import player.Player;
import board.Board;
import board.Move;
import board.Piece;
import board.Position;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.SWT;
import swing2swt.layout.BorderLayout;

import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.widgets.Label;
import org.eclipse.wb.swt.SWTResourceManager;
import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.events.MouseListener;
import org.eclipse.swt.events.PaintEvent;
import org.eclipse.swt.events.PaintListener;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.graphics.Image;
import org.eclipse.swt.graphics.ImageData;
import org.eclipse.swt.graphics.Point;
import org.eclipse.swt.widgets.Button;

public class MainView {


	private static Player currentPlayer = null;
	private static Board board = new Board();

	public static void main(String[] args) {
		Display display = new Display();
		Shell mainShell = new Shell(display);

		//TODO Neue, bessere Bilder finden.
		// Alle Bilder, die verwendet werden initialisieren
		final Image image_board = new Image(display, new ImageData("images/board.png"));
		final Image image_pawnWhite = new Image(display, new ImageData("images/pawn_white.png"));
		final Image image_pawnBlack = new Image(display, new ImageData("images/pawn_black.png"));
		final Image image_kingWhite = new Image(display, new ImageData("images/king_white.png"));
		final Image image_kingBlack = new Image(display, new ImageData("images/king_black.png"));


		//TODO Get player names via input?
		//Man könnte das doch mit nem JOptionPane machen oder?
		String nameWhite = "Name white";
		String nameBlack = "Name black";

		//Create 2 players
		final Player playerWhite = new Player(Player.WHITE, nameWhite);
		final Player playerBlack = new Player(Player.BLACK, nameBlack);

		System.out.println();
		System.out.println();
		// Wie sieht das Board nun aus?
		board.printBoard();

		// View erstellen

		mainShell.setImage(SWTResourceManager.getImage("images/board.png")); //Kleines icon in der Taskleiste
		mainShell.setMinimumSize(new Point(800, 700));
		mainShell.setText("CHECKERS");
		mainShell.setSize(1000, 800);
		mainShell.setLayout(new FillLayout(SWT.HORIZONTAL));

		final Composite composite = new Composite(mainShell, SWT.NONE);
		composite.setLayout(new BorderLayout(0, 0));

		final Composite eastComp = new Composite(composite, SWT.NONE);
		eastComp.setLayoutData(BorderLayout.EAST);
		eastComp.setLayout(new FillLayout(SWT.VERTICAL));

		final Composite westComp = new Composite(composite, SWT.NONE);
		westComp.setLayoutData(BorderLayout.WEST);
		westComp.setLayout(new FillLayout(SWT.VERTICAL));


		final Composite centerComp = new Composite(composite, SWT.NONE);
		centerComp.setLayoutData(BorderLayout.CENTER);
		centerComp.setLayout(new FillLayout(SWT.HORIZONTAL));


		// Weißen Bauer/König auf die östliche Seite
		Label image_pawnWhiteLabel = new Label(eastComp, SWT.NONE);
		Label image_kingWhiteLabel = new Label(eastComp, SWT.NONE);
		image_pawnWhiteLabel.setImage(image_pawnWhite);
		image_kingWhiteLabel.setImage(image_kingWhite);

		// Schwarzen Bauer/König auf die westliche Seite
		Label image_pawnBlackLabel = new Label(westComp, SWT.NONE);
		Label image_kingBlackLabel = new Label(westComp, SWT.NONE);
		image_pawnBlackLabel.setImage(image_pawnBlack);
		image_kingBlackLabel.setImage(image_kingBlack);


		//MouseListener für das Spielfeld. Registriert die Maustasten. Hiermit soll man später das Spiel spielen.
		centerComp.addMouseListener(new MouseListener() {

			@Override
			public void mouseUp(MouseEvent arg0) {
			}

			@Override
			public void mouseDown(MouseEvent event) {
				System.out.println("Button: " +event.button + " @" + event.x + " " + event.y +" pressed" );
				System.out.println("as");
				//TODO Ausrechnen, welches Feld von board geklickt wurde. Ähnlich wie die Berechnung wo die Figuren sind unten.
				/**
				 * Stein selektieren,
				 * Zielfeld selektieren,
				 * Stein bewegen,
				 * Übersprungen Steine löschen,
				 * Testen, ob man eine Dame bekommt,
				 * Spieler wechseln,
				 * LOOP
				 */
			}

			@Override
			public void mouseDoubleClick(MouseEvent arg0) {

			}
		});

		//Der PaintListener wird aufgerufen, wenn das Fenster neu gezeichnet werden muss. Das passiert z.b. bei einem ziehen des Fensters,
		//aber auch, wenn man centerComp.redraw() explizit aufruft.
		centerComp.addPaintListener(new PaintListener() {
			@Override
			public void paintControl(PaintEvent e) {
				e.gc.drawImage(image_board, 0, 0);
				//Aktuelles board holen für den redraw
				final Board pBoard = board;

				for (int i = 0; i< 8; i++){
					for (int j = 0; j < 8; j++){
						if (pBoard.getField(new Position(j, i))==Piece.DAME_BLACK){
							e.gc.drawImage(image_kingBlack, 40 + i*75, 42+j*75);
						}
						if (pBoard.getField(new Position(j, i))==Piece.PAWN_BLACK){
							e.gc.drawImage(image_pawnBlack, 40 + i*75, 42+j*75);
						}
						if (pBoard.getField(new Position(j, i))==Piece.DAME_WHITE){
							e.gc.drawImage(image_kingWhite, 40 + i*75, 42+j*75);
						}
						if (pBoard.getField(new Position(j, i))==Piece.PAWN_WHITE){
							e.gc.drawImage(image_pawnWhite, 40 + i*75, 42+j*75);
						}
					}
				}
			}
		});


		// Testbutton, mit dem man aktuell einen move machen kann
		Button btnNewButton = new Button(westComp, SWT.NONE);
		btnNewButton.setText("New Button");
		btnNewButton.addSelectionListener(new SelectionListener() {

			@Override
			public void widgetSelected(SelectionEvent arg0) {
				setCurrentPlayer(playerWhite);
				board.setMove(playerWhite, new Move(0, 0, 1, 0));
				centerComp.redraw();

			}

			@Override
			public void widgetDefaultSelected(SelectionEvent arg0) {
			}
		});



		//öffnet die Shell und lässt sie im "Leerlauf" bis man das Programm beendet.
		mainShell.open();
		while (!mainShell.isDisposed()) {
			if (!display.readAndDispatch())
				display.sleep();
		}
		display.dispose();
	}
	/**
	 * 
	 * @return Gibt den aktiven Spieler zurück
	 */
	public static Player getCurrentPlayer() {
		return currentPlayer;
	}

	/**
	 * Setzt den gerade aktiven Spieler: Weiß oder Schwarz
	 * @param currentPlayer der aktive Spieler
	 */
	public static void setCurrentPlayer(Player currentPlayer) {
		MainView.currentPlayer = currentPlayer;
	}

	public static Board getBoard () {
		return board;
	}
}
