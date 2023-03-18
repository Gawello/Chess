#include "bishop.h"
#include "board.h"
#include <stdlib.h>

Bishop::Bishop(int x, int y, bool isWhite) : Piece(x, y, isWhite)
{

}

bool Bishop::canMoveTo(int newX, int newY, const Board& board) const
{
    // Implementacja logiki ruchów gońca
    int dx = abs(newX - x);
    int dy = abs(newY - y);

    if (dx != dy) {
        return false; // Ruch nie jest po przekątnej
    }

    // Sprawdź, czy istnieją inne figury blokujące ruch
    int stepX = (newX > x) ? 1 : -1;
    int stepY = (newY > y) ? 1 : -1;
    int currentX = x + stepX;
    int currentY = y + stepY;

    while (currentX != newX || currentY != newY) {
        if (board.getPieceAt(currentX, currentY)) {
            return false; // Istnieje figura blokująca ruch
        }

        currentX += stepX;
        currentY += stepY;

        // Sprawdź, czy docelowe pole jest puste lub zajęte przez przeciwnika
        Piece* targetPiece = board.getPieceAt(newX, newY);
        if (!targetPiece || targetPiece->getIsWhite() != isWhite) {
            return true;
        }

        return false;
    }
}
