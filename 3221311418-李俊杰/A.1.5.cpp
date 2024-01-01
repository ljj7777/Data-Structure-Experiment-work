#include<stdio.h>
#include<stdlib.h>
#define n 10
int getmax(int* a)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	int count = 0;
	while (max != 0)
	{
		max = max / 10;
		count++;
	}
	return count;
}
int main()
{
	int a[n] = { 6,12,458,5,4,28,19,1230,9,47 };
	int k = getmax(a);
	int item[n][n] = { 0 };
	int count = 0;
	int shu;
	for (int i = 1; i <= k; i++)
	{

		for (int j = 0; j < n; j++)
		{
			shu = i;
			count = a[j];
			while (1)
			{
				shu--;
				if (shu == 0)
				{
					break;
				}
				else
				{
					count = count / 10;
				}
			}
			int ii = 0;
			count = count % 10;
			while (1)
			{
				if (item[ii][count] != 0)
				{
					ii++;
				}
				else
				{
					break;
				}
			}
			item[ii][count] = a[j];
		}
		int f = 0;
		for (int p = 0; p < n; p++)
		{
			for (int q = 0; q < n; q++)
			{
				if (item[q][p] != 0)
				{
					a[f++] = item[q][p];
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int u = 0; u < n; u++)
			{
				item[i][u] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}