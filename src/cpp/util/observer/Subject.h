/*
 * Subject.h
 *
 *  Created on: Aug 21, 2011
 *      Author: c0rn0
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <vector>
#include "Observer.h"
#include "../Logger.h"

using namespace std;

class Subject {
public:

    virtual ~Subject();

    virtual void attach(Observer*);
    virtual void detach(Observer*);
    virtual void notify();

protected:

    Subject();

private:

    static Logger* LOGGER;

    vector<Observer*> observers;

};

#endif /* SUBJECT_H_ */
