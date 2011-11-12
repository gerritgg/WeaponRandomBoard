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
        string queryString) {

    return new QueryStringBoardInputTransformer(queryString);

}

BoardInputTransformer* BoardInputTransformer::createTransformer(char *argv[],
        int numInputItems, int type) {

    if (type == CONSOLE) {
        return new ConsoleBoardInputTransformer(argv, numInputItems);
    }

    if (type == WEBFORM) {
        return new WebFormBoardInputTransformer(argv, numInputItems);
    }

    return NULL;

}
