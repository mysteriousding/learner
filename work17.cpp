/*(6)删除重复字符

//本题要求编写程序，将给定字符串去掉重复的字符后，按照字符ASCII码顺序从小到大排序后输出。
//
//输入格式：
//输入是一个以回车结束的非空字符串（少于80个字符）。
//
//输出格式：
//输出去重排序后的结果字符串。
//
//输入样例：
//ad2f3adjfeainzzzv
//输出样例：
//23adefijnvz

#include<iostream>
#include<iostream>
using namespace std;
int main()
{
    string n,k;
    int m,p,l=0;
    char h;
    getline(cin,n,'\n');
    m=n.size();
    for(int i=0;i<m;i++)
    {
        p=0;
        for(int j=i+1;j<m;j++)
        {
            if(n[i]==n[j]){p=1;break;}
        }
        if(p==0){k+=n[i];l++;}
    }
    for(int i=0;i<l-1;i++)
    {
        for(int j=0;j<l-1-i;j++)
        {
            if(k[j]>k[j+1]){h=k[j];k[j]=k[j+1];k[j+1]=h;}
        }
    }
    cout<<k;

    return 0;
}
*/

/*(7)判断回文

//作者 张墨逸
//单位 兰州理工大学
//输入一个以回车符为结束标志的字符串（少于80个字符），判断该字符串是否为回文。
//回文就是字符串中心对称，如“abcba”、“abccba”是回文，“abcdba”不是回文。
//
//输入格式:
//输入一个以回车符为结束标志的字符串（少于80个字符）
//
//输出格式:
//为回文，输出yes; 非回文，输出no，注意输出的结果后面有回车符
//
//输入样例:
//abccba
//
//输出样例:
//yes

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    int m,p=0;
    getline(cin,n,'\n');
    m=n.size();
    for(int i=0;i<m/2;i++)
    {
        if(n[i]!=n[m-1-i]){p=1;break;}
    }

    if(p==0)cout<<"yes"<<endl;
    else cout<<"no"<<endl;

    return 0;
}
*/

/*(8)字符串中的大写字母改成小写字母

//把一个字符串中的大写字母改成小写字母，其他字符不变。
//
//输入格式:
//在 一行中输入长度小于20的字符串。在字符串中不要出现换行符，空格，制表符。
//
//输出格式:
//直接输出变化后的字符串。
//
//输入样例:
//asDFGed
//输出样例:
//asdfged

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
    {
        if(n[i]>=65&&n[i]<=90)n[i]+=32;
    }
    cout<<n<<endl;

    return 0;
}
*/

/*(9)凯撒加密（后偏移）

//为了防止信息被别人轻易窃取，需要把电码明文通过加密方式变换成为密文。输入一个以回车符为结束标志的字符串（少于80个字符），再输入一个正整数offset，用凯撒密码将其加密后输出。恺撒密码是一种简单的替换加密技术，将明文中的所有字母都在字母表上向后偏移offset位后被替换成密文。
//例如，当偏移量offset是2时，表示所有的字母被向后移动 2 位后的字母替换，即所有的字母 A 将被替换成C，字母 B 将变为 D，…，字母 X 变成 Z，字母 Y 则变为 A，字母 Z 变为 B。
//
//输入格式:
//输入第一行给出一个以回车结束的非空字符串（少于80个字符）；第二行输入一个正整数offset。
//
//输出格式:
//输出加密后的结果字符串。
//如果输入的offset不在有效范围内，则在一行中输出"Invalid."。
//
//输入样例1:
//在这里给出一组输入。例如：
//
//Hello Hangzhou
//2
//输出样例1:
//在这里给出相应的输出。例如：
//
//Jgnnq Jcpibjqw
//输入样例2:
//在这里给出一组输入。例如：
//
//z=x+y
//-1
//输出样例2:
//Invalid.

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    int m, k;
    getline(cin, n, '\n');
    k = n.size();
    cin >> m;
    if (m <= 0) { cout << "Invalid." << endl; goto end; }
    m %= 26;
    for (int i = 0; i < k; i++)
    {
        if (n[i] >= 65 && n[i] <= 90)
        {
            if (n[i] + m > 90)n[i] -= 26;
            n[i] += m;
        }
        else if (n[i] >= 97 && n[i] <= 122)
        {
            if (n[i] + m > 122)n[i] -= 26;
            n[i] += m;
        }
    }
    cout << n << endl;
end:

    return 0;
}
*/

//求串长
//
//输入一个字符串（可能包含空格，长度不超过20），输出该串的长度。
//
//输入格式:
//输入在一行中给出1个长度不超过20的字符串s。
//
//输出格式:
//在一行中输出s的串长。
//
//输入样例:
//welcome to acm world
//输出样例:
//20

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    int m;
    getline(cin, n, '\n');
    m = n.size();
    cout << m << endl;

    return 0;
}