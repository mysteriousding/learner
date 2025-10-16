/*
利息计算

题目描述
本题为代码补全填空题，请将题目中给出的源代码补全，并复制到右侧代码框中，选择对应的编译语言（C/Java）后进行提交。
若题目中给出的源代码语言不唯一，则只需选择其一进行补全提交即可。
复制后需将源代码中填空部分的下划线删掉，填上你的答案。提交后若未能通过，除考虑填空部分出错外，还需注意是否因在复制后有改动非填空部分产生错误。

小李年初在银行存款 1 千元（一年定期）。他计划每年年底取出 100 元救助失学儿童。
假设银行的存款利率不变，年利率为 3%，年底利息自动计入本金。
下面的代码计算 5 年后，该账户上有多少存款。

试填写缺失的代码。

源代码
C

//#include <stdio.h>
//#include <stdlib.h>
//int main(int argc, char* argv[])
//{
//    double money = 1000;
//    int n = 5;
//    int i;
//    for(i=0; i<n; i++)
//    {
//        money = _______________;
//        money -= 100;
//    }
//    printf("%.2f\n", money);
//
//    return 0;
//}
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    double money = 1000;
    int n = 5;
    int i;
    for (i = 0; i < n; i++)
    {
        money = money * 1.03;
        money -= 100;
    }
    printf("%.2f\n", money);

    return 0;

}


