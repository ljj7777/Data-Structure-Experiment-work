//27. 稀疏矩阵的运算
#include<stdio.h>
#include<stdlib.h>
struct s
{
	int hang;
	int lie;
	int data;
};
int main()
{
	int a[100][100];
	int b[100][100];
	int n;
	int m;
	scanf("%d %d", &n, &m);//两矩阵行,列相等才能加，乘可不同，这里统一；
	for (int i = 0; i < n; i++)
	{
		for (int u = 0; u < m; u++)
		{
			scanf("%d", &a[i][u]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int u = 0; u < m; u++)
		{
			scanf("%d", &b[i][u]);
		}
	}
	struct s z[100], x[100], c[100], f[100];
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int u = 0; u < m; u++)
		{
			if (a[i][u] != 0)
			{
				z[k].hang = i; z[k].lie = u; z[k].data = a[i][u];
				k++;
			}
		}
	}
	int l = 0;
	for (int i = 0; i < n; i++)
	{
		for (int u = 0; u < m; u++)
		{
			if (b[i][u] != 0)
			{
				x[l].hang = i; x[l].lie = u; x[l].data = b[i][u];
				l++;
			}
		}
	}
	int i;
	int j;
	int g = 0;
	for (i = 0, j = 0; i < k && j < l;)
	{
		if (z[i].hang == x[j].hang && z[i].lie < x[j].lie || z[i].hang < x[j].hang)
		{
			c[g] = z[i];
			i++;
			g++;
		}
		else if (z[i].hang == x[j].hang && z[i].lie > x[j].lie || z[i].hang > x[j].hang)
		{
			c[g] = x[j];
			j++;
			g++;
		}
		else
		{
			if (z[i].data + x[j].data != 0)
			{
				c[g].hang = z[i].hang;
				c[g].lie = z[i].lie;
				c[g].data = z[i].data + x[j].data;
				g++;
				i++;
				j++;
			}
			else
			{
				i++;
				j++;
			}
		}
	}
	if (j > l - 1)
	{
		for (int p = i; i < k; i++)
		{
			c[g] = z[i]; g++;
		}
	}
	else
	{
		for (int p = j; j < l; j++)
		{
			c[g] = x[j]; g++;
		}
	}
	printf("\n相加结果:\n");
	for (int t = 0; t < g; t++)
	{
		printf("%d %d %d\n", c[t].hang, c[t].lie, c[t].data);
	}
	int sum;
	int d[100][100];
	for (int ii = 0; ii < n; ii++)
	{
		for (int jj = 0; jj < n; jj++)
		{
			sum = 0;
			for (int kk = 0; kk < n; kk++)
			{
				sum = sum + a[ii][kk] * b[kk][jj];
			}
			d[ii][jj] = sum;
		}
	}
	int cc = 0;
	for (int xx = 0; xx < n; xx++)
	{
		for (int yy = 0; yy < n; yy++)
		{
			if (d[xx][yy] != 0)
			{
				f[cc].hang = xx; f[cc].lie = yy; f[cc].data = d[xx][yy]; cc++;
			}
		}
	}
	printf("\n相乘结果:\n");
	for (int pp = 0; pp < cc; pp++)
	{
		printf("%d %d %d\n", f[pp].hang, f[pp].lie, f[pp].data);
	}
}