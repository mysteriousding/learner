#include<iostream>
using namespace std;
typedef struct lnode
{
    int data;
    struct lnode* next;
}Lnode, * Link;
//单链表的按位查找
int Get(Link L, int i)
{
    Lnode* p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p)
    {
        cout << "error";
        return -1;
    }
    else return p->data;
}
//单链表的插入
void Insert(Link& L, int i, int x)
{
    Lnode* p = L;
    int j = 0;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p)  cout << "位置不合理" << endl;
    else
    {
        Lnode* s = new Lnode;
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}
void Delete(Link& L, int i)//单链表的删除
{
    Lnode* p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || !p->next || i < 1)cout << "位置不合理";
    else
    {
        Lnode* q = p->next;
        p->next = q->next;
        delete q;
    }
}
Link creat()//单链表的建立
{
    Link head = new Lnode;
    head->next = NULL;
    int a;
    cout << "请输入单链表的元素(输入‘*’时结束)：" << endl;
    while (cin >> a)
    {
        Link newnode = new Lnode;
        newnode->data = a;
        newnode->next = head->next;
        head->next = newnode;
    }
    cin.clear();
    cin.ignore(100, '\n');
    return head;
}
void print(Link head)
{
    Link p = head->next;
    cout << "单链表的元素为：";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

}
void Delete(Link head)
{
    Link p;
    while (head)
    {
        p = head;
        head = head->next;
        delete p;
    }
}
int main()
{
    Link L = creat();
    print(L);
    int n, m;
    cout << "请输入插入位置和插入值：";
    cin >> n >> m;
    Insert(L, n, m);
    print(L);
    cout << "请输入要删除的位置：";
    cin >> n;
    Delete(L, n);
    print(L);
    Delete(L);

    return 0;
}