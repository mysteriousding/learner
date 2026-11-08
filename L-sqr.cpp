/*]]][[p
开平方

题目描述
本题为代码补全填空题，请将题目中给出的源代码补全，并复制到右侧代码框中，选择对应的编译语言（C/Java）后进行提交。
若题目中给出的源代码语言不唯一，则只需选择其一进行补全提交即可。
复制后需将源代码中填空部分的下划线删掉，填上你的答案。
提交后若未能通过，除考虑填空部分出错外，还需注意是否因在复制后有改动非填空部分产生错误。

如果没有计算器，我们如何求 2 的平方根？

可以先猜测一个数，比如 1.5，然后用 2 除以这个数字。如果我们猜对了，则除法的结果必然与我们猜测的数字相同。
我们猜测的越准确，除法的结果与猜测的数字就越接近。

根据这个原理，只要我们每次取猜测数和试除反馈数的中间值作为新的猜测数，肯定更接近答案！这种计算方法叫做“迭代法”。

下面的代码模拟了如何用手工的方法求2的平方根的过程。
请填写缺少的代码。

源代码
C

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    double n = 2;
    double a = 0;
    double b = n;
    while(fabs(a-b)>1E-15)
    {
        a = (a+b)/2;
        b = __________;
    }
    printf("%f\n", a);


    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    double n = 2;
    double a = 0;
    double b = n;
    while (fabs(a - b) > 1E-15)
    {
        a = (a + b) / 2;
        b = n / a;
    }
    printf("%f\n", a);


    return 0;
}
