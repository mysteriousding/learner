#include<iostream>
using namespace std;
#define PRICE 30   
//预处理指令，不用加分号  
//“#define 宏名 字符串”形式，例如：#define PI 3.14159   
int main()
{
	int num, total;
	num = 10;
	total = num * PRICE;
	cout << "total=" << total << endl;

	return 0;
}