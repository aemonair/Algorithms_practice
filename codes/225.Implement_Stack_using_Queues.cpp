/*
 * 225. Implement Stack using Queues
 * Implement the following operations of a stack using queues.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * Example:
 *
 * MyStack stack = new MyStack();
 *
 * stack.push(1);
 * stack.push(2); 
 * stack.top();   // returns 2
 * stack.pop();   // returns 2
 * stack.empty(); // returns false
 * Notes:
 *
 * You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 */

#include <queue>
#include <iostream>

class MyStack {
public:

    std::queue<int> q;

    /** Initialize your data structure here. */
    MyStack() {
    }
   
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
   
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = q.size();
        int x = q.back();
        while(size -- > 1)
        {
            int x = q.front();
            q.push(x);
            q.pop();
        }
        q.pop();
        return x;
    }
   
    /** Get the top element. */
    int top() {
        return q.back();
    }
   
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }

    int printqueue()
    {
        int size = q.size();
        int s    = q.size();
        std::cout << "Size: " << size << std::endl;

        s = size;
        std::cout << " ";
        while (s    -- > 0)
        {
            std::cout << "-" ;
        }
        std::cout << std::endl << "|";
        s = size;
        while (s --)
        {
            std::cout << q.front();
            int x = q.front();
            q.push(x);
            q.pop();
        }
        s = size;
        std::cout << std::endl << " ";
        while (s    --)
        {
            std::cout << "-" ;
        }
        std::cout << std::endl;
        return 0;
    }
    int print_queue()
    {
        int size = q.size();
        std::cout << "Size: " << size << std::endl;
        while (size --)
        {
            std::cout << q.front();
            int x = q.front();
            q.push(x);
            q.pop();
        }
        std::cout << std::endl;
        return 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main()
{
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    obj->push(6);
    obj->printqueue();
    int param_2 = obj->pop();
    std::cout << "pop   : " << param_2 << std::endl;
    obj->printqueue();
    int param_3 = obj->top();
    std::cout << "top   : " << param_3 << std::endl;
    obj->printqueue();
    bool param_4 = obj->empty();
    std::cout << "empty ? " << param_4 << std::endl;
    while (!obj->empty())
    {
        obj->pop();
    }
    std::cout << "empty ? " << obj->empty() << std::endl;
    return 0;
}
