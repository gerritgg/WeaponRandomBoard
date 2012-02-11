/*
 * QueryStringUtil.h
 *
 *  Created on: 12 Nov 2011
 *      Author: c0rn0
 */

#ifndef QUERYSTRINGUTIL_H_
#define QUERYSTRINGUTIL_H_

#include <map>
#include <string>

using namespace std;

class QueryStringUtil {
public:

    QueryStringUtil();
    virtual ~QueryStringUtil();

    static map<string, string> queryStringToMap(string qs) {

        map<string, string> returnMap;

        bool in_name = true;
        size_t n = qs.size(), i, start = 0;
        string name;

        for (i = 0; i < n; ++i) {

            if (in_name) {

                if (qs[i] == '=') {
                    name = val_cvt(qs, start, i);
                    start = i + 1;
                    in_name = false;
                } else if (qs[i] == '&') {
                    name = val_cvt(qs, start, i);
                    returnMap[name] = "";
                    start = i + 1;
                }

            } else {

                if (qs[i] == '&') {
                    returnMap[name] = val_cvt(qs, start, i);
                    start = i + 1;
                    name = "";
                    in_name = true;
                }

            }

        }

        if (in_name && name != "") {
            returnMap[val_cvt(qs, start, i)] = "";
        } else {
            returnMap[name] = val_cvt(qs, start, i);
        }

        return returnMap;

    }

private:

    static unsigned char unhex(char c) {

        switch (c) {

            case '0': return 0; case '5': return 5;
            case '1': return 1; case '6': return 6;
            case '2': return 2; case '7': return 7;
            case '3': return 3; case '8': return 8;
            case '4': return 4; case '9': return 9;
            case 'a':       case 'A': return 10;
            case 'b':       case 'B': return 11;
            case 'c':       case 'C': return 12;
            case 'd':       case 'D': return 13;
            case 'e':       case 'E': return 14;
            case 'f':       default : return 15;

        }

    }

    static string val_cvt(string q, size_t start, size_t end) {

        size_t i = start, n = 0;
        unsigned char c1;
        char *buf = new char[end - start];

        while (i < end) {

            c1 = q[i++];
            if (c1 == '%') {
                if (i + 3 > end)
                    break;
                buf[n++] = unhex(q[i + 1]) << 4 | unhex(q[i + 2]);
                i += 2;
            } else if (c1 == '+')
                buf[n++] = ' ';
            else
                buf[n++] = c1;
        }

        q = string(buf, n);
        delete[] buf;
        return q;

    }

};

#endif /* QUERYSTRINGUTIL_H_ */
