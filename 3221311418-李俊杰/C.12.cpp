//28. 二叉树公共祖先
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s
{
	char data;
	struct s* left;
	struct s* right;
};
#define max 100
void create(struct s*& q, char* str)
{
	struct s* a[max], * p = NULL;
	int top = -1;
	int k;
	int j = 0;
	char ch;
	ch = str[j];
	while (ch != '\0')
	{
		if (ch == '(')
		{
			top++; a[top] = p; k = 1;
		}
		else if (ch == ')')
		{
			top--;
		}
		else if (ch == ',')
		{
			k = 2;
		}
		else
		{
			p = (struct s*)malloc(sizeof(struct s));
			p->data = ch;
			p->left = p->right = NULL;
			if (q == NULL)
			{
				q = p;
			}
			else
			{
				if (k == 1)
				{
					a[top]->left = p;
				}
				else if (k == 2)
				{
					a[top]->right = p;
				}
			}
		}
		j++;
		ch = str[j];
	}
}
struct s* an(struct s* root, struct s* p, struct s* q)
{
	if (root == NULL || root == p || root == q)
	{
		return root;
	}
	struct s* left = an(root->left, p, q);
	struct s* right = an(root->right, p, q);
	if (left == NULL && right == NULL)
	{
		return NULL;
	}
	else if (left != NULL && right != NULL)
	{
		return root;
	}
	else
	{
		return left ? left : right;
	}
}

struct s* findnode(struct s* root, char x)
{
	if (root == NULL || root->data == x)
	{
		return root;
	}
	struct s* left = findnode(root->left, x);
	if (left != NULL)
	{
		return left;
	}
	struct s* right = findnode(root->right, x);
	return right;
}
int main()
{
	//a(b(d(, g)), c(e, f))
		char s[100];
	struct s* q, * p1, * p2, * p3;
	q = p1 = p2 = p3 = NULL;
	scanf("%s\n", s);//输入树
	create(q, s);
	char ch1, ch2;
	scanf("%c %c", &ch1, &ch2);//输入要查找的俩节点
	p1 = findnode(q, ch1);
	p2 = findnode(q, ch2);
	p3 = an(q, p1, p2);
	printf("%c", p3->data);
}