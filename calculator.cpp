#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

#define pi 3.14159265358979

void jiemian(); 
void gn1();
void gn2();
void gn3();
void gn4();
void gn5();
void gn6();
void gn7();
void gn8();
void gn9();
void gn10();
void gn11();
void gn12();
void gn13();
void gn14();
void gn15();
void gn16();
void gn17();
void gn18();
void gn19();
void gn20();
void gn21();
void gn22();


int main()
{
    int k; 
    //cout << fixed << endl;

    while (1)
    {
        system("cls");
        jiemian();
        cin >> k; 
        system("cls");
        switch (k) 
        {
        case 1:gn1(); break;
        case 2:gn2(); break;
        case 3:gn3(); break;
        case 4:gn4(); break;
        case 5:gn5(); break;
        case 6:gn6(); break;
        case 7:gn7(); break;
        case 8:gn8(); break;
        case 9:gn9(); break;
        case 10:gn10(); break; 
        case 11:gn11(); break;
        case 12:gn12(); break;
        case 13:gn13(); break;
        case 14:gn14(); break;
        case 15:gn15(); break;
        case 16:gn16(); break;
        case 17:gn17(); break;
        case 18:gn18(); break;
        case 19:gn19(); break;
        case 20:gn20(); break;
        case 21:gn21(); break;
        case 22:gn22(); break; 
        case 23:break;
        case 24:break;
        default:cout << "请重新输入！" << endl;;
        }
        cout << endl; 
        system("pause");
    }
    

	return 0;
}

void jiemian()
{
    cout << "***********************************" << endl;
    cout << "1. 加法" << endl;
    cout << "2. 减法" << endl;
    cout << "3. 乘法" << endl;
    cout << "4. 除法" << endl;
    cout << "5. 求余" << endl;
    cout << "6. 判断数字的位数" << endl;
    cout << "7. 计算圆面积" << endl;
    cout << "8. 判断闰年" << endl;
    cout << "9. 计算从 1 到输入数之间的奇数和 (for)" << endl;
    cout << "10. 计算从 1 到输入数之间的偶数和 (while) " << endl;
    cout << "11. 输出从1到输入数之间所有3的倍数（do-while)" << endl;
    cout << "12. 求即被 3 整除又被 5 整除的数" << endl;
    cout << "13. 求水仙花数" << endl;
    cout << "14. 求最大值" << endl;
    cout << "15. 求最大最小值" << endl;
    cout << "16. 冒泡排序" << endl;
    cout << "17. 矩阵转置" << endl;
    cout << "18. 求对角线和" << endl;
    cout << "19. 统计单词个数" << endl;
    cout << "20. 静态创建链表" << endl;
    cout << "21. 动态创建链表" << endl;
    cout << "22. 学生成绩排序" << endl;
    cout << "23. 学生成绩普涨 10 分" << endl;
    cout << "24. 退出" << endl;
    cout << "***********************************" << endl;
}

void gn1()
{
    cout << "请输入将相加的两个数:" << endl;
    double n, m;
    cin >> n >> m;
    cout << endl << n << " + " << m << " = " << n + m << endl;
}

void gn2()
{
    cout << "请输入将相减的两个数:" << endl;
    double n, m;
    cin >> n >> m;
    cout << endl << n << " - " << m << " = " << n - m << endl;
}

void gn3()
{
    cout << "请输入将相乘的两个数:" << endl;
    double n, m;
    cin >> n >> m;
    cout << endl << n << " * " << m << " = " << n * m << endl;
}

void gn4()
{
    cout << "请输入将相除的两个数:" << endl;
    double n, m;
    cin >> n >> m;
    if (m == 0)
    {
        cout << "请不要将除数输为0" << endl;
        return;
    }
    cout << endl << n << " / " << m << " = " << n * 1.0 / m << endl;
}

void gn5()
{
    cout << "请输入将相除的两个数:" << endl;
    long long n, m;
    cin >> n >> m;
    if (m == 0)
    {
        cout << "请不要将除数输为0！" << endl;
        return;
    }
    else if (n!=(int)n|| m != (int)m)
    {
        cout << "请输入整数！" << endl;
        return;
    }
    cout << endl << n << " % " << m << " = " << n / m << " ··· " << n % m << endl;
}

