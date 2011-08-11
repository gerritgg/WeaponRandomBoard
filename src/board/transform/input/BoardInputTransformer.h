/*
 * BoardInputTransformerFactory.h
 *
 *  Created on: Aug 11, 2011
 *      Author: c0rn0
 */

#ifndef BOARDINPUTTRANSFORMER_H_
#define BOARDINPUTTRANSFORMER_H_

#include <string>
#include "BoardInput.h"

using namespace std;

class BoardInputTransformer {
public:

    static const int CONSOLE = 1;
    static const int WEBFORM = 2;

    BoardInputTransformer();
    virtual ~BoardInputTransformer();

    virtual BoardInput* transform() = 0;
    static BoardInputTransformer* createTransformer(char *argv[], int type);

};

#endif /* BOARDINPUTTRANSFORMER_H_ */
