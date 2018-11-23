#pragma once
#include "process.h"
class draw
{
public:

	draw()
	{

		int ax, ay, bx, by;
		qsort(layers, length, sizeof(layers[0]), cmp);


		for (int i = length-1; i >= 0; i--)
		{
			if (layers[i].priority > 0)
			{
				ax = layers[i].pointax;
				ay = layers[i].pointay;
				bx = layers[i].pointbx;
				by = layers[i].pointby;

				for (int j = ax; j < bx; j++)
					for (int k = ay; k < by; k++)
						screen[k][j] = layers[i].content;

			}

		}
		for (int i = 0; i < MAXX; i++)
		{
			for (int j = 0; j < MAXY; j++)
				cout << screen[i][j];
			cout << endl;
		}


	}


	~draw()
	{

		for (int j = 0; j < MAXX; j++)
			for (int k = 0; k < MAXY; k++)
				screen[j][k] = ' ';

		for (int m = 0; m < MAXX; m++)
		{

			screen[m][0] = '*';
			screen[m][MAXY - 1] = '*';


		}
		for (int m = 0; m < MAXY; m++)
		{
			screen[0][m] = '*';
			screen[MAXX - 1][m] = '*';
		}


	}
};

