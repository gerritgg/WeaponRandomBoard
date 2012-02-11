/*
 * TestMain.cpp
 *
 *  Created on: Aug 21, 2011
 *      Author: c0rn0
 */

#include <cppunit/ui/text/TestRunner.h>
#include "BoardTestCase.h"

int mainn(int argc, char **argv) {

    CppUnit::TextUi::TestRunner runner;
    runner.addTest(BoardTestCase::suite());
    runner.run();
    return 0;

}
