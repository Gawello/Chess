#ifndef PIECE_H
#define PIECE_H

class Board;

class Piece
{
public:
    Piece(int x, int y, bool isWhite);

    virtual ~Piece();

    int getX() const;
    int getY() const;
    bool getIsWhite() const;
    void setX(int newX);
    void setY(int newY);

    virtual bool canMoveTo(int newX, int newY, const Board& board) const = 0;

protected:
    int x;
    int y;
    bool isWhite;
};

#endif // PIECE_H
