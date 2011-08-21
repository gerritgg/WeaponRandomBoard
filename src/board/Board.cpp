/*
 * Board.cpp
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */

#include <iostream>
#include <sstream>
#include "Board.h"
#include "../util/RandomUtil.h"
#include "transform/print/BoardPrinter.h"

using namespace std;

Logger* Board::LOGGER = Logger::getLogger("Board");

Board::Board() {
}

Board::~Board() {

    for (int var = 0; var < (int) weapons.size(); ++var) {
        delete weapons[var];
    }

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

        buildWeapon(pos->first, pos->second);

        numberOfTotalWeapons += pos->second;

    }

    randomise();

    stringstream ss;
    ss << "Number of Total weapons : " << numberOfTotalWeapons;
    LOGGER->info(ss.str());

    LOGGER->info("Board::initialise - Before notify call.");
    cout << "GOTJIR!!!!!" << endl;
    notify();
    LOGGER->info("Board::initialise - After notify call.");

}

void Board::buildWeapon(string weaponName, int weaponCount) {

    try {

        for (int var = 0; var < weaponCount; ++var) {

            weapons[weapons.size()] = Weapon::createWeapon(weaponName);

        }

    } catch (exception& e) {
        cout << "Could not create weapon : " << e.what() << endl;
    }

}

void Board::randomise() {

    for (int i = 0; i< (int) weapons.size(); ++i) {
        weaponsIndexesNotShuffled.push_back(i);
    }

    weaponsIndexShuffled = RandomUtil::randomise(weaponsIndexesNotShuffled);

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

void Board::print() {
    print(BoardPrintType::PRINT_TYPE_PLAIN);
}

void Board::print(BoardPrintType::PrintType printType) {

//    BoardPrinter *printer = BoardPrinter::createPrinter(printType);
//    printer->print(this);
//
//    delete printer;

}

map<int, Weapon*> Board::getWeapons() {
    return weapons;
}

vector<int> Board::getWeaponsIndexesShuffled() {
    return weaponsIndexShuffled;
}
