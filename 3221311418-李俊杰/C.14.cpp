//3 3
//1 3 5
//2 4 6
//21. 两序列中位数问题
#include<stdio.h>
int main()
{
	int a[10];
	int b[10];
	int n;
	int m;
	scanf("%d %d", &n, &m);
	int count = n + m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}
	int f = 0;
	if (count % 2 != 0)
	{
		count = (count / 2) + 1;
		int i = 0; int j = 0; int k = 0;
		while (1)
		{
			if (a[i] > b[j])
			{
				j++;
				f = 1;
			}
			else
			{
				i++;
				f = 2;
			}
			if (j + i == count)
			{
				if (f == 1)
				{
					printf("%d", b[j - 1]);
				}
				else
				{
					printf("%d", a[i - 1]);
				}
				break;
			}
		}
	}
	else
	{
		count = count / 2;
		double n;
		int i = 0; int j = 0; int k = 0;
		while (1)
		{
			if (a[i] > b[j])
			{
				j++;
				f = 1;
			}
			else
			{
				i++;
				f = 2;
			}
			if (i + j == count)
			{
				if (f == 1)
				{
					if (b[j] > a[i])
					{
						n = (double(b[j + 1]) + double(a[i])) / 2;
						printf("%.2lf", n);
					}
					else
					{
						n = (double(b[j - 1]) + double(b[j])) / 2;
						printf("%.2lf", n);
					}
				}
				if (f == 2)
				{
					if (a[i] > b[j])
					{
						n = (double(a[i - 1]) + double(b[j])) / 2;
						printf("%.2lf", n);
					}
					else
					{
						n = (double(a[i - 1]) + double(a[i])) / 2;
						printf("%.2lf", n);
					}
				}
				break;
			}
		}
	}
}