/*
 * Weapon.h
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */

#ifndef WEAPON_H_
#define WEAPON_H_

#include <iostream>
#include <string>

using namespace std;

class Weapon {
public:

    Weapon();
    Weapon(string name);
    virtual ~Weapon();

    static Weapon* createWeapon(string name);
    /*
     * C++ Abstract Type lesson:
     * To make Weapon an abstract type so that it can't be used as a function
     * return type for example, define the method below as follows:
     * <code>virtual void use() = 0;</code>
     */
    virtual void use();
    string getName();


private:

    string name;

};

#endif /* WEAPON_H_ */
