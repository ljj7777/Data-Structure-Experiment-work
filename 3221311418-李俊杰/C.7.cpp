//18. 约瑟夫环问题
#include<stdio.h>
#include<stdlib.h>
struct s
{
	int data;
	struct s* next;
	struct s* front;
};
int n;
struct s* creat(struct s* p)
{
	struct s* tail, * head, * p1;
	p1 = head = tail = NULL;
	scanf("%d", &n);//总人数;
	for (int i = 0; i < n; i++)
	{
		p1 = (struct s*)malloc(sizeof(struct s));
		p1->next = NULL;
		scanf("%d", &p1->data);
		if (head == NULL)
		{
			head = p1;
		}
		else
		{
			tail->next = p1;
			p1->front = tail;
		}
		tail = p1;
	}
	tail->next = head;
	head->front = tail;
	return head;
}
void sround(struct s* p, int k)
{
	struct s* p1, * p2;
	p1 = p2 = NULL;
	int g = n;
	p2 = p;
	if (k == 1)
	{
		for (; p->next != p2; p = p->next)
		{

		}
		printf("%d", p->data);
	}
	else
	{
		while (1)
		{
			for (int i = 0; i < k - 1; i++)
			{
				p2 = p2->next;
			}
			p1 = p2->front;
			p1->next = p2->next;
			p2->next->front = p1;
			p2 = p2->next;
			g--;
			if (g == 1)
			{
				break;
			}
		}
		printf("%d", p2->data);
	}
}
int main()
{
	struct s* p1 = NULL;
	p1 = creat(p1);
	int k;
	scanf("%d", &k);//报数
	sround(p1, k);
}