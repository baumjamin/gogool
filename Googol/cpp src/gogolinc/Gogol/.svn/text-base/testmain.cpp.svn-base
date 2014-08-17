#include <iostream>
#include "Move.hh"

#include "Board.hh"

using namespace std;
int main(){
    int i = 0;

    int  fromY, toY;
    char fromX, toX;
    Board board;
    const int** tmp = board.get_Field();
    for (int i= 0; i < 8; i++){
	for (int j = 0; j < 8; j++){
	    cout << tmp[i][j] << " ";
	}
	cout << endl;
    }
    board.print();
    const int * const * const tmp =  board.get_Field();
    for (int x = 0; x < 8; x++) {
      for (int y = 0; y < 8; y++) {
	cout << tmp[x][y] << "::";
      }
      cout << endl;
    }

    while(board.win()!=true){
	cout << "Player " << i%2+1 << " zieht." << endl;
	cout << "Geben Sie einen Zug ein: " << endl;
    	cin >> fromX >> fromY >> toX >> toY;
	Move move(fromX, fromY, toX, toY);
	i++;
	char playercolor = (i%2) ? 'w' : 'b';
	if (board.is_move_valid(move, playercolor) == true){
	    board.setMove(move);
	    board.print();
	}
	else {
	    cout << "Move ungueltig! " << endl;
	    i--;
	}
    }
    cout << "Gewonnen!" << endl;
    return 0;

}
