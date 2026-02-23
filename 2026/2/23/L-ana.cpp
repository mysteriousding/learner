/*
反转串

题目描述
本题为代码补全填空题，请将题目中给出的源代码补全，并复制到右侧代码框中，选择对应的编译语言（C/Java）后进行提交。
若题目中给出的源代码语言不唯一，则只需选择其一进行补全提交即可。
复制后需将源代码中填空部分的下划线删掉，填上你的答案。
提交后若未能通过，除考虑填空部分出错外，还需注意是否因在复制后有改动非填空部分产生错误。

我们把“cba”称为“abc”的反转串。

下面的代码可以把buf中的字符反转。
其中 n 表示buf中待反转的串的长度。
请补充缺少的代码。

源代码
C

#include <stdio.h>
#include <stdlib.h>
void reverse_str(char* buf, int n)
{
    if(n<2) return;
    char tmp = buf[0];
    buf[0] = buf[n-1];
    buf[n-1] = tmp;
    ___________________;   // 填空
}


int main(int argc, char* argv[])
{
    char x[] = "1234567";
    reverse_str(x, 7);
    printf("%s\n", x);

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
void reverse_str(char* buf, int n)
{
    if (n < 2) return;
    char tmp = buf[0];
    buf[0] = buf[n - 1];
    buf[n - 1] = tmp;
    reverse_str(buf + 1, n - 2);   // 填空
}


int main(int argc, char* argv[])
{
    char x[] = "1234567";
    reverse_str(x, 7);
    printf("%s\n", x);

    return 0;
}
