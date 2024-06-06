#include "factoryBuffer.h"
#include "pieces.h"

void FactoryBuffer::createBuffer() {
    buffer[0][7] = new Torre(ColorPed::white, 0, 7);
    buffer[7][7]= new Torre(ColorPed::white, 7, 7);;
    buffer[1][7]= new Cavallo(ColorPed::white, 1, 7);;
    buffer[6][7]= new Cavallo(ColorPed::white, 6, 7);;
    buffer[2][7]= new Alfiere(ColorPed::white, 2, 7);;
    buffer[5][7]= new Alfiere(ColorPed::white, 5, 7);
    buffer[4][7]= new Re(ColorPed::white, 4, 7);;
    buffer[3][7]= new Regina(ColorPed::white, 3, 7);
    buffer[0][6]= new Pedone(ColorPed::white, 0, 6);
    buffer[1][6]= new Pedone(ColorPed::white, 1, 6);;
    buffer[2][6]= new Pedone(ColorPed::white, 2, 6);;
    buffer[3][6]= new Pedone(ColorPed::white, 3, 6);;
    buffer[4][6]= new Pedone(ColorPed::white, 4, 6);;
    buffer[5][6]= new Pedone(ColorPed::white, 5, 6);;
    buffer[6][6]= new Pedone(ColorPed::white, 6, 6);;
    buffer[7][6]= new Pedone(ColorPed::white, 7, 6);;
    buffer[0][0]= new Torre(ColorPed::black, 0, 0);;
    buffer[7][0]= new Torre(ColorPed::black, 7, 0);;
    buffer[1][0]= new Cavallo(ColorPed::black, 1, 0);;
    buffer[6][0]= new Cavallo(ColorPed::black, 6, 0);;
    buffer[2][0]= new Alfiere(ColorPed::black, 2, 0);;
    buffer[5][0]= new Alfiere(ColorPed::black, 5, 0);;
    buffer[3][0]= new Regina(ColorPed::black, 3, 0);;
    buffer[4][0]= new Re(ColorPed::black, 4, 0);;
    buffer[0][1]= new Pedone(ColorPed::black, 0, 1);;
    buffer[1][1]= new Pedone(ColorPed::black, 1, 1);;
    buffer[2][1]= new Pedone(ColorPed::black, 2, 1);;
    buffer[3][1]= new Pedone(ColorPed::black, 3, 1);;
    buffer[4][1]= new Pedone(ColorPed::black, 4, 1);;
    buffer[5][1]= new Pedone(ColorPed::black, 5, 1);;
    buffer[6][1]= new Pedone(ColorPed::black, 6, 1);;
    buffer[7][1]= new Pedone(ColorPed::black, 7, 1);;
}