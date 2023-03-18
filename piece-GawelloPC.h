#ifndef PIECE_H
#define PIECE_H
#include "board.h"


class Piece
{
public:
public:
    Piece(int x, int y, bool isWhite) : x(x), y(y), isWhite(isWhite){}

    virtual ~Piece() {}

    int getX() const {return x;}
    int getY() const {return y;}
    bool getIsWhite() const {return isWhite;}
    void setX(int newX) {x = newX;}
    void setY(int newY) {y = newY;}

    virtual bool canMoveTo(int newX, int newY, const Board& board) const = 0;

private:
    int x;
    int y;
    bool isWhite;
};

#endif // PIECE_H
