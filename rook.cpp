#include "rook.h"
#include "board.h"

Rook::Rook(int x, int y, bool isWhite) : Piece(x, y, isWhite)
{

}

bool Rook::canMoveTo(int newX, int newY, const Board& board) const
{
    int dx = newX - x;
    int dy = newY - y;

    if (dx != 0 && dy != 0) {
        return false; // Ruch nie jest dostępny w linii prostej
    }

    // Sprawdź, czy istnieją inne figury blokujące ruch
    int stepX = (dx != 0) ? (dx > 0 ? 1 : -1) : 0;
    int stepY = (dy != 0) ? (dy > 0 ? 1 : -1) : 0;
    int currentX = x + stepX;
    int currentY = y + stepY;

    while (currentX != newX || currentY != newY) {
        if (board.getPieceAt(currentX, currentY)) {
            return false; // Istenieje figura blokująca ruch
        }

        currentX += stepX;
        currentY += stepY;
    }

    // Sprawdź,czy docelowe pole jest puste lub zajęte przez przeciwnika
    Piece* targetPiece = board.getPieceAt(newX, newY);
    if (!targetPiece || targetPiece->getIsWhite() != isWhite) {
        return true;
    }
}
