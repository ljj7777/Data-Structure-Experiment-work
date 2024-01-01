//33. 由遍历序列构造二叉树
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct s
{
	char data;
	struct s* left;
	struct s* right;
};
struct s* create(char* a, char* c, int n)
{
	struct s* b;
	char* p;
	int k;
	if (n <= 0)
	{
		return NULL;
	}
	b = (struct s*)malloc(sizeof(struct s));
	b->data = *a;
	for (p = c; p < c + n; p++)
	{
		if (*p == *a)
		{
			break;
		}
	}
	k = p - c;
	b->left = create(a + 1, c, k);
	b->right = create(a + k + 1, p + 1, n - k - 1);
	return b;
}
void print(struct s* b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->left != NULL || b->right != NULL)
		{
			printf("(");
			print(b->left);
			if (b->right != NULL)
			{
				printf(",");
			}
			print(b->right);
			printf(")");
		}
	}
}
int main()
{
	//ABDGCEF
	//DGBAECF
	char a[100];
	char b[100];
	struct s* p = NULL;
	scanf("%s %s", a, b);
	int n;
	n = strlen(a);
	p = create(a, b, n);
	print(p);
}