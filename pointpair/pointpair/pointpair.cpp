// ConsoleApplication4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// ConsoleApplication4.cpp: 定义控制台应用程序的入口点。
//


#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>



typedef struct Point {//点结构类型
	double x;//横坐标
	double y;//纵坐标
	int num;
} point;
typedef struct yQueue {
	double y;
	int num;
	struct yQueue* next;
} yq;



point other_W[20];
void switchpoint(point* p1, point* p2) {
	point temp;
	temp.x = (*p1).x;
	temp.y = (*p1).y;
	temp.num = (*p1).num;
	(*p1).x = (*p2).x;
	(*p1).y = (*p2).y;
	(*p1).num = (*p2).num;
	(*p2).x = temp.x;
	(*p2).y = temp.y;
	(*p2).num = temp.num;
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
void PRINTHEAP(point data[], int* n) {
	printf("heap\n");
	int i = 0;
	for (i = 0; i<*n; i++)
		printf("(%d,%.2f,%.2f)\n", data[i].num, data[i].x, data[i].y);
	printf("\n");
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

void INSERTHEAD(yq* head, int num, double y) {
	yq* temph = head;
	yq* tempy = (yq*)malloc(sizeof(yq));
	tempy->num = num;
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
		return -1;
	}
	else {
		del = temp->next;
		temp->next = temp->next->next;
		//free(del);
		return del->num;
	}
}
void PRINTHEAD(yq* head) {
	yq* temp = head;
	yq* del = NULL;
	printf("head:\n");
	while (temp->next != NULL) {
		printf("%.2f  ->", temp->next->y);
		temp = temp->next;

	}
	printf("\n");


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
	int i;
	
	//寻找最大匹配数
	yq* head = (yq*)malloc(sizeof(yq*));
	int nw = n;
	head->y = 0;
	head->next = NULL;
	int t;
	double temx, temy;
	for (countb = n - 1; countb >= 0; countb--) {
		// 寻找所有可能的匹配
		
		while (nw != 0 && W[0].x <= B[countb].x) {

			INSERTHEAD(head, W[0].num, W[0].y);

			//PRINTHEAP(W, &nw);
			//PRINTHEAD(head);
			DELETEHEAP(W, &nw);


		}
		// 匹配最合适的白点
		t = DELETEHEAD(head, B[countb].y);
		if (t>-1) {
			temx = other_W[t].x;
			temy = other_W[t].y;
			printf("\nwhite(%d,%.2f,%.2f) match black(%d,%.2f,%.2f)", other_W[t].num, temx, temy, B[countb].num,B[countb].x, B[countb].y);
			printf("\n");
			max++;
		}
	}
	printf("\n");
	printf("\n");
	printf("\n");
	return max;
}

void main()
{
	
	point test_B[20], test_W[20];
	int n;
	unsigned long t0 = time(NULL);
	
	int i;
	
	n = 20;
	srand(time(0));
	for (i = 0; i<n; i++)
	{
		test_B[i].num = i;
		other_W[i].num = i;
		test_W[i].num = i;
		test_B[i].x = rand() % 100 + (rand() % 100) / 100.0;
		test_B[i].y = rand() % 100 + (rand() % 100) / 100.0;
		test_W[i].x = rand() % 100 + (rand() % 100) / 100.0;
		test_W[i].y = rand() % 100 + (rand() % 100) / 100.0;
		other_W[i].x = test_W[i].x;
		other_W[i].y = test_W[i].y;
		printf("white(%d,%.2f,%.2f) , black(%d,%.2f,%.2f)\n", i, test_W[i].x, test_W[i].y, i, test_B[i].x, test_B[i].y);
	}


	printf("%d", MAXMATCHING(test_B, test_W, n));

	
	system("pause");
}

