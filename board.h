#ifndef BOARD_H
#define BOARD_H
#include <array>
#include "piece.h"

class Board {
public:
    Board();
    ~Board();

    Piece* getPieceAt(int x, int y) const;
    void addPiece(Piece* piece);
    void removePiece(Piece* piece);
    bool movePiece(Piece* piece, int newX, int newY);

private:
    std::array<std::array<Piece*, 8>, 8> board;
    void initializeBoard();
};
#endif // BOARD_H
