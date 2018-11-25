// display.cpp: 定义控制台应用程序的入口点。
//
#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "draw.h"
#include "model.h"



/*


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
	}*/


int main()
{
	model mo;
	draw d;
	
	

	char content='d';
	int ax, ay, bx, by, pri;
	char command;
	int exits = 1;
	while (exits)
	{
		cin >> command;
		if (command == 'r')
			cin >> content;
		if(command=='a'||command=='m')
			cin>> content >> ax >> ay >> bx >> by >> pri;
		switch (command) {
		case 'a': {
			mo.append(content, ax, ay, bx, by, pri);
			
		}break;
		case 'm': {
			if (mo.motify(content, ax, ay, bx, by, pri))
				cout << "成功修改" << endl;
			else
				cout << "已存在，成功添加" << endl;
			break;
		}
		
		case 'r': {
			if (mo.remove(content))
				cout << "成功删除" << endl;
			else
				cout << "未找到，删除失败" << endl;
			break;
		}
		case 'd':d.todraw(mo); break;
		case 'e':exits = 0; break;
		default: cout << "error"; break;
		}

	}
	


	
	
	system("pause");
	return 0;
}
