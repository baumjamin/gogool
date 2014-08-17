/*
 *  KI.cpp
 *  gogol
 *
 *  Created by Fabian Glaser on 04.07.07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#include "KI.hh"
#include "Position.hh"

/**
* Implementation of the class KI. 
 * @see KI
 * @file KI.cpp
 * @author GogolINC
 * @date 21.05.2007
 */


using namespace std;

KI::KI(char myColor, const Board &setBoard) : board(setBoard)	{
	color = myColor;
	if (color == 'w'){
		otherColor = 'b';
	}
	else if (color == 'b'){
		otherColor = 'w';
	}
	else ; //TODO Throw exception if mycolor!= b,w
	
	blackKing = board.getKingsPos('b');
	whiteKing = board.getKingsPos('w');
	myKing = board.getKingsPos(color);
	otherKing = board.getKingsPos(otherColor);
}

Move *KI::setKing()	{
    time_t t;
    srand((unsigned) time(&t));
    Move *move = new Move();
	Position *position = new Position();
	do{	
		int xint = rand()%8;
		toX = (char)(xint+97);
		toY = (rand()%8)+1;
		fromX = toX;
		fromY = toY;
		*position = Position(xint,toY-1);
		*move = Move(fromX, fromY, toX, toY, true);
	}	while(!board.is_king_move_valid(*move, color) || !isSave(color, (*move), board));
	
	delete position;
	cout << "King to: ";
	cout << toX << " " << toY << endl;
	return move;
}

// isSave with param Move
bool KI::isSave(char mycolor, const Move &move, const Board &b){
	Board* tmp = new Board(b);
	int x,y,vz;
	char othercolor;
	x = move.getToX();
	y = move.getToY();
	if (mycolor == 'w'){
		othercolor = 'b';
		vz = 1;
	}
	else if(mycolor == 'b'){
		othercolor = 'w';
		vz = -1;
	}
	
	tmp->setMove(move);
	
	// teste vertikal benachbarte Felder
	if (y > 0 && y < 7){
		if (tmp->get_Field(x,y+1)*vz <0 && tmp->get_Field(x,y-1) == 0){
			return false;
		}
		if (tmp->get_Field(x,y-1)*vz <0 && tmp->get_Field(x,y+1) == 0){
			return false;
		}
	}
	// teste horizontal benachbarte Felder
	if (x > 0 && x < 7){
		if (tmp->get_Field(x-1,y)*vz <0 && tmp->get_Field(x+1,y) == 0){
			return false;
		}
		if (tmp->get_Field(x+1,y)*vz <0 && tmp->get_Field(x-1,y) == 0){
			return false;
		}
	}
	// teste Diagonalen
	if (y > 0 && y < 7 && x > 0 && x < 7){
		if (tmp->get_Field(x-1,y+1)*vz <0 && tmp->get_Field(x+1,y-1) == 0){
			return false;
		}
		if (tmp->get_Field(x+1,y+1)*vz <0 && tmp->get_Field(x-1,y-1) == 0){
			return false;
		}
		if (tmp->get_Field(x+1,y-1)*vz <0 && tmp->get_Field(x-1,y+1) == 0){
			return false;
		}
		if (tmp->get_Field(x-1,y-1)*vz <0 && tmp->get_Field(x+1,y+1) == 0){
			return false;
		}
	}
	
	Move* winmove = 0;
	winmove = isWinPossible(othercolor, (*tmp));
	if (winmove != 0){
		delete winmove;
		winmove = 0;
		return false;
	}
	
	winmove = zwicky(othercolor, (*tmp));
	if (winmove != 0){
		delete winmove;
		winmove = 0;
		return false;
	}
	
	delete tmp;
	return true;
}

// isSave with param Position
bool KI::isSave(char mycolor, const Position &pos, const Board &b){
	int x,y,vz;
	x = pos.getX();
	y = pos.getY();
	vz = (mycolor=='w'?1:-1);
	
	// teste vertikal benachbarte Felder
	if (y > 0 && y < 7){
		if (b.get_Field(x,y+1)*vz <0 && b.get_Field(x,y-1) == 0){
			return false;
		}
		if (b.get_Field(x,y-1)*vz <0 && b.get_Field(x,y+1) == 0){
			return false;
		}
	}
	// teste horizontal benachbarte Felder
	if (x > 0 && x < 7){
		if (b.get_Field(x-1,y)*vz <0 && b.get_Field(x+1,y) == 0){
			return false;
		}
		if (b.get_Field(x+1,y)*vz <0 && b.get_Field(x-1,y) == 0){
			return false;
		}
	}
	// teste Diagonalen
	if (y > 0 && y < 7 && x > 0 && x < 7){
		if (b.get_Field(x-1,y+1)*vz <0 && b.get_Field(x+1,y-1) == 0){
			return false;
		}
		if (b.get_Field(x+1,y+1)*vz <0 && b.get_Field(x-1,y-1) == 0){
			return false;
		}
		if (b.get_Field(x+1,y-1)*vz <0 && b.get_Field(x-1,y+1) == 0){
			return false;
		}
		if (b.get_Field(x-1,y-1)*vz <0 && b.get_Field(x+1,y+1) == 0){
			return false;
		}
	}
	return true;
}


