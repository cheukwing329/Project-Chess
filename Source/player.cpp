#include "player.h"
#include <iostream>
using namespace std;

Player::Player(string name, Color color) {
    this->name = name;
    this->color = color;
}

string Player::getName() const {
    return name;
}

Color Player::getColor() const {
    return color;
}

int Player::getPieceCount() const {
    return (int) pieces.size();
}

Piece* Player::getPiece(int i) const {
    // TODO: 
    // Get the piece indexed at i from the pieces vector
    return pieces[i];
}

void Player::addPiece(Piece* p) {
    // TODO: 
    // Add p to the pieces vector
    pieces.push_back(p);
}

void Player::delPiece(Piece* p) {
    // TODO: 
    // Remove p from the pieces vector
    for (int i = 0; i < getPieceCount(); i++)
    {
        if (pieces[i] == p)
        {
            pieces.erase(pieces.begin() + i);
            break;
        }
    }
}
