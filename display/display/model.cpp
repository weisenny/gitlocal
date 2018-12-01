#include "stdafx.h"
#include "model.h"




model::model()
{
	layers.push_back(layer('s', 2, 5, 6, 7, 10));
	layers.push_back(layer('y', 12, 15, 16, 17, 47));
	layers.push_back(layer('f', 12, 25, 16, 27, 30));
	layers.push_back(layer('3', 3, 6, 16, 27, 7));
	layers.push_back(layer('g', 11, 12, 26, 28, 330));
	ini();
	length = 5;

}

void model::ini()
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
void model::show()
{
	for (int i = 0; i < MAXX; i++)
	{
		for (int j = 0; j < MAXY; j++)
			cout << screen[i][j];
		cout << endl;
	}
}

int cmp(const void *a, const void *b)

{
	//(*(In *)a).data > (*(In *)b).data ? 1 : -1
	return  (*(layer *)a).priority < (*(layer *)b).priority ? 1 : -1;//big -> small
}

int  model::append(char a, int b, int c, int d, int e, int f)
{
	if (findit(a)>0)
		return 0;

	layers.push_back(layer(a, b, c, d, e, f));
	length = length + 1;
	return 1;
}

int model::findit(char a)
{
	int succeed = -1;
	for (int i = 0; i < length; i++)
	{
		if (layers[i].content == a)
			succeed = i;
	}
	return succeed;

}

int  model::remove(char a)
{
	if (findit(a) == -1)
		return 0;
	else
	{
		int i = findit(a);
		layers[i].priority = -100;
		//vector <layer> ::iterator it;
	//	it = remove(layers.begin(),layers.end(),;
		layers.erase(layers.begin() + i);
		//layers[length - 1] = layers[length];
		length = length - 1;
		//cout << length << layers[0].priority << endl;
		return 1;

	}



}



int  model::motify(char a, int b, int c, int d, int e, int f)
{

	if (findit(a) == -1)
	{
		append(a, b, c, d, e, f);
		return 0;
	}
	else
	{
		remove(a);
		append(a, b, c, d, e, f);
		return 1;

	}

}