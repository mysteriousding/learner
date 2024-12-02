#pragma once
#include<iostream>
#include<conio.h>
#include<ctime>
#include<windows.h>
using namespace std;

class CHANGDI
{
public:
	CHANGDI();
	void HZ(); 
	void XG(int x, int y, int z);
private:
	char N[20][41];
};

class apple
{
public:
	apple(CHANGDI& N);
	void Xapple(CHANGDI& N);
	int CXapple(int z);
	bool CXappleB();
	void CL();
	void H(CHANGDI& N);
	
private:
	int x;
	int y;
	bool live;
};

class snake
{
public:
	snake(int x, int y, snake* p, CHANGDI& N, int z);
	snake(int x, int y, snake* p);

	int CXsnake1(int z);
	snake* CXsnake2();
	bool CXsnakeL();
	void XGsnake1(int x,int z);
	void XGsnake2(snake* y);
	void XGsnakeL();

	void YD(int X, int Y, snake& head, CHANGDI& N);
	void KZ(snake& head, apple& a, CHANGDI& N, int& DF);

private:
	bool live;
	int x;
	int y;
	snake* next;
};

void Xsnake(snake& head, apple a, CHANGDI& N);

void eat(snake& head, apple& a, CHANGDI& N); 

void JIANCHE(snake& head);