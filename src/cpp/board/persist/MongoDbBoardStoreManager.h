/*
 * MongoDbBoardStoreManager.h
 *
 *  Created on: 17 Nov 2011
 *      Author: c0rn0
 */

#ifndef MONGODBBOARDSTOREMANAGER_H_
#define MONGODBBOARDSTOREMANAGER_H_

#include "../Board.h"
#include "BoardStoreManager.h"

namespace board {
namespace persist {

class MongoDbBoardStoreManager : public BoardStoreManager {
public:

    MongoDbBoardStoreManager(board::Board*);
    virtual ~MongoDbBoardStoreManager();

    virtual void save();
    virtual void update(Subject*);

};

} /* namespace persist */
} /* namespace board */
#endif /* MONGODBBOARDSTOREMANAGER_H_ */
