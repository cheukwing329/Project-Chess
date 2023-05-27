#include <iostream>
#include "machine.h"
#include "board.h"
#include <ctime>

using namespace std;

const int TRIALS = 4096;    // 64 x 64

Machine::Machine(string name, Color color) : Player(name, color) {
    // randomize the seed
    srand(static_cast<unsigned int>(time(nullptr)));
}

// a sample machine that makes random but valid moves
void Machine::makeMove(Board* board) {

    bool Canmove = 0; //check move 1time only

    for (int i = 0; i < 10 * getPieceCount(); i++) {
        int j = rand() % getPieceCount();
        Piece* p = getPiece(j);
        int y1 = p->getY();
        int x1 = p->getX();
        // TODO: 
        // write a loop to repeat below at most TRIALS times:
        if (Canmove == 0)
        {
            for (int times = 0; times < TRIALS; times++)
            {
                // - generate random integers y2 and x2 in range of [0, H) and [0, W) respectively
                int y2 = rand() % H; //remainer for in the H range
                int x2 = rand() % W;
                // - call board's move(y1, x1, y2, x2)
                if (board->move(y1, x1, y2, x2))
                {
                    // - once a valid move is returned, print the from and to cell addresses 
                    cout << this->getName() << "'s turn: "; // from human.cpp
                    cout << (char)(x1 + 65) << (y1 + 1) << " " << (char)(x2 + 65) << (y2 + 1) << endl;
                    //and exit this function
                    Canmove = 1;
                    break;
                }
            }
        }

    }
}
