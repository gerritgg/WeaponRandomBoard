/*
 * BoardDistributor.cpp
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */


#include <iostream>
#include "BoardDistributor.h"

using namespace std;
using namespace board;

BoardDistributor::BoardDistributor() {
}

BoardDistributor::~BoardDistributor() {
}

Board* BoardDistributor::distribute(BoardInput* boardInput) {

    /*
     * The contract on this distributor needs to change drastically due to the
     * Printer that is an observer on the board now which only prints the
     * board upon certain events occurring.  This _BoardDistributor_ domain
     * might even fall away completely.
     */

    Board* board = new Board();
    return board;

}
