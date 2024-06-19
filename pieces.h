#ifndef INHERITANCE_PIECES_H
#define INHERITANCE_PIECES_H

#include <iostream>
#include "ColorPed.h"


class Chessboard;

class Piece {
public:
    virtual ~Piece() = default;

    Piece(ColorPed color, int x, int y) : color(color), x(x), y(y) {};

    virtual void printPieceString() = 0;

    virtual void printPiece() = 0;

    virtual bool isLegalMove(Chessboard &chessboard, int x, int y) = 0;

    virtual void setMove(const int x, const int y) {
        this->x = x;
        this->y = y;
    }

    ColorPed getColor() const {
        return color;
    }

    void setFirstMove() {
        this->firstMove = false;
    }

    bool isFirstMove() const {
        return firstMove;
    }

    void setCapture(const bool capture) {
        this->capture = capture;
    }

    bool isCapture() const {
        return capture;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

protected:
    ColorPed color;
    int x;
    int y;
    bool capture{false};
    bool firstMove{true};

    bool destinationBox(const Chessboard &chessboard, const int x, const int y);
};

class Torre : public Piece {
public:
    Torre(ColorPed color, int x, int y) : Piece(color, x, y) {};

    void printPiece() override {
        this->color == ColorPed::white ? std::cout << " T " : std::cout << " t ";
    }

    void printPieceString() override {
        std::cout << "Torre\n";
    }

    bool isLegalMove(Chessboard &chessboard, int x, int y) override;
};

class Cavallo : public Piece {
public:
    Cavallo(ColorPed color, int x, int y) : Piece(color, x, y) {};

    void printPiece() override {
        this->color == ColorPed::white ? std::cout << " C " : std::cout << " c ";
    }

    void printPieceString() override {
        std::cout << "Cavallo\n";
    }

    bool isLegalMove(Chessboard &chessboard, int x, int y) override;
};

class Alfiere : public Piece {
public:
    Alfiere(ColorPed color, int x, int y) : Piece(color, x, y) {}

    void printPiece() override {
        this->color == ColorPed::white ? std::cout << " A " : std::cout << " a ";
    }

    void printPieceString() override {
        std::cout << "Alfiere\n";
    }

    bool isLegalMove(Chessboard &chessboard, int x, int y) override;
};

class Regina : public Piece {
public:
    Regina(ColorPed color, int x, int y) : Piece(color, x, y) {};

    void printPiece() override {
        this->color == ColorPed::white ? std::cout << " Q " : std::cout << " q ";
    }

    void printPieceString() override {
        std::cout << "Regina\n";
    }

    bool isLegalMove(Chessboard &chessboard, int x, int y) override;

};

class Re : public Piece {
public:
    Re(ColorPed color, int x, int y) : Piece(color, x, y) {};

    void printPiece() override {
        this->color == ColorPed::white ? std::cout << " K " : std::cout << " k ";
    }

    void printPieceString() override {
        std::cout << "Re\n";
    }

    bool isLegalMove(Chessboard &chessboard, int x, int y) override;

};

class Pedone : public Piece {
public:
    Pedone(ColorPed color, int x, int y) : Piece(color, x, y) {};

    void printPiece() override {
        this->color == ColorPed::white ? std::cout << " P " : std::cout << " p ";
    }

    void printPieceString() override {
        std::cout << "Pedone\n";
    }

    bool isLegalMove(Chessboard &chessboard, int x, int y) override;
};


#endif //INHERITANCE_PIECES_H