/*(11)判断n是否是素数。

//输入正整数n，判断n是否是素数。输入 n ，当n为素数时，输出x 是素数；当n不为素数时，输出x不是素数。
//
//输入格式:
//请在这里写输入格式。例如：输入n。
//
//输出格式:
//请在这里描述输出格式。例如：当n为素数时，输出x 是素数，当n不为素数时，输出x不是素数。
//
//输入样例:
//在这里给出一组输入。例如：
//
//2
//输出样例:
//在这里给出相应的输出。例如：
//
//2是素数

#include<iostream>
using namespace std;
bool pd(int n)
{
    if(n==1)return 0;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)return 0;
    return 1;
}
int main()
{
    int n;
    cin>>n;
    cout<<n<<(pd(n)?"":"不")<<"是素数"<<endl;

    return 0;
}
*/

/*(12)统计字符

//编程输入一行文字，找出其中的大写字母、小写字母、空格、数字，以及其他字符的个数。
//
//输入格式:
//在一行中输入任意字符串。字符串长度不超过99个字符。
//注意，输入中不会出现汉字。
//
//输出格式:
//输出共有5行。分别为空格个数、大写英文字母个数、小写英文字母个数、数字个数、其他（除换行符外）字符个数。
//
//输入样例:
//在这里给出一组输入。例如：
//
//123 abc ABC ?
//输出样例:
//在这里给出相应的输出。例如：
//
//空格的个数：3
//大写英文字母个数：3
//小写英文字母个数：3
//数字的个数为：3
//其他字符的个数：1


#include<iostream>
#include<string>
using namespace std;
int main()
{
    string m;
    getline(cin,m);
    int n=m.size(),a[5]={0};
    for(int i=0;i<n;i++)
    {
        if(m[i]==' ')a[0]++;
        else if(m[i]>='A'&&m[i]<='Z')a[1]++;
        else if(m[i]>='a'&&m[i]<='z')a[2]++;
        else if(m[i]>='0'&&m[i]<='9')a[3]++;
        else a[4]++;
    }
    cout<<"空格的个数："<<a[0]<<endl;
    cout<<"大写英文字母个数："<<a[1]<<endl;
    cout<<"小写英文字母个数："<<a[2]<<endl;
    cout<<"数字的个数为："<<a[3]<<endl;
    cout<<"其他字符的个数："<<a[4]<<endl;

    return 0;
}
*/

/*(13)统计字符个数

//输入n个字符，统计其中英文字母、空格或回车、数字字符和其他字符的个数。
//
//输入格式:
//输入为n个字符。最后一个回车表示输入结束，不算在内。
//
//输出格式:
//在一行内按照，英文字母个数, 空格个数,  数字字符个数, 其他字符个数的顺序的格式输出。
//
//输入样例:
//在这里给出一组输入。例如：
//
//aaaaaa 11111 2223www
//输出样例:
//在这里给出相应的输出。例如：
//
//letter=9
//space=2
//digit=9
//other=0


#include<iostream>
#include<string>
using namespace std;
int main()
{
    string m;
    int n,a[4]={0};
    getline(cin,m,'\n');
    n=m.size();
    for(int i=0;i<n;i++)
    {
        if((m[i]>='A'&&m[i]<='Z')||(m[i]>='a'&&m[i]<='z'))a[0]++;
        else if(m[i]==' ')a[1]++;
        else if(m[i]>='0'&&m[i]<='9')a[2]++;
        else a[3]++;
    }

    cout<<"letter="<<a[0]<<endl;
    cout<<"space="<<a[1]<<endl;
    cout<<"digit="<<a[2]<<endl;
    cout<<"other="<<a[3]<<endl;

    return 0;
}
*/

/*(14)求一个字符串的长度

//编写函数fun，其功能是求一个字符串的长度,在main函数中输入字符串,并输出其长度，不能使用strlen函数。
//
//输入格式:
//输出格式:
//"%d\n"
//
//输入样例:
//在这里给出一组输入。例如：
//
//abcdedg
//输出样例:
//在这里给出相应的输出。例如：
//
//7

// #include<iostream>
// #include<cstring>
// int main()
// {
//     char m[100];
//     scanf("%s",m);
//     int n=strlen(m);
//     printf("%d\n",n);

//    return 0;
// }

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string m;
    getline(cin,m);
    int n=m.size();
    printf("%d\n",n);

   return 0;
}
*/

//替换空格
//
//输入字符串，把空格换成A
//
//输入格式:
//一个字符串
//
//输出格式:
//替换后的字符串
//
//输入样例:
//abc def
//输出样例:
//abcAdef

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string m;
    int i=0;
    getline(cin,m);
    while(m[i]!='\0')
    {
        if(m[i]==' ')m[i]='A';
        i++;
    }
    cout<<m<<endl;

    return 0;
}
