/* 
 * 232. Implement Queue using Stacks
 * Implement the following operations of a queue using stacks.
 * 
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 * Example:
 * 
 * MyQueue queue = new MyQueue();
 * 
 * queue.push(1);
 * queue.push(2);  
 * queue.peek();  // returns 1
 * queue.pop();   // returns 1
 * queue.empty(); // returns false
 * Notes:
 * 
 * You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 */

#include <stack>
#include <queue>
#include <iostream>

class MyQueue {
public:
    std::stack<int>  input;
    std::stack<int> output;

    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = peek();
        output.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if (output.empty())
        {
            while (input.size())
            {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }

    int printstack()
    {
        peek();
        int size = output.size();
        int s    = output.size();
        std::cout << "Size: " << size << std::endl;

        std::cout << " ";
        while (s    -- > 0)
        {
            std::cout << "-" ;
        }
        std::cout << std::endl << " ";

        s = size;
        while (s --)
        {
            std::cout << output.top();
            int x = output.top();
            input.push(x);
            output.pop();
        }

        s = size;
        std::cout <<  " <-- " << std::endl << " ";
        while (s    --)
        {
            std::cout << "-" ;
        }
        std::cout << std::endl;
        return 0;
    }
};

class MyQueue0 {
public:
    std::stack<int> s1;
    std::stack<int> s2;

    /** Initialize your data structure here. */
    MyQueue0() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (!s2.empty())
        {
            int size = s2.size();
            int s    = size;
            while (s -- > 0)
            {
                int xx = s2.top();
                s2.pop();
                s1.push(xx);
            }
        }
        if (!s1.empty() || s2.empty())
        {
            s1.push(x);
        }
    }
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!s1.empty())
        {
            int size = s1.size();
            int s    = size;
            while (s -- > 0)
            {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
        }
        int x = 0;
        if (s1.empty())
        {
            x = s2.top();
            s2.pop();
            return x;
        }
        return 0;
    }
    /** Get the front element. */
    int peek() {
        if (s2.empty())
        {
            int size = s1.size();
            int s    = size;
            while (s -- > 0)
            {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
        }
        int x = s2.top();
        return x;
    }
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }

    int printstack()
    {
        int size1 = s1.size();
        int size2 = s2.size();
        int size = size1 > 0 ? size1 : size2;
        std::cout << "Size: " << size << std::endl;

        std::cout << " ";
        int s = size;
        while (s    -- > 0)
        {
            std::cout << "-" ;
        }
        std::cout << std::endl << " ";

        if (s1.empty())
        {
            s = s2.size();
            while (s --)
            {
                std::cout << s2.top();
                int x = s2.top();
                s1.push(x);
                s2.pop();
            }
        }
        else if (s2.empty())
        {
            s = s1.size();
            while (s --)
            {
                std::cout << s1.top();
                int x = s1.top();
                s2.push(x);
                s1.pop();
            }
        }
        s = size;

        if (size1)
            std::cout <<  " --> " << std::endl << " ";
        if (size2)
            std::cout <<  " <-- " << std::endl << " ";

        while (s    --)
        {
            std::cout << "-" ;
        }
        std::cout << std::endl;
        return 0;
    }
};

class MyQueue1 {
public:
    std::stack<int> s1;
    std::stack<int> s2;

    /** Initialize your data structure here. */
    MyQueue1() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int size = s1.size();
        int s    = size;
        while (s -- > 1)
        {
            int x = s1.top();
            s1.pop();
            s2.push(x);
        }
        int x = s1.top();
        s1.pop();
        s = size;
        while (s -- > 1)
        {
            int x = s2.top();
            s2.pop();
            s1.push(x);
        }

        return x;
    }
    
    /** Get the front element. */
    int peek() {
        int size = s1.size();
        int s = size;
        while (s --)
        {
            //std::cout << s1.top();
            int x = s1.top();
            s2.push(x);
            s1.pop();
        }
        int x = s2.top();
        s = size;
        while (s --)
        {
            //std::cout << s1.top();
            int x = s2.top();
            s1.push(x);
            s2.pop();
        }
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }

    int printstack()
    {
        int size = s1.size();
        int s    = s1.size();
        std::cout << "Size: " << size << std::endl;

        s = size;
        while (s --)
        {
            //std::cout << s1.top();
            int x = s1.top();
            s2.push(x);
            s1.pop();
        }
        s = size;

        std::cout << " ";
        while (s    -- > 0)
        {
            std::cout << "-" ;
        }
        std::cout << std::endl << " ";

        s = size;
        while (s --)
        {
            std::cout << s2.top();
            int x = s2.top();
            s1.push(x);
            s2.pop();
        }

        s = size;
        std::cout <<  " <-- " << std::endl << " ";
        while (s    --)
        {
            std::cout << "-" ;
        }
        std::cout << std::endl;
        return 0;
    }
    int print_queue()
    {
        int size = s1.size();
        std::cout << "Size: " << size << std::endl;
        while (size --)
        {
            std::cout << s1.top();
            int x = s1.top();
            s2.push(x);
            s1.pop();
        }
        std::cout << std::endl;
        return 0;
    }
};

/*
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    obj->push(6);
    obj->printstack();
    int param_2 = obj->pop();
    std::cout << "pop   : " << param_2 << std::endl;
    obj->printstack();
    int param_3 = obj->peek();
    std::cout << "peek  : " << param_3 << std::endl;
    obj->printstack();
    bool param_4 = obj->empty();
    std::cout << "empty ? " << param_4 << std::endl;
    while (!obj->empty())
    {
        obj->pop();
    }
    std::cout << "empty ? " << obj->empty() << std::endl;
    return 0;
}
