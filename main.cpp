#include <iostream>
#include "pieces.h"
#include "chessboard.h"


int main() {
    Chessboard chessboard;
    chessboard.setTurn(ColorPed::white);
    std::cout << "Benvenuto\nStai per iniziare una partita a scacchi!!\nBuon divertimento\n";
    while (!chessboard.isScaccoMattoB() && !chessboard.isScaccoMattoW()) {
        chessboard.printChessboard();
        chessboard.getTurn() == ColorPed::white ? std::cout << "Tocca al Bianco\n" : std::cout << "Tocca al Nero\n";
        chessboard.insertCoordinate();
        chessboard.doMove();
        while (chessboard.isAutoScacco()) {
            std::cout << "Mossa non valida perchè si verifica un auto scacco.\nRiprovare\n";
            chessboard.cancelMove();
            chessboard.insertCoordinate();
            chessboard.doMove();
        }
        if (chessboard.getSquare(chessboard.getArrX(), chessboard.getArrY())->isCapture()) {
            std::cout << "Pezzo catturato\n";
            chessboard.getSquare(chessboard.getArrX(), chessboard.getArrY())->setCapture(false);
        }
        chessboard.getSquare(chessboard.getArrX(), chessboard.getArrY())->setFirstMove();
        chessboard.checkSubstionPedone();
        std::cout << "Mossa eseguita!\n";
        chessboard.checkScacco();
        ColorPed colorTurn = chessboard.getTurn() == ColorPed::white ? ColorPed::black : ColorPed::white;
        chessboard.setTurn(colorTurn);
    }
}
