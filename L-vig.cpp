/*
igenère 密码

题目描述
16 世纪法国外交家 Blaise de Vigenère 设计了一种多表密码加密算法------Vigenère 密码。
Vigenère 密码的加密解密算法简单易用，且破译难度比较高，曾在美国南北战争中为南军所广泛使用。

在密码学中，我们称需要加密的信息为明文，用 M 表示；
称加密后的信息为密文，用 C 表示；
而密钥是一种参数，是将明文转换为密文或将密文转换为明文的算法中输入的数据，记为 k。 
在 Vigenère 密码中，密钥 k 是一个字母串，k=k1 ,k2​ ,⋯kn 。
当明文 M=m1​ ,m2 ... mn 时， 得到的密文 C=c1 ,c2 ,...cn ，其中ci = mi ® ki ，运算 ® 的规则如下表所示：

https://doc.shiyanlou.com/courses/uid1580206-20210202-1612256464571

Vigenère 加密在操作时需要注意：

1.® 运算忽略参与运算的字母的大小写，并保持字母在明文 M 中的大小写形式；
2.当明文 M 的长度大于密钥 k 的长度时，将密钥 k 重复使用。
例如，明文 M=Helloworld，密钥 k=abc 时，密文 C=Hfnlpyosnd。

https://doc.shiyanlou.com/courses/uid1580206-20210202-1612256589713

输入描述
输入共 2 行。

第一行为一个字符串，表示密钥 k，长度不超过 100，其中仅包含大小写字母。

第二行为一个字符串，表示经加密后的密文，长度不超过 1000，其中仅包含大小写字母。

输出描述
输出共 1 行，一个字符串，表示输入密钥和密文所对应的明文。

输入输出样例
示例

输入
CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm

输出
Wherethereisawillthereisaway
*/
#include <iostream>
using namespace std;
int main()
{
	// 请在此输入您的代码
	return 0;
}
