//32. 二叉树路径输出
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
char a[100];
int k = 0;
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
int findpath(struct s* root, char x)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->data == x)
	{
		a[k++] = root->data;
		return 1;
	}
	int leftResult = findpath(root->left, x);
	if (leftResult)
	{
		a[k++] = root->data;
		return 1;
	}
	int rightResult = findpath(root->right, x);
	if (rightResult)
	{
		a[k++] = root->data;
		return 1;
	}
	return 0;
}
int main()
{
	//A(B(D(,G)),C(E,F))
	char s[100];
	struct s* q, * p1, * p2, * p3;
	q = p1 = p2 = p3 = NULL;
	scanf("%s\n", s);//输入树
	create(q, s);
	char ch1;
	scanf("%c", &ch1);//输入要查找的俩节点
	p1 = findnode(q, ch1);
	if (p1 == NULL)
	{
		printf("%c不是树的节点", ch1);
	}
	else
	{
		findpath(q, ch1);
	}
	for (int i = k - 1; i >= 0; i--)
	{
		printf("%c", a[i]);
		if (i != 0)
		{
			printf("->");
		}
	}
}