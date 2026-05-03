/*
小蓝的图书馆

问题描述
小蓝是一个热爱阅读的年轻人，他有一个小型图书馆。
为了能够管理他的书籍库存，他需要一个程序来记录图书的信息并执行两种操作：
添加图书 add 和查找作者 find。

初始小蓝没有书，给出 n 个操作。
add 操作给出两个字符串 bookname, author，表示添加的图书图书名和作者；
find 操作给出一个字符串 author，你需要输出小蓝的图书馆里这个 author 有多少本图书。

输入格式
第一行一个整数 n，表示有 n 个操作。

之后 n 行，给出操作及后面的参数，如题所述。

给出的字符串长度 len 不超过 10。

输出格式
对每一个 find 操作，你需要输出这个作者在小蓝的图书馆有多少本书，注意是书的数量，不是不同书的数量，同时不同作者可能出现同名的书。

样例输入
7
find author1
add book1 author1
find author1
add book1 author1
find author1
add book1 author2
find author2

样例输出
0
1
2
1

评测数据规模
1≤n≤1000,1≤len≤10。
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    map<string, int>a;
    int n;
    string x, y, z;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cin >> x >> y;
        if (x == "add")
            cin >> z, a[z]++;
        else if (x == "find")
            cout << a[y] << endl;
    }

    return 0;
}
