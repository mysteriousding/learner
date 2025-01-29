/*(1)阅览室

//天梯图书阅览室请你编写一个简单的图书借阅统计程序。
//当读者借书时，管理员输入书号并按下S键，程序开始计时；
//当读者还书时，管理员输入书号并按下E键，程序结束计时。
//书号为不超过1000的正整数。
//当管理员将0作为书号输入时，表示一天工作结束，你的程序应输出当天的读者借书次数和平均阅读时间。
//
//注意：由于线路偶尔会有故障，可能出现不完整的纪录，即只有S没有E，或者只有E没有S的纪录，系统应能自动忽略这种无效纪录。
//另外，题目保证书号是书的唯一标识，同一本书在任何时间区间内只可能被一位读者借阅。
//
//输入格式：
//输入在第一行给出一个正整数N（≤10），随后给出N天的纪录。
//每天的纪录由若干次借阅操作组成，每次操作占一行，格式为：
//
//书号（[1, 1000]内的整数） 键值（S或E） 发生时间（hh:mm，其中hh是[0,23]内的整数，mm是[0, 59]内整数）
//
//每一天的纪录保证按时间递增的顺序给出。
//
//输出格式：
//对每天的纪录，在一行中输出当天的读者借书次数和平均阅读时间（以分钟为单位的精确到个位的整数时间）。
//
//输入样例：
//3
//1 S 08:10
//2 S 08:35
//1 E 10:00
//2 E 13:16
//0 S 17:00
//0 S 17:00
//3 E 08:10
//1 S 08:20
//2 S 09:00
//1 E 09:20
//0 E 17:00
//输出样例：
//2 196
//0 0
//1 60

#include<iostream>
using namespace std;
struct Time
{
    int s;
    int f;
    friend istream& operator>>(istream& in,Time& T);
    int operator-(Time& b)
    {
        int c;
        if(b.f>f)c=f+60-b.f,s--;
        else c=f-b.f;
        c+=(s-b.s)*60;
        return c;
    }
};
istream& operator>>(istream& in,Time& T)
{
    char o;
    in>>T.s>>o>>T.f;
    return in;
}
struct book
{
    bool l=0;
    Time T[2];
    int jian()
    {
        return T[1]-T[0];
    }
}B[1001];
int main()
{
    int n,x,num=0,sum=0;
    char y;
    cin>>n;
    while(n)
    {
        cin>>x>>y;
        if(x==0)
        {
            for(int i=1;i<=1000;i++)
                B[i].l=0;
            if(num!=0)sum=sum*1.0/num+0.5;
            cout<<num<<" "<<sum<<endl;
            num=sum=0,n--;
            cin>>B[0].T[0];
            continue;
        }
        if(y=='S'&&!B[x].l)
        {
            B[x].l=1;
            cin>>B[x].T[0];
        }
        else
        {
            cin>>B[x].T[1];
            if(B[x].l)
            {
                B[x].l=0;
                num++;
                sum+=B[x].jian();
            }
        }
    }

    return 0;
}
*/

/*(2)求前缀表达式的值

//算术表达式有前缀表示法、中缀表示法和后缀表示法等形式。
//前缀表达式指二元运算符位于两个运算数之前，例如2+3*(7-4)+8/4的前缀表达式是：+ + 2 * 3 - 7 4 / 8 4。
//请设计程序计算前缀表达式的结果值。
//
//输入格式:
//输入在一行内给出不超过30个字符的前缀表达式，只包含+、-、*、/以及运算数，不同对象（运算数、运算符号）之间以空格分隔。
//
//输出格式:
//输出前缀表达式的运算结果，保留小数点后1位，或错误信息ERROR。
//
//输入样例:
//+ + 2 * 3 - 7 4 / 8 4
//输出样例:
//13.0

#include<iostream>
#include<iomanip>
#include<string>
#include<stack>
using namespace std;
int main()
{
    string x;
    double y,z;
    stack<string>n;
    stack<double>m;
    while(cin>>x)
        n.push(x);
    while(!n.empty())
    {
        x=n.top();
        n.pop();
        if(x[0]>='0'&&x[0]<='9'||x[1]>='0'&&x[1]<='9')
        {
            y=stod(x);
            m.push(y);
        }
        else
        {
            y=m.top();
            m.pop();
            z=m.top();
            m.pop();
            switch(x[0])
            {
                case '+':
                    y+=z;break;
                case '-':
                    y-=z;break;
                case '*':
                    y*=z;break;
                case '/':
                    if(z!=0)y/=z;
                    else
                    {
                        cout<<"ERROR"<<endl;
                        return 0;
                    }
                default:;
            }
            m.push(y);
        }
    }
    cout<<setiosflags(ios::fixed)<<setprecision(1);
    y=m.top();m.pop();
    cout<<y<<endl;

    return 0;
}
*/

