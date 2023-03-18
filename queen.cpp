#include "queen.h"
#include "board.h"
#include "rook.h"
#include "bishop.h"

Queen::Queen(int x, int y, bool isWhite) : Piece(x, y, isWhite)
{

}

bool Queen::canMoveTo(int newX, int newY, const Board& board) const
{
    // Implementacja logiki ruchów królowej
    // Królowa łączy w sobie ruchy wieży (rook) i gońca (bishop)
    // dlatego korzystam z metod utworzonych już w tych figurach
    Rook rook(x, y, isWhite);
    Bishop bishop(x, y, isWhite);

    return rook.canMoveTo(newX, newY, board) || bishop.canMoveTo(newX, newY, board);
}
