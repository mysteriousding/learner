#include<iostream>
#include<string>
#include<vector>
using namespace std;
//函数参数改变疑惑

/*//一、普通变量
void max1(int* x)         //地址值 -> 指针变量 ，地址值传递
{
    *x = 10;
}

void max2(int& x)         //引用 ，地址传递
{
    x = 20;
}

void max3(int* x)         //指针变量 -> 指针变量 ，地址值传递
{
    *x = 30;
}

int main() 
{
    int a=0;
    int* p = &a;

    max1(&a);
    cout << a << endl;

    max2(a);
    cout << a << endl;

    max3(p);
    cout << a << endl;


    return 0;
}
*/


/*//二、数组变量
void max1_1(int x[])         //数组名 -> 数组名 ，地址传递
{
    for (int i = 0; i < 10; i++)
        x[i] = 11;
}

void max1_2(int x[])         //数组名 -> 数组名 ，地址传递
{
    for (int i = 0; i < 10; i++)
        *(x + i) = 12;
}

void max1_3(int x[])         //数组名 -> 数组名 ，地址传递
{
    for (int i = 0; i < 10; x++, i++)
        *x = 13;
}


void max2_1(int* x)          //数组名 -> 指针变量 ，地址值传递
{
    for (int i = 0; i < 10; i++)
        x[i] = 21;
}

void max2_2(int* x)          //数组名 -> 指针变量 ，地址值传递
{
    for (int i = 0; i < 10; i++)
        *(x + i) = 22;
}

void max2_3(int* x)          //数组名 -> 指针变量 ，地址值传递
{
    for (int i = 0; i < 10; x++, i++)
        *x = 23;
}


void max3_1(int x[])         //指针变量 -> 数组名 ，地址传递
{
    for (int i = 0; i < 10; i++)
        x[i] = 31;
}

void max3_2(int x[])         //指针变量 -> 数组名 ，地址传递
{
    for (int i = 0; i < 10; i++)
        *(x + i) = 32;
}

void max3_3(int x[])         //指针变量 -> 数组名 ，地址传递
{
    for (int i = 0; i < 10; x++, i++)
        *x = 33;
}


void max4_1(int* x)          //指针变量 -> 指针变量 ，地址值传递
{
    for (int i = 0; i < 10; i++)
        x[i] = 41;
}

void max4_2(int* x)          //指针变量名 -> 指针变量 ，地址值传递
{
    for (int i = 0; i < 10; i++)
        *(x + i) = 42;
}

void max4_3(int* x)          //指针变量 -> 指针变量 ，地址值传递
{
    for (int i = 0; i < 10; x++, i++)
        *x = 43;
}

int main()
{
    int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int* p = a;

    max1_1(a);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;

    max1_2(a);
    for (int i = 0; i < 10; i++)
        cout << a[i] <<" ";
    cout << endl; 

    max1_3(a);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl << endl;

    
    max2_1(a);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;

    max2_2(a);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;

    max2_3(a);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl << endl; 


    max3_1(p);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;

    max3_2(p);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;

    max3_3(p);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl << endl;


    max4_1(a);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;

    max4_2(a);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;

    max4_3(a);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl << endl;


    return 0;
}

//int main()
//{
//    int a[10],i=4;
//    int* p = a;
//
//    a[i] = 1;
//    *(a + i) = 2;
//    p[i] = 3;
//    *(p + i) = 4;
//
//    (*a)[i] = 5;//错误！ a 为 a[0] ,是一个整形变量而不是指针变量,所以解引用是错的
//    (*p)[i] = 6;//错误！ (*p) 为 a[0] ,是一个整形变量而不是数组,所以数组操作是错的
//
//    return 0;
//}
*/


//三、向量变量
void max1(vector<int>* x)            //地址值 -> 指针变量 ，地址值传递
{
    for (int i = 0; i < 10; i++)
        //x[i] = 11;//错误！！！
        //*(x + i) = 11;//错误！！！
        (*x)[i] = 11;

    /*for (int i = 0; i < 10; x++, i++)//错误！！！
        *x = 11; */
}

void max2(vector<int>& x)            //引用 ，地址传递
{
    for (int i = 0; i < 10; i++)
        //(*x)[i] = 12;//错误！！！
        //*(x + i) = 12;//错误！！！
        x[i] = 12;  
       
    /*for (int i = 0; i < 10; x++, i++)//错误！！！
        *x = 12; */
}

void max3(vector<int>* x)            //指针变量 -> 指针变量 ，地址值传递
{
    for (int i = 0; i < 10; i++)
        //x[i] = 13;//错误！！！
        //*(x + i) = 13;//错误！！！
        (*x)[i] = 13;

    /*for (int i = 0; i < 10; x++, i++)//错误！！！
        *x = 13; */
}
   
int main()
{
    vector<int>a(10, 0);
    vector<int>* p = &a;

    max1(&a);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl << endl;

    max2(a);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl << endl;

    max3(p);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl << endl;


    return 0;
}

//int main()
//{
//    vector<int>a(10,0);
//    vector<int>* p = &a;
//
//    (*a)[i] = 5;//错误！ a 为vector<int>类型对象，而不是指针变量,所以解引用是错的
//    (*p)[i] = 6;//正确！
//
//    return 0;
//} 