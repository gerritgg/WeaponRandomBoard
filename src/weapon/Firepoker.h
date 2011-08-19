/*
 * Firepoker.h
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */

#ifndef FIREPOKER_H_
#define FIREPOKER_H_

#include "Weapon.h"

class Firepoker: public Weapon {
public:

    Firepoker();
    Firepoker(string name);
    virtual ~Firepoker();

    virtual void use();

};

#endif /* FIREPOKER_H_ */