Move *KI::getMove()	{
	Move *move = 0;
	bool safe, valid, kingsave;
	time_t t, start, now;
	start = time (NULL);
	srand((unsigned) time(&t));
	
	move = isWinPossible(color, board);
	if(move!=0){
		cout << "Move from [a-h][1-8] to [a-h][1-8]: ";
		cout << (char)(move->getFromX()+97) << " " << move->getFromY()+1 << " " << (char)(move->getToX()+97) << " " << move->getToY()+1 << endl;
	    return move;
	}
	
	move = defendBaseline(color, board);
	if(move!=0){
		cout << "Move from [a-h][1-8] to [a-h][1-8]: ";
		cout << (char)(move->getFromX()+97) << " " << move->getFromY()+1 << " " << (char)(move->getToX()+97) << " " << move->getToY()+1 << endl;
		return move;
	}
	
	move = zwicky(color, board);
	if(move!=0){
		cout << "Move from [a-h][1-8] to [a-h][1-8]: ";
		cout << (char)(move->getFromX()+97) << " " << move->getFromY()+1 << " " << (char)(move->getToX()+97) << " " << move->getToY()+1 << endl;
		return move;
	}
	
	move = defendZwicky(color, board);
	if(move!=0){
		cout << "Move from [a-h][1-8] to [a-h][1-8]: ";
		cout << (char)(move->getFromX()+97) << " " << move->getFromY()+1 << " " << (char)(move->getToX()+97) << " " << move->getToY()+1 << endl;
		return move;
	}
	
	
	kingsave = isSave(color, (*myKing), board);
	if (kingsave){
		move = getKillMove(color, board);
		if(move!=0){
			cout << "Move from [a-h][1-8] to [a-h][1-8]: ";
			cout << (char)(move->getFromX()+97) << " " << move->getFromY()+1 << " " << (char)(move->getToX()+97) << " " << move->getToY()+1 << endl;
			return move;
		}
	}
	
	
	move = new Move();
	do {
		safe = false;
		valid = false;
		int xint = rand()%8;
		toX = (char)(xint+97);
		toY = (rand()%8)+1;
		if (!kingsave){
			fromX = (char)(myKing->getX()+97);
			fromY = myKing->getY()+1;
		}
		else{
			fromX = (char)((rand()%8)+97);
			fromY = (rand()%8)+1;
		}
		*move =  Move(fromX, fromY, toX, toY);
		if (board.is_move_valid(*move, color)){
			valid = true;
			if (isSave(color, *move, board)){
				safe = true;
			}
			now = time(NULL);
			if ((int)difftime(now, start) > 2){
				safe = true;
			}
		}
	}while(!(valid) || !(safe));
	cout << "Move from [a-h][1-8] to [a-h][1-8]: ";
	cout << fromX << " " << fromY << " " << toX << " " << toY << endl;
	return move;
}

Move* KI::defendBaseline(char mycolor, const Board &b){
	Move* attackMove;
	Move* defend = 0;
	int baseline, vz;
	char otherC;
	if (mycolor == 'w'){
		otherC = 'b';
		baseline = 0;
		vz = 1;
	}
	else if(mycolor == 'b'){
		otherC = 'w';
		baseline = 7;
		vz = -1;
	}
	int xKing = otherKing->getX();
	int yKing = otherKing->getY();
	int xAttack;
	
	for (int i = 0; i < 8; i++){
		if (board.get_Field(i,baseline) == 0){
			xAttack = i;
			attackMove = new Move((char)(xKing+97),yKing+1,(char)(xAttack+97),baseline+1);
			if (board.is_move_valid(*attackMove, otherColor)){
				int xPawn, yPawn;
				for (int j = 0; j < 8; j++){
					for (int k = 0; k < 8; k++){
						if (board.get_Field(k,j) == 2*vz){
							xPawn = k;
							yPawn = j;
							defend = new Move((char)(xPawn+97),yPawn+1,(char)(xAttack+97),baseline+1);
							if (isSave(mycolor, *defend, board)){
								return defend;
							}
							else{
								delete defend;
								defend = 0;
							}
						}
					}
				}
				delete attackMove;
				attackMove = 0;
			}
		}
	}
	return defend;
}


