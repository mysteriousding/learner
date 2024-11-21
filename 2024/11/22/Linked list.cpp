// 静态链表    
//        ---指每个节点并不是按照程序运行时的需求而动态创建，而是在一开始就创建好，并使用指针链接起来。  
//           严格来说，静态链表跟数组比较类似，都是实现指定好了元素存放的位置。
//           但是不同之处在于，只能通过指针进行顺序访问，而不能通过下标随机访问
#include <iostream>
#include<string>
using namespace std;
struct STUDENT
{
    int stuNO;
    string stuName;
    float stuScore[3];
    STUDENT* next;
};
int main()
{
    STUDENT a, b, c;
    STUDENT* head;
    a.stuNO = 1; a.stuName = "张三"; a.stuScore[0] = 98; a.stuScore[1] = 100; a.stuScore[2] = 99;
    b.stuNO = 2; b.stuName = "李四"; b.stuScore[0] = 88; b.stuScore[1] = 94; b.stuScore[2] = 78;
    c.stuNO = 3; c.stuName = "王五"; c.stuScore[0] = 66; c.stuScore[1] = 90; c.stuScore[2] = 54;

    //建立链表结点之间的关联
    head = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    STUDENT* p = head;
    while (p != NULL)
    {
        cout << "学号:" << p->stuNO << "   名字:" << p->stuName << "   语文成绩:" << p->stuScore[0] << "   数学成绩:" << p->stuScore[1] << "   英语成绩:" << p->stuScore[2] << endl;
        p = p->next;
    }

    return 0;
}
