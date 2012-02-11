/*
 * BoardInput.h
 *
 *  Created on: Aug 11, 2011
 *      Author: c0rn0
 */

#ifndef BOARDINPUT_H_
#define BOARDINPUT_H_

#include <map>
#include <string>
#include <vector>

using namespace std;

class BoardInput {
public:

    BoardInput();
    BoardInput(map<string, int> weaponsInput);
    virtual ~BoardInput();

    map<string, int> getWeaponsInput();
    string getBoardName();
    void setBoardName(string boardName);
    string getBoardItemsString();
    void setBoardItemsString(string boardItemsString);

private:

    map<string, int> weaponsInput;
    string _boardName;
    string _boardItemsString;

};

#endif /* BOARDINPUT_H_ */
