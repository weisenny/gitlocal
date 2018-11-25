#pragma once
#include "layer.h"
#include <iostream>


#define MAXX 40
#define MAXY 100
using namespace std;

class model
{
private:
	
public:
	int length;
	char screen[MAXX][MAXY];
	layer layers[MAXX];
	 
	model();
	
	void ini();
	int motify(char a, int b, int c, int d, int e, int f);
	//int cmp(const void *a, const void *b);
	void append(char a, int b, int c, int d, int e, int f);
	int findit(char a);
	int  remove(char a);
};

