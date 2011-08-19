/*
 * Knife.cpp
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */

#include "Knife.h"

Knife::Knife() {
}

Knife::Knife(string name) : Weapon(name) {
}

Knife::~Knife() {
}

void Knife::use() {
    cout << "Knife::use()";
}