/*(3)家庭房产

//给定每个人的家庭成员和其自己名下的房产，请你统计出每个家庭的人口数、人均房产面积及房产套数。
//
//输入格式：
//输入第一行给出一个正整数N（≤1000），随后N行，每行按下列格式给出一个人的房产：
//
//编号 父 母 k 孩子1 ... 孩子k 房产套数 总面积
//其中编号是每个人独有的一个4位数的编号；
//父和母分别是该编号对应的这个人的父母的编号（如果已经过世，则显示-1）；
//k（0≤k≤5）是该人的子女的个数；孩子i是其子女的编号。
//
//输出格式：
//首先在第一行输出家庭个数（所有有亲属关系的人都属于同一个家庭）。
//随后按下列格式输出每个家庭的信息：
//
//家庭成员的最小编号 家庭人口数 人均房产套数 人均房产面积
//其中人均值要求保留小数点后3位。
//家庭信息首先按人均面积降序输出，若有并列，则按成员编号的升序输出。
//
//输入样例：
//10
//6666 5551 5552 1 7777 1 100
//1234 5678 9012 1 0002 2 300
//8888 -1 -1 0 1 1000
//2468 0001 0004 1 2222 1 500
//7777 6666 -1 0 2 300
//3721 -1 -1 1 2333 2 150
//9012 -1 -1 3 1236 1235 1234 1 100
//1235 5678 9012 0 1 50
//2222 1236 2468 2 6661 6662 1 300
//2333 -1 3721 3 6661 6662 6663 1 100
//输出样例：
//3
//8888 1 1.000 1000.000
//0001 15 0.600 100.000
//5551 4 0.750 100.000

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
struct man
{
    string h[9];
    int k;
    int f;
    int s;
    int p;
    vector<string>d;
    friend istream& operator>>(istream& in,man& r);
};
istream& operator>>(istream& in,man& r)
{
    int x=2,y=0;
    in>>r.h[y++];
    in>>r.h[y];
    if(r.h[y]!="-1")y++,x--;
    in>>r.h[y];
    if(r.h[y]!="-1")y++,x--;

    in>>r.k;
    r.k+=y;
    for(int i=y;i<r.k;i++)
        in>>r.h[i];
    sort(r.h,r.h+r.k);
    in>>r.f>>r.s;
    return in;
}
struct jia
{
    string min="9999";
    int shu=0;
    vector<string>d;
    double f=0;
    double s=0;
};
ostream& operator<<(ostream& out,jia& r)
{
    out<<r.min<<" "<<r.shu<<" "<<r.f<<" "<<r.s;
    return out;
}
bool pd(man& a,man& b)
{
    return a.p<b.p;
}
bool pd2(jia& x,jia& y)
{
    if(fabs(x.s-y.s)<1e-4)return x.min<y.min;
    else return x.s>y.s;
}
int main()
{
    int n,l;
    bool u;
    cin>>n;
    vector<man>m(n);
    for(int i=0;i<n;i++)
    {
        cin>>m[i];
        m[i].p=i;
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(m[i].p!=m[j].p)
            {
                u=0;
                for(int a=0;a<m[i].k;a++)
                {
                    for(int b=0;b<m[j].k;b++)
                    {
                        if(m[i].h[a]<m[j].h[b])break;
                        if(m[i].h[a]==m[j].h[b])
                        {
                            u=1;
                            m[i].d.push_back(m[i].h[a]);
                            m[j].d.push_back(m[j].h[b]);
                        }
                    }
                }
                if(u)
                {
                    l=m[j].p;
                    for(int c=0;c<n;c++)
                        if(m[c].p==l)
                            m[c].p=m[i].p;
                }
            }
    sort(m.begin(),m.end(),pd);
    l=m[0].p;
    int num=1;
    vector<jia>v(n);
    for(int i=0;i<n;i++)
    {
        if(l!=m[i].p)
            num++,l=m[i].p;
        for(int j=0;j<m[i].k;j++)
            if(v[num-1].min>m[i].h[j])
                v[num-1].min=m[i].h[j];
        v[num-1].shu+=m[i].k;
        v[num-1].d.insert(v[num-1].d.end(),m[i].d.begin(),m[i].d.end());
        v[num-1].f+=m[i].f;
        v[num-1].s+=m[i].s;
    }
    int sum;
    string f;
    for(int i=0;i<num;i++)
    {
        sort(v[i].d.begin(),v[i].d.end());
        if(!v[i].d.empty())
        {
            sum=1,f=v[i].d[0];
            for(size_t j=0;j<v[i].d.size();j++)
                if(f!=v[i].d[j])
                    sum++,f=v[i].d[j];
            v[i].shu-=v[i].d.size()-sum;
        }
        v[i].f/=v[i].shu,v[i].s/=v[i].shu;
    }
    sort(v.begin(),v.begin()+num,pd2);
    cout<<num<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(3);
    for(int i=0;i<num;i++)
        cout<<v[i]<<endl;

    return 0;
}
*/

