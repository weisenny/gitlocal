#pragma once
#include <iostream>
#include "statement.h"
using namespace std;
int cmp(const void *a, const void *b)

{
	//(*(In *)a).data > (*(In *)b).data ? 1 : -1
	return  (*(layer *)a).priority < (*(layer *)b).priority ? 1 : -1;//big -> small
}

void append(char a, int b, int c, int d, int e, int f)
{

	layers[length].setlayer(a, b, c, d, e, f);
	length = length + 1;
}

int findit(char a)
{
	int succeed = -1;
	for (int i = 0; i < length; i++)
	{
		if (layers[i].content == a)
			succeed = i;
	}
	return succeed;

}

int  remove(char a)
{
	if (findit(a) == -1)
		return 0;
	else
	{
		int i = findit(a);
		layers[i].priority = -100;
		qsort(layers, length, sizeof(layers[0]), cmp);
		//layers[length - 1] = layers[length];
		length = length - 1;
		cout << length << layers[0].priority <<endl;
		return 1;

	}



}



int  motify(char a, int b, int c, int d, int e, int f)
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