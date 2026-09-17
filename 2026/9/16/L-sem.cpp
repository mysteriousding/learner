/*
高半音

问题描述
在音乐中，我们常常使用 “do re mi fa sol la si” 来表示音符，它们分别对应着 C、D、E、F、G、A、B 这七个音名。
其中，除了 EF 和 BC 之间是半音之外，其他相邻的两个音符之间都是全音。

为了表达比某个音高半音的音，我们会在该音名的后面加上 “#” 符号，例如比 C 高半音的音记作 C#，比 D 高半音的音记作 D#，比 F 高半音的音记作 F#，比 G 高半音的音记作 G#，比 A 高半音的音记作 A#。 
由于 EF 之间是半音，因此 E 的升音就是 F；
同样地，由于 BC 之间是半音，因此 B 的升音就是 C。

现在，给定一个音名 S，请你回答比 S 高半音的音名是什么。

输入格式
输入一个字符 S，由大写字母 C、D、E、F、G、A、B 之一组成。

输出格式
输出比 S 高半音的音名。

样例输入
C

样例输出
C#
*/
#include <iostream>
using namespace std;
int main()
{
    char c;
    cin >> c;
    if (c == 'B')
        cout << 'C' << endl;
    else if (c == 'E')
        cout << 'F' << endl;
    else cout << c << '#' << endl;

    return 0;
}
