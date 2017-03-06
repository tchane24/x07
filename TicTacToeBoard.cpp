#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Switches turn member variable to represent whether it's X's or O's turn
void TicTacToeBoard::toggleTurn()
{
	if(turn == X)
	{
		turn = O;
	}
	else if(turn == O)
	{
		turn = X;
	}
}

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
	clearBoard();
	turn = O; //Setting turn to O because placePiece() toggles when called
}

//Resets each board location to the Blank Piece value
void TicTacToeBoard::clearBoard()
{
	for(int i=0; i < BOARDSIZE; i++)
		for(int j=0; j < BOARDSIZE; j++)
		{
			board[i][j] = Blank;
		}
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
	toggleTurn();
	if(row > 2 || row < 0 || column > 2 || column < 0)
		return Invalid;
	if(board[row][column] != Blank)
		return board[row][column];
	board[row][column] = turn;
	return turn;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
	if(row >= 0 && row <= 2)
	{
		if(column >= 0 && column <= 2)
		{
		return board[row][column];
		}
	}
	return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
	if(getPiece(0,0)!=Blank && getPiece(0,0)==getPiece(1,1) && getPiece(1,1)==getPiece(2,2))
		return getPiece(0,0);
	if(getPiece(0,1)!=Blank && getPiece(0,1)==getPiece(1,1) && getPiece(1,1)==getPiece(2,1))
		return getPiece(0,1);
	if(getPiece(0,2)!=Blank && getPiece(0,2)==getPiece(1,1) && getPiece(1,1)==getPiece(2,0))
		return getPiece(0,2);
	if(getPiece(0,0)!=Blank && getPiece(0,0)==getPiece(0,1) && getPiece(0,1)==getPiece(0,2))
		return getPiece(0,0);
	if(getPiece(1,0)!=Blank && getPiece(1,0)==getPiece(1,1) && getPiece(1,1)==getPiece(1,2))
		return getPiece(1,0);
	if(getPiece(2,0)!=Blank && getPiece(2,0)==getPiece(2,1) && getPiece(2,1)==getPiece(2,2))
		return getPiece(2,0);
	if(getPiece(0,0)!=Blank && getPiece(0,0)==getPiece(1,0) && getPiece(1,0)==getPiece(2,0))
		return getPiece(0,0);
	if(getPiece(0,2)!=Blank && getPiece(0,2)==getPiece(1,2) && getPiece(1,2)==getPiece(2,2))
		return getPiece(0,2);
	for(int i=0; i<BOARDSIZE; i++)
	{
		for(int j=0; j<BOARDSIZE; j++)
		{
			if(board[i][j] == Blank)
				return Invalid;
		}
	}
	return Blank;
}
