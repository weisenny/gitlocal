#pragma once
#include "layer.h"
#include <iostream>
#include <vector>
#include <iterator>   //������ͷ�ļ� 
#include <algorithm>
#include <functional>
#define MAXX 42
#define MAXY 102
using namespace std;

class model
{
private:
	
public:
	int length;					//����ͼ������
	char screen[MAXX][MAXY];	//������ʾ����
	vector<layer> layers;		//��STL ģ��vector����ͼ�㼯��
	 
	model();					//Ĭ�Ϲ��캯������ʼ��һЩͼ��
	void ini();					//��ʼ����ʾ������
	int motify(char a, int b, int c, int d, int e, int f);//�޸�ͼ�㺯��
	int append(char a, int b, int c, int d, int e, int f);//����ͼ�㺯��
	int findit(char a);								      //�������ݲ���ͼ�㺯��
	int remove(char a);								      //ɾ��ͼ�㺯��
	
};

