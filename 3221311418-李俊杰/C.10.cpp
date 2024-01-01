//24. 十进制转换成其他进制   //只适合正整数
#include<stdio.h>
char a[] = { 0,1,2,3,4,5,6,7,8,9,'A','B','C','D','E','F' };
void tsf(int n, int k)
{
	if (n < 1)
	{
		return;
	}
	tsf(n / k, k);
	if (n % k < 10)
	{
		printf("%d", a[n % k]);
	}
	else
		printf("%c", a[n % k]);
}
int main()
{
	int n;
	scanf("%d", &n);
	if (n)
		printf("二进制:");
	tsf(n, 2);
	printf("\n八进制:");
	tsf(n, 8);
	printf("\n十六进制:");
	tsf(n, 16);
}