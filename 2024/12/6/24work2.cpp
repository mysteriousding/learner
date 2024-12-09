/*(6)检阅

//马年到了，也到了检阅战马的时候。战马分为白色和棕色两种，一字排开，指挥官希望他的战马队列尽可能整齐好看，将相同颜色的战马放在一起。大部分人都喜欢高头白马，因此，指挥官要求白马排在前面，棕马排在后面。现在，N匹战马都已经在广场列队。为了达到要求，指挥官可以调换任意一个位置上的战马（有充足的备用战马）。问至少调换多少匹可以达到要求。
//
//输入格式:
//第一行一个整数N，表示已经排队的战马数量。
//第二行一个字符串，表示当前队列从前到后战马的颜色，只包含两种字符,"W"表示白马，"B"表示黑马。
//
//输出格式:
//输出一个数字，表示至少需要调换多少匹战马。
//
//输入样例:
//5
//WWWBB
//输出样例:
//0
//输入样例:
//5
//WBWBW
//输出样例:
//2
//【样例1解释】
//已经符合白马在前，棕马在后，不需要调换。
//
//【样例2解释】
//可以把棕马都换成白马WWWWW，或者WWWBB，都是符合要求的队列，至少调换2匹。
//【数据范围】
//30%的数据N<=20。
//70%的数据N<=500。
//100%的数据N<=1000。

#include<iostream>
using namespace std;
int main()
{
    int n,i=0;
    int p1=-1,p2=-1;
    int k1=0,k2=0;
    string m;
    cin>>n>>m;
    int min=n;
    while(i<n)
    {
        if(m[i]=='W')p2=-1;
        if(m[i]=='B')
            if(p2==-1)
            {
                p2=i;
                if(p1==-1)p1=i;
            }
        if(m[i]=='W')k1++;
        else k2++;
        i++;
    }
    p1=(p1==-1)?0:p1;
    p2=(p2==-1)?n:p2;
    if(k1==n||k2==n)cout<<0<<endl;
    else
    {
        for(int j=p1;j<p2;j++)
        {
            int h=0,l=p1;
            while(l<p2)
            {
                if(l<=j)
                {
                    if(m[l]=='B')h++;
                }
                else if(m[l]=='W')h++;
                l++;
            }
            if(h<min)min=h;
        }
        cout<<min<<endl;
    }

    return 0;
}
*/

/*(7)数的计算(compuer.c/cpp)

//【问题描述】
//我们要求找出具有下列性质数的个数（包含输入的正整数 n）。
//
//先输入一个正整数 n（n<=1000），然后对此正整数按照如下方法进行处理：
//
//1.不作任何处理；
//
//2.在它的左边拼接一个正整数，但该正整数不能超过原数，或者是上一个被拼接的数的一半；
//
//3.加上数后，继续按此规则进行处理，直到不能再加正整数为止。
//
//【输入格式】
//输入只有一行一个整数，表示 n。
//
//【输出格式】
//输出一行一个整数，表示合法的数列个数。
//
//【数据范围】
//对于20%的数据，n<=200
//
//对于60%的数据，n<=500
//
//对于100%的数据，n<=1000
//
//【输入样例】
//6
//【输出样例】
//6

// #include<iostream>
// #include<string>
// using namespace std;
// int sum=1;
// void DG(int n);
// int main()
// {
//     int n;
//     cin>>n;
//     DG(n);
//     cout<<sum<<endl;

//     return 0;
// }

// void DG(int n)
// {
//     if(n==1)return;
//     for(int i=1;i<=n/2;i++)
//     {
//         sum++;
//         DG(i);
//     }
// }



#include<iostream>
#include<string>
using namespace std;
int cc[1000];
int DG(int n);
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cc[i]=DG(i);
    cout<<cc[n]<<endl;

    return 0;
}

int DG(int n)    //我不会，蒙对了，很懵逼，wc为什么？！！
{
    int sum=1;
    for(int i=1;i<=n/2;i++)
        sum+=cc[i];
    return sum;
}
*/

/*(8)3名同学5门课程成绩，输出最好成绩及所在的行和列（要求指针作为函数的参数）

//编程:数组存储3名同学5门课程成绩
//输出最好成绩及所在的行和列
//要求：将输入、查找和打印的功能编写成函数
//并将二维数组通过指针参数传递的方式由主函数传递到子函数中
//
//输入格式:
//每行输入一个同学的5门课的成绩，每个成绩之间空一格，见输入样例
//
//输出格式:
//输出共3行：
//第一行输出，如：最高分是:97
//第二行输出最高分所在的行数，如：行数是:2
//第二行输出最高分所在的列数，如：列数是:3
//
//输入样例:
//在这里给出一组输入。例如：
//
//87 67 76 78 85
//92 78 79 86 88
//79 85 87 97 89
//输出样例:
//在这里给出相应的输出。例如：
//
//最高分是:97
//行数是:2
//列数是:3

#include<iostream>
using namespace std;
void xr(int *);
int cz(int *);
void dy(int N[][5],int);
int main()
{
    int N[3][5];
    int*p=&N[0][0];
    xr(p);
    dy(N,cz(p));

    return 0;
}
void xr(int *p)
{
    for(int i=0;i<15;i++)cin>>*(p+i);
}
int cz(int *p)
{
    int max=*(p+0);
    for(int i=0;i<15;i++)
        if(max<*(p+i))max=*(p+i);
    return max;
}
void dy(int N[][5],int x)
{
    cout<<"最高分是:"<<x<<endl;
    for(int i=0;i<3;i++)
        for(int j=0;j<5;j++)
            if(N[i][j]==x)cout<<"行数是:"<<i<<"\n列数是:"<<j<<endl;
}
*/

/*(9)求矩阵各行最大元素值

//本题要求编写程序，求一个给定的m×n矩阵各行最大的元素值。题目保证给出的矩阵每行至多存在一个最大值。
//
//输入格式:
//输入第一行给出两个正整数m和n（1≤m,n≤6）。随后m行，每行给出n个整数，其间以空格分隔。
//
//输出格式:
//每行按照“元素值 行号 列号”的格式输出该行最大元素，其中行、列编号从1开始。要求按照行号递增输出。
//
//输入样例:
//4 5
//1 8 2 6 5
//2 3 9 7 1
//6 5 3 4 1
//1 3 2 4 5
//输出样例:
//8 1 2
//9 2 3
//6 3 1
//5 4 5

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>>N(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>N[i][j];
    for(int i=0;i<m;i++)
    {
        int max=N[i][0],k=0;
        for(int j=0;j<n;j++)
            if(N[i][j]>max){max=N[i][j];k=j;}
        cout<<max<<" "<<i+1<<" "<<k+1<<endl;
    }

    return 0;
}
*/

//输出二维数组每列最小数
//
//数组a是4行4列的二维整型数组，输入每个元素，测试数据保证元素数据不重复，输出该数组每列的最小数。
//
//输入格式:
//输入4行整数，每行有4个整数，整数间用空格分隔。
//
//输出格式:
//在一行里输出4个整数，每个整数后有一个空格。
//
//输入样例:
//在这里给出一组输入。例如：
//
//3 6 0 8
//5 12 7 9
//11 90 61 1
//23 -5 2 66
//
//输出样例:
//在这里给出相应的输出。例如：
//
//3 -5 0 1

#include<iostream>
using namespace std;
int main()
{
    int N[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> N[i][j];
    for (int i = 0; i < 4; i++)
    {
        int min = N[0][i];
        for (int j = 0; j < 4; j++)
            if (N[j][i] < min)min = N[j][i];
        cout << min << " ";
    }

    return 0;
}
