#include<stdio.h>
void merge(int* a, int low, int mid, int high)
{
	int b[10];
	int i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= high)
	{
		if (a[i] <= a[j])
		{
			b[k] = a[i]; i++; k++;
		}
		else
		{
			b[k] = a[j]; j++; k++;
		}
	}
	while (i <= mid)
	{
		b[k] = a[i]; i++; k++;
	}
	while (j <= high)
	{
		b[k] = a[j]; j++; k++;
	}
	for (k = 0, i = low; i <= high; k++, i++)
	{
		a[i] = b[k];
	}
}
void msdc(int* a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		msdc(a, low, mid);
		msdc(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}
int main()
{
	int a[10] = { 6,12,458,5,4,28,19,1230,9,47 };
	int low = 0; int high = 9;
	msdc(a, low, high);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
}