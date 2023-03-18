#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Knight : public Piece
{
public:
    Knight(int x, int y, bool isWhite);

    bool canMoveTo(int newX, int newY, const Board& board) const override;
};

#endif // KNIGHT_H
