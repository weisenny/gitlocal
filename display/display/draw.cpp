#include "stdafx.h"
#include "draw.h"

draw::draw()
{

}
int cmp1(const void *a, const void *b)

{
	//(*(In *)a).data > (*(In *)b).data ? 1 : -1
	return  (*(layer *)a).priority < (*(layer *)b).priority ? 1 : -1;//big -> small
}


void draw::todraw(model m)
{

	int ax, ay, bx, by;
	qsort(m.layers, m.length, sizeof(m.layers[0]), cmp1);


	for (int i = m.length - 1; i >= 0; i--)
	{
		if (m.layers[i].priority > 0)
		{
			ax = m.layers[i].pointax;
			ay = m.layers[i].pointay;
			bx = m.layers[i].pointbx;
			by = m.layers[i].pointby;

			for (int j = ax; j < bx; j++)
				for (int k = ay; k < by; k++)
					m.screen[k][j] = m.layers[i].content;

		}

	}
	for (int i = 0; i < MAXX; i++)
	{
		for (int j = 0; j < MAXY; j++)
			cout << m.screen[i][j];
		cout << endl;
	}
}


void draw::newdraw(model mo)
{
	for (int j = 0; j < MAXX; j++)
		for (int k = 0; k < MAXY; k++)
			mo.screen[j][k] = ' ';

	for (int m = 0; m < MAXX; m++)
	{

		mo.screen[m][0] = '*';
		mo.screen[m][MAXY - 1] = '*';


	}
	for (int m = 0; m < MAXY; m++)
	{
		mo.screen[0][m] = '*';
		mo.screen[MAXX - 1][m] = '*';
	}



}
