/**
* KI-Class 
 * @file KI.hh
 * @author GogolINC
 * @date 17.05.2007
 */

#ifndef KI_h_
#define KI_h_

#include <iostream>
#include "Position.hh"
#include "Player.hh"
#include "Board.hh"
#include "Move.hh"

class KI : public Player	{
public:
	/** Konstruktor fuer die KI, 
	* wobei die Farbe der KI festgelegt werden und eine Referenz auf das Board ¸bergeben weden muss.
	*
	* \param myColor Color of the player's tokens. Default is white.
	*/
	KI(char myColor, const Board &board);
	
	/** Methode um den Kˆnig zu Beginn des Spiels zu setzen 
	*
	* \return Move. Muss vom Caller wieder gelˆscht werden.
	*/
	Move *setKing();
	
	/** Methode um die Z¸ge vom Humanplayer entgegenzunehmen 
		*
		* \return Move. Muss vom Caller wieder gelˆscht werden.
		*/
	Move *getMove();
	
protected:
		const Board &board;
	
private:
	bool isSave(char mycolor, const Move &move, const Board &b);
	bool isSave(char mycolor, const Position &pos, const Board &b);
	Move* defendZwicky(char mycolor, const Board &b);
	Move* isWinPossible(char mycolor, const Board &b);
	Move* defendBaseline(char mycolor, const Board &b);
	Move* getKillMove(char mycolor, const Board &b);
	Move* zwicky(char mycolor, const Board &b);
	
	const Position* blackKing;
	const Position* whiteKing;
	const Position* otherKing;
	const Position* myKing;
  
	char otherColor;
	char fromX;
	char toX;
	int fromY;
	int toY;
};

#endif /*KI_h_*/


