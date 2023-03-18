#ifndef ROOK_H
#define ROOK_H
#include "piece.h"


class Rook : public Piece
{
public:
    Rook(int x, int y, bool isWhite);

    bool canMoveTo(int newX, int newY, const Board& board) const override;
};

#endif // ROOK_H
