#include "ex04-library.h"
#include <iostream>

//Do not modify
Piece::~Piece(){}

//Do not modify
void Piece::printPosition(){
	cout << "(" << r << "," << c << ")" << endl;
}

WhitePiece::WhitePiece(int row, int column) {
    this->r = row;
    this->c = column;
}

WhitePiece::~WhitePiece() {
    
}


string WhitePiece::getColor(void) {
    /*
    if((this->r%2 == 0 && this->c%2 == 0) || (this->r%2 != 0 && this->c%2 != 0)){
		return "white";
	}
    */
    return "white";
}

string WhitePiece::printCode(void) {
    return "W";
}

void WhitePiece::moveRight(void) {
    this->c = this->c + 1;
    this->r = this->r - 1;
}

void WhitePiece::moveLeft(void) {
    this->c = this->c - 1;
    this->r = this->r - 1;
}

BlackPiece::BlackPiece(int row, int column) {
    this->r = row;
    this->c = column;
}

BlackPiece::~BlackPiece() {
}

/*
void BlackPiece::printPosition(void) {
    cout << "(" << this->r << "," << this->c << ")" << endl;
}
*/

string BlackPiece::getColor(void) {
    /*
    if((this->r%2 != 0 && this->c%2 != 0) || (this->r%2 == 0 && this->c%2 == 0)){
		return "black";
	}
    */
   return "black";
}

string BlackPiece::printCode(void) {
    return "B";
}

void BlackPiece::moveRight(void) {
    this->c = this->c - 1;
    this->r = this->r + 1;
}

void BlackPiece::moveLeft(void) {
    this->c = this->c + 1;
    this->r = this->r + 1;
}
