/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, TogglesCorrectly)
{
	TicTacToeBoard t;
	//Placed toggleTurn() in placePiece()
	t.placePiece(0,0);
	ASSERT_EQ(t.placePiece(1,2), O);
}

TEST(TicTacToeBoardTest, BoardIsClear)
{
	TicTacToeBoard t;
	t.clearBoard();
	ASSERT_EQ(t.getPiece(0,0) , Blank);
}

TEST(TicTacToeBoardTest, placePieceDuplicate)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	ASSERT_EQ(t.placePiece(0,0) , X);
}

TEST(TicTacToeBoardTest, placePieceOutofBounds)
{
	TicTacToeBoard t;
	ASSERT_EQ(t.placePiece(3,0) , Invalid);
}

TEST(TicTacToeBoardTest, getPieceLastRowBlank)
{
	TicTacToeBoard t;
	ASSERT_EQ(t.getPiece(2,2) , Blank);
}

TEST(TicTacToeBoardTest, getPieceLastRowX)
{
	TicTacToeBoard t;
	t.placePiece(2,2);
	ASSERT_EQ(t.getPiece(2,2) , X);
}

TEST(TicTacToeBoardTest, getPieceLastRowO)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	t.placePiece(2,2);
	ASSERT_EQ(t.getPiece(2,2) , O);
}

TEST(TicTacToeBoardTest, getPieceOoB)
{
	TicTacToeBoard t;
	ASSERT_EQ(t.getPiece(3,0) , Invalid);
}

TEST(TicTacToeBoardTest, getWinnerCase1)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	t.placePiece(0,1);
	t.placePiece(1,1);
	t.placePiece(0,2);
	t.placePiece(2,2);
	ASSERT_EQ(t.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerGameNotOver)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	ASSERT_EQ(t.getWinner(), Invalid);
}

TEST(TicTacToeBoardTest, getWinnerCase2OWin)
{
	TicTacToeBoard t;
	t.placePiece(2,0);
	t.placePiece(0,0);
	t.placePiece(2,1);
	t.placePiece(0,1);
	t.placePiece(1,1);
	t.placePiece(0,2);
	ASSERT_EQ(t.getWinner(), O);
}

TEST(TicTacToeBoardTest, getWinnerCase3)
{
	TicTacToeBoard t;
	t.placePiece(0,2);
	t.placePiece(1,2);
	t.placePiece(1,1);
	t.placePiece(2,2);
	t.placePiece(2,0);
	ASSERT_EQ(t.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerCase4)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	t.placePiece(0,1);
	t.placePiece(1,0);
	t.placePiece(1,1);
	t.placePiece(2,0);
	ASSERT_EQ(t.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerCase5)
{
	TicTacToeBoard t;
	t.placePiece(0,1);
	t.placePiece(0,0);
	t.placePiece(1,1);
	t.placePiece(1,0);
	t.placePiece(2,1);
	ASSERT_EQ(t.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerCase6)
{
	TicTacToeBoard t;
	t.placePiece(0,2);
	t.placePiece(0,0);
	t.placePiece(1,2);
	t.placePiece(1,0);
	t.placePiece(2,2);
	ASSERT_EQ(t.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerCase7)
{
	TicTacToeBoard t;
	t.placePiece(1,0);
	t.placePiece(0,0);
	t.placePiece(1,1);
	t.placePiece(0,1);
	t.placePiece(1,2);
	ASSERT_EQ(t.getWinner(), X);
}

TEST(TicTacToeBoardTest, getWinnerCase8)
{
	TicTacToeBoard t;
	t.placePiece(2,0);
	t.placePiece(0,0);
	t.placePiece(2,1);
	t.placePiece(0,0);
	t.placePiece(2,2);
	ASSERT_EQ(t.getWinner(), X);
}
TEST(TicTacToeBoardTest, getWinnerNoWinner)
{
	TicTacToeBoard t;
	t.placePiece(0,1);
	t.placePiece(0,0);
	t.placePiece(1,1);
	t.placePiece(0,2);
	t.placePiece(1,2);
	t.placePiece(1,0);
	t.placePiece(2,0);
	t.placePiece(2,1);
	t.placePiece(2,2);
	ASSERT_EQ(t.getWinner(), Blank);
}
