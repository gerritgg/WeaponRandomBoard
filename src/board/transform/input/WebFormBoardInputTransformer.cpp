/*
 * WebFormBoardInputTransformer.cpp
 *
 *  Created on: Aug 11, 2011
 *      Author: c0rn0
 */

#include <boost/algorithm/string.hpp>
#include <iostream>

#include "WebFormBoardInputTransformer.h"
#include "QueryStringBoardInputTransformer.h"

WebFormBoardInputTransformer::WebFormBoardInputTransformer() {
}

WebFormBoardInputTransformer::WebFormBoardInputTransformer(
        cgicc::Cgicc* cgicc) {
    _cgicc = cgicc;
}

WebFormBoardInputTransformer::~WebFormBoardInputTransformer() {
}

BoardInput* WebFormBoardInputTransformer::transform() {

    cgicc::form_iterator boardInputString = _cgicc->getElement("boardinput");
    if( !boardInputString->isEmpty() && boardInputString != (**_cgicc).end()) {

    }

    string inputString = **_cgicc->getElement("boardinput");
    string boardName = **_cgicc->getElement("boardname");

    boost::trim_right(inputString);
    boost::replace_all(inputString, "\r\n", "&");

    BoardInput* boardInput =  (QueryStringBoardInputTransformer(inputString))
        .transform();
    boardInput->setBoardName(boardName);
    boardInput->setBoardItemsString(inputString);

    return boardInput;

}
