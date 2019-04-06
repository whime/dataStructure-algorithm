/*定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））*/
class Solution {
private:
    stack<int> dataStack,minStack;
    int minNum=INT_MAX;
public:
    void push(int value) {
           dataStack.push(value);
           if(minNum>value)
           {
               minStack.push(value);
               minNum=value;
           }
            else    minStack.push(minNum);
    }
    void pop() {
        dataStack.pop();
        minStack.pop();
    }
    int top() {
        return dataStack.top();
    }
    int min() {
        int num=minStack.top();
        return num;    
    }
};