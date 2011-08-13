/*
 * BoardInput.cpp
 *
 *  Created on: Aug 11, 2011
 *      Author: c0rn0
 */

#include "BoardInput.h"

BoardInput::BoardInput() {
    // TODO Auto-generated constructor stub

}

BoardInput::BoardInput(map<string, int> weaponsInput)
        : weaponsInput(weaponsInput) {

}

BoardInput::~BoardInput() {
    // TODO Auto-generated destructor stub
}

map<string, int> BoardInput::getWeaponsInput() {
    return weaponsInput;
}
