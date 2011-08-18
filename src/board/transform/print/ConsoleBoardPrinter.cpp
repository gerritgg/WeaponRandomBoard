/*
 * ConsoleBoardPrinter.cpp
 *
 *  Created on: Aug 15, 2011
 *      Author: c0rn0
 */

#include "ConsoleBoardPrinter.h"

ConsoleBoardPrinter::ConsoleBoardPrinter() {
}

ConsoleBoardPrinter::~ConsoleBoardPrinter() {
}

void ConsoleBoardPrinter::print(Board* board) {

    vector<int> weaponsIndexesShuffled = board->getWeaponsIndexesShuffled();

    for (int var = 0; var < (int) weaponsIndexesShuffled.size(); ++var) {
        cout << " " << weaponsIndexesShuffled[var];
    }

    cout << endl;

}
