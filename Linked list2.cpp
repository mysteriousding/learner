// 动态链表    
#include <iostream>
#include<string>
using namespace std;
struct STUDENT
{
    int stuNO;
    string stuName;
    float stuScore[3];
    STUDENT* next = NULL;
};
STUDENT* create_list(int n);
void print_list(STUDENT* p);

int main()
{ 
    int n;
    cout << "请输入学生数量: ";
    cin >> n;

    STUDENT* head = create_list(n);
    
    print_list(head);

    return 0;
}


/*老师教的
STUDENT* create_list(int n)
{
    STUDENT* head = new STUDENT;           //(头指针 --- 错)头结点,无需使用循环创建，必须存在

    STUDENT* p = head;                   //p表示当前指针，即目前指向的结点是谁，从头结点开始（head）

    for (int i = 0; i < n; i++)          //根据n的大小，来创建若干个结点并链接起来
    {
        STUDENT* node = new STUDENT;     //node表示新创建的结点

        cout << "请输入学号: \n";
        cin >> node->stuNO;
        cout << "请输入姓名: \n";
        cin >> node->stuName;
        cout << "请输入语文成绩: \n";
        cin >> node->stuScore[0];
        cout << "请输入数学成绩: \n";
        cin >> node->stuScore[1];
        cout << "请输入英语成绩: \n";
        cin >> node->stuScore[2];

        //建立与之前的链表的关联
        p->next = node;//令当前结构体指针中保存的next指针，指向新创建的结点

        p = p->next;   //将循环指针移动到下一个结点的位置处
    }
    //注意，此处最后返回
    return head;

}

void print_list(STUDENT* p)
{
    cout << "学生信息如下:" << endl;

    //输出方式 1
    //p = p->next;
    //while (p != NULL)
    //{
    //    cout << "学号:" << p->stuNO << "   名字:" << p->stuName << "   语文成绩:" << p->stuScore[0] << "   数学成绩:" << p->stuScore[1] << "   英语成绩:" << p->stuScore[2] << endl;
    //    p = p->next;
    //}

    //输出方式 2
    do
    {
        p = p->next;
        cout << "学号:" << p->stuNO << "   名字:" << p->stuName << "   语文成绩:" << p->stuScore[0] << "   数学成绩:" << p->stuScore[1] << "   英语成绩:" << p->stuScore[2] << endl;
    } while (p->next != NULL);
    cout << "链表输出完成！" << endl;
}
*/

//我自己完善的
STUDENT* create_list(int n)
{
    STUDENT* head = NULL, * p = NULL, * node = NULL;

    for (int i = 0; i < n; i++)          //根据n的大小，来创建若干个结点并链接起来
    {
        node = new STUDENT;     //node表示新创建的结点

        if (i == 0)p = head = node;

        cout << "请输入学号: \n";
        cin >> node->stuNO;
        cout << "请输入姓名: \n";
        cin >> node->stuName;
        cout << "请输入语文成绩: \n";
        cin >> node->stuScore[0];
        cout << "请输入数学成绩: \n";
        cin >> node->stuScore[1];
        cout << "请输入英语成绩: \n";
        cin >> node->stuScore[2];

        //建立与之前的链表的关联
        p->next = node;//令当前结构体指针中保存的next指针，指向新创建的结点

        p = p->next;   //将循环指针移动到下一个结点的位置处
    }
    //注意，此处最后返回
    return head;
}

void print_list(STUDENT* p)
{
    cout << "学生信息如下:" << endl;

    while (p != NULL)
    {
        cout << "学号:" << p->stuNO << "   名字:" << p->stuName << "   语文成绩:" << p->stuScore[0] << "   数学成绩:" << p->stuScore[1] << "   英语成绩:" << p->stuScore[2] << endl;
        p = p->next;
    }

    cout << "链表输出完成！" << endl;
}