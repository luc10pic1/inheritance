#include "pieces.h"

bool Pieces::destinationBox(const Chessboard &chess,const int x,const int y) {
    bool result=false;
    if(!chess.buffer[x][y] || chess.buffer[x][y]->color!=color){
        result=true;
    }
    return result;
}

bool Torre::isLegalMove(Chessboard &chessboard,int x,int y) {
    bool result=true;
    if(this->x==x){
        int i=this->y;
        while(i!=y && result){
            if(i<y)
                i++;
            else
                i--;
            if(i!=y) {
                if (chessboard.buffer[this->x][i])
                    result = false;
            }
        }
    }
    else if(this->y==y){
        int i=this->x;
        while(i!=x && result){
            if(i<x)
                i++;
            else
                i--;
            if(i!=x) {
                if (chessboard.buffer[i][this->y])
                    result = false;
            }
        }
    }
    else
        result=false;
    if(result)
        result=this->destinationBox(chessboard,x,y);
    return result;
}
bool Cavallo::isLegalMove(Chessboard &chessboard,int x,int y) {
    bool result=false;
    if((x==this->x+1 && (y==this->y+2 || y==this->y-2)) || (x==this->x+2 && (y==this->y+1 || y==this->y-1)) || (x==this->x-1 && (y==this->y-2 || y==this->y+2)) || (x==this->x-2 && (y==this->y-1 || y==this->y+1)))
        result=true;
    if(result)
        result=this->destinationBox(chessboard,x,y);
    return result;
}
bool Alfiere::isLegalMove(Chessboard &chessboard,int x,int y) {
    int a,b;
    a=this->x;
    b=this->y;
    bool result = true;
    while (result && (this->x != x || this->y != y) && (x < 8 && x >= 0 || y < 8 && y >= 0)) {
        if ((this->x != x && this->y == y) || (this->x == x && this->y != y)) {
            result = false;
        } else {
            if (x > this->x) {
                this->x++;
                if (y < this->y) {
                    this->y--;
                }
                if (y > this->y) {
                    this->y++;
                }
                if(x!=this->x && y!=this->y && chessboard.buffer[this->x][this->y])
                    result=false;
            }
            if (x < this->x) {
                this->x--;
                if (y < this->y)
                    this->y--;
                if (y > this->y)
                    this->y++;
                if(x!=this->x && y!=this->y && chessboard.buffer[this->x][this->y])
                    result=false;
            }
        }
    }
    if(this->x!=x || this->y!=y)
        result=false;
    if(result)
        result= destinationBox(chessboard,this->x,this->y);
    this->x=a;
    this->y=b;
    return result;

}
bool Re::isLegalMove(Chessboard &chessboard, int x, int y) {
    bool result=false;
    if(abs(this->x-x)<2&&abs(this->y-y)<2)
        result=true;
    if(result)
        result= destinationBox(chessboard,x,y);
    return result;
}
bool Regina::isLegalMove(Chessboard &chessboard, int x, int y) {
    int a,b;
    a=this->x;
    b=this->y;
    bool result;
    if(this->x!=x && this->y!=y) {
        Alfiere alfiere(color,this->x,this->y);
        Pieces * alfiereAddr=&alfiere;
        result = alfiereAddr->isLegalMove(chessboard,x, y);
    }
    else{
        Torre torre(color,this->x,this->y);
        Pieces * torreAddr=&torre;
        result= torreAddr->isLegalMove(chessboard,x,y);
    }
    this->x=a;
    this->y=b;
    return result;
}
bool Pedone::isLegalMove(Chessboard &chessboard, int x, int y) {
    int a,b;
    a=this->x;
    b=this->y;
    bool result=true;
    if((chessboard.buffer[this->x][this->y]->getColor()==ColorPed::black && y<this->y) || (chessboard.buffer[this->x][this->y]->getColor()==ColorPed::white && y>this->y))
        result=false;
    while(result && y!=this->y) {
        if (x == this->x) {
            if (abs(y - this->y) < 3) {
                if(chessboard.buffer[this->x][this->y]->isFirstMove() && abs(y - this->y) > 1) {
                    if (y < this->y) {
                        if(chessboard.buffer[this->x][this->y-1] || chessboard.buffer[this->x][this->y-2])
                            result=false;
                        this->y-=2;
                    }
                    if (y > this->y) {
                        if(chessboard.buffer[this->x][this->y+1] || chessboard.buffer[this->x][this->y+2])
                            result=false;
                        this->y+=2;
                    }
                }
                else{
                    if(abs(y-this->y)<2){
                        if(y<this->y) {
                            if (chessboard.buffer[this->x][this->y - 1])
                                result = false;
                            this->y--;
                        }
                        if(y>this->y) {
                            if (chessboard.buffer[this->x][this->y + 1])
                                result = false;
                            this->y++;
                        }
                    }
                    else{result=false;}
                }
            }
            else{result=false;}
        }
        else{
            if(abs(this->x-x)<2 && abs(this->y-y)<2 && chessboard.buffer[x][y] && chessboard.buffer[x][y]->getColor()!=color){
                result=true;
                capture=true;
                this->y=y;
            }
            else{result=false;};
        }
    }
    if(y==this->y && x!=this->x && !capture)
        result=false;
    capture=false;
    this->x=a;
    this->y=b;
    return result;
}
