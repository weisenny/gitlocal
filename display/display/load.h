#pragma once
#include "statement.h"

class load
{
public:

	load() {
		layers[0].setlayer('s', 2, 5, 6, 7, 10);
		layers[1].setlayer('y', 12, 15, 16, 17, 47);
		layers[2].setlayer('f', 12, 25, 16, 27, 30);
		layers[3].setlayer('3', 3, 6, 16, 27, 7);
		layers[4].setlayer('g', 11, 12, 26, 28, 330);

		length = 5;

	}

};