/*(4)Tree Traversals Again

An inorder binary tree traversal can be implemented in a non-recursive way with a stack. 
For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: 
push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop().  
Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. 
Your task is to give the postorder traversal sequence of this tree.


Figure 1
Input Specification:
Each input file contains one test case. 
For each case, the first line contains a positive integer N (≤30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). 
Then 2N lines follow, each describes a stack operation in the format:
"Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:
For each test case, print the postorder traversal sequence of the corresponding tree in one line. 
A solution is guaranteed to exist. 
All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1

/*
再次遍历树形

中序二叉树遍历可以通过堆栈以非递归方式实现。
例如，假设当遍历一棵 6 节点二叉树（键编号为 1 到 6）时，堆栈操作为：
push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop().
然后，可以从这一系列操作中生成一个唯一的二叉树（如图 1 所示）。
你的任务是给出这个树的后序遍历序列。
https://images.ptausercontent.com/30
图 1
输入规格：
每个输入文件都包含一个测试用例。
对于每种情况，第一行都包含一个正整数 N （≤30），这是树中的节点总数（因此节点的编号从 1 到 N）。
然后是 2N 行，每行描述一个堆栈操作，格式如下：
“Push X”，其中 X 是被推送到堆栈上的节点的索引;或 “Pop” 表示从堆栈中弹出一个节点。

输出规格：
对于每个测试用例，在一行中打印相应树的后序遍历序列。
解决方案是肯定存在的。
所有数字必须用一个空格分隔，并且行尾不能有多余的空格。

示例输入：
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop

示例输出：
3 4 2 6 5 1
*

#include<iostream>
#include<string>
using namespace std;
struct Tree
{
    int num;
    bool l=1;
    Tree*left=NULL;
    Tree*right=NULL;
    Tree*q=NULL;
}*head=NULL,*p=NULL;
bool u=0;
void bl(Tree* p)
{
    if(!p)return;
    bl(p->left);
    bl(p->right);
    if(u)cout<<" ";
    cout<<p->num;
    u=1;
    delete p;
}
int main()
{
    int n;
    cin>>n;
    n*=2;
    string m;
    while(n--)
    {
        cin>>m;
        if(m=="Push")
        {
            Tree*node=new Tree;
            cin>>node->num;
            if(!head)
            {
                p=head=node;
                continue;
            }
            if(p->l)
            {
                p->left=node;
                node->q=p;
                p=node;
            }
            else
            {
                p->right=node;
                node->q=p;
                p=node;
            }
        }
        else
        {
            while(!p->l)
                p=p->q;
            p->l=0;
            //cout<<p->num<<" ";
        }
    }
    bl(head);

    return 0;
}
*/

