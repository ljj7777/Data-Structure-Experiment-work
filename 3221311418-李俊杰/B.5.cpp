#include<stdio.h>
#include<stdlib.h>
typedef struct anode
{
	int bianhao;
	struct anode* next;
}arcnode;
typedef struct vnode
{
	int data;
	arcnode* first;
}vnode;
typedef struct
{
	vnode a[10];
	int v;
	int e;
}adjgraph;
void create(adjgraph*& G, int a[10][10], int vcount, int ecount)
{
	int i, j;
	arcnode* p;
	G = (adjgraph*)malloc(sizeof(adjgraph));
	for (i = 0; i < vcount; i++)//初始化list的first域
	{
		G->a[i].first = NULL;
	}
	for (i = 0; i < vcount; i++)
	{
		for (j = vcount; j >= 0; j--)
		{
			if (a[i][j] != 0 && a[i][j] != 10)
			{
				p = (arcnode*)malloc(sizeof(arcnode));
				p->bianhao = j;
				p->next = G->a[i].first;
				G->a[i].first = p;
			}
		}
	}
	G->v = vcount;
	G->e = ecount;
}
void print(adjgraph* G)
{
	int i;
	arcnode* p;
	printf("邻接表:\n");
	for (i = 0; i < G->v; i++)
	{
		p = G->a[i].first;
		printf("%d ", i);
		while (p != NULL)
		{
			printf("%d", p->bianhao);
			p = p->next;
			if (p != NULL)
			{
				printf("->");
			}
		}
		printf("->NULL");
		printf("\n");
	}
}
int b[10][10] = { 0 };
int a[10][10] = { 0 };
int visit[10] = { 0 };
void dfs(adjgraph* G, int v)
{
	arcnode* p;
	visit[v] = 1;
	p = G->a[v].first;
	while (p != NULL)
	{
		if (visit[p->bianhao] == 0)
		{
			dfs(G, p->bianhao);
		}
		p = p->next;
	}
}
int main()
{
	int bianshu;
	int dingdianshu;
	int bian1; int bian2;
	adjgraph* G;
	scanf("%d %d", &bianshu, &dingdianshu);
	for (int i = 0; i < bianshu; i++)
	{
		scanf("%d %d", &bian1, &bian2);
		for (int u = 0; u < dingdianshu; u++)
		{
			for (int j = 0; j < dingdianshu; j++)
			{
				if (u == bian1 && j == bian2)
				{
					a[u][j] = 1;
					break;
				}
			}
		}
	}
	create(G, a, dingdianshu, bianshu); //实现邻接矩阵变为邻接表；
	print(G);
	int f = 0;
	for (int i = 0; i < dingdianshu; i++)
	{
		dfs(G, i);
		for (int u = 0; u < dingdianshu; u++)
		{
			if (visit[u] == 0)
			{
				f = 1;
				break;
			}
			else
			{
				visit[u] = 0;
			}
		}
		if (f == 1)
		{
			printf("no");
			break;
		}
	}
	if (f == 0)
	{
		printf("yes");
	}
}