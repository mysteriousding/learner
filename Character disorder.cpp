/*题目:字符串的全排列

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

/*（错误版1）
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

/*字符错序（错误版2）
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

/*（错误版3）
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

/*（错误版4）
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
                cout << XR(N, m, k); i[k]++; //输出一个字符     //一次计数加1
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
*/

/*（错误版5）
#include<iostream>
#include<string>
#include<vector>
using namespace std;
char XR(vector<vector<char>>&x, string y, int z, int a, int b);
void FX(vector<vector<char>>&x, int y, int z);
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

    vector<vector<char>>N(n0, vector<char>(n0, '!'));
    int i[8] = { 0 }, j[8] = { 0 };

    while (j[0] < n0)//输出多少个字符串    //j[0]二次计数计满停止                         ///
    {
        for (int k = 0; k < n0; k++)//进行一个字符串n0位的输出,写入、覆盖数组             ///
        {
            if (n0 > k)//判断具体输出多少位                                               ？？？无用
            {
                //cout << XR(N, n, k,n0,j[k]); i[k]++; //输出一个字符     //一次计数加1 
                //*
                XR(N, n, k, n0, j[k]);
                for (int i = 0; i < n0; i++)
                {
                    for (int j = 0; j < n0; j++)
                        cout << N[i][j] << " ";
                    cout << endl;
                }
                cout << "\n\n";  i[k]++;
                //*
                if (i[k] >= B[n0-1-k]) //如果一次计数计满
                {
                    i[k] = 0; j[k]++; //一次计数清零       //二次计数加1

                    if (k != 0 && j[k] >= n0)//除了j[0]，剩下的二次计算计满时
                    {
                        j[k] -= n0;//二次计数清零  
                        FX(N, k, n0);//清除相应以输数组

                        cout << "---" << endl;
                    }
                }
            }
        }
        cout << "-----------------------" << endl;
        cout << endl;//一个字符串结束，换行
    }

    return 0;
}
char XR(vector<vector<char>>&x, string y, int z, int a, int b)
{
    if (x[z][b] == '!')
    {
        for (int i = 0; i < a; i++)
        {
            int p = 0;
            for (int j = 0; j <= z; j++)                   //遍历此串，选
            {
                if (y[i] == x[j][b]) { p = 1; break; }
            }

            for (int j = 0; j <= b; j++)                   //遍历历史，选
            {
                if (y[i] == x[z][j]) { p = 1; break; }
            }
            if (p == 0)
            {
                x[z][b] = y[i];
                return x[z][b];
            }
        }
    }
    else return x[z][b];
}
void FX(vector<vector<char>>&x, int y, int z)
{
    for (int i = y; i < z; i++)
        for (int j = 0; j < z; j++)
            x[i][j] = '!';

}
*/

/*测试保留一
#include<iostream>
#include<string>
#include<vector>
using namespace std;
char XR(vector<vector<char>>& x, string y, int z, int a, int b);
void FX(vector<vector<char>>& x, int y, int z);
void FX2(vector<vector<char>>& x, int y);
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



    while (j[0] < n0)//输出多少个字符串    //j[0]二次计数计满停止                         ///
    {
        for (int k = 0; k < n0; k++)//进行一个字符串n0位的输出,写入、覆盖数组             ///
        {
            if (n0 > k)//判断具体输出多少位                                               ？？？无用
            {
                //cout << XR(N, n, k, n0, j[k]); i[k]++; //输出一个字符     //一次计数加1 
                //*
                 XR(N, n, k,n0,j[k]);                       //!!!
                 for (int i = 0; i <= n0 ; i++)
                 {
                     for (int j = 0; j < n0 ; j++)
                           cout<<N[i][j]<<" ";
                      cout<<endl;
                 }
                cout<<"\n\n";  i[k]++;
                //*
                if(k==n0-1)FX2(N, n0);
                if (i[k] >= B[n0 - 1 - k]) //如果一次计数计满
                {
                    i[k] = 0; j[k]++; //一次计数清零       //二次计数加1

                    if (k != 0 && j[k] >= n0)//除了j[0]，剩下的二次计算计满时
                    {
                        j[k] -= n0;//二次计数清零  
                        FX(N, k, n0);//清除相应以输数组
                    }
                }
            }
        }
        cout << "-----------------------" << endl;       //!!!
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
                cout << z << " " << b << endl;     //!!!
                return x[z][b];
            }
        }
    }
    else
    {
        cout << z << " " << b <<"    !" << endl;          //!!!
        x[a][z] = x[z][b];
        return x[z][b];
    }
}
void FX(vector<vector<char>>& x, int y, int z)
{
    for (int i = y; i < z; i++)
        for (int j = 0; j < z; j++)
            x[i][j] = '!';

}
void FX2(vector<vector<char>>& x, int y)
{
    for (int i = 0 ; i < y; i++)
        x[y][i] = '!';
}
*/

