/*(1)特殊a串数列求和

//给定两个均不超过9的正整数a和n，要求编写程序求a+aa+aaa+⋯+aa⋯a（n个a）之和。
//
//输入格式：
//输入在一行中给出不超过9的正整数a和n。
//
//输出格式：
//在一行中按照“s = 对应的和”的格式输出。
//
//输入样例：
//2 3
//输出样例：
//s = 246

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,n,m=0;
    cin>>a>>n;
    for(int i=0;i<n;i++)
        m+=(n-i)*a*pow(10,i);
    cout<<"s = "<<m<<endl;

    return 0;
}
*/

/*(2)帅到没朋友

//当芸芸众生忙着在朋友圈中发照片的时候，总有一些人因为太帅而没有朋友。本题就要求你找出那些帅到没有朋友的人。
//
//输入格式：
//输入第一行给出一个正整数N（≤100），是已知朋友圈的个数；
//随后N行，每行首先给出一个正整数K（≤1000），为朋友圈中的人数，然后列出一个朋友圈内的所有人
//——为方便起见，每人对应一个ID号，为5位数字（从00000到99999），ID间以空格分隔；
//之后给出一个正整数M（≤10000），为待查询的人数；随后一行中列出M个待查询的ID，以空格分隔。
//
//注意：没有朋友的人可以是根本没安装“朋友圈”，也可以是只有自己一个人在朋友圈的人。
//虽然有个别自恋狂会自己把自己反复加进朋友圈，但题目保证所有K超过1的朋友圈里都至少有2个不同的人。
//
//输出格式：
//按输入的顺序输出那些帅到没朋友的人。ID间用1个空格分隔，行的首尾不得有多余空格。如果没有人太帅，则输出No one is handsome。
//
//注意：同一个人可以被查询多次，但只输出一次。
//
//输入样例1：
//3
//3 11111 22222 55555
//2 33333 44444
//4 55555 66666 99999 77777
//8
//55555 44444 10000 88888 22222 11111 23333 88888
//输出样例1：
//10000 88888 23333
//输入样例2：
//3
//3 11111 22222 55555
//2 33333 44444
//4 55555 66666 99999 77777
//4
//55555 44444 22222 11111
//输出样例2：
//No one is handsome

// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;
// int main()
// {
//     int n,k,m;
//     bool u=0,v;
//     string s;
//     vector<string>N,M;
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         cin>>k;
//         cin.ignore();
//         for(int j=0;j<k;j++)
//         {
//             cin>>s;
//             N.push_back(s);
//         }
//     }
//     cin>>m;
//      for(int i=0;i<m;i++)
//      {
//          v=1;
//          cin>>s;
//          for(int l=0;l<M.size();l++)
//                  if(s==M[l])
//                  {
//                      v=0;
//                      break;
//                  }
//          if(v)
//            for(int j=0;j<N.size();j++)
//                 if(s==N[j])
//                 {
//                     v=0;
//                     break;
//                 }
//          if(v)
//          {
//              if(u)cout<<" ";
//              cout<<s;
//              M.push_back(s);
//              u=1;
//          }
//     }
//     if(!u)cout<<"No one is handsome";
//     cout<<endl;
//
//     return 0;
// }



#include<iostream>
#include<iomanip>
using namespace std;
int arr[100000]={0};
int main()
{
    int n,k,m,num;
    bool u=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        for(int j=0;j<k;j++)
        {
            cin>>num;
            if(k>1)arr[num]=2;
        }
    }
    cin>>m;
    cout<<setfill('0');
    for(int i=0;i<m;i++)
    {
        cin>>num;
        if(arr[num]<=1)
        {
            if(u)cout<<" ";
            cout<<setw(5)<<num;
            arr[num]=2;
            u=1;
        }
    }
     if(!u)cout<<"No one is handsome";
     cout<<endl;

    return 0;
}
*/

