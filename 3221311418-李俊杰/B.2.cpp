#include<stdio.h>
int main()
{
	int i, j = 0;
	int n;
	scanf("%d", &n);
	int a[10];
	for (int u = 0; u < n; u++)
	{
		scanf("%d", &a[u]);
	}
	int item;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				item = a[j];
				a[j] = a[j + 1];
				a[j + 1] = item;
				count++;
			}
		}
	}
	for (int u = 0; u < n; u++)
	{
		printf("%d ", a[u]);
	}
	printf("\n%d", count);
}