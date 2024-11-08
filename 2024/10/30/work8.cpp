/*(16) 字符串的全排列

给定一个全由小写字母构成的字符串，求它的全排列，按照字典序从小到大输出。

输入格式:
一行，一个字符串，长度不大于8。

输出格式:
输出所有全排列，每行一种排列形式，字典序从小到大。

输入样例:
在这里给出一组输入。例如：

abc
输出样例:
在这里给出相应的输出。例如：

abc
acb
bac
bca
cab
cba
*/

/*(16)字符错序（错误版1）
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<set>
using namespace std;
int main()
{
    string n,m;
    string arr[40320];
    cin >> n;
    int a = n.size();
    srand(static_cast<unsigned int>(time(nullptr)));
    int  k = 0, h = 0;
    int x1, x2, x3, x4, x5, x6, x7, x8;
    x1 = x2 = x3 = x4 = x5 = x6 = x7 = x8 = 0;
    set<int>generatedIndexes;
    for (int i = 0; i < 40320; i++)
    { 
        h = 0;

        //后来加入
        ////写一个函数！！！！！！！！！
        for (;;)
        {
            switch (a)
            {
            case 8:   x8 = rand() % a;
            case 7:   x7 = rand() % a;
            case 6:   x6 = rand() % a;
            case 5:   x5 = rand() % a;
            case 4:   x4 = rand() % a;
            case 3:   x3 = rand() % a;
            case 2:   x2 = rand() % a;
            case 1:   x1 = rand() % a;
            }
            // 根据当前的a值，将随机生成的数组成一个索引值
            int index = 0;
            switch (a)
            {
            case 8:  index += x8; index *= a;
            case 7:  index += x7; index *= a;
            case 6:  index += x6; index *= a;
            case 5:  index += x5; index *= a;
            case 4:  index += x4; index *= a;
            case 3:  index += x3; index *= a;
            case 2:  index += x2; index *= a;
            case 1:  index += x1;
            }
            // 检查生成的索引值是否已在set中存在
            if (generatedIndexes.find(index) == generatedIndexes.end()) {
                k++;
                // 将新生成的索引值插入到set中
                generatedIndexes.insert(index);
            }
            // 判断是否所有生成的随机数组成的情况都不同
            bool allDifferent = (generatedIndexes.size() == k);
            if (generatedIndexes.size() == k) 
            { 
                switch (a)
                {
                case 8:   m += n[x8];
                case 7:   m += n[x7];
                case 6:   m += n[x6];
                case 5:   m += n[x5];
                case 4:   m += n[x4];
                case 3:   m += n[x3];
                case 2:   m += n[x2];
                case 1:   m += n[x1];
                }
                break;
            }
        }
        //以上后来加入


        //for (;;)
        //{
        //    switch (a)
        //    {
        //    case 8:  int x8 = rand() % a;
        //    case 7:  int x7 = rand() % a;
        //    case 6:  int x6 = rand() % a;
        //    case 5:  int x5 = rand() % a;
        //    case 4:  int x4 = rand() % a;
        //    case 3:  int x3 = rand() % a;
        //    case 2:  int x2 = rand() % a;
        //    case 1:  int x1 = rand() % a;
        //    }
        //    if()

        //}
        ////cout << x<<y<<z<< endl;
        //switch (a)
        //{
        //case 8:   m += n[x8];
        //case 7:   m += n[x7];
        //case 6:   m += n[x6];
        //case 5:   m += n[x5];
        //case 4:   m += n[x4];
        //case 3:   m += n[x3];
        //case 2:   m += n[x2];
        //case 1:   m += n[x1];
        //}


        for (int j = 0; j <= 40320; j++)
        {
            if (m == arr[j]) { h = 1; break; }
        }

        if (h == 0)
        {
            cout << m << endl;
            arr[k] = m;
            k++;
        }

        m = "";

    }

    return 0;
}
*/

