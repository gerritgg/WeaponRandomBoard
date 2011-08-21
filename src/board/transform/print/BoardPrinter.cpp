/*
 * BoardPrinter.cpp
 *
 *  Created on: Aug 15, 2011
 *      Author: c0rn0
 */

#include <cstddef>
#include "BoardPrinter.h"
#include "ConsoleBoardPrinter.h"
#include "HtmlBoardPrinter.h"

BoardPrinter::BoardPrinter(Board* board) {
    subject = board;
    subject->attach(this);
}

BoardPrinter::~BoardPrinter() {
}

BoardPrinter* BoardPrinter::createPrinter(BoardPrintType::PrintType printType,
        Board* board) {

    if (printType == BoardPrintType::PRINT_TYPE_PLAIN) {
        return new ConsoleBoardPrinter(board);
    }

    if (printType == BoardPrintType::PRINT_TYPE_HTML) {
        return new HtmlBoardPrinter(board);
    }

    return NULL;

}
