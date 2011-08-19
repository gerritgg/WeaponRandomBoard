/*
 * Knife.h
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */

#ifndef KNIFE_H_
#define KNIFE_H_

#include "Weapon.h"

class Knife: public Weapon {
public:

    Knife();
    Knife(string name);
    virtual ~Knife();

    virtual void use();

};

#endif /* KNIFE_H_ */
