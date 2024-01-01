#include<stdio.h>
#include<stdlib.h>
struct s
{
	int data;
	struct s* left;
	struct s* right;
};
struct s* create(int a[100][3], int k, int n)
{
	if (k >= n || a[k][0] == -1)
	{
		return NULL;
	}
	struct s* p = NULL;
	p = (struct s*)malloc(sizeof(struct s));
	p->left = NULL;
	p->right = NULL;
	p->data = a[k][0];
	if (a[k][1] != -1)
	{
		p->left = create(a, a[k][1] - 1, n);
	}
	if (a[k][2] != -1)
	{
		p->right = create(a, a[k][2] - 1, n);
	}
	return p;
}
void print_pre(struct s* p)
{
	if (p != NULL)
	{
		printf("%d ", p->data);
		print_pre(p->left);
		print_pre(p->right);
	}
}
void print_in(struct s* p)
{
	if (p != NULL)
	{
		print_in(p->left);
		printf("%d ", p->data);
		print_in(p->right);
	}
}
void print_post(struct s* p)
{
	if (p != NULL)
	{
		print_pre(p->left);
		print_pre(p->right);
		printf("%d ", p->data);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int a[100][3];
	struct s* p = NULL;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	}
	p = create(a, 0, n);

	print_pre(p);
	printf("\n");
	print_in(p);
	printf("\n");
	print_post(p);
}