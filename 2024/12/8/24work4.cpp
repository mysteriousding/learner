/*(16)求一个字符串的长度

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

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    int m;
    getline(cin,n,'\n');
    m=n.size();
    printf("%d\n",m);

    return 0;
}
*/

/*(17)统计字符个数

//单位 兰州交通大学
//给出一段话，请分别统计这段话中a-z的字符数。
//
//输入样例:
//在这里给出一组输入。例如：
//
//abcdefghijklmnopqrstuvwxyz
//输出样例:
//在这里给出相应的输出。例如：
//
//a:1
//b:1
//c:1
//d:1
//e:1
//f:1
//g:1
//h:1
//i:1
//j:1
//k:1
//l:1
//m:1
//n:1
//o:1
//p:1
//q:1
//r:1
//s:1
//t:1
//u:1
//v:1
//w:1
//x:1
//y:1
//z:1

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    int m,k[27]={0};
    getline(cin,n,'\n');
    m=n.size();
    for(int i=0;i<m;i++)
        k[n[i]-97]++;
    for(int j=0;j<26;j++)
        cout<<char(j+97)<<":"<<k[j]<<endl;

    return 0;
}
*/

/*(18)替换空格

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
    string n;
    int m;
    getline(cin,n,'\n');
    m=n.size();
    for(int i=0;i<m;i++)
        if(n[i]==' ')n[i]='A';
    cout<<n<<endl;

    return 0;
}
*/

/*(19)统计单词数

//一般的文本编辑器都有查找单词的功能，该功能可以快速定位特定单词在文章中的位置，有的还能统计出特定单词在文章中出现的次数。
//
//现在，请你编程实现这一功能，具体要求是：给定一个单词，请你输出它在给定的文章中出现的次数和第一次出现的位置。注意：匹配单词时，不区分大小写，但要求完全匹配，即给定单词必须与文章中的某一独立单词在不区分大小写的情况下完全相同（参见样例 1），如果给定单词仅是文章中某一单词的一部分则不算匹配（参见样例 2）。
//
//输入格式
//共 2 行。
//
//第 1 行为一个字符串，其中只含字母，表示给定单词；
//
//第 2 行为一个字符串，其中只可能包含字母和空格，表示给定的文章。
//
//输出格式
//一行，如果在文章中找到给定单词则输出两个整数，两个整数之间用一个空格隔开，分别是单词在文章中出现的次数和第一次出现的位置（即在文章中第一次出现时，单词首字母在文章中的位置，位置从 $$ 开始）；如果单词在文章中没有出现，则直接输出一个整数 -1。
//
//注意：空格占一个字母位
//
//输入样例:
//To
//to be or not to be is a question
//输出样例:
//2 0
//输入样例:
//to
//Did the Ottoman Empire lose its power at that time
//输出样例:
//-1

// #include<iostream>
// #include<vector>
// #include<cmath>
// #include<string>
// using namespace std;
// int main()
// {
//     string n,n0;
//     int i=0,j,p=-1,k=0;
//     int m;
//     getline(cin,n,'\n');
//     getline(cin,n0,'\n');
//     n+=' ';
//     n0+=' ';
//     m=n.size();
//     while(n0[i]!='\0')
//     {
//         if(i==0)
//         {
//             if(n[0]==n0[0]||abs(n[0]-n0[0])==32)goto E;
//              else goto F;
//         }
//         if(n0[i-1]==' ')
//         {
//             E:
//             j=i;
//             for(;i<=j+m;i++)
//                 if((n0[i]!=n[i-j]&&abs(n0[i]-n[i-j])!=32)||n0[i]=='\0')break;

//             if(i==j+m){k++;if(p==-1)p=j;}
//         }
//         F:
//         i++;
//     }
//     if(p!=-1)cout<<k<<" ";
//     cout<<p<<endl;

//     return 0;
// }



#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
int main()
{
    string n,n0;
    int i=0,j,p=-1,k=0;
    int m;
    getline(cin,n,'\n');
    getline(cin,n0,'\n');
    n+=' ';
    n0+=' ';
    m=n.size();
    while(n0[i]!='\0')
    {
        if(i==0)
        {
            if(n[0]==n0[0]||abs(n[0]-n0[0])==32)goto E;
        }
        else if(n0[i-1]==' ')
        {
            E:
            j=i;
            for(;i<j+m;i++)
                if((n0[i]!=n[i-j]&&abs(n0[i]-n[i-j])!=32)||n0[i]=='\0')break;

            if(i==j+m){i--;k++;if(p==-1)p=j;}
        }
        i++;
    }
    if(p!=-1)cout<<k<<" ";
    cout<<p<<endl;

    return 0;
}
*/

//句子反转
//
//给定一行句子，每个词之间用空格隔开，要么是全小写英文单词，要么是全大写英文单词，要么是自然数。
//
//要求将这些单词倒序输出。而且对于每个单词，如果是小写词，应当转为大写；如果是大写词，应当转为小写；如果是自然数，应该倒转输出。
//
//举一个例子：
//
//we choose TO go 2 the 123 moon
//程序应当输出：
//
//MOON 321 THE 2 GO to CHOOSE WE
//输入格式
//仅一行，即需要反转的句子。
//
//输出格式
//仅一行，表示程序对句子的处理结果。
//
//说明/提示
//样例解释
//首先应当按单词逆序，即：
//
//moon 123 the 2 go TO choose we
//小写变大写、大写变小写、倒转自然数之后，得到最终结果：
//
//MOON 321 THE 2 GO to CHOOSE WE
//数据规模与约定
//对于 100% 的数据，句子中包含的单词数量不超过 1000，每个单词长度不超过 6。
//
//输入样例:
//we choose TO go 2 the 123 moon
//输出样例:
//MOON 321 THE 2 GO to CHOOSE WE


