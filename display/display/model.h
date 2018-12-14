#pragma once
#include "layer.h"
#include <iostream>
#include <vector>
#include <iterator>   //迭代器头文件 
#include <algorithm>
#include <functional>
#define MAXX 42
#define MAXY 102
using namespace std;

class model
{
private:
	
public:
	int length;					//定义图层数量
	char screen[MAXX][MAXY];	//定义显示矩阵
	vector<layer> layers;		//以STL 模板vector定义图层集合
	 
	model();					//默认构造函数，初始化一些图层
	void ini();					//初始化显示矩阵函数
	int motify(char a, int b, int c, int d, int e, int f);//修改图层函数
	int append(char a, int b, int c, int d, int e, int f);//增加图层函数
	int findit(char a);								      //根据内容查找图层函数
	int remove(char a);								      //删除图层函数
	
};

