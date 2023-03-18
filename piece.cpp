#include "piece.h"


Piece::Piece(int x, int y, bool isWhite) : x(x), y(y), isWhite(isWhite) {}

Piece::~Piece() {}

int Piece::getX() const { return x; }
int Piece::getY() const { return y; }
bool Piece::getIsWhite() const { return isWhite; }
void Piece::setX(int newX) { x = newX; }
void Piece::setY(int newY) { y = newY; }
