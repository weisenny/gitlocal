// ConsoleApplication4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdio.h> 
#include<string.h> 
#include<time.h> 
#include<math.h> 


#include<stdlib.h> 


typedef struct Point {//点结构类型 
	double x;//横坐标 
	double y;//纵坐标 
} point;
typedef struct yQueue {
	double y;
	struct yQueue* next;
} yq;
void switchpoint(point* p1, point* p2) {
	point temp;
	temp.x = (*p1).x;
	temp.y = (*p1).y;
	(*p1).x = (*p2).x;
	(*p1).y = (*p2).y;
	(*p2).x = temp.x;
	(*p2).y = temp.y;
}
void SIFT_DOWN(point data[], int i, int n) {
	int done = 0;
	if (i >= n / 2) {
		return;
	}
	do {
		i = 2 * i + 1;
		if (i + 1 < n && data[i + 1].x < data[i].x) i++;
		if (data[(i - 1) / 2].x > data[i].x) switchpoint(&data[(i - 1) / 2], &data[i]);
		else done = 1;
	} while (i < n / 2 && !done);
}
void SIFT_UP(point data[], int i, int n) {
	if (i == 0) return;
	do {
		if (data[i].x < data[(i - 1) / 2].x) switchpoint(&data[i], &data[(i - 1) / 2]);
		else break;
		i = (i - 1) / 2;
	} while (i > 0);
}
void DELETEHEAP(point data[], int* n) {
	switchpoint(&data[0], &data[(*n) - 1]);
	(*n)--;
	SIFT_DOWN(data, 0, *n);
}
void MAKEHEAP(point data[], int n) {
	int i;
	for (i = n / 2 - 1; i >= 0; i--) {
		SIFT_DOWN(data, i, n);
	}
}
void HEAPSORT(point data[], int n) {
	int j;
	MAKEHEAP(data, n);
	for (j = n - 1; j >= 1; j--) {
		switchpoint(&data[0], &data[j]);
		SIFT_DOWN(data, 0, j);
	}
}
void INSERTHEAD(yq* head, double y) {
	yq* temph = head;
	yq* tempy = (yq*)malloc(sizeof(yq*));
	tempy->y = y;
	tempy->next = NULL;
	while (temph->next != NULL && temph->next->y > y) {
		temph = temph->next;
	}
	tempy->next = temph->next;
	temph->next = tempy;
}
int DELETEHEAD(yq* head, double y) {
	yq* temp = head;
	yq* del = NULL;
	while (temp->next != NULL && temp->next->y > y) {
		temp = temp->next;
	}
	if (temp->next == NULL) {
		return 0;
	}
	else {
		del = temp->next;
		temp->next = temp->next->next;
		//free(del); 
		return 1;
	}
}


int MAXMATCHING(point B[], point W[], int n);
//函数声明， num个黑点B和白点W，求最大匹配数 
int MAXMATCHING(point B[], point W[], int n) {
	//函数实现， num个黑点B和白点W，求最大匹配数 
	int max = 0;
	int countb = n;
	// 以x坐标的降序对黑点排序 
	HEAPSORT(B, n);
	// 以x坐标的降序对白点排序 
	MAKEHEAP(W, n);
	//寻找最大匹配数 
	yq* head = (yq*)malloc(sizeof(yq*));
	int nw = n;
	head->y = 0;
	head->next = NULL;
	for (countb = n - 1; countb >= 0; countb--) {
		// 寻找所有可能的匹配 
		while (nw != 0 && W[0].x <= B[countb].x) {
			INSERTHEAD(head, W[0].y);
			DELETEHEAP(W, &nw);
		}
		// 匹配最合适的白点 
		if (DELETEHEAD(head, B[countb].y)) {
			max++;
		}
	}
	return max;
}
void test();
int main()
{
	test();
	system("pause");
	return 0;
}
void test()
{
	//用于检查程序是否是对的或提供正确结果以供参考 
	/*该测试程序只须直接放到main函数中运行即可*/
	int test_ans[] = {
		19519
		,37254
		,38377
		,46570
		,21847
		,37612
		,24956
		,47414
		,28698
		,40213
	};
	int test_correct = 0;
	point test_B[50000], test_W[50000];
	int n;
	unsigned long t0 = time(NULL);
	int test_turn;
	int i;
	/*for (test_turn = 0; test_turn<10; test_turn++)
	{*/
	n = 20000 + rand() % 30000;
	for (i = 0; i<n; i++)
	{
		test_B[i].x = rand() + (rand() % 1000) / 1000.0;
		test_B[i].y = rand() + (rand() % 1000) / 1000.0;
		test_W[i].x = rand() + (rand() % 1000) / 1000.0;
		test_W[i].y = rand() + (rand() % 1000) / 1000.0;
	}
	if (test_ans[test_turn] == MAXMATCHING(test_B, test_W, n)) {
		++test_correct;
	}
	/*
	}
	unsigned long t1 = time(NULL);
	if (test_correct >= 10)
	{
	t1 -= t0;
	if (t1 == 0)
	printf("A++\n");
	else if (t1<10)
	printf("A+\n");
	else if (t1<100)
	printf("B+\n");
	else printf("B\n");
	}
	else {
	printf("D\n");
	}*/
}