/*测试保留二
#include<iostream>
#include<string>
#include<vector>
using namespace std;
char XR(vector<vector<char>>& x, string y, int z, int a, int b);
///void FX(vector<vector<char>>& x, int y, int z);
///void FX2(vector<vector<char>>& x, int y);
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



    while (j[0] < n0)//输出多少个字符串    //j[0]二次计数计满停止                         ///
    {
        for (int k = 0; k < n0; k++)//进行一个字符串n0位的输出,写入、覆盖数组             ///
        {
            if (n0 > k)//判断具体输出多少位                                               ？？？无用
            {
                //cout << XR(N, n, k, n0, j[k]); i[k]++; //输出一个字符     //一次计数加1 
                //*
                XR(N, n, k, n0, j[k]);                       //!!!
                for (int i = 0; i <= n0; i++)
                {
                    for (int j = 0; j < n0; j++)
                        cout << N[i][j] << " ";
                    cout << endl;
                }
                cout << "\n\n";  i[k]++;
                //*
                //if (k == n0 - 1)FX2(N, n0);
                if (i[k] >= B[n0 - 1 - k]) //如果一次计数计满
                {
                    i[k] = 0; j[k]++; //一次计数清零       //二次计数加1

                    if (k != 0 && j[k] >= n0)//除了j[0]，剩下的二次计算计满时
                    {
                        j[k] -= n0;//二次计数清零  
                        ///FX(N, k, n0);//清除相应以输数组
                    }
                }
            }
        }
        cout << "-----------------------" << endl;       //!!!
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
                cout << z << " " << b << endl;     //!!!

                for (int i = z+1; i < a; i++)
                    for (int j = 0; j < a; j++)
                        x[i][j] = '!';
                for (int i = z + 1; i < a; i++)
                    x[a][i] = '!';

                return x[z][b];
            }
        }
    }
    else
    {
        cout << z << " " << b << "    !" << endl;          //!!!
        return x[z][b];
    }
}
//void FX(vector<vector<char>>& x, int y, int z)
//{
//    for (int i = y; i < z; i++)
//        for (int j = 0; j < z; j++)
//            x[i][j] = '!';
//
//}
//void FX2(vector<vector<char>>& x, int y)
//{
//    for (int i = 0; i < y; i++)
//        x[y][i] = '!';
//}
*/

/*成功实现全排列，但不可出现相同字符！！！*/
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//char XR(vector<vector<char>>& x, string y, int z, int a, int b);
//int main()
//{
//    string n;
//    char m;
//    cin >> n;
//    int n0 = n.size();
//    for (int i = 0; i < n0 - 1; i++)
//        for (int j = 0; j < n0 - 1 - i; j++)
//            if (n[j] > n[j + 1]) { m = n[j]; n[j] = n[j + 1]; n[j + 1] = m; }
//    vector<int>B(n0, 1);
//    for (int i = 2; i < n0; i++)B[i] = B[i - 1] * i;
//
//    vector<vector<char>>N(n0 + 1, vector<char>(n0, '!'));
//    int i[8] = { 0 }, j[8] = { 0 };
//
//
//    while (j[0] < n0)//输出多少个字符串    //j[0]二次计数计满停止 
//    {
//        for (int k = 0; k < n0; k++)//进行一个字符串n0位的输出,写入、覆盖数组 
//        {
//                cout << XR(N, n, k, n0, j[k]); i[k]++; //输出一个字符     //一次计数加1 
//                if (i[k] >= B[n0 - 1 - k]) //如果一次计数计满
//                {
//                    i[k] = 0; j[k]++; //一次计数清零       //二次计数加1
//                    if (k != 0 && j[k] >= n0)//除了j[0]，剩下的二次计算计满时
//                        j[k] -= n0;//二次计数清零                    
//                }
//        }
//        cout << endl;//一个字符串结束，换行
//    }
//
//    return 0;
//}
//char XR(vector<vector<char>>& x, string y, int z, int a, int b)
//{
//    if (x[z][b] == '!')
//    {
//        for (int i = 0; i < a; i++)
//        {
//            int p = 0;
//            for (int j = 0; j <= z; j++)                   //遍历此串，选
//            {
//                if (y[i] == x[a][j]) { p = 1; break; }
//            }
//
//            for (int j = 0; j <= b; j++)                   //遍历历史，选
//            {
//                if (y[i] == x[z][j]) { p = 1; break; }
//            }
//            if (p == 0)
//            {
//                x[z][b] = x[a][z] = y[i];
//
//                for (int i = z + 1; i < a; i++)
//                    for (int j = 0; j < a; j++)
//                        x[i][j] = '!';
//                for (int i = z + 1; i < a; i++)
//                    x[a][i] = '!';
//
//                return x[z][b];
//            }
//        }
//    }
//    else return x[z][b];
//}


