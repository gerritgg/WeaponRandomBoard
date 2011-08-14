/*
 * CouldNotCreateWeaponException.cpp
 *
 *  Created on: Aug 14, 2011
 *      Author: c0rn0
 */

#include "CouldNotCreateWeaponException.h"

const char* CouldNotCreateWeaponException::what() const throw() {
        return "Could not create weapon.";
}
