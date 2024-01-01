#include<stdio.h>
#include<string.h>
int d[100];
int min(int a, int b)
{
	if (a > b)return a;
	else return b;
}
void get_d(char* s, int n)
{
	d[1] = 1;
	for (int i = 2, l, r = 1; i <= n; i++)
	{
		if (i <= r)
		{
			d[i] = min(d[r - i + l], d[r - i + 1]);
		}
		while (s[i - d[i]] == s[i + d[i]])
		{
			d[i]++;
		}
		if (i + d[i] - 1 > r)
		{
			l = i - d[i] + 1, r = i + d[i] - 1;
		}
	}
}
void get_max(char* s, int n)
{
	int max = d[1];
	int k = 1;
	for (int i = 2; i < n; i++)
	{
		if (d[i] > max)
		{
			max = d[i];
			k = i;
		}
	}
	for (int i = k - max / 2 - 1; i <= k + max / 2 + 1; i = i + 2)
	{
		printf("%c", s[i]);
	}
}
int main()
{
	char a[100];
	char s[100];
	scanf("%s", a + 1);
	int n = strlen(a + 1); int k = 0;
	s[0] = '$';
	s[++k] = '#';
	for (int i = 1; i <= n; i++)
	{
		s[++k] = a[i]; s[++k] = '#';
	}
	n = k;
	get_d(s, n);
	get_max(s, n);
}