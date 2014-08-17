/*
 *  Position.cpp
 *  gogol
 *
 *  Created by Fabian Glaser on 04.07.07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */
#include "Position.hh"
Position::Position(){}

Position::Position(int x, int y){
	(*this).x = x;
	(*this).y = y;
}

int Position::getX() const{
	return x;
}

void Position::setX(int x){
	(*this).x = x;
}

int Position::getY() const{
	return y;
}

void Position::setY(int y){
	(*this).y = y;
}
