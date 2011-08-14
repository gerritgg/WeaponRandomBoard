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

    /*
     * Have to initialise var to 0, otherwise compound-assignment below does not
     * work.
     */
    int numberOfTotalWeapons = 0;

    for (pos = weaponsInput.begin(); pos != weaponsInput.end(); ++pos) {

        cout << "Board::initialise - " << "key: \"" << pos->first << "\" "
            << "value: " << pos->second << endl;

        buildWeapon(pos->first, pos->second);

        numberOfTotalWeapons += pos->second;

    }

    cout << "Number of Total weapons : " << numberOfTotalWeapons << endl;
    cout << "Confirming Number of Total weapons : " << weapons.size() << endl;

}

void Board::buildWeapon(string weaponName, int weaponCount) {

    try {
        for (int var = 0; var < weaponCount; ++var) {
            weapons[weapons.size()] = Weapon::createWeapon(weaponName);
            cout << "Board::buildWeapon - weapons.size() : " << weapons.size()
                << endl;
        }
    } catch (exception& e) {
        cout << "Could not create weapon : " << e.what() << endl;
    }

}

int Board::getNumberOfWeapons() {
    return weapons.size();
}

void Board::useAllWeapons() {

    map<int, Weapon*>::iterator pos;

    cout << "Before using all weapons - weapons.size() : " << weapons.size()
        << endl;

    for (pos = weapons.begin(); pos != weapons.end(); ++pos) {

        cout << "Weapon " << pos->first << ", Action : ";
        pos->second->use();
        cout << endl;

    }

}
