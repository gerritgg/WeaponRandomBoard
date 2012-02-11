/*
 * BoardPrinter.h
 *
 *  Created on: Aug 15, 2011
 *      Author: c0rn0
 */

#ifndef BOARDPRINTER_H_
#define BOARDPRINTER_H_

#include "../../Board.h"
#include "../../../util/observer/Observer.h"

class BoardPrinter : public Observer {
public:

    BoardPrinter(board::Board*);
    virtual ~BoardPrinter();

    virtual void print() = 0;

    static BoardPrinter* createPrinter(BoardPrintType::PrintType,
        board::Board*);


protected:

    board::Board* subject;

};

#endif /* BOARDPRINTER_H_ */
