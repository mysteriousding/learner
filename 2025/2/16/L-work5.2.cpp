/*(6)求前缀表达式的值

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
    stack<string>a;
    stack<double>b;
    string h;
    double x,y;
    while(cin>>h)
        a.push(h);
    while(!a.empty())
    {
        h=a.top();
        a.pop();
        if(h[0]>='0'&&h[0]<='9'||h[1]>='0'&&h[1]<='9')b.push(stod(h));
        else
        {
            x=b.top();
            b.pop();
            y=b.top();
            b.pop();
            switch(h[0])
            {
                case '+':x+=y;break;
                case '-':x-=y;break;
                case '*':x*=y;break;
                case '/':
                    if(y!=0)x/=y;
                    else
                    {
                        cout<<"ERROR"<<endl;
                        return 0;
                    }
            }
            b.push(x);
        }
    }
    x=b.top();
    b.pop();
    cout<<setiosflags(ios::fixed)<<setprecision(1)<<x<<endl;

    return 0;
}
*/

/*(7)树种统计

//随着卫星成像技术的应用，自然资源研究机构可以识别每一棵树的种类。
//请编写程序帮助研究人员统计每种树的数量，计算每种树占总数的百分比。
//
//输入格式:
//输入首先给出正整数 n（≤10^5 ），随后 n 行，每行给出卫星观测到的一棵树的种类名称。
//种类名称由不超过 30 个英文字母和空格组成（大小写有区分）。
//
//输出格式:
//按字典序递增输出各种树的种类名称及其所占总数的百分比，其间以空格分隔，保留小数点后 4 位。
//
//输入样例:
//29
//Red Alder
//Ash
//Aspen
//Basswood
//Ash
//Beech
//Yellow Birch
//Ash
//Cherry
//Cottonwood
//Ash
//Cypress
//Red Elm
//Gum
//Hackberry
//White Oak
//Hickory
//Pecan
//Hard Maple
//White Oak
//Soft Maple
//Red Oak
//Red Oak
//White Oak
//Poplan
//Sassafras
//Sycamore
//Black Walnut
//Willow
//
//输出样例:
//Ash 13.7931%
//Aspen 3.4483%
//Basswood 3.4483%
//Beech 3.4483%
//Black Walnut 3.4483%
//Cherry 3.4483%
//Cottonwood 3.4483%
//Cypress 3.4483%
//Gum 3.4483%
//Hackberry 3.4483%
//Hard Maple 3.4483%
//Hickory 3.4483%
//Pecan 3.4483%
//Poplan 3.4483%
//Red Alder 3.4483%
//Red Elm 3.4483%
//Red Oak 6.8966%
//Sassafras 3.4483%
//Soft Maple 3.4483%
//Sycamore 3.4483%
//White Oak 10.3448%
//Willow 3.4483%
//Yellow Birch 3.4483%
//
//鸣谢青岛大学周强老师修正题面！

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n,num=0,i;
    string h;
    cin>>n;
    vector<string>a(n);
    cin.ignore();
    for(i=0;i<n;i++)
        getline(cin,a[i]);
    sort(a.begin(),a.end());
    i=0,h=a[i];
    cout<<setiosflags(ios::fixed)<<setprecision(4);
    while(i<n)
    {
        if(a[i]==h)num++;
        else
        {
            cout<<h<<" "<<num*100.0/n<<"%\n";
            h=a[i];
            num=1;
        }
        i++;
    }
    cout<<h<<" "<<num*100.0/n<<"%\n";

    return 0;
}
*/

/*(8)魔法优惠券

//在火星上有个魔法商店，提供魔法优惠券
//每个优惠劵上印有一个整数面值K，表示若你在购买某商品时使用这张优惠劵，可以得到K倍该商品价值的回报！
//该商店还免费赠送一些有价值的商品，但是如果你在领取免费赠品的时候使用面值为正的优惠劵，则必须倒贴给商店K倍该商品价值的金额…… 
//但是不要紧，还有面值为负的优惠劵可以用！（真是神奇的火星）
//
//例如，给定一组优惠劵，面值分别为1、2、4、-1；
//对应一组商品，价值为火星币M7、6、−2、−3，其中负的价值表示该商品是免费赠品。
//我们可以将优惠劵3用在商品1上，得到M28的回报；
//优惠劵2用在商品2上，得到M12的回报；
//优惠劵4用在商品4上，得到M3的回报。
//但是如果一不小心把优惠劵3用在商品4上，你必须倒贴给商店M12。
//同样，当你一不小心把优惠劵4用在商品1上，你必须倒贴给商店M7。
//
//规定每张优惠券和每件商品都只能最多被使用一次，求你可以得到的最大回报。
//
//输入格式:
//输入有两行。
//第一行首先给出优惠劵的个数N，随后给出N个优惠劵的整数面值。
//第二行首先给出商品的个数M，随后给出M个商品的整数价值。
//N和M在[1, 10^6 ]之间，所有的数据大小不超过2^30 ，数字间以空格分隔。
//
//输出格式:
//输出可以得到的最大回报。
//
//输入样例:
//4 1 2 4 -1
//4 7 6 -2 -3
//输出样例:
//43

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n,m,sum=0;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    cin>>m;
    vector<int>b(m);
    for(int j=0;j<m;j++)
        cin>>b[j];
    sort(b.begin(),b.end());
    int k=0,p;
    while(a[k]<0&&b[k]<0)
        sum+=a[k]*b[k++];
    k=n-1,p=m-1;
    while(a[k]>0&&b[p]>0)
        sum+=a[k--]*b[p--];
    cout<<sum<<endl;

    return 0;
}
*/