void gn6()
{
    cout << "请输入将判断数:" << endl;
    long long n, m;
    int i = 0;
    cin >> n;
    m = n;
    while (m != 0)
    {
        m /= 10;
        i++;
    }

    cout << endl << n << " 为 " << i << " 位数" << endl;
}

void gn7()
{
    cout << "请输入计算圆的半径r:" << endl;
    double n;
    cin >> n ;
    cout << endl << "该圆的面积为: " << pi * n * n << endl;
}

void gn8()
{
    cout << "请输入计算判断的年份:" << endl;
    int n,i=0;
    cin >> n;
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)i = 1;

    cout << endl << n << "年" << (i ? "" : "不") << "是闰年" << endl;
}

void gn9()
{
    cout << "请输入上界:" << endl;
    int n;
    long long sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i += 2)
        sum += i;

    cout << endl << "从 1 到 " << n << " 之间的奇数和为: " << sum << endl;
}

void gn10()
{
    cout << "请输入上界:" << endl;
    int n,i = 0;
    long long sum = 0;
    cin >> n;
    while (i <= n)
    {
        sum += i;
        i += 2;
    }

    cout << endl << "从 1 到 " << n << " 之间的偶数和为: " << sum << endl;
}

void gn11()
{
    cout << "请输入上界:" << endl;
    int n, i = 0;
    bool u = 0;
    cin >> n;
    cout << endl << "从 1 到 " << n << " 之间所有3的倍数为: " << endl;
    if (n >= 3)
    do{

        if (u)cout << ",";
        cout << i;
        u = 1;
        i += 3;

    } while (i <= n);

    if (!u)cout << " 空！" << endl;
}

void gn12()
{
    cout << "请输入 x 求前 x 个即被 3 整除又被 5 整除的数:" << endl;
    int n, i = 0;
    bool u = 0;
    cin >> n;
    cout << endl << "前 x 个即被 3 整除又被 5 整除的数:为: "<< endl;
    while (i <= n)
    {
        if (u)cout << ",";
        cout << i;
        u = 1;
        i++;
    }

}

void gn13()
{
    cout << "请输入两个数将为你求它们之间的水仙花数:" << endl;
    int n, m, x, y, z;
    cin >> n >> m; 
    cout << endl << n << "," << m << " 之间的水仙花数为: " << endl;
    for (; n <= m; n++)
    {
        int x = n, y = 0, z = 0;
        while (x != 0)
        {
            x /= 10;
            z++;
        }
        x = n;
        while (x != 0)
        {
            y += pow(x % 10, z);
            x /= 10;
        }

        if (n == y)cout << n <<" ";
    }

    cout << endl;
}

void gn14()
{
    cout << "请输入 x 求 x 个数的最大值:" << endl;
    double n,h,max;
    cin >> n;
    cout << "请输入"<<n<<"个数" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        if (i == 0 || max < h)max = h;
    }
    cout << endl << "最大值为: " << max << endl;
}

void gn15()
{
    cout << "请输入 x 求 x 个数的最大最小值:" << endl;
    double n, h, max, min;
    cin >> n;
    cout << "请输入" << n << "个数" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        if (i == 0 || max < h)max = h;
        if (i == 0 || h > min)min = h;
    }
    cout << endl << "最大值为: " << max << "         最大值为: " << min << endl;
}

void gn16()
{
    cout << "请输入 x 将给 x 个数排序:" << endl;
    double n, h;
    cin >> n;
    vector<double>m(n);
    cout << "请输入" << n << "个数" << endl;
    for (int i = 0; i < n; i++)
        cin >> m[i];
 
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (m[j] > m[j + 1])
            {
                h = m[j];
                m[j] = m[j + 1];
                m[j + 1] = h;
            }

    cout << endl << "排序结果为: " << endl;

    for (int i = 0; i < n; i++)
        cout << m[i] << "  ";
    cout << endl;
}

//int ws(double x)
//{
//    int i = 0;
//    while (fabs(x) >= 1e-5)
//    {
//        x /= 10;
//        i++;
//    }
//    return i;
//}