/*(3)Shuffling Machine

//Shuffling is a procedure used to randomize a deck of playing cards.  
//Because standard shuffling techniques are seen as weak, and in order to avoid "inside jobs" where employees collaborate with gamblers by performing inadequate shuffles, many casinos employ automatic shuffling machines.  
//Your task is to simulate a shuffling machine.
//
//The machine shuffles a deck of 54 cards according to a given random order and repeats for a given number of times. 
//It is assumed that the initial status of a card deck is in the following order:
//
//S1, S2, ..., S13,
//H1, H2, ..., H13,
//C1, C2, ..., C13,
//D1, D2, ..., D13,
//J1, J2
//where "S" stands for "Spade", "H" for "Heart", "C" for "Club", "D" for "Diamond", and "J" for "Joker".
//A given order is a permutation of distinct integers in [1, 54].
//If the number at the i-th position is j, it means to move the card from position i to position j. 
//For example, suppose we only have 5 cards: S3, H5, C1, D13 and J2.  
//Given a shuffling order {4, 2, 5, 3, 1}, the result will be: J2, H5, D13, S3, C1. 
//If we are to repeat the shuffling again, the result will be: C1, H5, S3, J2, D13.
//
//Input Specification:
//Each input file contains one test case.  
//For each case, the first line contains a positive integer K (≤20) which is the number of repeat times.
//Then the next line contains the given order.  All the numbers in a line are separated by a space.
//
//Output Specification:
//For each test case, print the shuffling results in one line. 
//All the cards are separated by a space, and there must be no extra space at the end of the line.
//
//Sample Input:
//2
//36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
//Sample Output:
//S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5

/*(3)洗牌机

洗牌是一种用于随机化一副扑克牌的程序。 由于标准的洗牌技术被视为薄弱，
并且为了避免员工通过执行不适当的洗牌来与赌徒合作的“内部工作”，许多赌场使用自动洗牌机。
您的任务是模拟洗牌机。

机器根据给定的随机顺序洗牌 54 张牌，并重复给定的次数。
假设卡牌组的初始状态按以下顺序排列：
S1， S2， ...， S13，
H1， H2， ...， H13，
C1， C2， ...， C13，
D1， D2， ...， D13，
J1、J2
其中“S”代表“黑桃”，“H”代表“红桃”，“C”代表“梅花”，“D”代表“方块”，“J”代表“小丑”。
给定的顺序是 [1， 54] 中不同整数的排列。
如果第 i 个位置的数字是 j，则表示将卡片从位置 i 移动到位置 j。
例如，假设我们只有 5 张牌：S3、H5、C1、D13 和 J2。
给定一个洗牌顺序 {4， 2， 5， 3， 1}，
结果将是：J2， H5， D13， S3， C1。 如果我们要再次重复洗牌，
结果将是：C1、H5、S3、J2、D13。

输入规格：
每个输入文件都包含一个测试用例。
对于每种情况，第一行都包含一个正整数 K （≤20），即重复次数。
然后下一行包含给定的 order。 一行中的所有数字都用空格分隔。

输出规格：
对于每个测试用例，将随机排序结果打印在一行中。
所有卡片都用空格分隔，并且行尾不能有多余的空格。
*

#include<iostream>
using namespace std;
int main()
{
    int n, m[55], b[2][55], p = 0, q = 1, h;
    char e[5] = { 'S','H','C','D','J' };
    cin >> n;
    for (int i = 1; i <= 54; i++)cin >> m[i];
    for (int i = 1; i <= 54; i++)b[0][i] = i;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 54; j++)
            b[q][m[j]] = b[p][j];
        h = q, q = p, p = h;
    }
    for (int i = 1; i <= 54; i++)
    {
        if (i != 1)cout << " ";
        cout << e[(b[p][i] - 1) / 13] << (b[p][i] - 1) % 13 + 1;
    }
    cout << endl;

    return 0;
}
*/

/*(4)20056 求两个矩阵的乘积

//输入三个正整数m，l，n(0<m，n，l<10)，再输入两个的矩阵a（mxl）和b（lxn）。
//要求把a和b矩阵的乘积放入到矩阵c，并把矩阵c按矩阵形式输出。
//
//输入格式:
//第一行输入三个正整数m，l，n；第二行输入矩阵a（mxl）；第三行输入矩阵b（lxn）。
//
//输出格式:
//矩阵c，每一行最后无空格。
//
//输入样例:
//2 3 2
//2 4 6
//5 6 7
//3 4
//1 2
//6 7
//输出样例:
//46 58
//63 81

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int m,l,n;
    cin>>m>>l>>n;
    vector<vector<int>>a(m,vector<int>(l));
    vector<vector<int>>b(l,vector<int>(n));
    vector<vector<int>>c(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
        for(int j=0;j<l;j++)
            cin>>a[i][j];
    for(int i=0;i<l;i++)
        for(int j=0;j<n;j++)
            cin>>b[i][j];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<l;k++)
                c[i][j]+=a[i][k]*b[k][j];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j)cout<<" ";
            cout<<c[i][j];
        }
        cout<<endl;
    }

    return 0;
}
*/

//字母搬运工
//
//寒假过得过快，Mr.xiao发现自己还没怎么动过脑就过完了，就想要给快要生锈的脑袋补一补，于是设计了一个智力游戏《字母搬运工》，
// 游戏规则如下：
// 给你两个单词，两个单词里面所包含字母都相同，
// 对第一个单词进行搬运工作，一次操作就表示将单词里的某一个字母进行搬运(具体见提示)，
// 问至少需要多少次操作才能将第一个单词转换成第二个单词。
//
//输入格式:
//输入有多组，每一行有两个单词(每个单词长度不超过100，且只包含小写字母，且两个单词的字母组成相同，只是相对位置不同)，中间用空格隔开。
//
//输出格式:
//对每一组数据输出从第一个单词搬运到第二个单词最少的操作次数。
//
//输入样例:
//在这里给出一组输入。例如：
//
//ecabd abcde
//aba aab
//输出样例:
//在这里给出相应的输出。例如：
//
//2
//1
//提示
//
//ecabd abcde
//搬运的方法:
//ecabd -> cabde -> abcde
//第一次操作将e字母搬运到最后
//第二次操作将c字母搬运到b和d之间
//因此这里进行了两次操作，实际上这两个单词的最少操作也是两次

