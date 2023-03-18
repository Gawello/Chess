#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece
{
public:
    Queen(int x, int y, bool isWhite);

    bool canMoveTo(int newX, int newY, const Board& board) const override;
};

#endif // QUEEN_H