//代码排版
//
//某编程大赛中设计有一个挑战环节，选手可以查看其他选手的代码，发现错误后，提交一组测试数据将对手挑落马下。
//为了减小被挑战的几率，有些选手会故意将代码写得很难看懂，比如把所有回车去掉，提交所有内容都在一行的程序，令挑战者望而生畏。
//
//为了对付这种选手，现请你编写一个代码排版程序，将写成一行的程序重新排版。
//当然要写一个完美的排版程序可太难了，这里只简单地要求处理C语言里的for、while、if-else这三种特殊结构，而将其他所有句子都当成顺序执行的语句处理。
//输出的要求如下：
//
//默认程序起始没有缩进；每一级缩进是 2 个空格；
//每行开头除了规定的缩进空格外，不输出多余的空格；
//顺序执行的程序体是以分号“;”结尾的，遇到分号就换行；
//在一对大括号“{”和“}”中的程序体输出时，两端的大括号单独占一行，内部程序体每行加一级缩进，即：
//
//{
//  程序体
//}
//
//for的格式为：
//for (条件) {
//  程序体
//}
//
//while的格式为：
//while (条件) {
//  程序体
//}
//
//if-else的格式为：
//if (条件) {
//  程序体
//}
//
//else {
//  程序体
//}
//
//输入格式：
//输入在一行中给出不超过 331 个字符的非空字符串，以回车结束。
//题目保证输入的是一个语法正确、可以正常编译运行的 main 函数模块。
//
//输出格式：
//按题面要求的格式，输出排版后的程序。
//
//输入样例：
//int main()  {int n, i;  scanf("%d", &n);if( n>0)n++;else if (n<0) n--; else while(n<10)n++; for(i=0;  i<n; i++ ){ printf("n=%d\n", n);}return  0; }
//输出样例：
//int main()
//{
//  int n, i;
//  scanf("%d", &n);
//  if ( n>0) {
//    n++;
//  }
//  else {
//    if (n<0) {
//      n--;
//    }
//    else {
//      while (n<10) {
//        n++;
//      }
//    }
//  }
//  for (i=0;  i<n; i++ ) {
//    printf("n=%d\n", n);
//  }
//  return  0;
//}


// #include<iostream>
// #include<string>
// using namespace std;
// inline void kg(int n)
// {
//     for(int i=0;i<n;i++)
//         cout<<"  ";
// }

// int main()
// {
//     int n=0,i=0,h=0,u=0;
//     string m;
//     getline(cin,m);
//     bool t=0;
//     while(m[i])
//     {
//         if(m[i]=='(')
//         {
//             u=1;
//             int c=i;
//             while(m[c]!=')')
//             {
//                 if(m[c]==';')u=2;
//                 if(m[c++]==',')u=0;
//             }
//             if(t&&u&&m[i-1]!=' ')cout<<" ";
//             while(m[i]!=')')
//                 cout<<m[i++];
//             if(u)
//             {
//                 n++;
//                 if(t)
//                 {
//                     if(u==2)while(m[i]!=' ')i++;
//                     cout<<") {\n";
//                     h++;
//                     //cout<<h<<":--------------";
//                 }
//                 else
//                 {
//                     while(m[i]!=' ')i++;
//                     while(m[i]==' ')i++;
//                     cout<<")\n{\n";
//                 }
//                 kg(n);
//                 t=1;
//                 do{i++;}while(m[i]==' ');
//             }
//         }
//         if(m[i]==';')
//         {
//             //cout<<h<<":-----------";
//             bool v=0;
//             cout<<";\n";
//             if(m[i-1]=='0'){cout<<"}\n";return 0;}
//             if(h)h--,n--,v=1;
//             kg(n);
//             if(v&&m[i+1]!='}')
//             {
//                 cout<<"}\n";
//                 kg(n);
//             }
//             // if(h)
//             //     while(h)
//             //     {
//             //         cout<<h<<":-----------";
//             //         h--,n--,v=1;
//             //         kg(n);
//             //         if(v&&m[i+1]!='}')
//             //         {
//             //             cout<<"}\n";
//             //             kg(n);
//             //         }
//             //     }
//             // else kg(n);
//             do{i++;}while(m[i]==' ');
//         }
//         if(m[i]=='}'){cout<<"}\n";i++;kg(n);}
//         if(m[i]=='e')
//         {
//             string b="else";
//             int c=0;
//             while(b[c]!='\0')
//             {
//                 if(m[c+i]!=b[c])break;
//                 c++;
//             }
//             if(c==4)
//             {
//                 i+=3;
//                 cout<<"else {\n";
//                 n++,h++;
//                 while(m[i+1]==' ')i++;
//                 kg(n);
//             }
//             else cout<<"e";
//         }
//         else cout<<m[i];

//         i++;
//     }

//     return 0;
// }
// // int main()  {if(a==b){x=y;}else{y=x;}return  0; }



