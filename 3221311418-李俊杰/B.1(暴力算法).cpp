#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	gets_s(a);
	int i;
	int j;
	int  maxlen = 0;
	int cur;
	int len = strlen(a);
	int y;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (a[i] != a[j])
			{
				continue;
			}
			else
			{
				int k = i; int l = j; int f = 0;
				while (k <= l)
				{
					if (a[k++] != a[l--])
					{
						f = 1;
						break;
					}
				}
				if (f == 0 && j - i > maxlen)
				{
					maxlen = j - i;
					cur = i;
				}
			}
		}
	}
	for (int q = cur; q <= cur + maxlen; q++)
	{
		printf("%c", a[q]);
	}
}