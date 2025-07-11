/*
单选题

题目描述
有1、2、3、4共四道很难的单选题，每道题有A、B、C、D四个选项，每道题只有一个选项是正确答案。
现在让甲、乙、丙、丁四个学生来答题，每人选择答两道题。

甲：第1题的答案是B、第4题的答案是C。

乙：第2题的答案是B、第4题的答案是A。

丙：第1题的答案是A、第3题的答案是A。

丁：第2题的答案是D、第3题的答案是C。

现在已知四个同学都只答对了一道题，且每道题都只有一个人答对了。

请根据上述信息，确定四道单选题的答案。

输入描述
本题无输入。

输出描述
输出四道单选题的答案，用空格隔开。
如果有多组答案符合要求，则按字典序输出（有几个就输出几个），每个答案占一行。

知识点
命题的表示
命题的真值
联结词
枚举
*/
#include <iostream>
using namespace std;
int main()
{
    for (char i = 'A'; i <= 'D'; i++)
        for (char j = 'A'; j <= 'D'; j++)
            for (char k = 'A'; k <= 'D'; k++)
                for (char l = 'A'; l <= 'D'; l++)
                    if (
                        (i == 'B' && l != 'C' || i != 'B' && l == 'C') &&
                        (j == 'B' && l != 'A' || j != 'B' && l == 'A') &&
                        (i == 'A' && k != 'A' || i != 'A' && k == 'A') &&
                        (j == 'D' && k != 'C' || j != 'D' && k == 'C')
                        )
                        cout << i << " " << j << " " << k << " " << l << endl;

    return 0;
}
