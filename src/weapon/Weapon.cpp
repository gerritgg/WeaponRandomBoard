/*
 * Weapon.cpp
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */

#include "Weapon.h"
#include "Firepoker.h"
#include "Gun.h"
#include "Knife.h"
#include "Rope.h"
#include "CouldNotCreateWeaponException.h"

Weapon::Weapon() {
}

Weapon::~Weapon() {
}

Weapon* Weapon::createWeapon(string name) {

    if (name == "firepoker") {
        return new Firepoker();
    }

    if (name == "gun") {
        return new Gun();
    }

    if (name == "knife") {
        return new Knife();
    }

    if (name == "rope") {
        return new Rope();
    }

    throw new CouldNotCreateWeaponException();

}

void Weapon::use() {

}
