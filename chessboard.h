#ifndef INHERITANCE_CHESSBOARD_H
#define INHERITANCE_CHESSBOARD_H
#include <iostream>
#include <list>
#include "pieces.h"

class Pieces;

enum class ColorPed;

class Chessboard{
public:
    explicit Chessboard(Pieces*array[8][8]){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(array[i][j])
                    buffer[i][j]=array[i][j];
                else
                    buffer[i][j]=nullptr;
            }
        }
    };

    void printChessboard();

    void insertCoordinate(int & startX,int &startY,int &arrX,int & arrY);

    void doMove(int startX,int startY,int arrX,int arrY);
    void cancelMove(int startX,int startY,int arrX,int arrY);

    void checkSubstionPedone(int arrX,int arrY);

    bool isAutoScacco();
    bool checkScacco();

    Pieces *buffer[8][8]{nullptr};

    bool isScaccoMattoW()const{
        return scaccoMattoW;
    }
    bool isScaccoMattoB()const{
        return scaccoMattoB;
    }

    void setTurn(ColorPed color){
        turn=color;
    }
    ColorPed getTurn()const{
        return turn;
    }

private:
    // VARIABLES
    int xW{4};
    int yW{7};
    int xB{4};
    int yB{0};
    int startX;
    int arrX;
    int startY;
    int arrY;
    bool scaccoReW{false};
    bool scaccoMattoW{false};
    bool scaccoReB{false};
    bool scaccoMattoB{false};
    ColorPed turn;
    std::list<Pieces*>captureB;
    std::list<Pieces*>captureW;

    // METHODS
    bool canMoveK(int x,int y,ColorPed whoCheck);//torna vero quando il re non può muoversi
    bool checkCoordinates(int x,int y, bool start=true); // ->insertCoordinate
    void substionPedone(int arrX, int arrY, std::list<Pieces *> color); // ->checkSubstionPedone
    void printCapture(std::list<Pieces*> color); // ->substiotionPedone
    bool checkScaccoMatto(ColorPed whoCheck); // ->checkScacco()
    bool checkScacco(ColorPed whoCheck); //->checkScaccoMatto
    void insertCaptureB(Pieces * captured){
        captureB.push_front(captured);
    } // ->doMove
    void insertCaptureW(Pieces * captured){
        captureW.push_front(captured);
    } // ->doMove
    Pieces* takeCaptureB(){
        Pieces* element= *(captureB.begin());
        captureB.pop_front();
        return element;
    } // ->cancelMove
    Pieces* takeCaptureW(){
        Pieces* element= *(captureW.begin());
        captureW.pop_front();
        return element;
    } // ->cancelMove

};

#endif //INHERITANCE_CHESSBOARD_H