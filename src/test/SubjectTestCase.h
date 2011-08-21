/*
 * SubjectTestCase.h
 *
 *  Created on: Aug 21, 2011
 *      Author: c0rn0
 */

#ifndef SUBJECTTESTCASE_H_
#define SUBJECTTESTCASE_H_

#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>

#include "../util/observer/Subject.h"

class SubjectTestCase: public CppUnit::TestCase {
public:

    SubjectTestCase();
    virtual ~SubjectTestCase();

    static CppUnit::Test *suite() {

      CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("SubjectTest");

      suiteOfTests->addTest( new CppUnit::TestCaller<SubjectTestCase>(
                                     "testAddition",
                                     &SubjectTestCase::testAddition ) );

      return suiteOfTests;

    }

    void testAddition() {

        CPPUNIT_ASSERT(3 == 4);

    }

};

#endif /* SUBJECTTESTCASE_H_ */
