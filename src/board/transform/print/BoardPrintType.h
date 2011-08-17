/*
 * BoardPrintType.h
 *
 *  Created on: Aug 15, 2011
 *      Author: c0rn0
 */

#ifndef BOARDPRINTTYPE_H_
#define BOARDPRINTTYPE_H_


class BoardPrintType {
public:

    enum PrintType {
        PRINT_TYPE_PLAIN = 1,
        PRINT_TYPE_HTML = 2,
        PRINT_TYPE_CSV_TEXT = 3,
        PRINT_TYPE_CSV_FILE = 4,
        PRINT_TYPE_XLS_FILE = 5
    };

    BoardPrintType();
    virtual ~BoardPrintType();

};

#endif /* BOARDPRINTTYPE_H_ */
