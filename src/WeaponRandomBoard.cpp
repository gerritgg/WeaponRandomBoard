//============================================================================
// Name        : WeaponRandomBoard.cpp
// Author      : c0rn0
// Version     :
//============================================================================

#include <iostream>

#include "board/BoardDistributor.h"
#include "board/transform/input/BoardInputTransformer.h"

#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>

using namespace std;
using namespace log4cpp;

#define LOGFILE "/var/log/weaponrandomboard/weaponrandomboard.log"

int main(int argc, char *argv[]) {

	if (argc == 1) {

		cout << argc << endl; // prints Random Board!

	} else {

		if (argc > 1) {

	        BoardInputTransformer *transformer = BoardInputTransformer
                ::createTransformer(argv, argc, BoardInputTransformer::CONSOLE);
	        BoardInput *boardInput = transformer->transform();
	        Board board = BoardDistributor::distribute(boardInput);

	        delete transformer;
	        delete boardInput;

//	        board.useAllWeapons();
	        board.print();

		}

	}

	bool printArguments = false;

	if (printArguments) {

        for (int i = 0; i < argc; ++i) {
            cout << argv[i] << endl;
        }

    }

	Appender* appender = new FileAppender("FileAppender", LOGFILE);
	PatternLayout* layout = new PatternLayout();
	layout->setConversionPattern(PatternLayout::TTCC_CONVERSION_PATTERN);
	Category& category = Category::getInstance("Category");

	appender->setLayout(layout);
	category.setAppender(appender);
	category.setPriority(Priority::INFO);

	category.info("Done.");

	cout << "Done!" << endl; // prints Random Board!

	return 0;

}
