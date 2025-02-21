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


*/
