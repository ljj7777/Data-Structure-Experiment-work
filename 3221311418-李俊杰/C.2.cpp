#include<stdio.h>
int main()
{
	int a[10];
	int n;//输入的数据数量
	scanf_s("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int b[9];
	for (int i = 0; i < n - 1; i++)
	{
		b[i] = a[i + 1] - a[i];
	}
	int f;
	int k;
	if (b[0] > 0)
	{
		f = 1;
		k = 1;
		for (int i = 2; i < n - 1; i = i + 2)
		{
			if (b[i] < 0)
			{
				f = 0;
				break;
			}
		}
		for (int i = 1; i < n - 1; i = i + 2)
		{
			if (b[i] > 0)
			{
				k = 0;
				break;
			}
		}
		if (k == 1 && f == 1)
		{
			printf("是摆动序列");
		}
	}
	if (b[0] < 0)
	{
		f = 1;
		k = 1;
		for (int i = 2; i < n - 1; i = i + 2)
		{
			if (b[i] > 0)
			{
				f = 0;
				break;
			}
		}
		for (int i = 1; i < n - 1; i = i + 2)
		{
			if (b[i] < 0)
			{
				k = 0;
				break;
			}
		}
		if (k == 1 && f == 1)
		{
			printf("是摆动序列");
		}
	}
	int count = 0;
	int q;
	if (f != 1 || k != 1)//非摆动改摆动
	{
		for (int y = 0; y < n - 2; y = y + q)
		{
			q = 0;
			if (b[y] > 0)
			{
				for (int i = y + 1; i < n - 1; i++)
				{
					if (b[i] > 0)
					{
						count++;
						q++;
						continue;
					}
					else
					{
						q++;
						break;
					}
				}
			}
			if (b[y] < 0)
			{
				for (int i = y + 1; i < n - 1; i++)
				{
					if (b[i] < 0)
					{
						count++;
						q++;
						continue;
					}
					else
					{
						q++;
						break;
					}
				}
			}
		}
	}
	printf("非摆动序列，需要删除 %d 个元素", count);
}