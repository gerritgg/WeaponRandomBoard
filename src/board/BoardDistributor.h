/*
 * BoardDistributor.h
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */

#ifndef BOARDDISTRIBUTOR_H_
#define BOARDDISTRIBUTOR_H_

#include "Board.h"

class BoardDistributor {
public:

    BoardDistributor();
    virtual ~BoardDistributor();

    Board distribute(char *boardItems);
    Board distribute(char *boardItems[]);

};

#endif /* BOARDDISTRIBUTOR_H_ */
