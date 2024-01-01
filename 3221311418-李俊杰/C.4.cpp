//25. KMP算法实现
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	char b[100];
	scanf("%s\n", a + 1);
	scanf("%s", b + 1);
	char next[100];
	next[1] = 0;
	int len1 = strlen(a + 1);
	int len2 = strlen(b + 1);
	int j = 0;
	for (int i = 2; i <= len2; i++)//创建next数组;
	{
		while (j > 0 && b[i] != b[j + 1])
		{
			j = next[j];
		}
		if (b[i] == b[j + 1])
		{
			j++;
		}
		next[i] = j;
	}
	j = 0;
	int f = 0;
	for (int i = 1; i <= len1; i++)
	{
		while (j > 0 && a[i] != b[j + 1])
		{
			j = next[j];
		}
		if (a[i] == b[j + 1])
		{
			j++;
		}
		if (j == len2)
		{
			printf("%d", i + 1 - j);
			f = 1;
			break;
		}
	}
	if (f == 0)
	{
		printf("NONE!");
	}
}