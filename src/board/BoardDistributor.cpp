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
    // TODO Auto-generated constructor stub

}

BoardDistributor::~BoardDistributor() {
    // TODO Auto-generated destructor stub
}

Board BoardDistributor::distribute(char *boardItems) {
    Board b;
    cout << "BoardDistributor::distribute(char *boardItems) : " << boardItems << endl;
    return b;
}

Board BoardDistributor::distribute(char *boardItems[]) {
    Board b;
    return b;
}
