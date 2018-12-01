// test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

int main()
{
	map<string, int> wordCount;
	string word="c";
	int i= 0;
	pair<string, int> words("a",3);
	while (word != "e") 
	{

		cin >> word;
		wordCount[word]=++i;

	}
	wordCount.insert(words);
	for (map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it)
		cout << "Word: " << (*it).first << " \tCount: " << (*it).second << endl;

	system("pause");
	return 0;
}

