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
STUDENT* create_list(int n);     //链表创建
void print_list(STUDENT* p);     //打印链表
void append(STUDENT*& p);        //追加结点
void insert_note(STUDENT* &p);   //结点插入
void modify_node(STUDENT* p);    //结点修改
void delete_list(STUDENT* &p);    //结点删除


int main()
{
    int n;
    cout << "请输入学生数量: ";
    cin >> n;

    STUDENT* head = create_list(n);        //创建链表
    //print_list(head);
    while (1)
    {
        cout << "请输入你需要的操作编号" << endl;
        cout << "1：打印链表，2：删除结点，3：插入结点，4：追加结点，5：修改结点，0：退出程序" << endl;
        int choice;
        cin >> choice;
        /*if (choice == 0)break;*/
        switch (choice)
        {
        case 0:
            delete head;
            return 0;
        case 1:
            print_list(head);
            break;
        case 2:
            delete_list(head);
            break;
        case 3:
            insert_note(head);
            break;
        case 4:
            append(head);
            break;
        case 5:
            modify_node(head);
            break;
        }
    }

    return 0;
}


STUDENT* create_list(int n)
{
    STUDENT* head = NULL, * p = NULL, * node = NULL;

    for (int i = 0; i < n; i++)     
    {
        node = new STUDENT;           


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

        if (i != 0)
        {
            p->next = node;
            p = p->next;
        }
        else p = head = node;

    }

    return head;
}

void print_list(STUDENT* p)
{
    cout << "学生信息如下:" << endl;

    while (p != NULL)
    {
        cout << "学号:" << p->stuNO 
            << "   名字:" << p->stuName 
            << "   语文成绩:" << p->stuScore[0]
            << "   数学成绩:" << p->stuScore[1] 
            << "   英语成绩:" << p->stuScore[2] << endl;

        p = p->next;
    }

    cout << "链表输出完成！" << endl;
}

void insert_note(STUDENT* &p)
{
    cout << "请输入学生学号（新结点将放置在这个学生的后面）:" << endl;
    int stuNO;
    cin >> stuNO;

    //新创建结点
    STUDENT* node = new STUDENT;

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

    STUDENT* p0 = p, * p1 = NULL;
    int l = 0;
    if (p != NULL)
    {
        do
        {
            if (p0->stuNO == stuNO)
            {
                p1 = p0->next;
                p0->next = node;
                node->next = p1;
                l = 1;
                cout << "已将新的学生结点追加到链表的指定位置！" << endl;
                break;
            }
            p0 = p0->next;
        } while (p0/*->next*/ != NULL);
        if (l == 0)
        {
            p0 = node;
            cout << "在尾结点之前没有找到该学号的学生，默认追加到链表的末尾！" << endl;
        }
    }
    else
    {
        p = node;
        cout << "在尾结点之前没有找到该学号的学生，默认追加到链表的末尾！" << endl;
    }
}

void append(STUDENT*& p)        //现在指针 p 就是指针 head 的引用，他们是同一个指针（自己研究,自豪.ing
{
    //新创建结点
    STUDENT* node = new STUDENT;

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

    //插入链表末尾
    if (p == NULL)p = node;
    else
    {
        STUDENT* p0 = p;
        while (p0->next != NULL)p0 = p0->next;
        p0->next = node;
    }
}

void modify_node(STUDENT* p)
{
    cout << "请输入要修改的学生的学号:" << endl;
    int stuNO;
    cin >> stuNO;

    STUDENT* p0 = p;
    while (p0 != nullptr)
    {
        if (p0->stuNO == stuNO)
        {
            cout << "请输入学生新的姓名：" << endl;
            cin >> p0->stuName;
            return;
        }
        p0 = p0->next;
    }
    cout << "未找到指定的学生！无法进行修改！" << endl;
}

void delete_list(STUDENT*& p)
{
    cout << "请输入要删除的学生的学号:" << endl;
    int stuNO;
    cin >> stuNO;

    STUDENT* p0 = p,*p1=NULL;
    if (p->stuNO == stuNO)
    {
        p1 = p->next;
        p->next = NULL;
        delete p;
        p = p1;
        return;
    }
    while (p0 != NULL)
    {
        if (p0->stuNO == stuNO)
        {
            p1 = p0->next;
            p0->next = NULL;
            delete p0;
            p0 = p1;
            break;
        }
        p0 = p0->next;
    }



    //do
    //{
    //    if (p0->stuNO == stuNO)
    //    {
    //        p1 = p0->next;
    //        p0->next = NULL;
    //        delete p0;
    //        p0 = p1;
    //        return;
    //    }
    //    p0 = p0->next;
    //} while (p0/*->next*/ != NULL);

}