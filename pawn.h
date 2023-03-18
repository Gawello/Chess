#ifndef PAWN_H
#define PAWN_H

#include "piece.h"


class Pawn : public Piece {
public:
    Pawn(int x, int y, bool isWhite);

    bool canMoveTo(int newX, int newY, const Board& board) const override;
};

#endif // PAWN_H
