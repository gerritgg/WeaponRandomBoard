/*
 * QueryStringBoardInputTransformer.cpp
 *
 *  Created on: 12 Nov 2011
 *      Author: c0rn0
 */

#include <stdlib.h>

#include "QueryStringBoardInputTransformer.h"
#include "../../../util/QueryStringUtil.h"

using namespace std;

QueryStringBoardInputTransformer::QueryStringBoardInputTransformer(
        string queryString) {

    _queryString = queryString;

}

QueryStringBoardInputTransformer::~QueryStringBoardInputTransformer() {
}

BoardInput* QueryStringBoardInputTransformer::transform() {

    map<string, int> boardItemsInput;
    map<string, string> queryStringMap = QueryStringUtil::queryStringToMap(
        _queryString);
    map<string, string>::iterator pos;

    for (pos = queryStringMap.begin(); pos != queryStringMap.end(); ++pos) {

        boardItemsInput[pos->first] = atoi(pos->second.c_str());

    }

    return new BoardInput(boardItemsInput);

}