/*(16)字符错序（错误版2）
#include<iostream>
#include<string>
using namespace std;
int main()
{
start:
    string n;
    cin >> n;
    int a = n.size();

    //int a;
    //cin >> a;

    int  k1 = 0, k2 = 1;
    int X[8];
    int p1 = 0, p2 = 0;
    int h = 0, g = 0,hh=0;

    while (1)
    {
        for (int i = 0; i < a; i++) { X[i] = i; }
        if (p1 != 0)
        {
            h = X[k1]; X[k1] = X[k2]; X[k2] = h;
            k2++;
            if (a <= 3)
            {
                if (k2 >= a - 1) { k1++; k2 = k1 + 1; }
                if (k1 >= a - 1) { break; }
            }
               else
               {
                   if (k2 > a - 1) { k1++; k2 = k1 + 1; }
                   if (k1 > a - 1) { break; }
               }
        }
        p1 = 1; p2 = 0;
        for (int j = 0; j < a; j++)
        {
            if (p2 != 0)
            {
                h = X[0];
                for (int l = 0; l < a - 1; l++) { X[l] = X[l + 1]; }
                X[a - 1] = h;
            }
            p2 = 1;
            for (int k = 0; k < a; k++) { g = X[k]; cout << n[g]; }// { cout << X[k]; }
            cout << endl;
        }
        hh++;
        cout << endl;
    }
    cout << endl << hh;
    goto start;

    return 0;
}
*/

/*(16)（错误版3）
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int JX(int x);
    string n;
    cin >> n;
    char m[8];
    char m0;
    int c = n.size();
    for (int i = 0; i < c; i++)m[i] = n[i];
    for (int i = 0; i < c - 1; i++)
    {
        for (int j = 0; j < c - 1 - i; j++)
        {
            if ((int)m[j] > (int)m[j + 1]) { m0 = m[j]; m[j] = m[j + 1]; m[j + 1] = m0; }
        }
    }
    int i[8] = { 0 }, j[8] = { 0 };
    while (j[0] < c)
    {
        for (int k = 0; k < 8; k++)
        {
            if (c > k) { cout << m[j[k]]; i[k]++; if (i[k] >= JX(c - 1 - k)) { i[k] = 0; j[k]++; if (k != 0 && j[k] >= c)j[k] -= c; } }
        }
        cout << endl;
    }

    return 0;
}

int JX(int x)
{
    int y = 1;
    for (; x > 0; x--)y *= x;
    return y;
}
*/

/*(16)*/
#include<iostream>
#include<string>
using namespace std;
int JX(int x);
char XR(char x[][8], char y[], int z);
char FX(char x[][8], int y, int z);
int main()
{
    
    string n;
    cin >> n;
    char m[8];
    char m0;
    int c = n.size();
    for (int i = 0; i < c; i++)m[i] = n[i];
    for (int i = 0; i < c - 1; i++)
    {
        for (int j = 0; j < c - 1 - i; j++)
        {
            if ((int)m[j] > (int)m[j + 1]) { m0 = m[j]; m[j] = m[j + 1]; m[j + 1] = m0; }
        }
    }
    char N[8][8];
    int i[8] = { 0 }, j[8] = { 0 };
    while (j[0] < c)//输出多少个字符串    //j[0]二次计数计满停止
    {
        for (int k = 0; k < 8; k++)//进行一个字符串c位的输出，计入以输数组
        {
            if (c > k)//判断具体输出多少位
            {


                char d;
                d = XR(N, m, k);
                cout << d; i[k]++; //输出一个字符     //一次计数加1 
                cout << "_____________________________________" << endl;
                for (int i = 0; i < c ; i++)
                {
                    cout << N[k][i] << " ";
                }


                //cout << XR(N, m, k); i[k]++; //输出一个字符     //一次计数加1 
                if (i[k] >= JX(c - 1 - k)) //如果一次计数计满
                {
                    i[k] = 0; j[k]++; //一次计数清零       //二次计数加1

                    if (k != 0 && j[k] >= c)//除了j[0]，剩下的二次计算计满时
                    {
                        j[k] -= c;//二次计数清零  
                        FX(N,k ,k);//清除相应以输数组
                    }
                } 
            }
        }
        cout << endl;//一个字符串结束，换行
    }
   


    return 0;
}

