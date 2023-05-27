#include "game.h"
#include "board.h"
#include "rook.h"

const int DY[] = { -1, 0, 1, 0 };
const int DX[] = { 0, -1, 0, 1 };
                // U   L  D  R

Rook::Rook(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(ROOK));
    setScore(ROOK_POINTS);
}

bool Rook::isMoveValid(int y, int x) {
    Board* board = getBoard();

    if (y == getY() && x > getX())
        direction = 'R';
    else if (y == getY() && x < getX())
        direction = 'L';
    else if (x == getX() && y < getY())
        direction = 'U';
    else if (x == getX() && y > getY())
        direction = 'D';
    
    for (int d = 0; d < 4; d++)
    {
        if (d == 0 && direction != 'U')
            continue;
        else if (d == 1 && direction != 'L')
            continue;
        else if (d == 2 && direction != 'D')
            continue;
        else if (d == 3 && direction != 'R')
            continue;
        else 
            for (int i = 1; i < 8; i++)
            {
                Piece* target = board->get(getY() + i * DY[d], getX() + i * DX[d]);
                if (y == getY() + i * DY[d] && x == getX() + i*DX[d])
                {
                    if (target == EMPTY || target->getColor() != this->getColor())
                        return true;
                }
                else if (target == EMPTY)
                    continue;
                else return false;
            }
    }
    return false;
}