/*
 * StringUtil.h
 *
 *  Created on: Aug 13, 2011
 *      Author: c0rn0
 */

#ifndef STRINGUTIL_H_
#define STRINGUTIL_H_

#include <string>
#include <sstream>
#include <vector>

using namespace std;

class StringUtil {
public:

    StringUtil();
    virtual ~StringUtil();

    static vector<string> split(const string &s, char delim) {

        //First validate that the delimiter is present in the string.
        size_t found = s.find(delim);

        if (found != string::npos) {

            //Delimiter found in string.
            vector<string> elems;
            return split(s, delim, elems);

        }

        //Delimiter not found, return empty vector.
        vector<string> elems;
        return elems;

    }

private:

    static vector<string> &split(const string &s, char delim,
            vector<string> &elems) {

        stringstream ss(s);
        string item;

        while(getline(ss, item, delim)) {
            elems.push_back(item);
        }

        return elems;

    }

};

#endif /* STRINGUTIL_H_ */
