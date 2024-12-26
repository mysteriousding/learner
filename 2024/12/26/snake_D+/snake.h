#pragma once
#include<windows.h>
#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<ctime>
using namespace std;

class Snake;
class Tu
{
public:
	Tu();
	void huizhi();
	void xuigai(int y, int x, int z);
private:
	char t[20][41]; 
};

class Apple
{
public:
	static bool live;

	Apple(Tu& t);
	void shengzhang(Snake* p);
	void fuhuo(Tu& t);
	void chunhui(Tu& t);
private:
	int y;
	int x;
};




class Snake
{
public:
	static bool live;
	static int longs;

	Snake(int y, int x,int z, Tu& t);
	Snake(int y, int x, Snake* head, Tu& t);
	void kunzhi(Apple& a, Tu& t);
	void chuandi(int Y, int X, Tu& t);
	void chengzhang(int Y, int X, Snake* head, Tu& t);
	friend void Apple::shengzhang(Snake* p);
	void zihui();
	void qichu();
private:
	int y;
	int x;
	Snake* next;
};
