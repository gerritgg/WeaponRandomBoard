/*
 * HtmlBoardPrinter.h
 *
 *  Created on: Aug 19, 2011
 *      Author: c0rn0
 */

#ifndef HTMLBOARDPRINTER_H_
#define HTMLBOARDPRINTER_H_

#include "BoardPrinter.h"

class HtmlBoardPrinter: public BoardPrinter {
public:

    HtmlBoardPrinter(Board*);
    virtual ~HtmlBoardPrinter();

    virtual void print();
    virtual void update(Subject*);

};

#endif /* HTMLBOARDPRINTER_H_ */