void gn17()
{
    cout << "请输入 x y 将创建 x*y 矩阵然后转置:" << endl;
    double n, m, h;
    int k = 0;
    cin >> n >> m;
    vector < vector<double>>N(n, vector<double>(m));
    cout << "请输入" << n * m << "个数" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> N[i][j];

 /*           if (k == 0 || k < ws(N[i][j]))k = ws(N[i][j]);*/
        }

    //cout << setiosflags(ios::left);

    cout << endl << "矩阵为: " << endl;

   // cout << endl << "k为: " <<k<< endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            /*cout << setw(k + 2) << N[i][j];*/
            cout << N[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < n ; i++)
        for (int j = i; j < n; j++)
        {
            h = N[i][j];
            N[i][j] = N[j][i]; 
            N[j][i] = h; 
        }

    cout << endl << "转置结果为: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            /*cout << setw(k + 2) << N[i][j];*/
            cout << N[i][j] << " ";
        cout << endl;
    }

}

void gn18()
{
    cout << "请输入 x y 将创建 x*y 矩阵然后求 主,副对角线和:" << endl;
    double n, m, sum = 0;
    cin >> n >> m;
    vector < vector<double>>N(n, vector<double>(m));
    cout << "请输入" << n * m << "个数" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> N[i][j];

    cout << endl << "矩阵为: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << N[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j || i + j == n - 1)
                sum += N[i][j];

    cout << endl << "主,副对角线和为: " << sum << endl;  
}

void gn19()
{
    cout << "请输入一个不含换行的字符串，该字符串中相邻的字母算做一个单词:" << endl;
    string n;
    getchar();
    getline(cin, n);

    int i = 0, j = 0;
    bool u = 0,b;
    
    while (n[i] != '\0')
    {
        b = ('a' <= n[i] && n[i] <= 'z' || 'A' <= n[i] && n[i] <= 'Z');
        if (u && !b)j++;
        u = b;

        i++;
    }
    if (u)j++;

    cout << endl << "单词个数为: " <<j << endl;
}


struct stu
{
    string num;
    string name;
    double cj;
    stu* next;
};


void gn20()
{
    cout << "请输入三个学生的信息:" << endl;
    stu n[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "请输入第" << i + 1 << "个学生的学号" << endl;
        cin >> n[i].num;
        cout << "请输入第" << i + 1 << "个学生的名字" << endl;
        cin >> n[i].name;
        cout << "请输入第" << i + 1 << "个学生的成绩" << endl;
        cin >> n[i].cj;
        cout << endl;
    }
    n[0].next = &n[1];
    n[1].next = &n[2];
    n[2].next = NULL;


    cout << "\n\n链表输出:" << endl;
    stu* p = &n[0];
    while (p != NULL)
    {
        cout << "学号:" << p->num << "   名字:" << p->name << "   成绩:" << p->cj << endl;
        p = p->next;
    }
    cout << endl;
}

void gn21()
{
    cout << "请输入n ,将储存n个学生的信息:" << endl;
    int n;
    stu* head = NULL, * p;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        stu* node = new stu;
        cout << "请输入第" << i + 1 << "个学生的学号" << endl;
        cin >> node->num;
        cout << "请输入第" << i + 1 << "个学生的名字" << endl;
        cin >> node->name;
        cout << "请输入第" << i + 1 << "个学生的成绩" << endl;
        cin >> node->cj;
        node->next = head;
        head = node;
        cout << endl;
    }


    cout << "\n\n链表输出:" << endl;
    while (head != NULL)
    {
        cout << "学号:" << head->num << "   名字:" << head->name << "   成绩:" << head->cj << endl;
        p = head;
        head = head->next;
        delete p;
    }
    cout << endl;
}

void gn22()
{
    cout << "请输入n ,将储存n个学生的信息:" << endl;
    int n;
    stu* head = NULL, * p;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        stu* node = new stu;
        cout << "请输入第" << i + 1 << "个学生的学号" << endl;
        cin >> node->num;
        cout << "请输入第" << i + 1 << "个学生的名字" << endl;
        cin >> node->name;
        cout << "请输入第" << i + 1 << "个学生的成绩" << endl;
        cin >> node->cj;

        if (head == NULL)head = node;
        else
        {
            if (head->cj > node->cj)
            {
                node->next = head;
                head = node;
            }
            else
            {
                p = head;
                while (p->next->next != NULL)
                {
                    if (p->next->cj > node->cj)
                        break;
                    p = p->next;
                }
                node->next = p->next;
                p->next = node;
            }

        }
      
        cout << endl;
    }


    cout << "\n\n链表输出:" << endl;
    while (head != NULL)
    {
        cout << "学号:" << head->num << "   名字:" << head->name << "   成绩:" << head->cj << endl;
        p = head;
        head = head->next;
        delete p;
    }
    cout << endl;
}




//学生成绩排序