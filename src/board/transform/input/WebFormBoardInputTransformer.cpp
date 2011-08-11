/*
 * WebFormBoardInputTransformer.cpp
 *
 *  Created on: Aug 11, 2011
 *      Author: c0rn0
 */

#include "WebFormBoardInputTransformer.h"

WebFormBoardInputTransformer::WebFormBoardInputTransformer() {
    // TODO Auto-generated constructor stub

}

WebFormBoardInputTransformer::WebFormBoardInputTransformer(char *argv[]) {

}

WebFormBoardInputTransformer::~WebFormBoardInputTransformer() {
    // TODO Auto-generated destructor stub
}

BoardInput* WebFormBoardInputTransformer::transform() {
    cout << "WebFormBoardInputTransformer::transform()" << endl;
    return new BoardInput();
}
