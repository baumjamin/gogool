#include "Board.hh"
#include <iostream>
#include <iomanip>

using namespace std;

// Konstruktor ------------------------------------------------------------------------------------------
Board::Board(){
    // init field
    for (int i = 0; i < 8 ; i++){
		for (int j = 0; j < 8; j++){
			field[i][j] = free;
		}
	}
    // init Position of Kings
	
	kingw = Position(-1,-1);
	kingb = Position(-1,-1);
	
    // init pawns
    for (int i = 0; i < 8 ; i++){
		field[0][i] = pw;
		field[7][i] = pb;
    }
}

Board::Board(const Board &other){
	copy(other);
}

// is_king_move_valid ___________________________________________________________________________________
bool Board::is_king_move_valid(Move& move, char color) const{
	int stone;
	int bad_line;
	int vz;
	int toX = move.getToX();
	int toY = move.getToY();
	
	if (toY < 0 || toY > 7 || toX < 0 || toX > 7){
		return false;
    }
	
	if (move.moveSetsKing() == false){
		return false;
	}
	if (color == 'w'){
		stone = kw;
		vz = 1;
		bad_line = 0;
	}
	else {
		stone = kb;
		vz = -1;
		bad_line = 7;
	}
	
	if (field[toY][toX] !=free){
		return false;
	}
	
	if (abs(bad_line-toY) == 1){
		return false;	
	}
	
	return true;
}
	
// is_move_valid ----------------------------------------------------------------------------------------
bool Board::is_move_valid(Move& move, char color) const{
    int toX = move.getToX();
    int toY = move.getToY();
    int fromX = move.getFromX();
    int fromY = move.getFromY();
    int bad_line, vz;
    int stone = field[fromY][fromX];
    int deltaX, deltaY;
	int absdX, absdY;
    
    if (toX < 0 || toX > 7 || toY < 0 || toY > 7 || fromX < 0 || fromX > 7 || fromY < 0 || fromY > 7){
		return false;
    }

    if (field[toY][toX] != free){ // target-position is not free
		return false;
    }
	
    if (color == 'w'){   	// Player white´s turn
		bad_line = 0;
		vz = 1;
		if (stone <= free){  // test if player white tries to move enemy-stones/ free field
			return false;
		}
    }
    else {			// Player black´s turn
		bad_line = 7;
		vz = -1;
		if (stone >= free){  // test if player black tries to move enemy-stones/ free field
			return false;
		}
    }
    
	deltaX = fromX - toX;
	deltaY = fromY - toY;
	absdX = abs(deltaX);
	absdY = abs(deltaY);
    
	if (abs(stone) == 3){ 
	  // moving stone is king
	  // test if move is a kings´s move
		if ((absdX != absdY) && !(absdX > 0 && absdY == 0) && !(absdX == 0 && absdY > 0 )){
			return false;
		}
	// avoid collision
		bool isbeatmove = ((absdX == 2 && absdY == 2) || (absdX == 0 && absdY == 2) || (absdX == 2 && absdY == 0));
		if (!(isbeatmove && stone*field[fromY-deltaY/2][fromX-deltaX/2] < 0)){
			int sy;
			int sx;
			if (deltaY!=0){
				sy = deltaY/absdY;
			}
			else{
				sy = 0;
			}
			if (deltaX!=0){
				sx = deltaX/absdX;
			}
			else{
				sx = 0;
			}
			for (int i = 1; i < absdY || i < absdX; i++){
				if (field[fromY-sy*i][fromX-sx*i] != free){
					return false;
				}	      
			}
		}
	
	  // test if player tries to move king to second line
		if (abs(bad_line-toY) == 1){
			if (abs(stone + (toX > 0?field[bad_line][toX-1]:(2*vz)) + field[bad_line][toX] + (toX < 7?field[bad_line][toX+1]:(2*vz))) == 9){
				return false;
			}	
		}
	}
	
	// moving stone is pawn
	else{
		if (toY == bad_line){
			int kingpos = -1;
			for (int i = 1; i < 7 ; i++){
				if (field[bad_line+vz][i] == (vz*3)){
					kingpos = i;
					break;
				}
			}
			int deltapos = toX-kingpos; 
			if (kingpos != -1 && abs(deltapos) <= 1 && !(fromY == bad_line && absdX == 1 && abs(fromX - kingpos) <= 1)){
				if (abs(stone + (kingpos > 0?field[bad_line][kingpos-1]:(2*vz)) + field[bad_line][kingpos] + (kingpos < 7?field[bad_line][kingpos+1]:(2*vz))) == 6){
					return false;
				}
			}		 
		}
	}
    
// test if player trie s to move stone to side egde    
    if (toX == 0 || toX ==7){
		if (toY < 7 && toY > 0 && (abs(stone +field[toY+1][toX]) == 5 || abs(stone + field[toY-1][toX]) == 5)){
			return false;
		}
		else{
			if (toY == bad_line && toY == 0 && abs(stone +field[toY+1][toX]) == 5){
				return false;
			}
			else{
				if (toY == bad_line && toY == 7 && abs(stone +field[toY-1][toX]) == 5){
					return false;
				}
			}
		}
    }
    
// test if player tries to move stone to ground_line
    if (toY == bad_line){
		if (toX < 7 && toX > 0 && (abs(stone +field[toY][toX+1]) == 5 || abs(stone + field[toY][toX-1]) == 5)){
			return false;
		}
		else{
			if (toX == 0 && abs(stone + field[toY][toX+1]) == 5){
				return false;
			}
			else{
				if(toX == 7 && abs(stone + field[toY][toX-1]) == 5){
					return false;
				}
			}
		}
	}
    return true;
}

