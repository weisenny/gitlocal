#pragma once

class layer
{
public:
	char content;	//内容，也是识别一个窗口的标识
	int  pointax;	//左上点横坐标
	int  pointay;	//左上点纵坐标
	int  pointbx;	//右下点横坐标
	int  pointby;	//右下点纵坐标
	int  priority;	//优先级


	layer(char a, int b, int c, int d, int e, int f);
	
};