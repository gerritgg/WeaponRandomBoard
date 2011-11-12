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

Weapon::Weapon(string weaponName) {
    name = weaponName;
}

Weapon::~Weapon() {
}

Weapon* Weapon::createWeapon(string name) {

    if (name == "firepoker") {
        return new Firepoker(name);
    }

    if (name == "gun") {
        return new Gun(name);
    }

    if (name == "knife") {
        return new Knife(name);
    }

    if (name == "rope") {
        return new Rope(name);
    }

    return new Weapon(name);
//    throw new CouldNotCreateWeaponException();

}

void Weapon::use() {

}

string Weapon::getName() {
    return name;
}
