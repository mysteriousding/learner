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

/*成功实现全排列，但不可出现相同字符！！！*
#include<iostream>
#include<string>
#include<vector>
using namespace std;
char XR(vector<vector<char>>& x, string y, int z, int a, int b);
int main()
{
    string n;
    char m;
    cin >> n;
    int n0 = n.size();
    for (int i = 0; i < n0 - 1; i++)
        for (int j = 0; j < n0 - 1 - i; j++)
            if (n[j] > n[j + 1]) { m = n[j]; n[j] = n[j + 1]; n[j + 1] = m; }
    vector<int>B(n0, 1);
    for (int i = 2; i < n0; i++)B[i] = B[i - 1] * i;

    vector<vector<char>>N(n0 + 1, vector<char>(n0, '!'));
    int i[8] = { 0 }, j[8] = { 0 };


    while (j[0] < n0)//输出多少个字符串    //j[0]二次计数计满停止 
    {
        for (int k = 0; k < n0; k++)//进行一个字符串n0位的输出,写入、覆盖数组 
        {
                cout << XR(N, n, k, n0, j[k]); i[k]++; //输出一个字符     //一次计数加1 
                if (i[k] >= B[n0 - 1 - k]) //如果一次计数计满
                {
                    i[k] = 0; j[k]++; //一次计数清零       //二次计数加1
                    if (k != 0 && j[k] >= n0)//除了j[0]，剩下的二次计算计满时
                        j[k] -= n0;//二次计数清零                    
                }
        }
        cout << endl;//一个字符串结束，换行
    }

    return 0;
}
char XR(vector<vector<char>>& x, string y, int z, int a, int b)
{
    if (x[z][b] == '!')
    {
        for (int i = 0; i < a; i++)
        {
            int p = 0;
            for (int j = 0; j <= z; j++)                   //遍历此串，选
            {
                if (y[i] == x[a][j]) { p = 1; break; }
            }

            for (int j = 0; j <= b; j++)                   //遍历历史，选
            {
                if (y[i] == x[z][j]) { p = 1; break; }
            }
            if (p == 0)
            {
                x[z][b] = x[a][z] = y[i];

                for (int i = z + 1; i < a; i++)
                    for (int j = 0; j < a; j++)
                        x[i][j] = '!';
                for (int i = z + 1; i < a; i++)
                    x[a][i] = '!';

                return x[z][b];
            }
        }
    }
    else return x[z][b];
}
*/

/*枚举 ---实现*
#include<iostream>
#include<string>
using namespace std;
enum QBL { s1, s2, s3, s4, s5, s6, s7, s8 }str;
void SHUCHU(int i[], string n, int n0);
int main()
{
    string n;
    char m;
    int i[8];
    cin >> n;
    int n0 = n.size();
    for (int i = 0; i < n0 - 1; i++)
        for (int j = 0; j < n0 - 1 - i; j++)
            if (n[j] > n[j + 1]) { m = n[j]; n[j] = n[j + 1]; n[j + 1] = m; }

    for (i[0] = s1; i[0] < QBL(n0); i[0]++)

    {
        if (n0 > 1)
        {
            for (i[1] = s1; i[1] < QBL(n0); i[1]++)
            {
                if (i[1] != i[0])

                    if (n0 > 2)
                    {
                        for (i[2] = s1; i[2] < QBL(n0); i[2]++)
                        {
                            if ((i[2] != i[0]) && (i[2] != i[1]))

                                if (n0 > 3)
                                {
                                    for (i[3] = s1; i[3] < QBL(n0); i[3]++)
                                    {
                                        if ((i[3] != i[0]) && (i[3] != i[1]) && (i[3] != i[2]))

                                            if (n0 > 4)
                                            {
                                                for (i[4] = s1; i[4] < QBL(n0); i[4]++)
                                                {
                                                    if ((i[4] != i[0]) && (i[4] != i[1]) && (i[4] != i[2]) && (i[4] != i[3]))

                                                        if (n0 > 5)
                                                        {
                                                            for (i[5] = s1; i[5] < QBL(n0); i[5]++)
                                                            {
                                                                if ((i[5] != i[0]) && (i[5] != i[1]) && (i[5] != i[2]) && (i[5] != i[3]) && (i[5] != i[4]))

                                                                    if (n0 > 6)
                                                                    {
                                                                        for (i[6] = s1; i[6] < QBL(n0); i[6]++)
                                                                        {
                                                                            if ((i[6] != i[0]) && (i[6] != i[1]) && (i[6] != i[2]) && (i[6] != i[3]) && (i[6] != i[4]) && (i[6] != i[5]))

                                                                                if (n0 > 7)
                                                                                {
                                                                                    for (i[7] = s1; i[7] < QBL(n0); i[7]++)
                                                                                        if ((i[7] != i[0]) && (i[7] != i[1]) && (i[7] != i[2]) && (i[7] != i[3]) && (i[7] != i[4]) && (i[7] != i[5]) && (i[7] != i[6]))
                                                                                            SHUCHU(i, n, n0);
                                                                                }

                                                                                else SHUCHU(i, n, n0);
                                                                        }
                                                                    }

                                                                    else SHUCHU(i, n, n0);
                                                            }
                                                        }

                                                        else SHUCHU(i, n, n0);
                                                }
                                            }

                                            else SHUCHU(i, n, n0);
                                    }
                                }

                                else SHUCHU(i, n, n0);
                        }
                    }

                    else SHUCHU(i, n, n0);
            }
        }

        else SHUCHU(i, n, n0);
    }

    return 0;
}

void SHUCHU(int i[], string n, int n0)
{
    int loop;
    for (loop = 0; loop < n0; loop++)
    {
        switch (loop)
        {
        case 0: str = QBL(i[0]); break;
        case 1: str = QBL(i[1]); break;
        case 2: str = QBL(i[2]); break;
        case 3: str = QBL(i[3]); break;
        case 4: str = QBL(i[4]); break;
        case 5: str = QBL(i[5]); break;
        case 6: str = QBL(i[6]); break;
        case 7: str = QBL(i[7]); break;
        default:break;
        }
        switch (str)
        {
        case s1: cout << n[0]; break;
        case s2: cout << n[1]; break;
        case s3: cout << n[2]; break;
        case s4: cout << n[3]; break;
        case s5: cout << n[4]; break;
        case s6: cout << n[5]; break;
        case s7: cout << n[6]; break;
        case s8: cout << n[7]; break;
        default: break;
        }
    }
    cout << endl;
}
*/

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

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string X[10], Y[10];
    for (int i = 0; i < 10; i++) { cin >> X[i]; }
    int y[10] = { 9,9,9,9,9,9,9,9,9,9 };
    int p;
    int max(string x, string y);

    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            p = max(X[i], X[j]);
            (p == 1) ? y[i]-- : y[j]--;
        }
    }
    for (int k = 0; k < 10; k++) { Y[y[k]] = X[k]; }
    for (int j = 0; j < 10; j++)
    {
        cout << Y[j] << endl;
    }

    return 0;
}

int max(string x, string y)
{
    char n, m; int k;
    for (int i = 0;; i++)
    {
        n = x[i]; m = y[i];
        if (n == m) { continue; }
        k = ((int)n < (int)m) ? 1 : 0;
        break;
    }
    return(k);
}
