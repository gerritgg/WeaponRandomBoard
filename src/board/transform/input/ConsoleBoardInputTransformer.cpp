/*
 * ConsoleBoardInputTransformer.cpp
 *
 *  Created on: Aug 11, 2011
 *      Author: c0rn0
 */

#include "ConsoleBoardInputTransformer.h"

ConsoleBoardInputTransformer::ConsoleBoardInputTransformer() {
}

ConsoleBoardInputTransformer::ConsoleBoardInputTransformer(char *inputItems[],
        int numInputItems) : BoardInputTransformer(inputItems, numInputItems) {
}

ConsoleBoardInputTransformer::~ConsoleBoardInputTransformer() {
}

BoardInput* ConsoleBoardInputTransformer::transform() {

    map<string, int> weaponsInput;

    for (int var = 0; var < numberOfInputItems; ++var) {

        vector<string> weaponCountSplit = StringUtil::split(inputItems[var],
            ':');

        if (weaponCountSplit.size() > 0) {
            weaponsInput[weaponCountSplit[0]] = atoi(weaponCountSplit[1]
                .c_str());
        }

    }

    return new BoardInput(weaponsInput);

}
