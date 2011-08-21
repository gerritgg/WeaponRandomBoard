/*
 * Observer.h
 *
 *  Created on: Aug 21, 2011
 *      Author: c0rn0
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

class Subject;

class Observer {
public:

    virtual ~Observer();
    virtual void update(Subject* subject) = 0;

protected:

    Observer();

};

#endif /* OBSERVER_H_ */
