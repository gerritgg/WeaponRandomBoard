/*
 * WebFormBoardInputTransformer.h
 *
 *  Created on: Aug 11, 2011
 *      Author: c0rn0
 */

#ifndef WEBFORMBOARDINPUTTRANSFORMER_H_
#define WEBFORMBOARDINPUTTRANSFORMER_H_

#include <iostream>

#include "BoardInputTransformer.h"

using namespace std;

class WebFormBoardInputTransformer: public BoardInputTransformer {
public:

    WebFormBoardInputTransformer();
    WebFormBoardInputTransformer(string inputString);
    virtual ~WebFormBoardInputTransformer();

    virtual BoardInput* transform();

private:

    string _inputString;

};

#endif /* WEBFORMBOARDINPUTTRANSFORMER_H_ */
