/*
 * Firepoker.cpp
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */

#include "Firepoker.h"

Firepoker::Firepoker() {
}

Firepoker::Firepoker(string name) : Weapon(name) {
}

Firepoker::~Firepoker() {
}

void Firepoker::use() {
    cout << "Firepoker::use()";
}
