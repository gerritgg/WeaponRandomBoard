/*
 * ConsoleBoardPrinter.h
 *
 *  Created on: Aug 15, 2011
 *      Author: c0rn0
 */

#ifndef CONSOLEBOARDPRINTER_H_
#define CONSOLEBOARDPRINTER_H_

#include "BoardPrinter.h"

class ConsoleBoardPrinter: public BoardPrinter {
public:

    ConsoleBoardPrinter();
    virtual ~ConsoleBoardPrinter();

    virtual void print(Board* board);

};

#endif /* CONSOLEBOARDPRINTER_H_ */
