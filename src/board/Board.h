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

using namespace std;

class Board {
public:

    Board();
    virtual ~Board();

    void initialise(BoardInput* boardInput);
    void useAllWeapons();
    int getNumberOfWeapons();
    void print();
    void print(BoardPrintType::PrintType printType);
    vector<int> getWeaponsIndexesShuffled();

private:

    map<int, Weapon*> weapons;
    vector<int> weaponsIndexesNotShuffled;
    vector<int> weaponsIndexShuffled;

    void buildWeapon(string weaponName, int weaponCount);
    void randomise();

};

#endif /* BOARD_H_ */
