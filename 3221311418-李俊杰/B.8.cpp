#include<stdio.h>
#include<stdbool.h>
int lie[8] = { 0 };
bool flag[8] = { 1,1,1,1,1,1,1,1 };
bool dup[15] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
bool ddown[15] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
int num = 0;
void print()
{
	int col, i, j;
	num++;
	printf("%d.", num);
	int table[8][8] = { 0 };
	for (col = 0; col < 8; col++)
	{
		table[col][lie[col]] = 1;
	}
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (table[j][i] != 0)
			{
				printf("(%d %d) ", j, i);
			}
		}
	}
	printf("\n");
}
void gnr(int n)
{
	int col;
	for (col = 0; col < 8; col++)
	{
		if (flag[col] && dup[n - col + 7] && ddown[n + col])
		{
			lie[n] = col;
			flag[col] = 0;
			dup[n - col + 7] = 0;
			ddown[n + col] = 0;
			if (n < 7)
			{
				gnr(n + 1);
			}
			else
			{
				print();
			}
			flag[col] = 1;
			dup[n - col + 7] = 1;
			ddown[n + col] = 1;
		}
	}
}
int main()
{
	gnr(0);
}