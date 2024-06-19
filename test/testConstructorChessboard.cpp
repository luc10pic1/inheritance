#include "gtest/gtest.h"
#include "../chessboard.h"

class ConstructorChessboardSuite:public testing::Test{
protected:
    Chessboard*chessboard=new Chessboard;
};

TEST_F(ConstructorChessboardSuite, checkConstructor){
    bool result;
    if(!chessboard->getSquare(4,5))
        result=false;
    EXPECT_FALSE(result);
    if(chessboard->getSquare(7,7))
        result=true;
    EXPECT_TRUE(result);
}