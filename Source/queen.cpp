#include "game.h"
#include "board.h"
#include "queen.h"

const int DY[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
const int DX[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
                 //UN, DN, NL, NR, UL, UR, DL, DR


Queen::Queen(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(QUEEN));
    setScore(QUEEN_POINTS);
}

bool Queen::isMoveValid(int y, int x) {
    Board* board = getBoard();

    if (y > getY())
        directionY = 'D';
    else if (y < getY())
        directionY = 'U';
    else if (y == getY())
        directionY = 'N';

    if (x > getX())
        directionX = 'R';
    else if (x < getX())
        directionX = 'L';
    else if (x == getX())
        directionX = 'N';


    if (directionY == 'U' && directionX == 'N')
        d = 0;
    else if (directionY == 'D' && directionX == 'N')
        d = 1;
    else if (directionY == 'N' && directionX == 'L')
        d = 2;
    else if (directionY == 'N' && directionX == 'R')
        d = 3;
    else if (directionY == 'U' && directionX == 'L')
        d = 4;
    else if (directionY == 'U' && directionX == 'R')
        d = 5;
    else if (directionY == 'D' && directionX == 'L')
        d = 6;
    else if (directionY == 'D' && directionX == 'R')
        d = 7;

        for (int i = 1; i < 8; i++)
        {
            Piece* target = board->get(getY() + i * DY[d], getX() + i * DX[d]);
            if (y == getY() + i * DY[d] && x == getX() + i * DX[d])
            {
                if (target == EMPTY || target->getColor() != this->getColor())
                    return true;
            }
            else if (target == EMPTY)
                continue;
            else return false;
        }
    return false;
}