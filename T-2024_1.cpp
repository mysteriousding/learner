/*(1)
//L1 - 097 编程解决一切
//分数 5
//作者 陈越
//单位 浙江大学
//编程解决一切 —— 本题非常简单，就请你直接在屏幕上输出这句话：“Problem ? The Solution : Programming.”。
//
//输入格式：
//本题没有输入。
//
//输出格式：
//在一行中输出 Problem ? The Solution : Programming.。
//
//输入样例：
//无
//输出样例：
//Problem ? The Solution : Programming.

#include<iostream>
using namespace std;
int main()
{
    cout<<"Problem? The Solution: Programming."<<endl;

    return 0;
}
*/

/*(2)
//L1-098 再进去几个人
//分数 5
//作者 陈越
//单位 浙江大学
//https://images.ptausercontent.com/353b9d66-ed72-4eb4-a5f7-9e04c899dd35.png
//数学家、生物学家和物理学家坐在街头咖啡屋里，看着人们从街对面的一间房子走进走出。
//他们先看到两个人进去。时光流逝。他们又看到三个人出来。
//物理学家:“测量不够准确。”
//生物学家:“他们进行了繁殖。”
//数学家:“如果现在再进去一个人，那房子就空了。”
//下面就请你写个程序，根据进去和出来的人数，帮数学家算出来，再进去几个人，那房子就空了。
//
//输入格式：
//输入在一行中给出 2 个不超过 100 的正整数 A 和 B，其中 A 是进去的人数，B 是出来的人数。
//题目保证 B 比 A 要大。
//
//输出格式：
//在一行中输出使得房子变空的、需要再进去的人数。
//
//输入样例：
//4 7
//输出样例：
//3

#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<b-a<<endl;

    return 0;
}
*/

/*(3)
//L1-099 帮助色盲
//分数 10
//作者 陈越
//单位 浙江大学
//https://images.ptausercontent.com/61953f88-d2e9-4784-add8-0dd51f84aba9.jpg
//
//在古老的红绿灯面前，红绿色盲患者无法分辨当前亮起的灯是红色还是绿色，有些聪明人通过路口的策略是这样的：
//当红灯或绿灯亮起时，灯的颜色无法判断，但前方两米内有同向行走的人，就跟着前面那人行动，人家走就跟着走，人家停就跟着停；
//如果当前是黄灯，那么很快就要变成红灯了，于是应该停下来。
//麻烦的是，当灯的颜色无法判断时，前方两米内没有人……
//本题就请你写一个程序，通过产生不同的提示音来帮助红绿色盲患者判断当前交通灯的颜色
//；但当患者可以自行判断的时候（例如黄灯或者前方两米内有人），就不做多余的打扰。
//具体要求的功能为：
//当前交通灯为红灯或绿灯时，检测其前方两米内是否有同向行走的人 —— 如果有，则患者自己可以判断，程序就不做提示；
//如果没有，则根据灯的颜色给出不同的提示音。
//黄灯也不需要给出提示。
//
//输入格式：
//输入在一行中给出两个数字 A 和 B，其间以空格分隔。
//其中 A 是当前交通灯的颜色，取值为 0 表示红灯、1 表示绿灯、2 表示黄灯；B 是前方行人的状态，取值为 0 表示前方两米内没有同向行走的人、1 表示有。
//
//输出格式：
//根据输入的状态在第一行中输出提示音：
//dudu 表示前方为绿灯，可以继续前进；biii 表示前方为红灯，应该止步；
//- 表示不做提示。
//在第二行输出患者应该执行的动作：
//move 表示继续前进、stop 表示止步。
//
//输入样例 1：
//0 0
//输出样例 1：
//biii
//stop
//输入样例 2：
//1 1
//输出样例 2：
//-
//move

#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(b||a==2)cout<<"-";
    else if(a)cout<<"dudu";
    else cout<<"biii";
    cout<<endl;
    if(a==1)cout<<"move";
    else cout<<"stop";

    return 0;
}
*/

/*(4)
//L1-100 四项全能
//分数 10
//作者 陈越
//单位 浙江大学
//https://images.ptausercontent.com/27e9cd15-9758-494d-b991-243c488dfbd4.jpg
//新浪微博上有一个帖子给出了一道题：
//全班有 50 人，有 30 人会游泳，有 35 人会篮球，有 42 人会唱歌，有 46 人会骑车，至少有（ ）人四项都会。
//发帖人不会做这道题，但是回帖有会做的：
//每一个才艺是一个技能点，一共是 30 + 35 + 42 + 46 = 153 个技能点，50 个人假设平均分配，每人都会 3 个技能那也只有 150，所以至少有 3 人会四个技能。
//本题就请你写个程序来自动解决这类问题：
//给定全班总人数为 n，其中有 m 项技能，分别有 k1 、k2 、……、km 个人会，问至少有多少人 m 项都会。
//
//输入格式：
//输入在第一行中给出 2 个正整数：n（4≤n≤1000）和 m（1<m≤n/2），分别对应全班人数和技能总数。
//随后一行给出 m 个不超过 n 的正整数，其中第 i 个整数对应会第 i 项技能的人数。
//
//输出格式：
//输出至少有多少人 m 项都会。
//
//输入样例：
//50 4
//30 35 42 46
//输出样例：
//3

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m,a=0,b;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>b;
        a+=b;
    }
    cout<<(a>(n*--m)?a-(n*m):0)<<endl;

    return 0;
}
*/

