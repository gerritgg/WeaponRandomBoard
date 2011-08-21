/*
 * ConsoleBoardPrinter.cpp
 *
 *  Created on: Aug 15, 2011
 *      Author: c0rn0
 */

#include "ConsoleBoardPrinter.h"

ConsoleBoardPrinter::ConsoleBoardPrinter(Board* board) : BoardPrinter(board) {
}

ConsoleBoardPrinter::~ConsoleBoardPrinter() {
}

void ConsoleBoardPrinter::update(Subject* changedSubject) {

    if (subject == changedSubject) {
        print();
    }

}

void ConsoleBoardPrinter::print() {

    vector<int> weaponsIndexesShuffled = subject->getWeaponsIndexesShuffled();

    for (int var = 0; var < (int) weaponsIndexesShuffled.size(); ++var) {
        cout << " " << weaponsIndexesShuffled[var];
    }

    cout << endl;

}
