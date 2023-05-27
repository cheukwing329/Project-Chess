#include "game.h"
#include "board.h"
#include "bishop.h"
#include <iostream>

const int DY[] = { -1, -1, 1, 1 };
const int DX[] = { -1, 1, -1, 1 };
                 //UL UR  DL DR

Bishop::Bishop(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(BISHOP));
    setScore(BISHOP_POINTS);
}

bool Bishop::isMoveValid(int y, int x) {
    Board* board = getBoard();

    if (y > getY())
        directionY = 'D';
    if (y < getY())
        directionY = 'U';
    if (x > getX())
        directionX = 'R';
    if (x < getX())
        directionX = 'L';

    if (directionY == 'U' && directionX == 'L')
        d = 0;
    else if (directionY == 'U' && directionX == 'R')
        d = 1;
    else if (directionY == 'D' && directionX == 'L')
        d = 2;
    else if (directionY == 'D' && directionX == 'R')
        d = 3;

    for (int i = 1; i < 8; i++)
    {
        Piece* target = board->get(getY() + i * DY[d], getX() + i * DX[d]);

        if (y == getY() + (i * DY[d]) && x == getX() + (i* DX[d]))
        {
            if (target == EMPTY || target->getColor() != this->getColor())
                return true;
        }
        else if (target == EMPTY)
            continue;
        else 
            return false;
    }
    return false;
}