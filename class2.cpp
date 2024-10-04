#include<iostream>
using namespace std;
class Student
{
private:
	int num;
	int score;
public:
	void setdata()
	{
		cin >> num;
		cin >> score;
	}
	void display()
	{
		cout << "学号：" << num << endl;
		cout << "成绩：" << score << endl;
		cout << "------------" << endl;
	};
};
Student stud1, stud2;
int main()
{
	stud1.setdata();
	stud2.setdata();
	stud1.display();
	stud2.display();

	return 0;
}
