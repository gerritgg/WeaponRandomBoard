/*
 * Subject.cpp
 *
 *  Created on: Aug 21, 2011
 *      Author: c0rn0
 */

#include "Subject.h"


Logger* Subject::LOGGER = Logger::getLogger("Subject");

Subject::Subject() {
}

Subject::~Subject() {
}

void Subject::attach(Observer* observer) {
    observers.push_back(observer);
}

void Subject::detach(Observer* observer) {

}

void Subject::notify() {

    for (int var = 0; var < (int) observers.size(); ++var) {
        observers[var]->update(this);
    }

    LOGGER->info("Subject::notify()");

}
