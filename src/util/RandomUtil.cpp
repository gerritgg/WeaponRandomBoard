/*
 * RandomUtil.cpp
 *
 *  Created on: Aug 15, 2011
 *      Author: c0rn0
 */

#include <algorithm>
#include <time.h>
#include "RandomUtil.h"

RandomUtil::RandomUtil() {
}

RandomUtil::~RandomUtil() {
}

vector<int> RandomUtil::randomise(vector<int> vectorToShuffle) {

    //Seed the system clock.
    srand(time(NULL));

    random_shuffle(vectorToShuffle.begin(), vectorToShuffle.end());

    return vectorToShuffle;

}
