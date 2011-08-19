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

BoardPrinter::BoardPrinter() {
}

BoardPrinter::~BoardPrinter() {
}

BoardPrinter* BoardPrinter::createPrinter(BoardPrintType::PrintType printType) {

    if (printType == BoardPrintType::PRINT_TYPE_PLAIN) {
        return new ConsoleBoardPrinter();
    }

    if (printType == BoardPrintType::PRINT_TYPE_HTML) {
        return new HtmlBoardPrinter();
    }

    return NULL;

}
