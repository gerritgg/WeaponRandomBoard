/*
 * BoardTestCase.h
 *
 *  Created on: Aug 21, 2011
 *      Author: c0rn0
 */

#ifndef BOARDTESTCASE_H_
#define BOARDTESTCASE_H_

#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>

#include "../board/Board.h"
#include "../board/transform/input/BoardInput.h"

class BoardTestCase: public CppUnit::TestCase {
public:

    BoardTestCase();
    virtual ~BoardTestCase();

    static CppUnit::Test *suite() {

      CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("SubjectTest");

      suiteOfTests->addTest( new CppUnit::TestCaller<BoardTestCase>(
                                     "testEquality",
                                     &BoardTestCase::testEquality ) );

      suiteOfTests->addTest( new CppUnit::TestCaller<BoardTestCase>(
                                     "testAddition",
                                     &BoardTestCase::testAddition ) );

      return suiteOfTests;

    }

    void testEquality() {

        board::Board board;
        BoardInput* boardInput = new BoardInput();
        board.initialise(boardInput);
//        CPPUNIT_ASSERT_ASSERTION_PASS(!subject);
//        CPPUNIT_ASSERT(2 == 1);

    }

    void testAddition() {

        CPPUNIT_ASSERT(3 == 4);

    }

};

#endif /* BOARDTESTCASE_H_ */
