/*
 * WebFormBoardInputTransformer.cpp
 *
 *  Created on: Aug 11, 2011
 *      Author: c0rn0
 */

#include "WebFormBoardInputTransformer.h"

WebFormBoardInputTransformer::WebFormBoardInputTransformer() {
}

WebFormBoardInputTransformer::WebFormBoardInputTransformer(char *inputItems[],
        int numInputItems) : BoardInputTransformer(inputItems, numInputItems) {
}

WebFormBoardInputTransformer::~WebFormBoardInputTransformer() {
}

BoardInput* WebFormBoardInputTransformer::transform() {

    cout << "WebFormBoardInputTransformer::transform() - NumberOfInputItems : "
        << numberOfInputItems << endl;

    return new BoardInput();

}
