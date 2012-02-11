/*
 * HtmlBoardPrinter.cpp
 *
 *  Created on: Aug 19, 2011
 *      Author: c0rn0
 */

#include "HtmlBoardPrinter.h"

HtmlBoardPrinter::HtmlBoardPrinter(board::Board* board) : BoardPrinter(board) {
}

HtmlBoardPrinter::~HtmlBoardPrinter() {
}

void HtmlBoardPrinter::update(Subject* changedSubject) {


    if (subject == changedSubject) {
        print();
    }

}

void HtmlBoardPrinter::print() {

    map<int, Weapon*> weapons = subject->getWeapons();
    vector<int> weaponsIndexesShuffled = subject->getWeaponsIndexesShuffled();

    cout << "<div id='content'>" << endl;
    cout << "<table border='1'>" << endl;
    cout << "<tr><td colspan='2'>Total items on the board : "<< weapons.size()
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
    cout << "</div>";

    cout << endl;

}
