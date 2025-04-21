/*
3．线性表的应用（可根据实际情况进行调整）约瑟夫环问题。
有n个人围坐一圈，现从某个人开始报数，数到M的人出列，接着从出列的下一个人开始重新报数，数到M的人又出列，如此下去，直到所有人都出列为止。
要求依次输出出列人的编码。
*/
/*线性表实现
#include<iostream>
using namespace std;
int main()
{
	int n, m, a[1000], i, j, k;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		a[i] = i;
	i = 1, k = n;
	while (k--)
	{
		j = 0;
		while (1)
		{
			if (i > n)i = 1;
			if (a[i] != -1)j++;
			if (j == m)
			{
				cout << a[i] << " ";
				a[i] = -1;
				i++;
				break;
			}
			i++;
		}
	}

	return 0;
}
*/

/*链表实现*/
#include<iostream>
using namespace std;
struct list
{
	int a;
	list* next;
}*p, * q, * w;
void jin(int x)
{
	for (int i = 0; i < x; i++)
	{
		q = new list;
		if (!i)w = p = q;
		q->next = p, q->a = x - i, p = q, w->next = p;
	}
}
void chu(int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 1; j < y - 1; j++)
			p = p->next;
		q = p->next;
		p->next = p->next->next;
		p = p->next;
		cout << q->a << " ";
		delete q;
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	jin(n);
	chu(n, m);

	return 0;
}