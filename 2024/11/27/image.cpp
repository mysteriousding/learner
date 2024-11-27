#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
	initgraph(860,860);                     ///数字:界面大小（不可省略）
	//定义变量：
	IMAGE img;

	//赋值：
	loadimage(&img, "爱心.png",860,860);    ///数字:图片比例大小 （可省略，默认正常）    //绝对路径: "C:\\Users\\lenovo\\Pictures\\7865.png_860.png"  

	//输出：
	putimage(0,0,&img);                     ///数字:图片左上角坐标（不可省略）

	//卡屏
	system("pause");      //或者： getchar();

	return 0;
}