#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    string n, m;
    int i, j, k, f, l, sum, max;
    while (cin >> n >> m)
    {
        l = m.size();
        f = max = 0;
        while (f < l)
        {
            i = f;
            k = sum = 0;
            while (i < l)
            {
                j = k;
                while (j < l)
                    if (m[i] == n[j])
                    {
                        sum++, k = j + 1;
                        break;
                    }
                    else j++;
                i++;
            }
            f++;
            if (max < sum)max = sum;
        }

        f = l - 1;
        while (f >= 0)
        {
            i = f;
            k = l - 1, sum = 0;
            while (i >= 0)
            {
                j = k;
                while (j >= 0)
                    if (m[i] == n[j])
                    {
                        sum++, k = j - 1;
                        break;
                    }
                    else j--;
                i--;
            }
            f--;
            if (max < sum)max = sum;
        }

        cout << l - max << endl;
    }

    return 0;
}
/*漏洞
asjkdhakajdaqhashakdakadasd  hjdaqdakdajkaskasaadsdhahka
aasdfghjkldgh aghfghjkasdld
aasdghjkldgh aghghjkasdld
aasghjkldgh aghghjkasdl
aasghjkdgh aghghjkasd
aasgjkdgh agghjkasd
aasgjkdg aggjkasd
asgjkdg aggjksd
asgjdg aggjsd
*/



// #include <iostream>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// const int MAX_LEN = 101;
// char a[MAX_LEN], b[MAX_LEN];
// int dp[MAX_LEN][MAX_LEN];
//
// int main() {
//     while(cin >> a >> b) {
//         memset(dp, 0, sizeof(dp));
//         int len = strlen(b);
//        
//         for(int i = 1; i <= len; i++) {
//             for(int j = 1; j <= len; j++) {
//                 if(a[i-1] == b[j-1])
//                     dp[i][j] = dp[i-1][j-1] + 1;
//                 else
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//         cout << len-dp[len][len] << endl;
//     }
//     return 0;
// }





// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
// // 用于从正向或反向获取最长子序列
// string getSubsequence(const string& n, const string& m, int& max, bool forward) {
//     int l = m.size();
//     int f = forward? 0 : l - 1;
//     int step = forward? 1 : -1;
//     string longestSubseq;
//     while (forward? f < l : f >= 0) {
//         int i = f;
//         int k = forward? 0 : n.size() - 1;
//         int sum = 0;
//         string currentSubseq;
//         while (forward? i < l : i >= 0) {
//             int j = k;
//             while (forward? j < n.size() : j >= 0) {
//                 if (m[i] == n[j]) {
//                     currentSubseq += m[i];
//                     sum++;
//                     k = forward? j + 1 : j - 1;
//                     break;
//                 }
//                 forward? j++ : j--;
//             }
//             forward? i++ : i--;
//         }
//         if (sum > max) {
//             max = sum;
//             longestSubseq = currentSubseq;
//         }
//         f += step;
//     }
//     if (!forward) {
//         reverse(longestSubseq.begin(), longestSubseq.end());
//     }
//     return longestSubseq;
// }
// int main() {
//     string n, m;
//     while (cin >> n >> m) {
//         int f, max;
//         f = max = 0;
//         string forwardSubseq = getSubsequence(n, m, max, true);
//         string reverseSubseq = getSubsequence(n, m, max, false);
//         string longestSubseq = forwardSubseq.size() > reverseSubseq.size()? forwardSubseq : reverseSubseq;
//         cout << "最长子序列: " << longestSubseq << endl;
//     }
//     return 0;
// }



// #include <iostream>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// const int MAX_LEN = 101;
// char a[MAX_LEN], b[MAX_LEN];
// int dp[MAX_LEN][MAX_LEN];
// // 通过回溯dp数组获取最长子序列
// string getLongestSubsequence() {
//     int len = strlen(b);
//     int i = len, j = len;
//     string subseq;
//     while (i > 0 && j > 0) {
//         if (a[i - 1] == b[j - 1]) {
//             subseq = a[i - 1] + subseq;
//             i--;
//             j--;
//         }
//         else if (dp[i - 1][j] > dp[i][j - 1]) {
//             i--;
//         }
//         else {
//             j--;
//         }
//     }
//     return subseq;
// }
// int main() {
//     while (cin >> a >> b) {
//         memset(dp, 0, sizeof(dp));
//         int len = strlen(b);
//         
//         for (int i = 1; i <= len; i++) {
//             for (int j = 1; j <= len; j++) {
//                 if (a[i - 1] == b[j - 1])
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                 else
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//         string longestSubseq = getLongestSubsequence();
//         cout << "最长子序列: " << longestSubseq << endl;
//     }
//     return 0;
// }
