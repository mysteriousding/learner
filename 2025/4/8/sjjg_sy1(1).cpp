/*
1．顺序表的操作利用顺序存储方式实现下列功能：
根据键盘输入数据建立一个线性表，并输出该线性表；对该线性表进行数据的插入、删除、查找操作，并在插入和删除数据后，再输出线性表。
*/
#include<iostream>
using namespace std;
typedef struct
{
    int data[100];
    int size;
}Sqlist;
//输出线性表
void output(Sqlist L)
{
    cout << "线性表的元素为：";
    for (int i = 0; i < L.size; i++)
        cout << L.data[i] << " ";
    cout << endl;
}
//输入线性表
void input(Sqlist& L)
{
    cout << "请输入线性表的元素个数：";
    cin >> L.size;
    cout << "请输入线性表的元素：";
    for (int i = 0; i < L.size; i++)
        cin >> L.data[i];
    output(L);
}
//线性表的按位查找
int Get(Sqlist L, int i)
{
    if (i >= 1 && i <= L.size)
        return L.data[i - 1];
    else
    {
        cout << "超出范围" << endl;
        return -1;
    }
}
//线性表的按值查找
int Locate(Sqlist L, int x)
{
    for (int i = 0; i < L.size; i++)
        if (L.data[i] == x)return i + 1;
    return 0;
}
//线性表的插入
void Insert(Sqlist& L, int i, int x)
{
    if (L.size >= 100)
    {
        cout << "上溢";
        return;
    }
    if (i<1 || i>L.size + 1)
    {
        cout << "位置不合适";
        return;
    }
    for (int j = L.size; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = x;
    L.size++;
    output(L);
}
//线性表的删除
void Delete(Sqlist& L, int i)
{
    if (L.size == 0)
    {
        cout << "下溢";
        return;
    }
    if (i<1 || i>L.size)
    {
        cout << "位置不合适";
        return;
    }
    for (int j = i; j <= L.size - 1; j++)
        L.data[j - 1] = L.data[j];
    L.size--;
    output(L);
}
int main()
{
    int n, m;
    Sqlist L;
    input(L);
    cout << "请输入查找位次：";
    cin >> n;
    m = Get(L, n);
    if (m != -1)cout << "元素为：" << m << endl;
    cout << "请输入查找元素：";
    cin >> n;
    m = Locate(L, n);
    if (m)cout << "位次为：" << m << endl;
    cout << "请输入插入位次和插入位次元素：";
    cin >> n >> m;
    Insert(L, n, m);
    cout << "请输入删除位次：";
    cin >> n;
    Delete(L, n);

    return 0;
}
