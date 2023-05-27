#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
private:
    char direction;
    int d;
public:
    Rook(Color color, int y, int x, Board* board);
    virtual bool isMoveValid(int y, int x);
};

#endif /* ROOK_H */