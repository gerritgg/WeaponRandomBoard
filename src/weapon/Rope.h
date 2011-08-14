/*
 * Rope.h
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */

#ifndef ROPE_H_
#define ROPE_H_

#include "Weapon.h"

class Rope: public Weapon {
public:

    Rope();
    virtual ~Rope();

    virtual void use();

};

#endif /* ROPE_H_ */
