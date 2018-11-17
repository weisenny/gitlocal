#include "stdafx.h"
class layer
{
public:
	char content;
	int  pointax;
	int  pointay;
	int  pointbx;
	int  pointby;
	int  priority;

	void setlayer(char a, int b, int c, int d, int e, int f)
	{
		content = a;
		pointax = b;
		pointay = c;
		pointbx = d;
		pointby = e;
		priority = f;


	}
};