//============================================================================
// Name        : WeaponRandomBoard.cpp
// Author      : c0rn0
// Version     :
//============================================================================

#include <iostream>
using namespace std;

#include "board/BoardDistributor.h"

int main(int argc, char *argv[]) {

	if (argc == 1) {

		cout << argc << endl; // prints Random Board!

	} else {

		if (argc > 1) {
			cout << argc << endl; // prints Random Board!
		}

	}

	for (int i = 0; i < argc; ++i) {
		cout << argv[i] << endl;
	}

	cout << "Random Board!" << endl; // prints Random Board!

	BoardDistributor boardDistributor;
	boardDistributor.distribute(argv[1]);

	return 0;

}
