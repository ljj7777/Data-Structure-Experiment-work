#include<stdio.h>
void down(int* a, int low, int high)
{
	int i = low, j = 2 * i;
	int item = a[i];
	while (j <= high)
	{
		if (j < high && a[j] < a[j + 1])
		{
			j++;
		}
		if (item < a[j])
		{
			a[i] = a[j];
			i = j;
			j = 2 * i;
		}
		else break;
	}
	a[i] = item;
}
void swap(int* a, int* b)
{
	int item;
	item = *a;
	*a = *b;
	*b = item;
}
int main()
{
	int a[11] = { 0,6,12,458,5,4,28,19,1230,9,47 };//从a[1]开始
	int len = 10;
	int i;
	for (i = len / 2; i >= 1; i--)
	{
		down(a, i, len);
	}
	for (i = len; i >= 2; i--)
	{
		swap(&a[1], &a[i]);
		down(a, 1, i - 1);
	}
	for (int u = 1; u <= len; u++)
	{
		printf("%d ", a[u]);
	}
}