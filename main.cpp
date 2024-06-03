#include <iostream>
#include "pieces.h"
#include "chessboard.h"
#include <list>


int main() {
    Torre torreB1(ColorPed::white, 0, 7);
    Torre torreB2(ColorPed::white, 7, 7);
    Cavallo cavalloB1(ColorPed::white, 1, 7);
    Cavallo cavalloB2(ColorPed::white, 6, 7);
    Alfiere alfiereB1(ColorPed::white, 2, 7);
    Alfiere alfiereB2(ColorPed::white, 5, 7);
    Re reB(ColorPed::white, 4, 7);
    Regina reginaB(ColorPed::white, 3, 7);
    Pedone pedoneB1(ColorPed::white, 0, 6);
    Pedone pedoneB2(ColorPed::white, 1, 6);
    Pedone pedoneB3(ColorPed::white, 2, 6);
    Pedone pedoneB4(ColorPed::white, 3, 6);
    Pedone pedoneB5(ColorPed::white, 4, 6);
    Pedone pedoneB6(ColorPed::white, 5, 6);
    Pedone pedoneB7(ColorPed::white, 6, 6);
    Pedone pedoneB8(ColorPed::white, 7, 6);
    Torre torreN1(ColorPed::black, 0, 0);
    Torre torreN2(ColorPed::black, 7, 0);
    Cavallo cavalloN1(ColorPed::black, 1, 0);
    Cavallo cavalloN2(ColorPed::black, 6, 0);
    Alfiere alfiereN1(ColorPed::black, 2, 0);
    Alfiere alfiereN2(ColorPed::black, 5, 0);
    Regina reginaN(ColorPed::black, 3, 0);
    Re reN(ColorPed::black, 4, 0);
    Pedone pedoneN1(ColorPed::black, 0, 1);
    Pedone pedoneN2(ColorPed::black, 1, 1);
    Pedone pedoneN3(ColorPed::black, 2, 1);
    Pedone pedoneN4(ColorPed::black, 3, 1);
    Pedone pedoneN5(ColorPed::black, 4, 1);
    Pedone pedoneN6(ColorPed::black, 5, 1);
    Pedone pedoneN7(ColorPed::black, 6, 1);
    Pedone pedoneN8(ColorPed::black, 7, 1);
    Pieces *buffer[8][8]{nullptr};
    buffer[0][7] = &torreB1;
    buffer[7][7]= &torreB2;
    buffer[1][7]= &cavalloB1;
    buffer[6][7]= &cavalloB2;
    buffer[2][7]= &alfiereB1;
    buffer[5][7]= &alfiereB2;
    buffer[4][7]= &reB;
    buffer[3][7]= &reginaB;
    buffer[0][6]= &pedoneB1;
    buffer[1][6]= &pedoneB2;
    buffer[2][6]= &pedoneB3;
    buffer[3][6]= &pedoneB4;
    buffer[4][6]= &pedoneB5;
    buffer[5][6]= &pedoneB6;
    buffer[6][6]= &pedoneB7;
    buffer[7][6]= &pedoneB8;
    buffer[0][0]= &torreN1;
    buffer[7][0]= &torreN2;
    buffer[1][0]= &cavalloN1;
    buffer[6][0]= &cavalloN2;
    buffer[2][0]= &alfiereN1;
    buffer[5][0]= &alfiereN2;
    buffer[3][0]= &reginaN;
    buffer[4][0]= &reN;
    buffer[0][1]= &pedoneN1;
    buffer[1][1]= &pedoneN2;
    buffer[2][1]= &pedoneN3;
    buffer[3][1]= &pedoneN4;
    buffer[4][1]= &pedoneN5;
    buffer[5][1]= &pedoneN6;
    buffer[6][1]= &pedoneN7;
    buffer[7][1]= &pedoneN8;
    Chessboard chessboard(buffer);
    chessboard.setTurn(ColorPed::white);
    std::cout<<"Benvenuto\nStai per iniziare una partita a scacchi!!\nBuon divertimento\n";
    while(!chessboard.isScaccoMattoB() && !chessboard.isScaccoMattoW()) {
        chessboard.printChessboard();
        chessboard.getTurn() == ColorPed::white ? std::cout << "Tocca al Bianco\n" : std::cout << "Tocca al Nero\n";
        chessboard.insertCoordinate();
        chessboard.doMove();
        while(chessboard.isAutoScacco()){
            std::cout<<"Mossa non valida perchè si verifica un auto scacco.\nRiprovare\n";
            chessboard.cancelMove();
            chessboard.insertCoordinate();
            chessboard.doMove();
        }
        if(chessboard.buffer[chessboard.getArrX()][chessboard.getArrY()]->isCapture()) {
            std::cout << "Pezzo catturato\n";
            chessboard.buffer[chessboard.getArrX()][chessboard.getArrY()]->setCapture(false);
        }
        chessboard.buffer[chessboard.getArrX()][chessboard.getArrY()]->setFirstMove();
        chessboard.checkSubstionPedone();
        std::cout<<"Mossa eseguita!\n";
        chessboard.checkScacco();
        ColorPed colorTurn=chessboard.getTurn()==ColorPed::white?ColorPed::black:ColorPed::white;
        chessboard.setTurn(colorTurn);
    }
}
