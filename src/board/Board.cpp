/*
 * Board.cpp
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */

#include <iostream>
#include "Board.h"

using namespace std;

Board::Board() {
}

Board::~Board() {
}

void Board::initialise(BoardInput* boardInput) {

    map<string, int> weaponsInput = boardInput->getWeaponsInput();
    map<string, int>::iterator pos;

    for (pos = weaponsInput.begin(); pos != weaponsInput.end(); ++pos) {
        cout << "Board::initialise - " << "key: \"" << pos->first << "\" "
            << "value: " << pos->second << endl;
    }

}

int Board::getNumberOfWeapons() {
    return weapons.size();
}
