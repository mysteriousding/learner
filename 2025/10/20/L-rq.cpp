/*
日期差

题目描述
本题为代码补全填空题，请将题目中给出的源代码补全，并复制到右侧代码框中，选择对应的编译语言（C/Java）后进行提交。
若题目中给出的源代码语言不唯一，则只需选择其一进行补全提交即可。
复制后需将源代码中填空部分的下划线删掉，填上你的答案。
提交后若未能通过，除考虑填空部分出错外，还需注意是否因在复制后有改动非填空部分产生错误。

历史上，不同的人类聚居地可能有不同的历法，因而记录下来的资料中日期的换算就很麻烦。
幸好今天我们统一使用公元纪年法。当然，这种历法对求两个日期差多少天也不是十分简便，但毕竟是可以忍受的。

下面的程序计算了两个日期的差值，两个日期都使用公元纪年法。

请分析程序逻辑，并推断划线部分缺失的代码。

源代码
C

//#include <stdio.h>
//int today(int y, int m, int d)
//{
//    int mon[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//    int day = 0;
//    int i;
//    for(i=1; i<y; i++){
//        day += (i%4==0 && i%100!=0 || i%400==0)? 366 : 365;
//    }
//
//    if(y%4==0 && y%100!=0 || y%400==0) mon[2]++;
//
//    for(i=1; i<m; i++){
//        _______________;
//    }
//
//    return day + d;
//}
//
//int diff(int y1, int m1, int d1, int y2, int m2, int d2)
//{
//    int a = today(y1, m1, d1);
//    int b = today(y2, m2, d2);
//    return b-a;
//}
//
//int main()
//{
//    //int n = diff(1864,12,31,1865,1,1);
//    int n = diff(1864,12,31,2012,3,18);
//    printf("%d\n", n);
//    return 0;
//}
*/
#include <stdio.h>
int today(int y, int m, int d)
{
    int mon[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int day = 0;
    int i;
    for (i = 1; i < y; i++) {
        day += (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) ? 366 : 365;
    }

    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) mon[2]++;

    for (i = 1; i < m; i++) {
        day += mon[i];
    }

    return day + d;
}

int diff(int y1, int m1, int d1, int y2, int m2, int d2)
{
    int a = today(y1, m1, d1);
    int b = today(y2, m2, d2);
    return b - a;
}

int main()
{
    //int n = diff(1864,12,31,1865,1,1);
    int n = diff(1864, 12, 31, 2012, 3, 18);
    printf("%d\n", n);
    return 0;

}




