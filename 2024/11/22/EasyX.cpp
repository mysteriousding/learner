#include<iostream>
//#include<EasyX.h>       //这个不清楚
//#include<easyx.h>       //这个是只包含最新的API（函数）
#include<graphics.h>      //这个头文件包含了＜easyx.h＞还包含了已经不推荐使用了的函数

using namespace std;

void drawShape()
{
	//绘制一个点
	putpixel(50, 50, RED);

	//绘制一条线
	setlinecolor(RED);                         //设置线条颜色
	//setlinestyle(PS_SOLID, 3);               //设置线条的样式(好像是以下所有线)      还有多种
  //line(0, 0, 640, 480);                      //绘制线   (x1,y1) --> (x2,y2)
	line(0, 0, getwidth(), getheight());       // 'getwidth()' :获取窗口的宽度   'getheight()':获取窗口的高度

	//绘制一个矩形
	rectangle(100, 0, 150, 50);                //绘矩形   (x1,y1) --> (x2,y2)    框        //无填充矩形
	setfillcolor(YELLOW);                      //设置填充颜色(以下所有图形.包括圆形等!)
	fillrectangle(100, 50, 150, 100);          //填充矩形   默认白色
	solidrectangle(100, 100, 150, 150);        //无边框填充矩形

	roundrect(160, 0, 210, 50, 10, 10);        //绘制圆角矩形    后两个参数是四个角圆的宽带和高度
	fillroundrect(160, 50, 210, 100, 10, 10);  //填充圆角矩形
	solidroundrect(160, 100, 210, 150, 10, 10);//无边框填充圆角矩形

	//绘制一个圆形
	circle(50, 50, 50);                        //绘制圆形   圆点(x1,y1)     半径:R
	fillcircle(50, 150, 50);                   //填充圆形
	solidcircle(50, 250, 50);                  //无边框填充圆形

	//绘制一个椭圆
	ellipse(250, 0, 300, 100);                 //绘制椭圆   (x1,y1) --> (x2,y2)    框里绘制一个最大椭圆
	fillellipse(250, 100, 300, 200);           //填充椭圆
	solidellipse(250, 200, 300, 300);          //无边框填充椭圆

	//绘制折线条
	POINT points[] = { {100,300},{180,270},{270,432},{400,470} };
	polyline(points, 4);                       //传递坐标数组名，和坐标个数
	
	//还有很多种绘制，转到定义查看
}


int main()
{
	//创建一个图形窗口 宽度*高度
	initgraph(640, 480, EX_NOCLOSE | EX_NOMINIMIZE);

	//设置窗口的背景颜色
	//setbkcolor(RGB(255, 234, 254));

	//用设置的背景颜色填充整个窗口
	//cleardevice();

	//窗口的坐标体系: 窗口左上角是坐标原点，X轴向右增大，Y轴向下增大

	drawShape();


	//防止程序退出
	getchar();

	return 0;
}
