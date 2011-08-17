/*
 * BoardPrinter.cpp
 *
 *  Created on: Aug 15, 2011
 *      Author: c0rn0
 */

#include <cstddef>
#include "BoardPrinter.h"
#include "ConsoleBoardPrinter.h"

BoardPrinter::BoardPrinter() {
}

BoardPrinter::~BoardPrinter() {
}

BoardPrinter* BoardPrinter::createPrinter(BoardPrintType::PrintType printType) {

    if (printType == BoardPrintType::PRINT_TYPE_PLAIN) {
        return new ConsoleBoardPrinter();
    }

    return NULL;

}
