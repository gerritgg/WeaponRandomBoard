//============================================================================
// Name        : WeaponRandomBoard.cpp
// Author      : c0rn0
// Version     :
//============================================================================

#include <iostream>
using namespace std;

#include "board/BoardDistributor.h"
#include "board/transform/input/BoardInputTransformer.h"

int main(int argc, char *argv[]) {

	if (argc == 1) {

		cout << argc << endl; // prints Random Board!

	} else {

		if (argc > 1) {

	        Board board = BoardDistributor::distribute(BoardInputTransformer
                ::createTransformer(argv, argc, BoardInputTransformer::CONSOLE)
	            ->transform());

	        board.useAllWeapons();

		}

	}

	bool printArguments = false;

	if (printArguments) {

        for (int i = 0; i < argc; ++i) {
            cout << argv[i] << endl;
        }

    }

	cout << "Random Board Finished!" << endl; // prints Random Board!

	return 0;

}
