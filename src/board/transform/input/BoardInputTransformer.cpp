/*
 * BoardInputTransformerFactory.cpp
 *
 *  Created on: Aug 11, 2011
 *      Author: c0rn0
 */

#include "BoardInputTransformer.h"
#include "ConsoleBoardInputTransformer.h"
#include "WebFormBoardInputTransformer.h"

BoardInputTransformer::BoardInputTransformer() {
    // TODO Auto-generated constructor stub

}

BoardInputTransformer::BoardInputTransformer(char *inputItemsArg[],
        int numInputItems) {

    for (int var = 0; var < numInputItems; ++var) {

        /*
         * Each item in the array must first be initialised (memory allocated)
         * otherwise program crashes with "Segmentation fault" due to accessing
         * invalid memory.
         *
         * TODO : Must figure out why 90 is necessary to make test case pass.
         */
        inputItems[var] = new char[90];

        strcpy(inputItems[var], inputItemsArg[var]);

    }

    numberOfInputItems = numInputItems;

}

BoardInputTransformer::~BoardInputTransformer() {
    // TODO Auto-generated destructor stub
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
