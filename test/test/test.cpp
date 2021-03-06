// test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>


using namespace std;
class Date 		             //定义日期类Date
{
public: 			//声明类成员 
	Date(int y = 2011, int m = 1, int d = 1);
	

	~Date()
	{
		cout << "destructing…" << endl;
	}
	void ShowDate();
private:
	int year;      int month;      int day;
};




Date::Date(int y, int m, int d)
{
	year = y;   month = m;  day = d;
	cout <<"Constructing…"<<endl;  
}
	
	void Date::ShowDate()
	{
		cout << "Date：" << year <<month<< day;
		cout << endl;
	}



Date Fun(Date date2)
{
	Date date3(date2);      //调用拷贝构造函数
	return date3;
}
int main()
{
	Date obj1(1999, 3, 20);
	Date obj3;
	Date obj2(obj1);        //调用拷贝构造函数    
	obj2.ShowDate();

	Date obj4 = obj2;
	obj3 = obj2;
	obj3 = Fun(obj2);
	obj3.ShowDate();

	cin.ignore();
	return 1;
}

