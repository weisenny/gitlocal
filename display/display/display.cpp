// display.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "layer.cpp"
#define MAXX 40
#define MAXY 100
int length;
char screen[MAXX][MAXY];
layer layers[MAXX];

using namespace std;




int cmp(const void *a, const void *b)

{
	//(*(In *)a).data > (*(In *)b).data ? 1 : -1
	return  (*(layer *)a).priority > (*(layer *)b).priority ? 1 : -1;//big -> small
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
		layers[length - 1] = layers[length];
		length = length - 1;
		cout << length << endl;
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




void ini()
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


void draw()
{
	
	int ax, ay, bx, by;
	qsort(layers, length, sizeof(layers[0]), cmp);
	
	ini();
	for (int i = 0; i < length; i++)
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




int main()
{

	char content;
	int ax, ay, bx, by, pri;
	char command;
	int exits = 1;
	layers[0].setlayer('s', 2, 5, 6, 7, 10);
	layers[1].setlayer('y', 12, 15, 16, 17, 47);
	layers[2].setlayer('f', 12, 25, 16, 27, 30);
	layers[3].setlayer('3', 3, 6, 16, 27, 120);
	layers[4].setlayer('g', 11, 12, 26, 28, 330);
	
	length = 5;
	while (exits)
	{
		cin >> command;
		if(command=='a'||command=='m')
			cin>> content >> ax >> ay >> bx >> by >> pri;
		switch (command) {
		case 'a': {
			append(content, ax, ay, bx, by, pri);
			draw();
		}break;
		case 'm': {
			if (motify(content, ax, ay, bx, by, pri))
				cout << "成功修改" << endl;
			else
				cout << "已存在，成功添加" << endl;
			break;
		}
		
		case 'r': {
			if (remove(content))
				cout << "成功删除" << endl;
			else
				cout << "未找到，删除失败" << endl;
			break;
		}
		case 'd':draw(); break;
		case 'e':exits = 0; break;
		default: cout << "error"; break;
		}

	}
	


	
	
	system("pause");
	return 0;
}
