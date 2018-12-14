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




int main()
{
	model mo;
	draw d;
	
	

	char content='d';
	int ax=0, ay=0, bx=0, by=0, pri;
	char command;
	int exits = 1;
	while (exits)
	{
		cin >> command;
		if (command == 'r')
			cin >> content;
		if (command == 'a' || command == 'm')
		{
			cin >> content >> ax >> ay >> bx >> by >> pri;
			bx = bx + 1;
			by = by + 1;

		}
			
		switch (command) {
		case 'a': {
			if(mo.append(content, ax, ay, bx, by, pri))
				cout << "成功添加" << endl;
			else 
				cout << "已存在，添加失败" << endl;
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
		case 'd':d.todraw(mo);  break;
		case 'e':exits = 0; break;
		default: cout << "error"; break;
		}

	}
	


	
	
	system("pause");
	return 0;
}
