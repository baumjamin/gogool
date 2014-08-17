/**
 * KI-Class 
 * @file randKI.hh
 * @author GogolINC
 * @date 21.05.2007
 */

#ifndef KI_h_
#define KI_h_

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Player.hh"
#include "Board.hh"

class KI : public Player	{
public:
	/** Konstruktor für die KI, 
	 * wobei die Farbe der KI festgelegt werden und eine Referenz auf das Board übergeben weden muss.
	 *
	 * \param myColor Color of the player's tokens. Default is white.
	 */
	KI(char myColor, const Board &setBoard);
	
	/** Methode um den König zu Beginn des Spiels zu setzen 
	 *
	 * \return Move. Muss vom Caller wieder gelöscht werden.
	 */
	Move *setKing();
	
	/** Methode um die Züge zu setzen 
	 *
	 * \return Move. Muss vom Caller wieder gelöscht werden.
	 */
	Move *getMove();
	
protected:
	const Board &board;

private:
	char fromX;
	char toX;
	int fromY;
	int toY;
};

#endif /*KI_h_*/