Move* KI::isWinPossible(char mycolor, const Board &b){
	char otherC;
	if (mycolor == 'w'){
		otherC = 'b';
	}
	else if(mycolor == 'b'){
		otherC = 'w';
	}
	
	const Position* otherKing = b.getKingsPos(otherC);
	const Position* myKing = b.getKingsPos(mycolor);
	
    if(!isSave(otherC, *otherKing, b)){
		int vz=(mycolor=='w'?1:-1);
		Move *kill = new Move();
		int y=otherKing->getY(), x=otherKing->getX();
		
		if(y>0 && y<7){
			if(b.get_Field(x,y+1)*vz > 0){
				*kill = Move((char)x+97,y+2,(char)x+97,y,false);
				if(b.is_move_valid(*kill,mycolor)){
					if (isSave(mycolor, *kill, b)){
						return kill;
					}
				}
			}
			
			if(b.get_Field(x,y-1)*vz > 0){
				*kill = Move((char)x+97,y,(char)x+97,y+2,false);
				if(b.is_move_valid(*kill,mycolor)){
					if (isSave(mycolor, *kill, b)){
						return kill;
					}
				}
			}
		}
		
		
		if(x>0 && x<7){
			if(b.get_Field(x+1,y)*vz > 0){
				*kill=Move((char)x+98,y+1,(char)x+96,y+1,false);
				if(b.is_move_valid(*kill,mycolor)){
					if (isSave(mycolor, *kill, b)){
						return kill;
					}
				}
			}
			
			if(b.get_Field(x-1,y)*vz>0){
				*kill= Move((char)x+96,y+1,(char)x+98,y+1,false);
				if(b.is_move_valid(*kill,mycolor)){
					if (isSave(mycolor, *kill, b)){
						return kill;
					}
				}
			}
		}	
		
		
		if(y>0 && x<7 && y<7 && x>0){
			if(b.get_Field(x+1,y+1)*vz>0){
				*kill= Move((char)x+98,y+2,(char)x+96,y,false);
				if (isSave(mycolor, *kill, b)){
					return kill;
				}
			}
			
			if(b.get_Field(x+1,y-1)*vz > 0){
				*kill= Move((char)x+98,y,(char)x+96,y+2,false);
				if(b.is_move_valid(*kill,mycolor)){
					if (isSave(mycolor, *kill, b)){
						return kill;
					}
				}
			}
			
			if(b.get_Field(x-1,y+1)*vz > 0){
				*kill= Move((char)x+96,y+2,(char)x+98,y,false);
				if(b.is_move_valid(*kill,mycolor)){
					if (isSave(mycolor, *kill, b)){
						return kill;
					}
				}
			}
			
			if(b.get_Field(x-1,y-1)*vz > 0){
				*kill= Move((char)x+96,y,(char)x+98,y+2,false);
				if(b.is_move_valid(*kill,mycolor)){
					if (isSave(mycolor, *kill, b)){
						return kill;
					}
				}
			}
		}
		delete kill;
		kill = 0;
	}
	
    Move *move = 0;
    int baseline;
    baseline = (mycolor=='w'?7:0);
    for(int i = 0 ; i <=7; i++){
		if(b.get_Field(i,baseline)==0){
			move = new Move((char)myKing->getX()+97,myKing->getY()+1,(char)i+97,baseline+1, false);
			if(b.is_move_valid((*move),mycolor)){
				return move;
			}
			else{
				delete move;
				move=0;
			}
		}
    }
	
    return move;
}

