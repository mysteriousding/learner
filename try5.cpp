#include<iostream>
#include<cstdio>                           //在其他编译器尽量添加头文件；
#include<stdio.h>                          //在其他编译器尽量添加头文件；
/*
int main()//printf输出函数
{
    printf("Hello \n""World! \n\n");       //两个“”之间不需要任何分隔

    int a = 10;
    printf(" %d\n", a);                    //正确
  //printf("%d", &a);                      //错误  

    printf("\n a = %d \n", a);             //%d不需要和其他输出字符分隔

    //%d  整型 
    //%u 无符号整型 
    unsigned b = 123;
    printf("\n b = %u \n", b);
    //%x十六进制整型
    int c = 15;                            //输入为任何进制
    printf("\n c = %x \n", c);             //输出转换为十六进制输出
    //%lld 长长整型 
    long long d = 1234567890987654321;
    printf("\n d = %lld \n", d);
    //%f 单精度浮点型 
    float e = 15.123456;                        
    printf("\n e = %f \n", e);
    //%lf 双精度浮点型
    double f = 15.1234567890987654321;
    printf("\n f = %lf \n", f);

    
    //%c字符型
    char g = '+';
    printf("\n g = %c \n", g);
    //%s字符串型
    char h[] = "Hello  World";
    printf("\n h = %s \n", h);
    
    

    ///精度与格式
    printf("\n\n\n");
    //浮点取精度    %.nf(例如%.3f) 和 %.nlf(例如%.13lf)
    printf("\n e.3 = %.3f \n", e);

    printf("\n f.13 = %.13lf \n", f);
    
    
    //输出格式
    int x, y, z;
    x = 10000;
    z = x % 60;
    x /= 60;
    y = x % 60;
    x /= 60;
    
    printf("\n\n%d:%d:%d\n", x, y, z);       //直接正常输出

    printf("%2d:%2d:%2d\n", x, y, z);        //输出内容站2位，相当于水平制表两位，后对齐

    printf("%-2d:%-2d:%-2d\n", x, y, z);     //前对齐

    printf("%02d:%02d:%02d\n", x, y, z);     //输出内容站2位，没有数字的位填充‘0’

    //printf("%-02d:%-02d:%-02d\n", x, y, z);//这个是错误的，前对齐好像无法填充‘0’    （‘-’在‘0’和‘2’之间也一样！）


    double X=1.23, Y=4.56, Z=7.89;

    printf("\n%7.3lf:%7.3lf:%7.3lf\n", X, Y, Z);   //当然浮点型也可以，小数点也占一位

    printf("%-7.3lf:%-7.3lf:%-7.3lf\n", X, Y, Z);

    printf("%07.3lf:%07.3lf:%07.3lf\n", X, Y, Z);


    return 0;
}
*/

/**/
int main()//scanf输入函数                 //不该输入空格，回车等（或者可以说它把每一个空格，回车等按输入的普通字符一样对待！）      *注1:
{
    int a;
    //scanf("%d", &a);       //错误          ///VS2022正常无法使用scanf函数！
    //scanf_s("%d", &a);     //正确          ///可以后加 '_s' 解决，但是在其他平台，如作业提交平台，可能报错！
    scanf("%d", &a);         //正确          ///在属性中修改了预处理命令！
    printf("%d", a);

    //%d  整型 
    //%u 无符号整型 
    unsigned b;
    scanf("%u", &b);
    printf("\n b = %u \n", b);
    //%x十六进制整型
    int c ;
    scanf("%x", &c);                       //输入为任何进制
    printf("\n c = %x \n", c);             //输出转换为十六进制输出
    //%lld 长长整型 
    long long d ;
    scanf("%lld", &d);
    printf("\n d = %lld \n", d);
    //%f 单精度浮点型 
    float e ;
    scanf("%f", &e);
    printf("\n e = %f \n", e);
    //%lf 双精度浮点型
    double f ;
    scanf("%lf", &f);
    printf("\n f = %lf \n", f);


    //%c字符型
    char g ;
    scanf("%c", &g);                      //这里同样错误，它应该读取了上一个输入结束时的'\n'     (相对后      *注1:
    printf("\n g = %c \n", g);
    //%s字符串型
    char h[100] ;                          
    //scanf("%s", &h);    //算作错        //h就是数组的首元素的首地址 ； &h是整个数组的首地址（说可能影响后面偏移，会出现问题，这里涉及一些指针的知识
    scanf("%s", h);                       //遇到空格就停止了
    printf("\n h = %s \n", h);




    
    //浮点取精度    %.nf(例如%.3f) 和 %.nlf(例如%.13lf)
    char JD;
    //看注1内容解除注释 scanf("%*1c", &JD);
    scanf("%c", &JD);                     //无法起到我认为的停顿效果，    它可能直接读取了一个 '\n'！     (相对前      *注1:
    printf("\n JD = %c \n", JD);

    
    printf("\n e.3 = %.3f \n", e);

    printf("\n f.13 = %.13lf \n", f);



    //实际遇到
    int x, y;
    //输入654321
    scanf("%2d%*3d%d", &x, &y);             //"%2d"意思是读入2位     "%*3d"意思是忽略3位
    printf("%d %d", x, y);
    
    return 0;
}
//*注1:若输入空格，回车等。可以在要读取字符、字符串的前面加"%*1c"，如130行。