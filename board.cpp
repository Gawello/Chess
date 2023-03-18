#include "board.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

Board::Board() {
    initializeBoard();
}

Board::~Board() {
    // Usuń pionki z pamięci.
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            delete board[i][j];
        }
    }
}

Piece* Board::getPieceAt(int x, int y) const {
    return board[x][y];
}

void Board::addPiece(Piece* piece) {
    int x = piece->getX();
    int y = piece->getY();
    board[x][y] = piece;
}

void Board::removePiece(Piece* piece) {
    int x = piece->getX();
    int y = piece->getY();
    board[x][y] = nullptr;
}

bool Board::movePiece(Piece* piece, int newX, int newY) {
    // Przenieś pionek na nową pozycję, jeśli ruch jest dozwolony.


    if (piece == nullptr) {
        // Nie ma figury na pozycji (newX, newY)
        return false;
    }

    int fromX = piece->getX();
    int fromY = piece->getY();

    if (!piece->canMoveTo(newX, newY, *this)) {
        // Figura nie może się aprzemieścić na pozycję (newX, newY)
        return false;
    }

    // Usuń figury z pozycji docelowej (jeśli istnieje)
    delete getPieceAt(newX, newY);

    // Przesuń figurę na pozycję docelową
    piece->setX(newX);
    piece->setY(newY);
    board[newX][newY] = piece;
    board[fromX][fromY] = nullptr;

    return true;
}

void Board::initializeBoard() {
    // Inicjalizacja szachownicy i ustawienie pionków.
    // Należy dodać pionki do szachownicy, korzystając z addPiece.

    // Wyczyść planszę
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            board[x][y] = nullptr;
        }
    }

    //Ustaw białe pionki
    for (int x=0; x < 8; x++) {
        board[x][1]= new Pawn(x, 1, true);
    }

    // Ustaw czarne pionki
    for (int x=0; x<8; x++) {
        board[x][6] = new Pawn(x, 6, false);
    }

    //Ustaw białe figury
    board[0][0] = new Rook(0,0, true);
    board[1][0] = new Knight(1,0, true);
    board[2][0] = new Bishop(2,0, true);
    board[3][0] = new Queen(3,0, true);
    board[4][0] = new King(4,0, true);
    board[5][0] = new Bishop(5,0, true);
    board[6][0] = new Knight(6,0, true);
    board[7][0] = new Rook(7,0, true);

    // Ustaw czarne figury
    board[0][7] = new Rook(0,7, false);
    board[1][7] = new Knight(1,7, false);
    board[2][7] = new Bishop(2,7, false);
    board[3][7] = new Queen(3,7, false);
    board[4][7] = new King(4,7, false);
    board[5][7] = new Bishop(5,7, false);
    board[6][7] = new Knight(6,7, false);
    board[7][7] = new Rook(7,7, false);
}
