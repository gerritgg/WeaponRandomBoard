/*
 * Board.h
 *
 *  Created on: Aug 8, 2011
 *      Author: c0rn0
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include "BoardVO.h"
#include "transform/input/BoardInput.h"
#include "transform/print/BoardPrintType.h"
#include "../weapon/Weapon.h"
#include "../util/Logger.h"
#include "../util/observer/Subject.h"

using namespace std;

namespace board {

class Board : public Subject {
public:

    Board();
    virtual ~Board();

    void initialise(BoardInput* boardInput);
    void useAllWeapons();
    int getNumberOfWeapons();
    void print();
    void print(BoardPrintType::PrintType printType);
    map<int, Weapon*> getWeapons();
    vector<int> getWeaponsIndexesShuffled();
    string getName();
    string itemsToString();

private:

    static Logger* LOGGER;

    map<int, Weapon*> weapons;
    vector<int> weaponsIndexesNotShuffled;
    vector<int> weaponsIndexShuffled;
    string name;
    string itemsString;

    void buildWeapon(string weaponName, int weaponCount);
    void randomise();

};

} /* namespace board */
#endif /* BOARD_H_ */
