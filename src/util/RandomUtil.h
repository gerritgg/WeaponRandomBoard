/*
 * RandomUtil.h
 *
 *  Created on: Aug 15, 2011
 *      Author: c0rn0
 */

#ifndef RANDOMUTIL_H_
#define RANDOMUTIL_H_

#include <vector>

using namespace std;

class RandomUtil {
public:

    RandomUtil();
    virtual ~RandomUtil();

    static vector<int> randomise(vector<int> vectorToShuffle);

};

#endif /* RANDOMUTIL_H_ */
