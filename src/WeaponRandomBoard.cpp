//============================================================================
// Name        : WeaponRandomBoard.cpp
// Author      : c0rn0
// Version     :
//============================================================================

#include <iostream>

#include "board/BoardDistributor.h"
#include "board/transform/input/BoardInputTransformer.h"
#include "board/transform/print/BoardPrinter.h"

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/CgiEnvironment.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>

using namespace std;
using namespace log4cpp;
using namespace cgicc;

int main(int argc, char *argv[]) {

    try {

        Cgicc cgicc;

        // Send HTTP header: Content-type: text/html
        cout << HTTPHTMLHeader() << endl;

        // Print: <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0//EN" "http://www.w3.org/TR/REC-html40/strict.dtd">
        cout << HTMLDoctype(HTMLDoctype::eStrict) << endl;

        // Print: <html lang="en" dir="LTR">
        cout << html().set("lang", "EN").set("dir", "LTR") << endl;

        // Set up the HTML document
        cout << html() << head() << title("Random Board") << head() << endl;
        cout << body().set("bgcolor","#cccccc").set("text","#000000").set("link","#0000ff").set("vlink","#000080") << endl;

        string queryString = cgicc.getEnvironment().getQueryString();

//        queryString = "rope=1&firepoker=1";
        if (queryString.length() > 0) {

//            cout << "QueryString : " << queryString << endl;

            BoardInputTransformer *transformer = BoardInputTransformer
                ::createTransformer(queryString, BoardInputTransformer
                ::WEB_QUERY_STRING);
            BoardInput* boardInput = transformer->transform();
            Board* board = BoardDistributor::distribute(boardInput);

            BoardPrinter* printer = BoardPrinter::createPrinter(BoardPrintType
                ::PRINT_TYPE_HTML, board);

            board->initialise(boardInput);

            delete transformer;
            delete boardInput;
            delete printer;

        } else {

            form_iterator boardInput = cgicc.getElement("boardinput");
            if( !boardInput->isEmpty() && boardInput != (*cgicc).end()) {

                BoardInputTransformer *transformer = BoardInputTransformer
                    ::createTransformer(**boardInput, BoardInputTransformer
                    ::WEB_FORM_TEXTAREA);
                BoardInput* boardInput = transformer->transform();
                Board* board = BoardDistributor::distribute(boardInput);

                BoardPrinter* printer = BoardPrinter::createPrinter(BoardPrintType
                    ::PRINT_TYPE_HTML, board);

                board->initialise(boardInput);

                delete transformer;
                delete boardInput;
                delete printer;

            } else {
                cout << "No text entered for boardinput" << endl;
            }

        }

        // Close the HTML document
        cout << body() << html();
    }
    catch(exception& e) {
        // handle any errors here.
        cout << "ERROR!!" << endl;
    }
    return 0;   // To avoid Apache errors.

    /*

	if (argc == 1) {

		cout << argc << endl; // prints Random Board!

	} else {

		if (argc > 1) {

	        BoardInputTransformer *transformer = BoardInputTransformer
                ::createTransformer(argv, argc, BoardInputTransformer::CONSOLE);
	        BoardInput* boardInput = transformer->transform();
	        Board* board = BoardDistributor::distribute(boardInput);

	        BoardPrinter* printer = BoardPrinter::createPrinter(BoardPrintType
                ::PRINT_TYPE_HTML, board);

	        board->initialise(boardInput);

	        delete transformer;
	        delete boardInput;
	        delete printer;

		}

	}

	bool printArguments = false;

	if (printArguments) {

        for (int i = 0; i < argc; ++i) {
            cout << argv[i] << endl;
        }

    }

	Logger* logger = Logger::getLogger("WeaponRandomBoard");
	logger->info("Done.");

	return 0;

	*/

}
