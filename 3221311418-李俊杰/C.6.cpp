//19. 集合的交集和并集
#include<stdio.h>
#include<stdlib.h>
struct s
{
	int data;
	struct s* next;
};
void qpai(int* a, int n)
{
	if (n < 2)
	{
		return;
	}
	int item = a[0];
	int sleft = 0;
	int sright = n - 1;
	int f = 1;
	while (sleft < sright)
	{
		if (f == 1)
		{
			if (a[sright] >= item)
			{
				sright--;
				continue;
			}
			a[sleft] = a[sright];
			sleft++;
			f = 0;
			continue;
		}
		if (f == 0)
		{
			if (a[sleft] <= item)
			{
				sleft++;
				continue;
			}
			a[sright] = a[sleft];
			sright--;
			f = 1;
			continue;
		}
	}
	a[sleft] = item;
	qpai(a, sleft);
	qpai(a + sleft + 1, n - sleft - 1);
};
struct s* creat(int* a, struct s* p, int k)
{
	struct s* tail, * head, * p1;
	tail = p1 = head = NULL;
	for (int i = 0; i < k; i++)
	{
		p1 = (struct s*)malloc(sizeof(struct s));
		p1->next = NULL;
		p1->data = a[i];
		if (head == NULL)
		{
			head = p1;
		}
		else
		{
			tail->next = p1;
		}
		tail = p1;
	}
	return head;
};
void jiaoji(struct s* p1, struct s* p2)//数据较少
{
	printf("交集:");
	struct s* head = p2;
	for (; p1 != NULL; p1 = p1->next)
	{
		for (p2 = head; p2 != NULL; p2 = p2->next)
		{
			if (p1->data == p2->data)
			{
				printf("%d ", p1->data);
			}
		}
	}
}
void bingji(struct s* p1, struct s* p2)
{
	printf("\n并集:");
	struct s* tail1 = p1;
	struct s* tail2 = p2;
	for (; p1 != NULL && p2 != NULL;)
	{
		if (p1->data < p2->data)
		{
			printf("%d ", p1->data);
			p1 = p1->next;
		}
		else if (p1->data > p2->data)
		{
			printf("%d ", p2->data);
			p2 = p2->next;
		}
		else
		{
			printf("%d ", p1->data);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	if (p1 == NULL)
	{
		for (; p2 != NULL; p2 = p2->next)
		{
			printf("%d ", p2->data);
		}
	}
	else
	{
		for (; p1 != NULL; p1 = p1->next)
		{
			printf("%d ", p1->data);
		}
	}
}
int main()
{
	int a[100];
	int b[100];
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}
	qpai(a, n);
	qpai(b, m);
	struct s* p1 = NULL, * p2 = NULL;
	p1 = creat(a, p1, n);
	p2 = creat(b, p2, m);
	jiaoji(p1, p2);
	bingji(p1, p2);
}