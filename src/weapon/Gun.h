/*
 * Gun.h
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */

#ifndef GUN_H_
#define GUN_H_

#include "Weapon.h"

class Gun: public Weapon {
public:

    Gun();
    Gun(string name);
    virtual ~Gun();

    virtual void use();

};

#endif /* GUN_H_ */
