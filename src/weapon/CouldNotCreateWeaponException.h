/*
 * CouldNotCreateWeaponException.h
 *
 *  Created on: Aug 14, 2011
 *      Author: c0rn0
 */

#ifndef COULDNOTCREATEWEAPONEXCEPTION_H_
#define COULDNOTCREATEWEAPONEXCEPTION_H_

#include <exception>

class CouldNotCreateWeaponException: public std::exception {
public:

    virtual const char* what() const throw();

};

#endif /* COULDNOTCREATEWEAPONEXCEPTION_H_ */
