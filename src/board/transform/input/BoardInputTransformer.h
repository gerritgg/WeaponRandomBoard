/*
 * BoardInputTransformerFactory.h
 *
 *  Created on: Aug 11, 2011
 *      Author: c0rn0
 */

#ifndef BOARDINPUTTRANSFORMER_H_
#define BOARDINPUTTRANSFORMER_H_

#include "BoardInput.h"

using namespace std;

class BoardInputTransformer {
public:

    static const int CONSOLE = 1;
    static const int WEBFORM = 2;

    BoardInputTransformer();
    BoardInputTransformer(char *inputItems[], int numInputItems);
    virtual ~BoardInputTransformer();

    virtual BoardInput* transform() = 0;
    static BoardInputTransformer* createTransformer(char *argv[],
        int numInputItems, int type);

protected:

    char *inputItems[];
    int numberOfInputItems;

};

#endif /* BOARDINPUTTRANSFORMER_H_ */
