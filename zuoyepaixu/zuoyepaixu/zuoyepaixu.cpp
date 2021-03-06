#include"stdafx.h"
#include<iostream>
using namespace std;

int JS(int D[], int J[], int n, int k)
{
	int r, i;
	D[0] = J[0] = 0;
	k = 1;
	J[1] = 1;
	for (i = 2; i <= n; i++)
	{
		r = k;
		while (D[J[r]] > D[i] && D[J[r]] != r)
			r--;

		if (D[J[r]] <= D[i] && D[i]>r)
		{
			for (int j = k; j > r; j--)
				J[j + 1] = J[j];

			J[r + 1] = i;
			k++;
		}
	}
	return k;
}

void SORT(int P[], int D[], int start, int end)
{
	for (int i = start + 1; i <= end; i++)
	{
		int item = P[i];
		int item_d = D[i];
		int j = i - 1;
		while (j >= start && item > P[j])
		{
			P[j + 1] = P[j];
			D[j + 1] = D[j];
			j--;
		}
		P[j + 1] = item;
		D[j + 1] = item_d;
	}
}

int main()
{
	const int MAX = 8;
	int P[MAX] = { 0,30,25,20,15,10,5,35 };
	int D[MAX] = { 0,2,4,3,4,8,3,4 };


	int J[MAX];
	int n = 7;

	cout << "i\tP[i]\tD[i]\t Before Sort" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << i << "\t" << P[i] << "\t" << D[i] << "\t" << endl;
	}
	cout << endl;
	SORT(P, D, 1, n);
	cout << "i\tP[i]\tD[i]\t After Sort" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << i << "\t" << P[i] << "\t" << D[i] << "\t" << endl;
	}
	cout << endl;
	n = JS(D, J, n, 0);

	cout << "i\tJ[i]\tP[J[i]]\tD[J[i]]\t Result" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << i << "\t" << J[i] << "\t" << P[J[i]] << "\t" << D[J[i]] << "\t" << endl;
	}

	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cout << "->" << J[i];
		sum += P[J[i]];
	}
	cout << "\tsum=>" << sum;
	system("pause");
	return 0;
}
