#include "gtest/gtest.h"
#include "../pieces.h"

TEST(ConstructorPiece, Torre) {
    Torre torreTest(ColorPed::black, 2, 6);
    EXPECT_EQ(ColorPed::black, torreTest.getColor());
    EXPECT_EQ(2, torreTest.getX());
    EXPECT_EQ(6, torreTest.getY());
}

TEST(ConstructorPiece, Cavallo) {
    Cavallo cavalloTest(ColorPed::black, 2, 6);
    EXPECT_EQ(ColorPed::black, cavalloTest.getColor());
    EXPECT_EQ(2, cavalloTest.getX());
    EXPECT_EQ(6, cavalloTest.getY());
}

TEST(ConstructorPiece, Alfiere) {
    Alfiere alfiereTest(ColorPed::black, 2, 6);
    EXPECT_EQ(ColorPed::black, alfiereTest.getColor());
    EXPECT_EQ(2, alfiereTest.getX());
    EXPECT_EQ(6, alfiereTest.getY());
}

TEST(ConstructorPiece, Regina) {
    Regina reginaTest(ColorPed::black, 2, 6);
    EXPECT_EQ(ColorPed::black, reginaTest.getColor());
    EXPECT_EQ(2, reginaTest.getX());
    EXPECT_EQ(6, reginaTest.getY());
}

TEST(ConstructorPiece, Re) {
    Re reTest(ColorPed::black, 2, 6);
    EXPECT_EQ(ColorPed::black, reTest.getColor());
    EXPECT_EQ(2, reTest.getX());
    EXPECT_EQ(6, reTest.getY());
}

TEST(ConstructorPiece, Pedone) {
    Pedone pedoneTest(ColorPed::black, 2, 6);
    EXPECT_EQ(ColorPed::black, pedoneTest.getColor());
    EXPECT_EQ(2, pedoneTest.getX());
    EXPECT_EQ(6, pedoneTest.getY());
}