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

    void printChessboard()const;

    void insertCoordinate();

    void doMove();
    void cancelMove();

    void checkSubstionPedone();

    bool isAutoScacco();
    bool checkScacco();

    Pieces *buffer[8][8]{nullptr};

    bool isScaccoMattoW()const{
        return scaccoMattoW;
    }
    bool isScaccoMattoB()const{
        return scaccoMattoB;
    }
    void setTurn(const ColorPed color){
        turn=color;
    }
    ColorPed getTurn()const{
        return turn;
    }
    int getArrX()const{
        return arrX;
    }
    int getArrY()const{
        return arrY;
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
    bool canMoveK(int x,int y,ColorPed whoCheck);// ->checkScaccoMatto
    bool checkCoordinates(int x,int y, bool start=true); // ->insertCoordinate
    void printCapture(std::list<Pieces*> color); // ->substiotionPedone
    bool checkScaccoMatto(ColorPed whoCheck); // ->checkScacco()
    bool checkScacco(ColorPed whoCheck); //->checkScaccoMatto
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
    void doMove(int startX,int startY,int arrX,int arrY); // ->checkScaccoMatto
    void cancelMove(int startX,int startY,int arrX,int arrY); // ->checkScaccoMatto
    void substitionPedone(std::list<Pieces *> color);// ->checkSubstitionPedone
};

#endif //INHERITANCE_CHESSBOARD_H