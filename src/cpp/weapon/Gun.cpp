/*
 * Gun.cpp
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */

#include "Gun.h"

Gun::Gun() {
}

Gun::Gun(string name) : Weapon(name) {
}

Gun::~Gun() {
}

void Gun::use() {
    cout << "Gun::use()";
}
