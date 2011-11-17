/*
 * BoardDistributor.h
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */

#ifndef BOARDDISTRIBUTOR_H_
#define BOARDDISTRIBUTOR_H_

#include "Board.h"
#include "transform/input/BoardInput.h"

class BoardDistributor {
public:

    BoardDistributor();
    virtual ~BoardDistributor();

    static board::Board* distribute(BoardInput* boardInput);

};

#endif /* BOARDDISTRIBUTOR_H_ */