//L1-101 别再来这么多猫娘了！
//分数 15
//作者 DAI, Longao
//单位 杭州百腾教育科技有限公司
//以 GPT 技术为核心的人工智能系统出现后迅速引领了行业的变革，不仅用于大量的语言工作（如邮件编写或文章生成等工作），还被应用在一些较特殊的领域——例如去年就有同学尝试使用 ChatGPT 作弊并被当场逮捕（全校被取消成绩）。
//相信聪明的你一定不会犯一样的错误！
//
//言归正传，对于 GPT 类的 AI，一个使用方式受到不少年轻用户的欢迎——将 AI 变成猫娘：
//
//https://images.ptausercontent.com/44165688-7919-4455-9f69-4ab68b0a42c3.png
//
//部分公司使用 AI 进行网络营销，网友同样乐于使用“变猫娘”的方式进行反击。
//注意：图中内容与题目无关，如无法看到图片不影响解题。
//
//
//当然，由于训练数据里并不区分道德或伦理倾向，因此如果不加审查，AI 会生成大量的、不一定符合社会公序良俗的内容。
//尽管关于这个问题仍有争论，但至少在比赛中，我们还是期望 AI 能用于对人类更有帮助的方向上，少来一点猫娘。
//
//因此你的工作是实现一个审查内容的代码，用于对 AI 生成的内容的初步审定。
//更具体地说，你会得到一段由大小写字母、数字、空格及 ASCII 码范围内的标点符号的文字，以及若干个违禁词以及警告阈值，你需要首先检查内容里有多少违禁词，如果少于阈值个，则简单地将违禁词替换为<censored>；
//如果大于等于阈值个，则直接输出一段警告并输出有几个违禁词。
//
//输入格式:
//输入第一行是一个正整数 N (1≤N≤100)，表示违禁词的数量。
//接下来的 N 行，每行一个长度不超过 10 的、只包含大小写字母、数字及 ASCII 码范围内的标点符号的单词，表示应当屏蔽的违禁词。
//然后的一行是一个非负整数 k (0≤k≤100)，表示违禁词的阈值。
//最后是一行不超过 5000 个字符的字符串，表示需要检查的文字。
//从左到右处理文本，违禁词则按照输入顺序依次处理；
//对于有重叠的情况，无论计数还是替换，查找完成后从违禁词末尾继续处理。
//
//输出格式:
//如果违禁词数量小于阈值，则输出替换后的文本；
//否则先输出一行一个数字，表示违禁词的数量，然后输出He Xie Ni Quan Jia!。
//
//输入样例1:
//5
//MaoNiang
//SeQing
//BaoLi
//WeiGui
//BuHeShi
//4
//BianCheng MaoNiang ba! WeiGui De Hua Ye Keyi Shuo! BuYao BaoLi NeiRong.
//
//输出样例1:
//BianCheng <censored> ba! <censored> De Hua Ye Keyi Shuo! BuYao <censored> NeiRong.
//输入样例2:
//5
//MaoNiang
//SeQing
//BaoLi
//WeiGui
//BuHeShi
//3
//BianCheng MaoNiang ba! WeiGui De Hua Ye Keyi Shuo! BuYao BaoLi NeiRong.
//
//输出样例2:
//3
//He Xie Ni Quan Jia!
//输入样例3:
//2
//AA
//BB
//3
//AAABBB
//
//输出样例3:
//<censored>A<censored>B
//输入样例4:
//2
//AB
//BB
//3
//AAABBB
//
//输出样例4:
//AA<censored><censored>
//输入样例5:
//2
//BB
//AB
//3
//AAABBB
//
//输出样例5:
//AAA<censored>B

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int n,m,i=0,j,x=0,y,z=0;
    bool u;
    string h,p="<censored>";
    cin>>n;
    vector<string>a(n);
    cin.ignore();
    for(i=0;i<n;i++)
        getline(cin,a[i]);
    cin>>m;
    cin.ignore();
    getline(cin,h);
    for(i=0;i<n;i++)
    {
        z=y=0;
        while((z=h.find(a[i],z))!=string::npos)
        {
            h.erase(z,a[i].size());
            h.insert(z,p);
            z+=p.size();
            y++;
        }
        x+=y;
    }
    if(x<m)cout<<h<<endl;
    else cout<<x<<"\nHe Xie Ni Quan Jia!"<<endl;

    return 0;
}