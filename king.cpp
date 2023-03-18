#include "king.h"
#include "board.h"
#include <cstdlib>

King::King(int x, int y, bool isWgite) : Piece(x, y, isWhite)
{

}

bool King::canMoveTo(int newX, int newY, const Board& board) const
{
    // Implementacja logiki ruchów króla
    int dx = abs(newX - x);
    int dy = abs(newY - y);

    if (dx > 1 || dy > 1) {
        return false; // Król może się poruszać tylko o jedno pole
    }

    // Sprawdź, czy docelowe pole jest puste lub zajęte przez przeciwnika
    Piece* targetPiece = board.getPieceAt(newX, newY);
    if (!targetPiece || targetPiece->getIsWhite() != isWhite) {
        return true;
    }

    return false;
}
