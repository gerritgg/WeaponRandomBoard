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

WebFormBoardInputTransformer::WebFormBoardInputTransformer(string inputString) {
    _inputString = inputString;
}

WebFormBoardInputTransformer::~WebFormBoardInputTransformer() {
}

BoardInput* WebFormBoardInputTransformer::transform() {

    boost::trim_right(_inputString);
    boost::replace_all(_inputString, "\r\n", "&");

    return (QueryStringBoardInputTransformer(_inputString)).transform();

}
