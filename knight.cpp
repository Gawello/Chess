#include "knight.h"
#include "board.h"
#include <cstdlib>


Knight::Knight(int x, int y, bool isWhite) : Piece(x, y, isWhite)
{

}

bool Knight::canMoveTo(int newX, int newY, const Board& board) const
{
    // Implementacja logiki ruchów skoczka
    int dx = abs(newX - x);
    int dy = abs(newY - y);

    if ((dx == 2 && dy == 1) || dx == 1 && dy == 2) {
        Piece* targetPiece = board.getPieceAt(newX, newY);
        if (!targetPiece || targetPiece->getIsWhite() != isWhite) {
            return true;
        }
    }

    return false;

}
