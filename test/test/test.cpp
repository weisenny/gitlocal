// test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <limits> 
#include <algorithm>
#include <iterator>

#include <functional>


using namespace std;    //引入名字空间std
						//std覆盖了C++所有的定义和声明
namespace one    //定义名字空间one，包含M和inf
{
	const int M = 200;
	int x = 110;
}

namespace two    //定义名字空间two，包含x和inf
{
	int x=10;
	int inf = -100;
}




void test()
{
	string str1("0123456789");
	string str2("0123456789") ;

	reverse(str1.begin(), str1.end());
	cout << str1 << endl;
	copy(str1.begin(), str1.end(), str2.begin());
	cout << str1 << endl;
	cout << str2 << endl;

	reverse_copy(str1.begin(), str1.end(), str2.begin());
	cout << str2 << endl;

	reverse(str2.begin() + 2, str2.begin() + 8);
	copy(str2.begin() + 2, str2.begin() + 8, ostream_iterator<char>(cout));

	cout << endl;

	sort(str1.begin(), str1.end(), greater<char>());
	cout << str1 << endl;
	str1.swap(str2);  //互相交换内容
	cout << str1 << " " << str2 << endl;
	cin.ignore();





}

void test2()
{
	

}
int main()
{
	
	test();
	test2();
	
	system("pause");
	return 0;
}
