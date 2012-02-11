/*
 * BoardStoreManager.h
 *
 *  Created on: 17 Nov 2011
 *      Author: c0rn0
 */

#ifndef BOARDSTOREMANAGER_H_
#define BOARDSTOREMANAGER_H_

#include "../Board.h"
#include "BoardStoreType.h"

namespace board {
namespace persist {

class BoardStoreManager : public Observer {
public:

    BoardStoreManager(board::Board*);
    virtual ~BoardStoreManager();

    virtual void save() = 0;

    static BoardStoreManager* createStoreManager(BoardStoreType::StoreType,
        Board*);

protected:

    Board* subject;

};

} /* namespace persist */
} /* namespace board */
#endif /* BOARDSTOREMANAGER_H_ */
