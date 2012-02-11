/*
 * BoardInputTransformerFactory.cpp
 *
 *  Created on: Aug 11, 2011
 *      Author: c0rn0
 */

#include <cstddef>
#include "BoardInputTransformer.h"
#include "ConsoleBoardInputTransformer.h"
#include "QueryStringBoardInputTransformer.h"
#include "WebFormBoardInputTransformer.h"

BoardInputTransformer::BoardInputTransformer() {
}

BoardInputTransformer::BoardInputTransformer(char *inputItemsArg[],
        int numInputItems) {

    for (int var = 0; var < numInputItems; ++var) {

        inputItemsVector.push_back(inputItemsArg[var]);

    }

    numberOfInputItems = numInputItems;

}

BoardInputTransformer::~BoardInputTransformer() {
}

BoardInputTransformer* BoardInputTransformer::createTransformer(
        string inputString, int type, cgicc::Cgicc* cgicc) {

    if (type == WEB_QUERY_STRING) {
        return new QueryStringBoardInputTransformer(inputString);
    }

    if (type == WEB_FORM_TEXTAREA) {
        return new WebFormBoardInputTransformer(cgicc);
    }

    return NULL;

}

BoardInputTransformer* BoardInputTransformer::createTransformer(char *argv[],
        int numInputItems, int type) {

    if (type == CONSOLE) {
        return new ConsoleBoardInputTransformer(argv, numInputItems);
    }

    return NULL;

}
