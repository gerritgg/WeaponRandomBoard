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

BoardInputTransformer::~BoardInputTransformer() {
    // TODO Auto-generated destructor stub
}

BoardInputTransformer* BoardInputTransformer::createTransformer(char *argv[],
        int type) {

    if (type == CONSOLE) {
        return new ConsoleBoardInputTransformer(argv);
    }

    if (type == WEBFORM) {
        return new WebFormBoardInputTransformer(argv);
    }

    return NULL;

}
