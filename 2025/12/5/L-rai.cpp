/*
金字塔

题目描述
本题为代码补全填空题，请将题目中给出的源代码补全，并复制到右侧代码框中，选择对应的编译语言（C/Java）后进行提交。
若题目中给出的源代码语言不唯一，则只需选择其一进行补全提交即可。
复制后需将源代码中填空部分的下划线删掉，填上你的答案。
提交后若未能通过，除考虑填空部分出错外，还需注意是否因在复制后有改动非填空部分产生错误。

下面代码的目标是输出一个大写字母组成的金字塔。 
其中 space 表示金字塔底距离左边的空白长度，x 表示金字塔底的中心字母。 
比如： space=0,x=′C′ ，则输出：

  A
 ABA
ABCBA

再如： space=2,x=′E′ , 则输出：

    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA

请分析该段代码的逻辑，填写缺少的部分。

源代码
C

#include <stdio.h>
#include <stdlib.h>
void h(int space, char x)
{
    int i;
    if(x<'A' || x>'Z') return;
    _______________;
    for(i=0; i<space; i++) printf(" ");
    for(i=0; i<x-'A'; i++) printf("%c",'A'+i);
    for(i=0; i<=x-'A'; i++) printf("%c",______);
    printf("\n");
}
int main(int argc, char* argv[])
{

    h(6,'E');
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
void h(int space, char x)
{
    int i;
    if (x < 'A' || x>'Z') return;
    h(space + 1, x - 1);
    for (i = 0; i < space; i++) printf(" ");
    for (i = 0; i < x - 'A'; i++) printf("%c", 'A' + i);
    for (i = 0; i <= x - 'A'; i++) printf("%c", x - i);
    printf("\n");
}
int main(int argc, char* argv[])
{

    h(6, 'E');
    return 0;

}