Move* KI::zwicky(char mycolor, const Board &b){
	const Position *King = (mycolor == 'w'?whiteKing:blackKing);
    Move *move=0;
    int baseline;
    baseline = (mycolor=='w'?7:0);
    Position vec[8];
    int vec_count=0;
    for(int i = 0 ; i <=7; i++){
		if(b.get_Field(i,baseline)==0){
			vec[vec_count++]=Position(i,baseline);   //Vector inizialisieren fuer naechste funktion
		}
    }
	
	
    for(int i = 1;i<=vec_count;i++){
		for(int j = vec_count; j>i;j--){  
			if(vec_count<=1){
				break;
			}
			{
				//1.feld ermitteln fuer |\ :
				Position zwick(vec[i-1].getX(),(baseline==7)?(7-(vec[j-1].getX()-vec[i-1].getX())):(vec[j-1].getX()-vec[i-1].getX()));
				if(b.get_Field((zwick.getX()),(zwick.getY()))==0){
					//2.testen ob Feld fuer den Koenig ungefaehrlich ist
					if(isSave(mycolor,zwick,b)){
						
						//3. Testen ob es moeglich ist fuer den koenig beide felder der zwickmuehle zu erreichen
						
						bool iswayfree=true;
						for(int n = 0;((baseline==7)?(zwick.getY()+n<=7):(zwick.getY()+n>=0));(baseline==7)?n++:n--){
							
							if(b.get_Field(zwick.getX(),zwick.getY()+n)==0){
							}
							else{
								
								iswayfree=false;
								break;
							}
							
							if(b.get_Field((baseline==7)?(zwick.getX()+n):(zwick.getX()-n),zwick.getY()+n) ==0){
							}
							else{
								
								iswayfree=false;
								break;
							}
							
						}
						//wenn der Weg frei ist move erzeugen testen ob der Move gueltig ist... wenn ja return move;
						if(iswayfree){
							move= new Move((char)King->getX()+97,King->getY()+1,(char)zwick.getX()+97,zwick.getY()+1, false);
							if(b.is_move_valid(*move,mycolor)){
								return move;
							}
							else{
								delete move;
								move=0;
							}
						}
						
						
					}
					
				}
				
			}
			
			//AB HIER \|  bzw /|
			{
				//1.feld ermitteln fuer |\ :
				Position zwick(vec[j-1].getX(),(baseline==7)?(7-(vec[j-1].getX()-vec[i-1].getX())):(vec[j-1].getX()-vec[i-1].getX()));
				
				if(b.get_Field((zwick.getX()),(zwick.getY()))==0){
					//2.testen ob Feld fuer den Koenig ungefaehrlich ist
					if(isSave(mycolor,zwick,b)){
						
						//3. Testen ob es moeglich ist fuer den koenig beide felder der zwickmuehle zu erreichen
						
						bool iswayfree=true;
						for(int n = 0;((baseline==7)?(zwick.getY()+n<=7):(zwick.getY()+n>=0));(baseline==7)?n++:n--){
							
							if(b.get_Field(zwick.getX(),zwick.getY()+n)==0){
							}
							else{
								iswayfree=false;
								break;
							}
							
							if(b.get_Field((baseline==7)?(zwick.getX()-n):(zwick.getX()+n),zwick.getY()+n) ==0){
							}
							else{
								iswayfree=false;
								break;
							}
							
						}
						//wenn der Weg frei ist move erzeugen testen ob der Move gueltig ist... wenn ja return move;
						if(iswayfree){
							move= new Move((char)King->getX()+97,King->getY()+1,(char)zwick.getX()+97,zwick.getY()+1, false);
							if(b.is_move_valid(*move,mycolor)){
								return move;
							}
							else{
								delete move;
								move=0;
							}
						}
						
						
					}
					
				}
				
			}
			
			//   /\  bzw \/
			if((vec[j-1].getX()-vec[i-1].getX())%2==0) {		//Felder gleiche farbe?^
																//1.feld ermitteln fuer |\ :
				Position zwick(((vec[j-1].getX()-vec[i-1].getX())/2)+vec[i-1].getX(),(baseline==7)?(7-((vec[j-1].getX()-vec[i-1].getX())/2)):((vec[j-1].getX()-vec[i-1].getX())/2));
				if(b.get_Field((zwick.getX()),(zwick.getY()))==0){
					//2.testen ob Feld fuer den Koenig ungefaehrlich ist
					if(isSave(mycolor,zwick,b)){
						
						//3. Testen ob es moeglich ist fuer den koenig beide felder der zwickmuehle zu erreichen
						
						bool iswayfree=true;
						for(int n = 0;((baseline==7)?(zwick.getY()+n<=7):(zwick.getY()+n>=0));(baseline==7)?n++:n--){
							
							if(b.get_Field((baseline==7)?(zwick.getX()+n):(zwick.getX()-n),zwick.getY()-n) ==0){
							}
							else{
								iswayfree=false;
								break;
							}
							if(b.get_Field((baseline==7)?(zwick.getX()-n):(zwick.getX()+n),zwick.getY()+n) ==0){
							}
							else{
								iswayfree=false;
								break;
							}
							
						}
						//wenn der Weg frei ist move erzeugen testen ob der Move gueltig ist... wenn ja return move;
						if(iswayfree){
							move= new Move((char)King->getX()+97,King->getY()+1,(char)zwick.getX()+97,zwick.getY()+1, false);
							if(b.is_move_valid(*move,mycolor)){
								return move;
							}
							else{
								delete move;
								move=0;
							}
						}
					}
				}
			}
		}
    }
    return move;
}


