#include "gtest/gtest.h"
#include "../chessboard.h"
#include "../pieces.h"

class CheckScaccoSuite : public testing::Test {
protected:
    virtual void setChessboardRe() {
        chessboard->doMove(5, 7, 1, 3);
        chessboard->doMove(3, 1, 3, 2);
    }

    virtual void setChessboardMatto() {

        chessboard->doMove(5, 7, 2, 4);
        chessboard->doMove(3, 7, 5, 1);
    }

    Chessboard *chessboard = new Chessboard;
};

TEST_F(CheckScaccoSuite, checkScaccoAlRe) {
    bool result;
    result = chessboard->checkScacco();
    EXPECT_FALSE(result);
    setChessboardRe();
    result = chessboard->checkScacco(ColorPed::white);
    EXPECT_TRUE(result);
}

TEST_F(CheckScaccoSuite, checkScaccoMatto) {
    bool result;
    result = chessboard->checkScaccoMatto(ColorPed::black);
    EXPECT_FALSE(result);
    setChessboardMatto();
    result = chessboard->checkScaccoMatto(ColorPed::black);
    EXPECT_TRUE(result);
}