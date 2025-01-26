/*(6)ZigZagging on a Tree

//Suppose that all the keys in a binary tree are distinct positive integers.  
//A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences. 
//And it is a simple standard routine to print the numbers in level-order.  
//However, if you think the problem is too simple, then you are too naive.  
//This time you are supposed to print the numbers in "zigzagging order" -- that is, starting from the root, print the numbers level-by-level, alternating between left to right and right to left. 
//For example, for the following tree you must output: 1 11 5 8 17 12 20 15.
//
//https://images.ptausercontent.com/337cbfb0-a7b2-4500-9664-318e9ffc870e.jpg
//
//Input Specification:
//Each input file contains one test case. 
//For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree.  
//The second line gives the inorder sequence and the third line gives the postorder sequence.  
//All the numbers in a line are separated by a space.
//
//Output Specification:
//For each test case, print the zigzagging sequence of the tree in a line.  
//All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
//
//Sample Input:
//8
//12 11 20 17 1 15 8 5
//12 20 17 11 15 8 5 1
//Sample Output:
//1 11 5 8 17 12 20 15


*/

/*(7)Universal Travel Sites

//After finishing her tour around the Earth, CYLL is now planning a universal travel sites development project.  
//After a careful investigation, she has a list of capacities of all the satellite transportation stations in hand.  
//To estimate a budget, she must know the minimum capacity that a planet station must have to guarantee that every space vessel can dock and download its passengers on arrival.
//
//Input Specification:
//Each input file contains one test case. For each case, the first line contains the names of the source and the destination planets, and a positive integer N (≤500).  
//Then N lines follow, each in the format: source[i] destination[i] capacity[i] 
//where source[i] and destination[i] are the names of the satellites and the two involved planets, and capacity[i] > 0 is the maximum number of passengers that can be transported at one pass from source[i] to destination[i]. 
//Each name is a string of 3 uppercase characters chosen from {A-Z}, e.g., ZJU.
//
//Note that the satellite transportation stations have no accommodation facilities for the passengers. 
//Therefore none of the passengers can stay.  
//Such a station will not allow arrivals of space vessels that contain more than its own capacity.  
//It is guaranteed that the list contains neither the routes to the source planet nor that from the destination planet.
//
//Output Specification:
//For each test case, just print in one line the minimum capacity that a planet station must have to guarantee that every space vessel can dock and download its passengers on arrival.
//
//Sample Input:
//EAR MAR 11
//EAR AAA 300
//EAR BBB 400
//AAA BBB 100
//AAA CCC 400
//AAA MAR 300
//BBB DDD 400
//AAA DDD 400
//DDD AAA 100
//CCC MAR 400
//DDD CCC 200
//DDD MAR 300
//Sample Output:
//700

/*
在树上之字形

假设二叉树中的所有键都是不同的正整数。
唯一的二叉树可以由给定的一对后序和中序遍历序列来确定。
按级别顺序打印数字是一个简单的标准例程。
但是，如果你认为问题太简单，那你就太天真了。
这一次，您应该以 “之字形顺序” 打印数字 -- 即从根开始，逐级打印数字，在左到右和从右到左之间交替。
例如，对于以下树，您必须输出：1 11 5 8 17 12 20 15。

https://images.ptausercontent.com/337cbfb0-a7b2-4500-9664-318e9ffc870e.jpg

输入规格：
每个输入文件都包含一个测试用例。
对于每种情况，第一行给出一个正整数 N （≤30），即二叉树中的节点总数。
第二行给出中序序列，第三行给出后序序列。
一行中的所有数字都用空格分隔。

输出规格：
对于每个测试用例，将树的 之字形 序列打印成一行。
一行中的所有数字必须用一个空格分隔，并且行尾不能有多余的空格。

示例输入：
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
示例输出：
1 11 5 8 17 12 20 15
*

#include<iostream>
#include<stack>
using namespace std;
#define N 35
struct tree
{
    int num;
    tree* left = NULL;
    tree* right = NULL;
};
void dg(tree*& p, int n[], int m[], int a, int b, int c, int d)
{
    if (a > b)return;
    p = new tree;
    p->num = m[d];
    if (a == b)return;
    int x, y;
    for (int i = a; i <= b; i++)if (n[i] == m[d]) { x = i; break; }
    y = x - a;
    dg(p->left, n, m, a, x - 1, c, c + y - 1);
    dg(p->right, n, m, x + 1, b, c + y, d - 1);
}

int main()
{
    int n[N], m[N], k;
    stack<tree*>s[2];
    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> n[i];
    for (int i = 1; i <= k; i++)
        cin >> m[i];
    tree* T, * p, * q[2];
    dg(T, n, m, 1, k, 1, k);
    s[0].push(T);
    int a = 0, b = 1, h;
    bool u = 0;
    while (!s[0].empty() || !s[1].empty())
    {
        p = s[a].top();
        s[a].pop();
        q[0] = p->left;
        q[1] = p->right;
        if (u)cout << " ";
        cout << p->num;
        u = 1;
        if (q[b])s[b].push(q[b]);
        if (q[a])s[b].push(q[a]);
        delete p;
        if (s[a].empty())h = a, a = b, b = h;
    }

    return 0;
}
*/

/*(8)计算物体自由下落的距离

//一个物体从100米的高空自由落下。编写程序，求它在前3秒内下落的垂直距离。
//设重力加速度为10米/秒^2。
//
//输入格式:
//本题目没有输入。
//
//输出格式:
//按照下列格式输出
//
//height = 垂直距离值
//结果保留2位小数。

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float h,g=10,t=3;
    h=0.5*g*t*t;
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout<<"height = "<<h<<endl;

    return 0;
}
*/

/*(9)求奇数分之一序列前N项和

//本题要求编写程序，计算序列 1 + 1/3 + 1/5 + ... 的前N项之和。
//
//输入格式:
//输入在一行中给出一个正整数N。
//
//输出格式:
// 在一行中按照“sum = S”的格式输出部分和的值S，精确到小数点后6位。
//题目保证计算结果不超过双精度范围。
//
//输入样例:
//23
//输出样例:
//sum = 2.549541

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    double sum;
    cin>>n;
    for(int i=1;i<=n;i++)
        sum+=1.0/(2*i-1);
    cout<<setiosflags(ios::fixed)<<setprecision(6);
    cout<<"sum = "<<sum<<endl;

    return 0;
}
*/

//监控
//
//某国的安全部门监控了全国的数据流，该部门的程序员接到一个任务，恐怖组织会给手下发送一个数字序列A，其中由n个正整数组成，
//而其中任何两个值Ai和Aj都可以求它们的余数 x=Ai mod Aj ，（其中1<=i,j<=n，Ai>= Aj）。
//
//所有x中，最大的x就是破译机密的秘钥。程序员的任务就是找到这个最大的x。
//
//输入格式:
//第一行是一个正整数n，第二行由n个小于等于10
//6
// 的正整数组成
//1 ≤ n ≤ 2·10
//5
//
//
//输出格式:
//输出找到的最大值。
//
//输入样例:
//3
//1 3 10
//
//输出样例:
//1

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    //sync_with_stdio(false);
    int n, max = 0;
    cin >> n;
    vector<int>m(n);
    for (int i = 0; i < n; i++)
        cin >> m[i];
    sort(m.begin(), m.end());
    for (int i = n - 1; m[i] > 1; i--)
        for (int j = i - 1; m[j] > 1; j--)
            if (max < m[i] % m[j])
                max = m[i] % m[j];
    cout << max << endl;

    return 0;
}
