/**
 * Humanplayer-Class 
 * @file Humanplayer.hh
 * @author GogolINC
 * @date 17.05.2007
 */

#ifndef Humanplayer_h_
#define Humanplayer_h_

#include <iostream>
#include "Player.hh"
#include "Board.hh"
#include "Graphicobserver.hh"
#include <SDL/SDL.h>

class Humanplayer : public Player	{
public:
	/** Konstruktor f�r den Humanplayer, 
	 * wobei die Farbe des Hp festgelegt werden und eine Referenz auf das Board �bergeben weden muss.
	 *
	 * \param myColor Color of the player's tokens. Default is white.
	 */
	Humanplayer(char myColor, const Board &setBoard, Graphicobserver &setOutput);
	
	/** Methode um den K�nig zu Beginn des Spiels zu setzen 
	 *
	 * \return Move. Muss vom Caller wieder gel�scht werden.
	 */
	Move *setKing();
	
	/** Methode um die Z�ge vom Humanplayer entgegenzunehmen 
	 *
	 * \return Move. Muss vom Caller wieder gel�scht werden.
	 */
	Move *getMove();
	
protected:
	const Board &board;
	Graphicobserver &output;

private:
	char fromX;
	char toX;
	int fromY;
	int toY;
        bool done;
        char fX, tX;
        int fY,tY, foX;
        int mouseX, mouseY;
};

#endif /*Humanplayer_h_*/
