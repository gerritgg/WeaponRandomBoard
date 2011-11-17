/*
 * BoardStoreManager.cpp
 *
 *  Created on: 17 Nov 2011
 *      Author: c0rn0
 */

#include "MongoDbBoardStoreManager.h"

namespace board {
namespace persist {

BoardStoreManager::BoardStoreManager(board::Board* board) {
    subject = board;
    subject->attach(this);
}

BoardStoreManager::~BoardStoreManager() {
}

BoardStoreManager* BoardStoreManager::createStoreManager(
        BoardStoreType::StoreType storeType, board::Board* board) {

    if (storeType == BoardStoreType::STORE_TYPE_MONGODB) {
        return new MongoDbBoardStoreManager(board);
    }

    return NULL;

}

} /* namespace persist */
} /* namespace board */
