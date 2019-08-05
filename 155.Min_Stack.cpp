/* 
 * 155. Min Stack
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 */

#include <stack>
#include <queue>
#include <iostream>

class MinStack {
public:
    std::stack<int> s;
    std::stack<int> min;

    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) 
    {
        //std::cout << "Push - min: " << min.top() <<  ", x: " << x << std::endl;
        if (!min.empty() && min.top() < x)
        {
            //std::cout << "min: " << min.top() <<  ", x: " << x << std::endl;
            min.push(min.top());
        }
        else
        {
            min.push(x);
        }
        s.push(x);
    }
    
    void pop() 
    {
        min.pop();
        s.pop();
    }
    
    int top() 
    {
        if (!s.empty())
        {
            return s.top();
        }
        else
        {
            return -1;
        }
    }
    
    int getMin() 
    {
        if (!min.empty())
            return min.top();
        else
            return -1;
    }

    int printstack()
    {
        int size = s.size();
        int slen = s.size();
        std::cout << "Size: " << size << " , Min:"  << getMin() << std::endl;
        if (size <= 0)
        {
            return 0;
        }
        slen = size;
        while (slen -- > 0)
        {
            //std::cout << s1.top();
            int x = s.top();
            min.push(x);
            s.pop();
        }
        slen = size;

        std::cout << " ";
        while (slen    -- > 0)
        {
            std::cout << "-" ;
        }
        std::cout << std::endl << " ";

        slen = size;
        while (slen -- > 0)
        {
            std::cout << min.top() << ',';
            int x = min.top();
            s.push(x);
            min.pop();
        }

        slen = size;
        std::cout <<  " <-- " << std::endl << " ";
        while (slen    -- > 0)
        {
            std::cout << "-" ;
        }
        std::cout << std::endl;
        return 0;
    }
};

/*
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{
    MinStack* obj = new MinStack();
    obj->printstack();
    obj->push(6);
    obj->printstack();
    obj->push(5);
    obj->push(4);
    obj->push(3);
    obj->printstack();
    std::cout << "getMin? " << obj->getMin() << std::endl;
    obj->push(2);
    obj->push(-1);
    obj->push(5);
    obj->push(-2);
    obj->printstack();
    obj->pop();
    obj->printstack();
    int param_3 = obj->top();
    std::cout << "top  : " << param_3 << std::endl;
    obj->printstack();
    int param_4 = obj->getMin();
    std::cout << "getMin? " << param_4 << std::endl;
    while (obj->top() > 0)
    {
        obj->pop();
        param_4 = obj->getMin();
        std::cout << "getMin? " << param_4 << std::endl;
    }
    return 0;
}
