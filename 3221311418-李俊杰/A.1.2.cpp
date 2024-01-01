#include<stdio.h>
void qpai(int* a, int n)
{
	if (n < 2)
	{
		return;
	}
	int item = a[0];
	int sleft = 0;
	int sright = n - 1;
	int f = 1;
	while (sleft < sright)
	{
		if (f == 1)
		{
			if (a[sright] >= item)
			{
				sright--;
				continue;
			}
			a[sleft] = a[sright];
			sleft++;
			f = 0;
			continue;
		}
		if (f == 0)
		{
			if (a[sleft] <= item)
			{
				sleft++;
				continue;
			}
			a[sright] = a[sleft];
			sright--;
			f = 1;
			continue;
		}
	}
	a[sleft] = item;
	qpai(a, sleft);
	qpai(a + sleft + 1, n - sleft - 1);
}
int main()
{
	int a[10] = { 6,12,458,5,4,28,19,1230,9,47 };
	int len = 10;
	qpai(a, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
}