#include<stdio.h>
void pai(int a[], int len) {
	int i, j, dist;
	for (dist = len / 2; dist > 0; dist = dist / 2)
	{
		for (i = 0; i < dist; i++)
		{
			for (j = i + dist; j < len; j = j + dist)
			{
				if (a[j] < a[j - dist])
				{
					int tmp = a[j];
					int k = j - dist;
					while (k >= 0 && a[k] > tmp)
					{
						a[k + dist] = a[k];
						k = k - dist;
					}
					a[k + dist] = tmp;
				}
			}
		}
	}
}
int main()
{
	int a[10] = { 6,12,458,5,4,28,19,1230,9,47 };
	int len = 10;
	pai(a, len);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
}