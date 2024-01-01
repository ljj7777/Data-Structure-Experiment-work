#include<stdio.h>
int main()
{
	int k;
	scanf("%d", &k);
	int change = k;
	int a;
	int b;
	int c;
	int d;
	a = b = c = d = 0;
	while (1) {
		if (k - 25 >= 0) {
			a++;
			k = k - 25;
		}
		else break;
	}
	while (1) {
		if (k - 10 >= 0) {
			b++;
			k = k - 10;
		}
		else break;
	}
	while (1) {
		if (k - 5 >= 0) {
			c++;
			k = k - 5;
		}
		else break;
	}
	while (1) {
		if (k - 1 >= 0) {
			d++;
			k = k - 1;
		}
		else break;
	}
	printf("找零 %d 分，期望输出：", change);
	if (a > 0)
	{
		printf("%d 个 25 分 ", a);
	}
	if (b > 0)
	{
		printf("%d 个 10 分 ", b);
	}
	if (c > 0)
	{
		printf("%d 个 5 分 ", c);
	}
	if (d > 0)
	{
		printf("%d 个 1 分 ", d);
	}
}