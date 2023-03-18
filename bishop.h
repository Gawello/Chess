#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"


class Bishop : public Piece
{
public:
    Bishop(int x, int y, bool isWhite);

    bool canMoveTo(int newX, int newY, const Board& board) const override;
};

#endif // BISHOP_H
