/*
 * MongoDbBoardStoreManager.cpp
 *
 *  Created on: 17 Nov 2011
 *      Author: c0rn0
 */

//#include <iostream>
//#include <string>
#include <mongo/client/dbclient.h>
#include "MongoDbBoardStoreManager.h"
#include "../../util/DateUtil.h"

using namespace mongo;
using namespace board::util;

namespace board {
namespace persist {

MongoDbBoardStoreManager::MongoDbBoardStoreManager(Board* board) :
        BoardStoreManager(board) {
}

MongoDbBoardStoreManager::~MongoDbBoardStoreManager() {
}

void MongoDbBoardStoreManager::update(Subject* changedSubject) {

    if (subject == changedSubject) {
        save();
    }

}

void MongoDbBoardStoreManager::save() {

    DBClientConnection c;
    c.connect("192.168.2.105");

    BSONObjBuilder b;
    b.append("Name", subject->getName());
    b.appendDate("DateCreated", DateUtil::getCurrentMillis());
    b.appendDate("DateToUse", DateUtil::getMillisForDate(2011, 11, 25));
    b.append("ItemsInputString", subject->itemsToString());
    b.append("ItemsDataString", subject->itemsToString());
    b.append("ItemsData", subject->itemsToString());
    BSONObj board = b.obj();
    c.insert("tutorial.boards", board);

}

} /* namespace persist */
} /* namespace board */
