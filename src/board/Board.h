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
#include "../weapon/Weapon.h"

using namespace std;

class Board {
public:

    Board();
    virtual ~Board();

    int getNumberOfWeapons();
    void initialise(BoardInput* boardInput);

private:

    vector<Weapon> weapons;

};

#endif /* BOARD_H_ */