int JX(int x)
{
    int y = 1;
    for (; x > 0; x--)y *= x;
    return y;
}
char XR(char x[][8], char y[], int z)
{
    
    for (int i = 0; i < 8; i++)
    {
        int p = 0,h;
        for (int j = 0; j < 8; j++)
        {
            h = j;
            if (y[i] == x[z][j]) { p = 1; break; }
        }
        if (p == 0)
        {
            x[z][] = y[i];
            return y[i];
        }
    }
    
}
char FX(char x[][8], int y, int z)
{
    for (int i = y; i < 8; i++)x[z][i] = '\0';
    return 0;
}



/*(17)两整数求和

//本题目要求读入2个整数num1和num2，然后输出它们的和。
//
//输入格式:
//输入:在一行中给出2个绝对值不超过1000的整数num1和num2。
//
//输出格式:
//对每一组输入，在一行中输出num1+num2的值。
//
//输入样例:
//1 2
//输出样例:
//3

#include<iostream>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;

    cout<<n+m<<endl;

    return 0;
}
*/

/*(18)求一元二次函数的根

//这是一个编程题模板。请在这里写题目描述。例如：本题目要求读入2个整数A和B，然后输出它们的和。
//
//输入格式:
//请在这里写输入格式。例如：求一元二次方程式ax^2+bx+c=0的根。a,b,c的值在运行时由键盘输入
//
//输出格式:
//请在这里描述输出格式。例如：对每一组输入，在一行中输出根x1和根x2的值。
//
//输入样例:
//在这里给出一组输入。例如：
//
//1 5 4
//输出样例:
//在这里给出相应的输出。例如：
//
//x1=-1
//x2=-4

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a, b, c, n, m;
    cin >> a >> b >> c;

    n = (-b + pow(pow(b, 2) - 4 * a * c, 1.0 / 2)) / 2 * a;
    m = (-b - pow(pow(b, 2) - 4 * a * c, 1.0 / 2)) / 2 * a;

    cout << "x1+ " << n << endl << "x2= " << m << endl;

    return 0;
}
*/

/*(19)求n！

//这是一个编程题模板。请在这里写题目描述。例如：本题目要求n!。
//
//输入格式:
//请在这里写输入格式。例如：输入在一行中给出5。
//
//输出格式:
//请在这里描述输出格式。例如：对每一组输入，在一行中输出A+B的值。
//
//输入样例:
//在这里给出一组输入。例如：
//
//5
//输出样例:
//在这里给出相应的输出。例如：
//
//5!=120

#include<iostream>
using namespace std;
int main()
{
    int n, m = 1;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        m *= i;
    }

    cout << n << "!=" << m << endl;

    return 0;
}
*/

//比较10个字符串的大小，按从小到大输出
//
//本题要求编写一个函数实现字符串的排序具体，程序运行时具体输入与输出如下：
//
//输入格式:
//依次输入10个字符串，各字符串之间使用换行进行区分
//
//输出格式:
//输出一列排序好后的字符串
//
//输入样例:
//在这里给出一组输入。例如：
//
//zhao
//qian
//sun
//li
//zhou
//wu
//zheng
//wang
//feng
//chen
//输出样例:
//在这里给出相应的输出。例如：
//
//chen
//feng
//li
//qian
//sun
//wang
//wu
//zhao
//zheng
//zhou

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    string X[10], Y[10];
//    for (int i = 0; i < 10; i++) { cin >> X[i]; }
//    int y[10] = { 9,9,9,9,9,9,9,9,9,9 };
//    int p;
//    int max(string x, string y);
//
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = i + 1; j < 10; j++)
//        {
//            p = max(X[i], X[j]);
//            (p == 1) ? y[i]-- : y[j]--;
//        }
//    }
//    for (int k = 0; k < 10; k++) { Y[y[k]] = X[k]; }
//    for (int j = 0; j < 10; j++)
//    {
//        cout << Y[j] << endl;
//    }
//
//    return 0;
//}
//
//int max(string x, string y)
//{
//    char n, m; int k;
//    for (int i = 0;; i++)
//    {
//        n = x[i]; m = y[i];
//        if (n == m) { continue; }
//        k = ((int)n < (int)m) ? 1 : 0;
//        break;
//    }
//    return(k);
//}