#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int ignore_space(const string& s, int d, int t) {
    while (d < s.size() && d > 0 && s[d] == ' ') {
        d += t;
    }
    return d;
}
int trim_space(string& s, int d, int t) {
    if (s[d] != ' ') s.insert(d, " ");
    d += t;
    int i = 0;
    while (i + d < s.size() && s[i + d] == ' ') i++;
    if (i) s.erase(d, i);
    return d;
}
bool judge(string s, int d, int& flag) {
    if (d && isalpha(s[d - 1])) return false;
    if (s.substr(d, 2) == "if" && (s[d + 2] == ' ' || s[d + 2] == '(')) return true;
    if (s.substr(d, 3) == "for" && (s[d + 3] == ' ' || s[d + 3] == '(')) return true;
    if (s.substr(d, 5) == "while" && (s[d + 5] == ' ' || s[d + 5] == '(')) return true;
    flag = 0;
    if (s.substr(d, 4) == "else" && (s[d + 4] == ' ' || s[d + 4] == '{')) return true;
    return false;
}
void perfect(string& s) {
    for (int i = s.size() - 1; i >= 0; i--) {
        int ise = 1;
        if (s[i] == ')') {
            int d = 1, j = i - 1;
            while (d && j >= 0) {
                if (s[j] == ')') d++;
                else if (s[j] == '(') d--;
                j--;
            }
            i = j + 1;
        }
        else if (judge(s, i, ise)) {
            int j = i;
            while (j < s.size() && isalpha(s[j])) j++;
            if (ise) {
                j = trim_space(s, j, 1);
                int d = 1;
                while (d != 0 && ++j < s.size()) {
                    if (s[j] == '(') d++;
                    else if (s[j] == ')') d--;
                }
                j++;
            }
            j = trim_space(s, j, 1);
            if (s[j] != '{') {
                s.insert(j, "{");
                j++;
                int flag = 0;
                while (j < s.size()) {
                    if (s[j] == ';' && flag == 0) {
                        s.insert(j + 1, "}");
                        break;
                    }
                    else if (s[j] == '(') flag++;
                    else if (s[j] == ')') flag--;
                    else if (s.substr(j, 2) == "if") flag++;
                    else if (s.substr(j, 4) == "else") flag--;
                    else if (s[j] == '{') flag++;
                    else if (s[j] == '}') {
                        flag--;
                        if (flag == 1 && s[ignore_space(s, j + 1, 1)] != 'e') flag--;
                        if (flag == 0) {
                            s.insert(j + 1, "}");
                            break;
                        }
                    }
                    j++;
                }
            }
        }
    }
}
void put_space(int k) {
    while (k--) {
        printf("  ");
    }
}
bool check(char s) {
    return s == ')' || s == 'e' || s == '{' || s == '}' || s == ';';
}
int main() {
    int flag = 0, space_num = 0, start = 1;
    string s;
    getline(cin, s);
    perfect(s);
    for (int i = ignore_space(s, 0, 1); i < s.size(); i++) {
        if (start) {
            start = 0;
            if (s[i] == '}') put_space(space_num - 1);
            else put_space(space_num);
        }
        if (s[i] == '{') {
            int d = ignore_space(s, i - 1, -1);
            if (!flag || !check(s[d])) {
                putchar('\n');
                put_space(space_num);
            }
            flag = 1;
            putchar(s[i]);
            putchar('\n');
            space_num++;
            start = 1;
            i = ignore_space(s, i + 1, 1) - 1;
        }
        else if (s[i] == '}') {
            space_num--;
            putchar(s[i]);
            i = ignore_space(s, i + 1, 1) - 1;
            if (s[i + 1] == '}') {
                putchar('\n');
                start = 1;
            }
            else if (i < s.size() - 1) {
                putchar('\n');
                start = 1;
            }
        }
        else if (s[i] == '(') {
            int d = 1, j = i;
            putchar(s[i]);
            while (d) {
                putchar(s[++j]);
                if (s[j] == '(') d++;
                else if (s[j] == ')') d--;
            }
            i = j;
            if (!flag) i = ignore_space(s, i + 1, 1) - 1;
        }
        else if (s[i] == ';') {
            putchar(s[i]);
            i = ignore_space(s, i + 1, 1) - 1;
            putchar('\n');
            start = 1;
        }
        else { putchar(s[i]); }
    }
    return 0;
}