/*(9)小甘老师的分组优化策略

//在大学校园的一次大型活动筹备中，活动组织者小甘老师拥有一份包含 n 个元素 ( 1≤n≤4×10^5 )的信息序列 s，序列中的每个元素均由大小写英文字母或数字构成。
//
//小甘老师计划对该信息序列进行重新整理与分组。
//他首先会对序列 s 中的元素顺序进行重新排列，然后将其分割成若干长度完全相等的部分。
//并且分割出的每一部分均为回文结构，即从前往后读取与从后往前读取的内容完全一致，例如 “n1oo1n” “RadaR”等。
//
//现请你协助小甘老师对序列 s 进行重新排列与分割。
//要求在分割的字串长度完全相同且字串都是回文结构的情况下，分割成的子结构数量最少。
//
//输入格式：
//第一行输入一个整数 t ( 1≤t≤20 )，表示测试用例的组数
//
//接下来有 t 行数据，每行输入一个长度为 n( 1≤n≤4×10^5 ) 的字符串，该字符串只包含大小写英文字母或数字。
//
//题目保证对于每一个输入，所有测试用例的字符串总长度不超过 4×10^5
//
//
//输出格式：
//输出 t 组答案，每一组答案单独输出一行。
//对于每一组答案，输出一个整数 k ，此为将给定信息序列分割成的最小回文部分的数量。
//如果对于该组数据无法进行任何分组，输出−1。
//
//输入样例:
//3
//aabaac
//0xYxY066
//dD
//
//输出样例:
//2
//1
//2
//
//说明
//对于第一组测试数据，其中一种划分是将字符重新排列成aba和aca两个回文子结构，可以证明划分成 2 组是满足题目要求的最小划分。


*/

//基于贪心策略的离散背包问题近似算法
//
//离散背包问题（也称为“0-1 背包问题”）的定义是：
//给定一个总承重量为 W 的背包和 n 件物品的集合 S={s1,⋯,sn }，其中第 i 件物品有其重量 wi 和价值 vi 。
//要求一种分派方案x = (x1, ⋯, xn)，在满足约束条件 R : Σ(n)(i = 1) xi⋅wi≤W（即装入的物品总重量不超过背包承重）的前提下，使优化函数 f(x)=ΣΣ(n)(i = 1) xi⋅vi 取极大值（即装入的物品总价值最大）。
//其中 xi 是整数，取值或为 1 或为 0，即每一件物品只有 2 种选择，或者完全放进背包，或者被完全舍弃。
//
//基于贪心策略的离散背包问题近似算法是分别利用按原价贪心（greedy by value）和按单价贪心（greedy by unit value）两种算法求出两组解，取两者中较优的解。
//本题就请你实现这个算法。
//
//输入格式：
//输入首先在第一行中给出正整数 n（≤1000）和正实数 W（≤500）。
//随后两行各给出 n 个不超过 2000 的正实数，分别为 n 件物品的重量和价值，即第一行第 i 个数字表示第 i 件物品的重量，第二行对应位置表示其价值。
//同行数字间以空格分隔。
//
//输出格式：
//首先在第一行输出装入物品的最大总价值，要求输出小数点后 2 位。
//随后一行输出最优分派方案的分量(x1, ⋯, xn)。
//简单起见，每个分量后面跟一个空格。
//
//输入样例：
//5 11.2
//1 2 5 6 7
//4 6 18 22 25.3
//输出样例：
//35.30
//1 1 0 0 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Itm
{
    int id;
    double wt;
    double vl;
    double up;
};

bool cmpV(const Itm& a, const Itm& b)
{
    return a.vl > b.vl;
}

bool cmpP(const Itm& a, const Itm& b)
{
    return a.up > b.up;
}

pair<double, vector<int>> gk(int n, double W, const vector<Itm>& its, bool (*cmp)(const Itm&, const Itm&)) {
    vector<Itm> srt = its;
    sort(srt.begin(), srt.end(), cmp);

    double tv = 0.0; // 总价值
    vector<int> x(n, 0); // 分配方案
    double tw = W; // 剩余重量

    for (const auto& itm : srt)
        if (tw >= itm.wt)
        {
            x[itm.id] = 1;
            tv += itm.vl;
            tw -= itm.wt;
        }

    return { tv, x };
}

int main()
{
    int n;
    double W;
    cin >> n >> W;

    vector<Itm> its(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> its[i].wt;
        its[i].id = i;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> its[i].vl;
        its[i].up = its[i].vl / its[i].wt;
    }

    auto [v1, x1] = gk(n, W, its, cmpV);
    auto [v2, x2] = gk(n, W, its, cmpP);

    pair<double, vector<int>> res;
    if (v1 >= v2) res = { v1, x1 };
    else res = { v2, x2 };

    cout << fixed << setprecision(2) << res.first << endl;
    for (int i = 0; i < n; ++i)
        cout << res.second[i] << " ";
    cout << endl;

    return 0;
}
