/*
 * BoardPrinter.h
 *
 *  Created on: Aug 15, 2011
 *      Author: c0rn0
 */

#ifndef BOARDPRINTER_H_
#define BOARDPRINTER_H_

#include "../../Board.h"

class BoardPrinter {
public:

    BoardPrinter();
    virtual ~BoardPrinter();

    virtual void print(Board* board) = 0;

    static BoardPrinter* createPrinter(BoardPrintType::PrintType printType);

};

#endif /* BOARDPRINTER_H_ */
