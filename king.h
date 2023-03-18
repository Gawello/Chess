#ifndef KING_H
#define KING_H
#include "piece.h"

class King : public Piece
{
public:
    King(int x, int y, bool isWhite);

    bool canMoveTo(int newX, int newY, const Board& board) const override;
};

#endif // KING_H
