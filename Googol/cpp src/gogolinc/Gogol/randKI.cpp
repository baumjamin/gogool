/**
 * Implementation of the class KI. 
 * @see randKI
 * @file randKI.cpp
 * @author GogolINC
 * @date 21.05.2007
 */

#include "randKI.hh"
 
using namespace std;

KI::KI(char myColor, const Board &setBoard) : board(setBoard)	{
	// TODO Exception werfen, wenn myColor != b,w
	if(myColor != 'b' || myColor != 'w') color = myColor;
}
	
Move *KI::setKing()	{
    time_t t;
    srand((unsigned) time(&t));
    Move *move = new Move();
	do{
		toX = (char)((rand()%8)+97);
		toY = (rand()%8)+1;
		fromX = (color == 'w') ? 'b' : 'g';
		fromY = (color == 'w') ?  2  :  7 ;
		*move = Move(fromX, fromY, toX, toY, true);
	}	while(!board.is_king_move_valid(*move, color));
	cout << "King to: ";
	cout << toX << " " << toY << endl;
	return move;
}
	
Move *KI::getMove()	{
    time_t t;
    srand((unsigned) time(&t));
	Move *move = new Move();
	do {
		toX = (char)((rand()%8)+97);
		toY = (rand()%8)+1;
		fromX = (char)((rand()%8)+97);
		fromY = (rand()%8)+1;
		*move = Move(fromX, fromY, toX, toY);
	}	while(!board.is_move_valid(*move, color));
	cout << "Move from [a-h][1-8] to [a-h][1-8]: ";
	cout << fromX << " " << fromY << " " << toX << " " << toY << endl;
	return move;
}
