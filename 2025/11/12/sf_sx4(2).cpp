/*
第1关：找到出现次数最多的数

任务描述
本关任务：给定 n 个正整数，编写一个实验程序找出它们中出现次数最多的数。如果这样的数有多个，输出其中最小的一个。

编程要求
请在右侧编辑器Begin-End处补充代码，完成本关任务。

测试说明
平台会对你编写的代码进行测试，比对你输出的数值与实际正确数值，只有所有数据全部计算正确才能通过测试：

测试输入：

6     //给定6（n）个正整数
10    //此行及以下为具体的每个数据
1
10
20
30
20
预期输出：出现次数最多的且最小的数为：10

开始你的任务吧，祝你成功！
*/
#include <stdio.h>
using namespace std;
#include<algorithm>

/**********  Begin  **********/

int main()
{
    int n;
    if (scanf("%d", &n) != 1) return 0;

    const int MAXV = 100000;
    static int cnt[MAXV + 1] = { 0 };

    int bestNum = 0, bestCnt = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
        if (cnt[x] > bestCnt ||
            (cnt[x] == bestCnt && x < bestNum)) {
            bestCnt = cnt[x];
            bestNum = x;
        }
    }

    printf("出现次数最多的且最小的数为：%d\n", bestNum);

    return 0;
}
/**********  End  **********/
