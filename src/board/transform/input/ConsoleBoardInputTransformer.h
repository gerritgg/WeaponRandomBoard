/*
 * ConsoleBoardInputTransformer.h
 *
 *  Created on: Aug 11, 2011
 *      Author: c0rn0
 */

#ifndef CONSOLEBOARDINPUTTRANSFORMER_H_
#define CONSOLEBOARDINPUTTRANSFORMER_H_

#include <iostream>
#include "BoardInputTransformer.h"

using namespace std;

class ConsoleBoardInputTransformer: public BoardInputTransformer {
public:
    ConsoleBoardInputTransformer();
    ConsoleBoardInputTransformer(char *argv[]);
    virtual ~ConsoleBoardInputTransformer();

    virtual BoardInput* transform() {
        cout << "ConsoleBoardInputTransformer::transform()" << endl;
        return new BoardInput();
    }

};

#endif /* CONSOLEBOARDINPUTTRANSFORMER_H_ */
