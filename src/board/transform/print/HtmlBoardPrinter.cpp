/*
 * HtmlBoardPrinter.cpp
 *
 *  Created on: Aug 19, 2011
 *      Author: c0rn0
 */

#include "HtmlBoardPrinter.h"

HtmlBoardPrinter::HtmlBoardPrinter() {
}

HtmlBoardPrinter::~HtmlBoardPrinter() {
}

void HtmlBoardPrinter::print(Board* board) {

    map<int, Weapon*> weapons = board->getWeapons();
    vector<int> weaponsIndexesShuffled = board->getWeaponsIndexesShuffled();

    cout << "<table border='1'>" << endl;
    cout << "<tr><td colspan='2'>Total weapons : "<< weapons.size()
        << "</td></tr>";

    int i = 0;

    for (int var = 0; var < (int) weaponsIndexesShuffled.size(); ++var) {

        map<int, Weapon*>::iterator it;
        it = weapons.find(weaponsIndexesShuffled[var]);

        if (it != weapons.end()) {

            cout << "<tr><td>" << ++i << "</td><td>" << it->second->getName()
                << "</td></tr>" << endl;

        }

    }

    cout << "</table>";

    cout << endl;

}
