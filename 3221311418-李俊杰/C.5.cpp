//26. 英文句子格式化
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	gets_s(a);
	char b[100];
	int len = strlen(a);
	int f = 0;
	int k = 0;
	int o = 0;
	int count;
	while (1)
	{
		if (a[k] == ' ')
		{
			k++;
		}
		else
		{
			break;
		}
	}
	int i = 0;
	int n;
	int c = 0;
	while (1)
	{
		count = 0;
		if (a[i + k] != ' ')
		{
			b[o] = a[i + k];
			o++;
			i++;
		}
		else
		{
			n = 0;
			while (1)
			{
				if (a[i + k + n] == ' ')
				{
					count++;
					if (i + k + count > len)
					{
						c = 1;
						break;
					}
				}
				else
				{
					break;
				}
				n++;
			}
			if (c == 1)
			{
				break;
			}
			b[o] = ' ';
			o++;
			i = i + count;
		}
		if (i + k == len)
		{
			break;
		}
	}
	for (int i = 0; i < o; i++)
	{
		printf("%c", b[i]);
	}
}