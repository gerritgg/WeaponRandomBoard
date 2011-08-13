/*
 * BoardDistributor.cpp
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */

#include <iostream>
using namespace std;

#include "BoardDistributor.h"

BoardDistributor::BoardDistributor() {
}

BoardDistributor::~BoardDistributor() {
}

Board BoardDistributor::distribute(BoardInput* boardInput) {

    Board b;
    b.initialise(boardInput);
    return b;

}
