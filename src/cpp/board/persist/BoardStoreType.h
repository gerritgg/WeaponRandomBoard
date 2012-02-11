/*
 * BoardStoreType.h
 *
 *  Created on: 17 Nov 2011
 *      Author: c0rn0
 */

#ifndef BOARDSTORETYPE_H_
#define BOARDSTORETYPE_H_

namespace board {
namespace persist {

class BoardStoreType {
public:

    enum StoreType {
        STORE_TYPE_MONGODB = 1
    };

    BoardStoreType();
    virtual ~BoardStoreType();
};

} /* namespace persist */
} /* namespace board */
#endif /* BOARDSTORETYPE_H_ */
