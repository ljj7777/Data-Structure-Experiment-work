//36. 图的邻接表和邻接矩阵转换	//无向图
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
void createprint_reverse(adjgraph* G)
{
	int i;
	arcnode* p;
	printf("\n");
	for (i = 0; i < G->v; i++)
	{
		p = G->a[i].first;
		//printf("%d ", i);头
		while (p != NULL)
		{
			b[i][p->bianhao] = 1;
			p = p->next;
		}
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
					a[j][u] = 1;
					break;
				}
			}
		}
	}
	create(G, a, dingdianshu, bianshu); //实现邻接矩阵变为邻接表；
	print(G);
	createprint_reverse(G);
	for (int i = 0; i < dingdianshu; i++)
	{
		for (int u = 0; u < dingdianshu; u++)
		{
			printf("%d ", b[i][u]);
		}
		printf("\n");
	}
}