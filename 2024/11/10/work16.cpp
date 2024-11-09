/*(1）字符串排序

//本题要求编写程序，读入5个字符串，按由小到大的顺序输出。
//
//输入格式：
//输入为由空格分隔的5个非空字符串，每个字符串不包括空格、制表符、换行符等空白字符，长度小于80。
//
//输出格式：
//按照以下格式输出排序后的结果：
//
//After sorted:
//每行一个字符串
//输入样例：
//red yellow blue black white
//输出样例：
//After sorted:
//black
//blue
//red
//white
//yellow

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string X[5],Y[5];
    for(int i=0;i<5;i++){cin>>X[i];}
    int y[10]={4,4,4,4,4};
    int p;
    int max(string x,string y);

    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            p=max(X[i],X[j]);
            (p==1)?y[i]--:y[j]--;
        }
    }
    for(int k=0;k<5;k++){Y[y[k]]=X[k];}
    cout<<"After sorted:"<<endl;
    for(int j=0;j<5;j++)
    {
        cout<<Y[j];
        if(j!=4)cout<<endl;
    }

    return 0;
}

int max(string x,string y)
{
    char n,m;int k;
    for(int i=0;;i++)
    {
        n=x[i];m=y[i];
        if(n==m){continue;}
        k=((int)n<(int)m)?1:0;
        break;
    }
    return(k);
}
*/

/*(2)IP地址转换

//一个IP地址是用四个字节（每个字节8个位）的二进制码组成。请将32位二进制码表示的IP地址转换为十进制格式表示的IP地址输出。
//
//输入格式：
//输入在一行中给出32位二进制字符串。
//
//输出格式：
//在一行中输出十进制格式的IP地址，其由4个十进制数组成（分别对应4个8位的二进制数），中间用“.”分隔开。
//
//输入样例：
//11001100100101000001010101110010
//输出样例：
//204.148.21.114

#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    string n;
    int m=0,j=7;
    cin>>n;
    for(int i=0;i<32;i++,j--)
    {
        m+=(n[i]-48)*pow(2,j);   //pow(2,8-((i+1)%8));
        if((i+1)%8==0)
        {
            cout<<m;
            if(i!=31)cout<<".";
            m=0;j=8;
        }
    }

    return 0;
}
*/

/*(3)找最小的字符串

//本题要求编写程序，针对输入的N个字符串，输出其中最小的字符串。
//
//输入格式：
//输入第一行给出正整数N；随后N行，每行给出一个长度小于80的非空字符串，其中不会出现换行符，空格，制表符。
//
//输出格式：
//在一行中用以下格式输出最小的字符串：
//
//Min is: 最小字符串
//输入样例：
//5
//Li
//Wang
//Zha
//Jin
//Xian
//输出样例：
//Min is: Jin

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int max(string x,string y);
    int n,p;
    cin>>n;
    vector<string>m(n);
    vector<string>M(n);
    vector<int>x(n,n-1);
    for(int i=0;i<n;i++)cin>>m[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            p=max(m[i],m[j]);
            (p==1)?x[i]--:x[j]--;
        }
    }
    for(int j=0;j<n;j++)M[x[j]]=m[j];

    cout<<"Min is: "<<M[0];

    return 0;
}
int max(string x,string y)
{
    for(int i=0;;i++)
    {
        if(x[i]==y[i])continue;
        return ((x[i]<y[i])?1:0);
    }
}
*/

/*(4)找最长的字符串

//本题要求编写程序，针对输入的N个字符串，输出其中最长的字符串。
//
//输入格式：
//输入第一行给出正整数N；随后N行，每行给出一个长度小于80的非空字符串，其中不会出现换行符，空格，制表符。
//
//输出格式：
//在一行中用以下格式输出最长的字符串：
//
//The longest is: 最长的字符串
//如果字符串的长度相同，则输出先输入的字符串。
//
//输入样例：
//5
//li
//wang
//zhang
//jin
//xiang
//输出样例：
//The longest is: zhang

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n,h;
    string k;
    cin>>n;
    vector<string>m(n);
    vector<int>x(n);
    for(int i=0;i<n;i++)
    {
        cin>>m[i];
        x[i]=m[i].size();
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(x[j]>x[j+1])
            {
                k=m[j];m[j]=m[j+1];m[j+1]=k;
                h=x[j];x[j]=x[j+1];x[j+1]=h;
            }
        }
        h=x[n-1];
    }
    for(int j=0;j<n;j++)
    {
        if(x[j]==h){cout<<"The longest is: "<<m[j];break;}
    }

    return 0;
}
*/

//挑选整数
//分数 10
//作者 xuwanzhen
//单位 广东东软学院
//输入一个字符串，内有数字和非数字字符，例如：a123x67 222y35i088 09x8 c，请编写程序，将其中连续的数字作为一个整数，依次存放到一维数组a中。例如前面的字符串，应将123存放到a[0]中，67存放到a[1]中……，最后输出整数的个数以及各个整数的值。
//
//输入格式:
//长度不超过100的一个字符串，其中包含整数字符和非整数字符。
//
//输出格式:
//第一行输出整数的个数
//
//第2行输出各个整数的值，以空格间隔，最后一个整数后面没有空格。
//
//输入样例:
//a123x67 222y35i088 09x8 c
//输出样例:
//7
//123 67 222 35 88 9 8

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    int m[50];
    int o, k = 0;
    getline(cin, n);
    o = n.size();
    for (int j = 0; j < o;)
    {
        int a = 0, p = 0, l = 1;
        for (;; j++)
        {
            if (n[j] < 48 || n[j]>57)break;
            a = (n[j] - 48) + a * 10;
            l *= 10;
            p = 1;
        }
        if (p == 1)
        {
            m[k] = a;
            k++;
        }
        else j++;
    }
    cout << k << endl;
    for (int i = 0; i < k; i++)
    {
        if (i != 0)cout << " ";
        cout << m[i];
    }

    return 0;
}
