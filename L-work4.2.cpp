/*(6)梅森数

//形如2^n−1的素数称为梅森数（Mersenne Number）。
//例如2^2−1=3、2^3−1=7都是梅森数。
//1722年，双目失明的瑞士数学大师欧拉证明了2^31−1=2147483647是一个素数，堪称当时世界上“已知最大素数”的一个记录。
//
//本题要求编写程序，对任一正整数n（n<20），输出所有不超过2^n−1的梅森数。
//
//输入格式：
//输入在一行中给出正整数n（n<20）。
//
//输出格式：
//按从小到大的顺序输出所有不超过2^n−1的梅森数，每行一个。
//如果完全没有，则输出“None”。
//
//输入样例：
//6
//输出样例：
//3
//7
//31

#include<iostream>
using namespace std;
bool pd(int x)
{
    if(x==1)return 0;
    if(x==2)return 1;
    if(x%2==0)return 0;
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0)return 0;
    return 1;
}
int main()
{
    int n,m=1;
    bool u=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        if(pd((m*=2)-1))
        {
            cout<<m-1<<endl;
            u=0;
        }
    if(u)cout<<"None"<<endl;

    return 0;
}
*/
