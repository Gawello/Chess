#include "pawn.h"
#include "board.h"
#include <cstdlib>

Pawn::Pawn(int x, int y, bool isWhite) : Piece(x, y, isWhite) {}

bool Pawn::canMoveTo(int newX, int newY, const Board& board) const
{
    // Implementacja logiki ruchu pionów
    int dx = newX - x;
    int dy = newY - y;

    if (isWhite) { // Białe
        if (dx == 0 && dy == 1 && !board.getPieceAt(newX, newY)) {
            return true;
        }

        if (y == 1 && dx == 0 && dy == 2 && !board.getPieceAt(newX, newY) && !board.getPieceAt(newX, newY-1)) {
            return true;
        }

        if (abs(dx) == 1 && dy == 1 && board.getPieceAt(newX, newY) && board.getPieceAt(newX, newY)->getIsWhite() != isWhite) {
            return true;
        }
    } else { //Czarne
        if (dx == 0 && dy == -1 && !board.getPieceAt(newX, newY)) {
            return true;
        }

        if (y == 6 && dx == 0 && dy == -2 && !board.getPieceAt(newX, newY) && !board.getPieceAt(newX, newY + 1)) {
            return true;
        }

        if (abs(dx) == 1 && dy == -1 && board.getPieceAt(newX, newY) && board.getPieceAt(newX, newY)->getIsWhite() != isWhite) {
            return true;
        }
    }

}
