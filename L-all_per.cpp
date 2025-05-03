/*
全排列

题目描述
本题为代码补全填空题，请将题目中给出的源代码补全，并复制到右侧代码框中，选择对应的编译语言（C/Java）后进行提交。若题目中给出的源代码语言不唯一，则只需选择其一进行补全提交即可。复制后需将源代码中填空部分的下划线删掉，填上你的答案。提交后若未能通过，除考虑填空部分出错外，还需注意是否因在复制后有改动非填空部分产生错误。

对于某个串，比如：“1234”，求它的所有全排列。 并且要求这些全排列一定要按照字母的升序排列。

对于“1234”，应该输出(一共4!=24行)：

1234
1243
1324
1342
1423
1432
2134
2143
2314
2341
2413
2431
3124
3142
3214
3241
3412
3421
4123
4132
4213
4231
4312
4321
copy
下面是实现程序，请仔细分析程序逻辑，并填写划线部分缺少的代码。

源代码
C

#include <stdio.h>
#include <string.h>

//轮换前n个，再递归处理
void permu(char* data, int cur)
{
    int i,j;

    if(data[cur]=='\0'){
        printf("%s\n", data);
        return;
    }

    for(i=cur; data[i]; i++){
        char tmp = data[i];
        for(j=i-1; j>=cur; j--) data[j+1] = data[j];
        data[cur] = tmp;

        permu(data, cur+1);

        tmp = data[cur];
        ___________________________________ ;  //填空
        data[i] = tmp;
    }
}

int main()
{
    char a[105];
    scanf("%s",a);
    permu(a,0);
    return 0;
}
*/
#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    return 0;
}