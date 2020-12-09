#include <iostream>
#include "ex01-library.h"

using namespace std;

//Exercise 1 (a) Implement this function
cell ** createAndInitBoard(int n){
	//put your code here
	cell** board = new cell*[n];
	for(unsigned int i = 0; i < n; ++i){
		board[i] = new cell[n];
	}
	int drop_ = n - 4;
	for(unsigned int r=0; r<n; r++){
		for(unsigned int c=0; c<n; c++){
			board[r][c].color = computeColor(r, c);
			if((r<3)&(board[r][c].color == dark)){
				board[r][c].status = blackPiece;
			}
			else if ((r>drop_)&(board[r][c].color == dark)){
				board[r][c].status = whitePiece;
			}else{
				board[r][c].status = emptyC;
			}
		}
	}
	return board;
}

//Exercise 1 (b) Implement this function
cell ** duplicateBoard(cell ** A, int n){
	//put your code here
	cell** B = new cell*[n];
	for(unsigned int i = 0; i < n; ++i){
		B[i] = new cell[n];
	}
	for(unsigned int r=0; r<n; r++){
		for(unsigned int c=0; c<n; c++){
			B[r][c].color = A[r][c].color;
			B[r][c].status = A[r][c].status;
		}
	}
	return B;
}

//Exercise 1 (c) Implement this function
bool moveRight(cell ** A,int n,int r, int c){
	
	//cout << "Color and Status" << endl;
	//cout << A[r][c].status << " " << A[r][c].color << endl;

	if(A[r][c].status == whitePiece){
		if((A[r-1][c+1].status == emptyC) && (r-1<n) && (c+1<n) && (r-1>=0) && (c+1>=0)){
			A[r][c].status= emptyC;
			A[r-1][c+1].status = whitePiece;
			return true;
		}
		else{
			return false;
		}
	}
	else if (A[r][c].status == blackPiece){
		if((A[r+1][c-1].status == emptyC) && (c-1<n) && (r+1<n) && (c-1>=0) && (r+1>=0)){
			A[r][c].status = emptyC;
			A[r+1][c-1].status = blackPiece;
			return true;
		}
		else{
			return false;
		}
	}
	else if(A[r][c].status == emptyC){
		return false;
	}
	else{
		cout << "\n" << "what the hell?" << endl;
	}
}

//Exercise 1 (d) Implement this function
bool moveLeft(cell ** A,int n,int r, int c){

	//cout << "Color and Status" << endl;
	//cout << A[r][c].status << " " << A[r][c].color << endl;
	
	if(A[r][c].status == whitePiece){
		if((A[r-1][c-1].status == emptyC) && (r-1<n) && (c-1<n) && (r-1>=0) && (c-1>=0)){
			A[r][c].status = emptyC;
			A[r-1][c-1].status = whitePiece;
			return true;
		}
		else{
			return false;
		}
	}
	else if (A[r][c].status == blackPiece){
		if((A[r+1][c+1].status == emptyC) && (c+1<n) && (r+1<n) && (c+1>=0) && (r+1>=0)){
			A[r][c].status = emptyC;
			A[r+1][c+1].status = blackPiece;
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

//Do not modify
cellColor computeColor(int r,int c){
	if((r%2 == 0 && c%2 == 0) || (r%2 != 0 && c%2 != 0)){
		return bright;
	}
	return dark;
}

//Do not modify
void printBoard(cell ** A, int n){
	cout << ' ';
	for(int c=0;c<n;c++){
		cout << c;
	}
	cout << endl;
	for(int r=0;r<n;r++){
		cout << r;
		for(int c=0;c<n;c++){
			//Print ' ' or '#' if empty, or the piece color (W or B)
			switch (A[r][c].status) {
			case emptyC:
				cout << ((A[r][c].color==bright)?' ':'#');
				break;
			case whitePiece:
				cout << "W";
				break;
			case blackPiece:
				cout << "B";
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}