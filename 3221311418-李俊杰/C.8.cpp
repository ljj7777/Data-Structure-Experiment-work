//23. 合法出栈序列判断
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10
struct s* p;
char c[max];
int o = 0;
struct s
{
	char data[max];
	int top;
};
void creat()
{
	p = (struct s*)malloc(sizeof(struct s));
	p->top = -1;
};
void in(char ch)
{
	p->top++;
	p->data[p->top] = ch;
};
char out()
{
	char ch;
	ch = p->data[p->top];
	p->top--;
	return ch;
};
int f;
void judge(char ch)
{
	if (p->top == -1)
	{
		return;
	}
	if (p->data[p->top] == ch)
	{
		c[o] = ch;
		o++;
		p->top--;
		f = 1;
	}
};
int main()
{
	char a[max];
	char b[max];
	gets_s(a);	//基准
	gets_s(b);  //判断
	int len2 = strlen(b);
	printf("%d\n", len2);
	creat();
	char ch;
	char e;
	int k = 0;
	int i;
	for (i = 0; i < len2; i++)
	{
		f = 0;
		ch = b[i];
		judge(ch);
		if (f == 1)
		{
			continue;
		}
		in(a[k]);
		if (a[k] == ch)
		{
			e = out();
			c[o] = e;
			o++;
			k++;
		}
		else
		{
			k++;
			i--;
		}
		if (k == len2)
		{
			break;
		}
	}
	while (i < len2)
	{
		ch = b[i];
		judge(ch);
		i++;
	}
	if (o != len2)
	{
		printf("不是合法的出栈序列");
	}
	else
	{
		printf("是合法的出栈序列");
	}
}