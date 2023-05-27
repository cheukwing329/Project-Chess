#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
private:
    char directionX, directionY;
    int d;
public:
    Bishop(Color color, int y, int x, Board* board);
    virtual bool isMoveValid(int y, int x);
};

#endif /* BISHOP_H */