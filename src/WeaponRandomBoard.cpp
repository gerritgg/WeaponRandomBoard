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

        //       cout << h1("This is a demonstration of the GNU CgiCC library") << endl;

        string queryString = cgicc.getEnvironment().getQueryString();

//        queryString = "rope=1&firepoker=1";
        if (queryString.length() > 0) {

//            cout << "QueryString : " << queryString << endl;

            BoardInputTransformer *transformer = BoardInputTransformer
                ::createTransformer(queryString);
            BoardInput* boardInput = transformer->transform();
            Board* board = BoardDistributor::distribute(boardInput);

            BoardPrinter* printer = BoardPrinter::createPrinter(BoardPrintType
                ::PRINT_TYPE_HTML, board);

            board->initialise(boardInput);

            delete transformer;
            delete boardInput;
            delete printer;

        } else {

            cout << "No QueryString provided!" << endl;

        }

        form_iterator fvalue1 = cgicc.getElement("value1");
        if( !fvalue1->isEmpty() && fvalue1 != (*cgicc).end()) {
            cout << "Value1: " << **fvalue1 << endl;
        }
        else
            cout << "No text entered for value1" << endl;

        cout << p();

        form_iterator fvalue2 = cgicc.getElement("value2");
        if( !fvalue2->isEmpty() && fvalue2 != (*cgicc).end()) {
            // Note this is just a different way to access the string class.
            // See the YoLinux GNU string class tutorial.
            cout << "Value2: " << (**fvalue2).c_str() << endl;
        }

        cout << p();

        form_iterator fvalue3 = cgicc.getElement("value3");
        if( !fvalue3->isEmpty() && fvalue3 != (*cgicc).end()) {
            cout << "Value3: " << **fvalue3 << endl;
        }

        cout << p();

        form_iterator fvalue4 = cgicc.getElement("value4");
        if( !fvalue4->isEmpty() && fvalue4 != (*cgicc).end()) {
            cout << "Value4: " << **fvalue4 << endl;
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
