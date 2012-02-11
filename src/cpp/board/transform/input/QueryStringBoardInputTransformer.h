/*
 * QueryStringBoardInputTransformer.h
 *
 *  Created on: 12 Nov 2011
 *      Author: c0rn0
 */

#ifndef QUERYSTRINGBOARDINPUTTRANSFORMER_H_
#define QUERYSTRINGBOARDINPUTTRANSFORMER_H_

#include "BoardInputTransformer.h"

class QueryStringBoardInputTransformer: public BoardInputTransformer {
public:

    QueryStringBoardInputTransformer();
    QueryStringBoardInputTransformer(string queryString);
    virtual ~QueryStringBoardInputTransformer();

    virtual BoardInput* transform();

private:

    string _queryString;

};

#endif /* QUERYSTRINGBOARDINPUTTRANSFORMER_H_ */