/*
//测试标记程序
#include<iostream>
#include<string>
#include<vector>
using namespace std;
char XR(vector<vector<char>>& x, string y, int z, int a, int b);
///void FX(vector<vector<char>>& x, int y, int z);
///void FX2(vector<vector<char>>& x, int y);
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



    while (j[0] < n0)//输出多少个字符串    //j[0]二次计数计满停止                         ///
    {
        for (int k = 0; k < n0; k++)//进行一个字符串n0位的输出,写入、覆盖数组             ///
        {
            if (n0 > k)//判断具体输出多少位                                               ？？？无用
            {
                //cout << XR(N, n, k, n0, j[k]); i[k]++; //输出一个字符     //一次计数加1
                //*
                XR(N, n, k, n0, j[k]);                       //!!!
                for (int i = 0; i <= n0; i++)
                {
                    for (int j = 0; j < n0; j++)
                        cout << N[i][j] << " ";
                    cout << endl;
                }
                cout << "\n\n";  i[k]++;
                //*
                //if (k == n0 - 1)FX2(N, n0);
                if (i[k] >= B[n0 - 1 - k]) //如果一次计数计满
                {
                    i[k] = 0; j[k]++; //一次计数清零       //二次计数加1

                    if (k != 0 && j[k] >= n0)//除了j[0]，剩下的二次计算计满时
                    {
                        j[k] -= n0;//二次计数清零
                        ///FX(N, k, n0);//清除相应以输数组
                    }
                }
            }
        }
        cout << "-----------------------" << endl;       //!!!
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
                cout << z << " " << b << endl;     //!!!

                for (int i = z + 1; i < a; i++)
                    for (int j = 0; j < a; j++)
                        x[i][j] = '!';
                for (int i = z + 1; i < a; i++)
                    x[a][i] = '!';

                return x[z][b];
            }
        }
    }
    else
    {
        cout << z << " " << b << "    !" << endl;          //!!!
        return x[z][b];
    }
}
*/





/*老师的指导!!!

*递归
//递归方法是通过固定一个字符，然后对剩余的字符进行全排列，最后将固定字符与其他字符交换位置，继续进行全排列。
//以字符串"abc"为例：
//固定'a'，对'bc'进行全排列，得到'abc'和'acb'。
//将'a'和'b'交换，得到'bac'。
//固定'b'，对'ac'进行全排列，得到'bac'和'bca'。
//将'c'放到第一位，得到'cba'。
//固定'c'，对'ba'进行全排列，得到'cba'和'cab'

#include<iostream>
#include<iomanip>
using namespace std;
void permution(char* pstr, int k, int m)
{
    char temp;
    if (*pstr == NULL)
        return;
    if (k == m)
    {
        static int num = 1;
        cout << "��" << setw(2) << num++ << " �����У�" << pstr << endl;
    }
    else
    {
        for (int i = k; i <= m; i++)
        {
            temp = *(pstr + k);
            *(pstr + k) = *(pstr + i);
            *(pstr + i) = temp;
            permution(pstr, k + 1, m);
            temp = *(pstr + k);
            *(pstr + k) = *(pstr + i);
            *(pstr + i) = temp;
        }
    }
}
int main()
{
    char s[100];
    cin >> s;
    permution(s, 0, strlen(s) - 1);
    return 0;
}


*非递归
//要考虑全排列的非递归实现，先来考虑如何计算字符串的下一个排列。
//
//如"1234"的下一个排列就是"1243"。只要对字符串反复求出下一个排列，全排列的也就迎刃而解了。
//如何计算字符串的下一个排列了？
//
//来考虑"926520"这个字符串，我们从后向前找第一双相邻的递增数字，
//"20"、"52"都是非递增的，"26 "即满足要求，称前一个数字2为替换数，替换数的下标称为替换点，
//再从后面找一个比替换数大的最小数（这个数必然存在），0、2都不行，5可以，将5和2交换得到"956220"，
//然后再将替换点后的字符串"6220"颠倒即得到"950226"。
//
//对于像“4321”这种已经是最“大”的排列，
//首先将字符串整个颠倒得到最“小”的排列"1234"并返回false。

*/





/*枚举 ---实现*/
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