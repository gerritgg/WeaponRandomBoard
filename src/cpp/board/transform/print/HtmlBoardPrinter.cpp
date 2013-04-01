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

    cout << "<table cellpadding=\"0\" cellspacing=\"0\" border=\"0\" class=\"display\" id=\"board\" width=\"100%\">" << endl;
    cout << "<thead>";
    cout << "<tr>";
    cout << "<th>Number</th>";
    cout << "<th>Name</th>";
    cout << "</tr>";
    cout << "</thead>";
    cout << "<tbody>";
    cout << "<tbody>";

    int i = 0;

    for (int var = 0; var < (int) weaponsIndexesShuffled.size(); ++var) {

        map<int, Weapon*>::iterator it;
        it = weapons.find(weaponsIndexesShuffled[var]);

        if (it != weapons.end()) {

            if ((i & 1) == 0) {
                cout << "<tr class=\"even gradeA\">";
            } else {
                cout << "<tr class=\"odd gradeA\">";
            }

            cout << "<td>" << ++i << " - " << it->second->getName()
                << "</td></tr>" << endl;

        }

    }

    cout << "</tbody>";
    cout << "<tfoot>";
    cout << "<tr>";
    cout << "<th>Number</th>";
    cout << "<th>Name</th>";
    cout << "</tr>";
    cout << "</tfoot>";
    cout << "</table>";

    cout << endl;

}
