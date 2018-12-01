#pragma once
#include "layer.h"
#include <iostream>
#include <vector>
#include <iterator>   //迭代器头文件 
#include <algorithm>
#include <functional>




#define MAXX 41
#define MAXY 101
using namespace std;

class model
{
private:
	
public:
	int length;
	char screen[MAXX][MAXY];
	vector<layer> layers;

	 
	model();
	
	void ini();
	int motify(char a, int b, int c, int d, int e, int f);
	//int cmp(const void *a, const void *b);
	int  append(char a, int b, int c, int d, int e, int f);
	int findit(char a);
	int  remove(char a);
	void show();
};

