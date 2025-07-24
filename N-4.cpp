/*
//BM42 用两个栈实现队列
//
//描述
//用两个栈来实现一个队列，使用n个元素来完成 n 次在队列尾部插入整数(push)和n次在队列头部删除整数(pop)的功能。
//队列中的元素为int类型。保证操作合法，即保证pop操作时队列内已有元素。
//
//数据范围：n≤1000
//要求：存储n个元素的空间复杂度为 O(n) ，插入与删除的时间复杂度都是 O(1)
//示例1
//输入：
//["PSH1","PSH2","POP","POP"]
//
//返回值：
//1,2
//
//说明：
//"PSH1":代表将1插入队列尾部
//"PSH2":代表将2插入队列尾部
//"POP“:代表删除一个元素，先进先出=>返回1
//"POP“:代表删除一个元素，先进先出=>返回2
//
//
//示例2
//输入：
//["PSH2","POP","PSH1","POP"]
//
//返回值：
//2,1

class Solution {
  public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int node = stack2.top();
        stack2.pop();
        return node;
    }

  private:
    stack<int> stack1;
    stack<int> stack2;
};
*/

/*
//BM43 包含min函数的栈
//
//描述
//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的 min 函数，输入操作时保证 pop、top 和 min 函数操作时，栈中一定有元素。
//
//此栈包含的方法有：
//push(value):将value压入栈中
//pop():弹出栈顶元素
//top():获取栈顶元素
//min():获取栈中最小元素
//
//数据范围：操作数量满足 0≤n≤300  ，输入的元素满足 ∣val∣≤10000
//进阶：栈的各个操作的时间复杂度是 O(1)  ，空间复杂度是 O(n)
//
//示例:
//输入:    ["PSH-1","PSH2","MIN","TOP","POP","PSH1","TOP","MIN"]
//输出:    -1,2,1,-1
//解析:
//"PSH-1"表示将-1压入栈中，栈中元素为-1
//"PSH2"表示将2压入栈中，栈中元素为2，-1
//“MIN”表示获取此时栈中最小元素==>返回-1
//"TOP"表示获取栈顶元素==>返回2
//"POP"表示弹出栈顶元素，弹出2，栈中元素为-1
//"PSH1"表示将1压入栈中，栈中元素为1，-1
//"TOP"表示获取栈顶元素==>返回1
//“MIN”表示获取此时栈中最小元素==>返回-1
//
//示例1
//输入：
// ["PSH-1","PSH2","MIN","TOP","POP","PSH1","TOP","MIN"]
//
//返回值：
//-1,2,1,-1

class Solution {
  public:
    //用于栈的push 与 pop
    stack<int> s1;
    //用于存储最小min
    stack<int> s2;
    void push(int value) {
        s1.push(value);
        //空或者新元素较小，则入栈
        if (s2.empty() || s2.top() > value)
            s2.push(value);
        else
            //重复加入栈顶
            s2.push(s2.top());
    }
    void pop() {
        s1.pop();
        s2.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
};
*/