Move* KI::getKillMove(char mycolor, const Board &b){
	char othercolor;
	int vz;
	Position* pos = new Position();
	Move *kill = new Move;
	if (mycolor == 'w'){
		othercolor = 'b';
		vz = 1;
	}
	else if(mycolor == 'b'){
		othercolor = 'w';
		vz = -1;
	}
	
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if(b.get_Field(j,i)*vz < 0){
				*pos = Position(j,i);
				if(!isSave(othercolor,(*pos),b)){
					int y = pos->getY(); 
					int x = pos->getX();
					
					if(y>0 && y<7){
						if(b.get_Field(x,y+1)*vz > 0){
							*kill = Move((char)x+97,y+2,(char)x+97,y,false);
							if(b.is_move_valid(*kill,mycolor)){
								if (isSave(mycolor, *kill, b)){
									return kill;
								}
							}
						}
						
						if(b.get_Field(x,y-1)*vz > 0){
							*kill = Move((char)x+97,y,(char)x+97,y+2,false);
							if(b.is_move_valid(*kill,mycolor)){
								if (isSave(mycolor, *kill, b)){
									return kill;
								}
							}
						}
					}
					
					
					if(x>0 && x<7){
						if(b.get_Field(x+1,y)*vz > 0){
							*kill=Move((char)x+98,y+1,(char)x+96,y+1,false);
							if(b.is_move_valid(*kill,mycolor)){
								if (isSave(mycolor, *kill, b)){
									return kill;
								}
							}
						}
						
						if(b.get_Field(x-1,y)*vz>0){
							*kill= Move((char)x+96,y+1,(char)x+98,y+1,false);
							if(b.is_move_valid(*kill,mycolor)){
								if (isSave(mycolor, *kill, b)){
									return kill;
								}
							}
						}
					}	
					
					
					if(y>0 && x<7 && y<7 && x>0){
						if(b.get_Field(x+1,y+1)*vz>0){
							*kill= Move((char)x+98,y+2,(char)x+96,y,false);
							if (isSave(mycolor, *kill, b)){
								return kill;
							}
						}
						
						if(b.get_Field(x+1,y-1)*vz > 0){
							*kill= Move((char)x+98,y,(char)x+96,y+2,false);
							if(b.is_move_valid(*kill,mycolor)){
								if (isSave(mycolor, *kill, b)){
									return kill;
								}
							}
						}
						
						if(b.get_Field(x-1,y+1)*vz > 0){
							*kill= Move((char)x+96,y+2,(char)x+98,y,false);
							if(b.is_move_valid(*kill,mycolor)){
								if (isSave(mycolor, *kill, b)){
									return kill;
								}
							}
						}
						
						if(b.get_Field(x-1,y-1)*vz > 0){
							*kill= Move((char)x+96,y,(char)x+98,y+2,false);
							if(b.is_move_valid(*kill,mycolor)){
								if (isSave(mycolor, *kill, b)){
									return kill;
								}
							}
						}
					}
				}
			}
		}
	}
	delete kill;
	kill = 0;
	return kill;
}

Move* KI::defendZwicky(char mycolor, const Board &b){
	Move* defend = 0;
	int vz;
	char othercolor;
	if (mycolor == 'w'){
		othercolor = 'b';
		vz = 1;
	}
	else if(mycolor == 'b'){
		othercolor = 'w';
		vz = -1;
	}
	Move* winmove = zwicky(othercolor, b);
	
	if (winmove != 0){
		Position* defpos = new Position();		
		int toX = winmove->getToX();
		int toY = winmove->getToY();
		int fromX = winmove->getFromX();
		int fromY = winmove->getFromY();
		int deltaX = fromX - toX;
		int deltaY = fromY - toY;
		int absdX = abs(deltaX);
		int absdY = abs(deltaY);
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
		delete winmove;
		winmove = 0;
		
		for (int i = 1; i <= absdY || i <= absdX; i++){
			*defpos = Position(fromX-sx*i,fromY-sy*i);
			if (isSave(mycolor, *defpos, b)){
				for (int j = 0; j < 8; j++){  // find Figure to defend Zwicky
					for (int k = 0; k < 8; k++){
						if (board.get_Field(k,j)*vz > 0){  // found Figure of own Color
							defend = new Move((char)(k+97),j+1,(char)(defpos->getX()+97),defpos->getY()+1);
							if (b.is_move_valid(*defend,mycolor) && isSave(mycolor, *defend, b)){
								return defend;
							}
							else{
								delete defend;
								defend = 0;
							}
						}
					}
				}
			}
		}
	}
	return defend;
}

