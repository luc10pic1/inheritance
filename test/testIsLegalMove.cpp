#include "gtest/gtest.h"

#include "../pieces.h"
#include "../chessboard.h"

class ChessboardSuite : public ::testing::Test {
protected:
    Chessboard *chessboard = new Chessboard;
};

TEST_F(ChessboardSuite, movePedone) {
    bool result;
    result = chessboard->getSquare(4, 6)->isLegalMove(*chessboard, 4, 5);
    EXPECT_TRUE(result);
    result = chessboard->getSquare(3, 6)->isLegalMove(*chessboard, 4, 5);
    EXPECT_FALSE(result);
}

TEST_F(ChessboardSuite, moveTorre) {
    bool result;
    chessboard->doMove(7, 6, 7, 5);
    result = chessboard->getSquare(7, 7)->isLegalMove(*chessboard, 7, 6);
    EXPECT_TRUE(result);
    result = chessboard->getSquare(7, 7)->isLegalMove(*chessboard, 7, 5);
    EXPECT_FALSE(result);
}

TEST_F(ChessboardSuite, moveCavallo) {
    bool result;
    result = chessboard->getSquare(6, 7)->isLegalMove(*chessboard, 7, 5);
    EXPECT_TRUE(result);
    result = chessboard->getSquare(6, 7)->isLegalMove(*chessboard, 4, 5);
    EXPECT_FALSE(result);
}

TEST_F(ChessboardSuite, moveAlfiere) {
    bool result;
    chessboard->doMove(6, 6, 6, 5);
    result = chessboard->getSquare(5, 7)->isLegalMove(*chessboard, 6, 6);
    EXPECT_TRUE(result);
    result = chessboard->getSquare(5, 7)->isLegalMove(*chessboard, 6, 5);
    EXPECT_FALSE(result);
}

TEST_F(ChessboardSuite, moveRe) {
    bool result;
    chessboard->doMove(4, 6, 4, 5);
    result = chessboard->getSquare(4, 7)->isLegalMove(*chessboard, 4, 6);
    EXPECT_TRUE(result);
    result = chessboard->getSquare(4, 7)->isLegalMove(*chessboard, 7, 5);
    EXPECT_FALSE(result);
}

TEST_F(ChessboardSuite, moveRegina) {
    bool result;
    chessboard->doMove(3, 6, 3, 5);
    result = chessboard->getSquare(3, 7)->isLegalMove(*chessboard, 3, 6);
    EXPECT_TRUE(result);
    result = chessboard->getSquare(3, 7)->isLegalMove(*chessboard, 7, 5);
    EXPECT_FALSE(result);
}