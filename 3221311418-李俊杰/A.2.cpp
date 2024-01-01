#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct s
{
	double num;//电话号码
	char name[100];//姓名
	char address[100];//地址
	int bshu = 0;
	double cft = -1;
};
struct k
{
	double num;
	char name[100];
	char address[100];
	struct k* next;
};
struct kk
{
	struct k* first;
};
int get_k(int n)
{
	int i;
	int f;
	while (1)
	{
		f = 0;
		for (i = n / 2 + 1; i > 1; i--)
		{
			if (n % i == 0)
			{
				f = 1;
				break;
			}
		}
		if (f == 0)
		{
			return n;
		}
		else
		{
			n--;
		}
	}
};
struct s a[100];
struct kk b[100];
void create(int num, int k, char* name, char* adress)
{
	int adr;
	adr = num % k;
	int cft;
	if (a[adr].bshu == 0)
	{
		a[adr].num = num;
		strcpy(a[adr].name, name);
		strcpy(a[adr].address, adress);
		a[adr].bshu = 1;
		a[adr].cft = 1;
	}
	else
	{
		cft = 1;//记录冲突数；
		while (1)
		{
			adr = (adr + 1) % k;
			cft++;
			if (a[adr].bshu == 0)
			{
				a[adr].num = num;
				strcpy(a[adr].name, name);
				strcpy(a[adr].address, adress);
				a[adr].bshu = 1;
				a[adr].cft = cft;
				break;
			}
		}
	}
}
void create_sq(int num, int k, char* name, char* adress)
{
	int adr;
	int f = 1;//符号；
	int n = 1;
	adr = num % k;
	int cft;
	if (a[adr].bshu == 0)
	{
		a[adr].num = num;
		strcpy(a[adr].name, name);
		strcpy(a[adr].address, adress);
		a[adr].bshu = 1;
		a[adr].cft = 1;
	}
	else
	{
		cft = 1;//记录冲突数；
		while (1)
		{
			adr = (adr + 1 * f * (n * n)) % k;
			cft++;
			f = -f;
			n++;
			if (a[adr].bshu == 0)
			{
				a[adr].num = num;
				strcpy(a[adr].name, name);
				strcpy(a[adr].address, adress);
				a[adr].bshu = 1;
				a[adr].cft = cft;
				break;
			}
		}
	}
}
void aslandcft_rate(int k)
{
	double asl;//平均探测数
	double sum_1 = 0;//总探测数
	double sum_2 = 0;//总存有数
	for (int i = 0; i < k; i++)
	{
		if (a[i].bshu != 0)
		{
			sum_2++;
			sum_1 = sum_1 + a[i].cft;
		}
	}
	printf("%f %f\n", sum_1, sum_2);
	printf("冲突率:%.2lf\n平均探测数:%.4f", (sum_1 - sum_2) / sum_1, sum_1 / sum_2);
}
void aslandcft_rate_1(int k)
{
	double asl;
	double sum = 0;
	struct k* p = NULL;
	double m = 0;
	for (int i = 0; i < k; i++)
	{
		if (b[i].first != NULL)
		{
			p = b[i].first;
			m++;
			for (; p != NULL; p = p->next)
			{
				sum++;
			}
		}
	}
	printf("平均探测数:%.4f", sum / m);
}
void create_l(int k, int num, char* name, char* adress)
{
	int adr;
	adr = num % k;
	struct k* q = NULL;
	q = (struct k*)malloc(sizeof(struct k));
	q->next = NULL;
	q->num = num;
	if (b[adr].first == NULL)
	{
		b[adr].first = q;
	}
	else
	{
		q->next = b[adr].first;
		b[adr].first = q;
	}
}
int main()
{
	int n;//哈希表长度
	scanf("%d", &n);
	int m;
	int k;//标准
	k = get_k(n);
	k = k - 1;
	int haoma;
	char name[100];
	char adress[100];
	scanf("%d", &m);
	for (int i = 0; i < k; i++)
	{
		b[i].first = NULL;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d %s %s", &haoma, name, adress);//输入数据
		create_sq(haoma, k, name, adress);
		create_l(k, haoma, name, adress);//拉链法;
	}
	aslandcft_rate(k);
	aslandcft_rate_1(k);
}