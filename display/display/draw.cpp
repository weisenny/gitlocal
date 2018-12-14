#include "stdafx.h"
#include "draw.h"



draw::draw()
{

}
struct cmp1
{
	bool operator()(const layer &a, const layer &b)

	{
		//(*(In *)a).data > (*(In *)b).data ? 1 : -1
		return  a.priority > b.priority;
			//(*(layer *)a).priority < (*(layer *)b).priority ? 1 : -1;//big -> small
	}
};



void draw::todraw(model m)
{

	int ax, ay, bx, by;
	sort(m.layers.begin(), m.layers.end(),  cmp1());


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
					m.screen[j][k] = m.layers[i].content;

		}

	}
	for (int i = 0; i < MAXX; i++)
	{
		for (int j = 0; j < MAXY; j++)
			cout << m.screen[i][j];
		cout << endl;
	}
}



