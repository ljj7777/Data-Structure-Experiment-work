#include<stdio.h>
#include<stdlib.h>
struct s
{
	int data;
	struct s* next;
};
struct s* creat(struct s* p)
{
	struct s* tail = NULL;
	struct s* head = NULL;
	struct s* p1 = NULL;
	while (1)
	{
		p1 = (struct s*)malloc(sizeof(struct s));
		p1->next = NULL;
		scanf("%d", &p1->data);
		if (p1->data == -1)
		{
			break;
		}
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
}
void sort(struct s* p)
{
	struct s* tail1 = NULL, * tail2 = NULL;
	struct s* p1 = NULL, * p2 = NULL, * head1 = NULL, * head2 = NULL;
	for (; p != NULL; p = p->next)
	{
		if (p->data % 2 != 0)//奇数
		{
			p1 = (struct s*)malloc(sizeof(struct s));
			p1->next = NULL;
			p1->data = p->data;
			if (head1 == NULL)
			{
				head1 = p1;
			}
			else
			{
				tail1->next = p1;
			}
			tail1 = p1;
		}
		else
		{
			p2 = (struct s*)malloc(sizeof(struct s));
			p2->next = NULL;
			p2->data = p->data;
			if (head2 == NULL)
			{
				head2 = p2;
			}
			else
			{
				tail2->next = p2;
			}
			tail2 = p2;
		}
	}
	printf("L1:");
	for (; head1 != NULL; head1 = head1->next)
	{
		printf("%d", head1->data);
		if (head1->next != NULL)
		{
			printf("->");
		}
	}
	printf("\nL2:");
	for (; head2 != NULL; head2 = head2->next)
	{
		printf("%d", head2->data);
		if (head2->next != NULL)
		{
			printf("->");
		}
	}
}
int main()
{
	struct s* p = NULL;
	p = creat(p);
	sort(p);
}