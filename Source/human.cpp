#include <iostream>
#include "human.h"
#include "game.h"
#include "board.h"

using namespace std;

Human::Human(string name, Color color) : Player(name, color) { }

void Human::makeMove(Board* board) {
    while (true) {
        cout << this->getName() <<  "'s turn: ";
        char c1, c2;    // columns letters
        int r1, r2;     // row indexes (begin at 1)
        cin >> c1 >> r1 >> c2 >> r2;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "invalid input!" << endl;
            continue;
        }
        
        // ad hoc stop condition
        if (c1 == 'Z' && c2 == 'Z' && r1 == 0 && r2 == 0) {
            board->getGame()->setState(STOPPED);
            return;
        }
        
        // TODO:
        // Convert r1, c1 and r2, c2 into integers y1, x1, y2, x2 
        //cout << "r1r2c1c2 " << r1 << " " << r2 << " " << c1 << " " << (int)c2 << endl; //debug only

        int y1, y2, x1, x2;
        y1 = r1 - 1; //array start from 0
        y2 = r2 - 1;

        if ((int)c1 > 96 && (int)c1 < 123)
            x1 = (int)c1 - 97; //'a' = 97 in ascii
        else
            x1 = (int)c1 - 65; //'A' = 65 in ascii

        if ((int)c2 > 96 && (int)c1 < 123)
            x2 = (int)c2 - 97; //'a' = 97 in ascii
        else
            x2 = (int)c2 - 65; //'A' = 65 in ascii
        //cout << "y1y2x1x2 " << y1 << " " << y2 << " " << x1 << " " << x2 << endl;//debug only

        bool valid = board->move(y1, x1, y2, x2);
        if (valid)
            break;
        cout << "invalid input!" << endl;
    }
}