// get_Field -----------------------------------------------------------------------------------------------------------------------------
int Board::get_Field(int x, int y) const{
//TODO throw exception
  return  field[y][x];
}

// set_Move ------------------------------------------------------------------------------------------------------------------------------
bool Board::setMove(const Move &move, char color){
    int toX = move.getToX();
    int toY = move.getToY();
    int fromX = move.getFromX();
    int fromY = move.getFromY();
    int deltaX = fromX-toX;
    int deltaY = fromY-toY;
	int absdX = abs(deltaX);
	int absdY = abs(deltaY);
	bool isbeatmove;
	
	if (!move.moveSetsKing()){
		isbeatmove = ((absdX == 2 && absdY == 2) || (absdX == 0 && absdY == 2) || (absdX == 2 && absdY == 0));
		if (isbeatmove && field[fromY][fromX]*field[fromY-deltaY/2][fromX-deltaX/2] < 0){
			field[fromY-deltaY/2][fromX-deltaX/2] = free;
		}
		field[toY][toX] = field[fromY][fromX];
		if (field[fromY][fromX] == kw){
			kingw.setX(toX);
			kingw.setY(toY);
		}
		
		if (field[fromY][fromX] == kb){
			kingb.setX(toX);
			kingb.setY(toY);
		}
			
		field[fromY][fromX] = free;
		return true;
	}
	else {
		if (color == 'w'){
			field[toY][toX] = kw;
			kingw.setX(toX);
			kingw.setY(toY);
		}
		else{
			field[toY][toX] = kb;
			kingb.setX(toX);
			kingb.setY(toY);
		}
	}		
	return true;
}

// win()--------------------------------------------------------------------------------------------------------------------------------
bool Board::win(){
    int kings = 0;
    for (int i = 0; i < 8; i++){
		if (field[0][i] == kb || field[7][i] == kw){
			return true;
		}
		for (int j = 0; j < 8; j++){
			if (abs(field[i][j]) == 3){
				kings++;
			}
		}	    
    }
	if (kings == 2){
		return false;
    }
    else{
		return true;
    }
}
//getKingsPos-------------------------------------------------------------------------------------------------------------------------------------
const Position* Board::getKingsPos(char color) const{
	if (color == 'w')
		return &kingw;
	if (color == 'b')
		return &kingb;
	else return 0;
}
// copy-------------------------------------------------------------------------------------------------------------------------------------------
void Board::copy(const Board &other){
	for(int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			(*this).field[i][j] = other.field[i][j];
		}
	}
	
	kingw = Position(other.kingw.getX(), other.kingw.getY());
	kingb = Position(other.kingb.getX(), other.kingb.getY());
}
	
