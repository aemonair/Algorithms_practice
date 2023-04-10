/*
 * 224. Basic Calculator
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
 * 
 * Example 1:
 * 
 * Input: "1 + 1"
 * Output: 2
 * Example 2:
 * 
 * Input: " 2-1 + 2 "
 * Output: 3
 * Example 3:
 * 
 * Input: "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 *
 * Note:
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 */

#include <iostream>
#include <string>
#include <stack>
#include <cassert>

class Solution {
public:
    template <typename T>
    int printstack(std::stack<T> s)
    {
        if (s.empty())
        {
            std::cout << "The stack is empty." << std::endl;
            return 0;
        }
        std::cout <<  "The stack size is: " << s.size() << std::endl;
        std::stack<T> tmp;
        while (!s.empty())
        {
            std::cout << s.top() << ", ";
            s.pop();
        }
        std::cout <<  std::endl;
        return s.size();
    }
    int print_stack(std::stack<int> s)
    {
        if (s.empty())
        {
            std::cout << "The stack is empty." << std::endl;
            return 0;
        }
        std::cout <<  "The stack size is: " << s.size() << std::endl;
        std::stack<int> tmp;
        while (!s.empty())
        {
            std::cout << s.top() << ", ";
            s.pop();
        }
        std::cout <<  std::endl;
        return s.size();
    }
    int calculate(std::string s) 
    {
        int num    = 0;
        int sign   = 1;
        int result = 0;
        int length = s.length();
        std::stack<int>  nums;
        std::stack<int>  ops ;

        for (char c : s)
        {
            std::cout << "c:" << c << std::endl;
            if (isdigit(c))
            {
                num = num * 10 + c - '0';
            }
            else
            {
                result += sign * num;
                num = 0;
                if (c == '+')
                {
                    sign = 1;
                }
                if (c == '-')
                {
                    sign = -1;
                }
                if (c == '(')
                {
                    nums.push(result);
                    ops.push(sign);
                    result = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size())
                {
                    result = ops.top() * result + nums.top();
                    ops.pop();
                    nums.pop();
                }
            }
            std::cout << "result:" << result << std::endl;
            printstack(nums);
            printstack(ops);
        }
        result += sign * num;
        return result;
    }
/*
 *  "(1+(4+5+2)-3)+(6+8)"
 *
 */
    int calculate1(std::string s) 
    {
        int result = 0;
        int sign   = 1;
        int num    = 0;

        std::stack<int> calc;
        calc.push(sign);

        for (int i = 0; i < s.length(); ++i)
        {
            char c = s[i];

            if (c >= '0' && c <= '9')
            {
                num = num * 10 + (c - '0');
            }
            else if (c == '+' || c == '-')
            {
                result += sign * num;
                sign =  calc.top() * (c =='+'?1: -1);
                num = 0;
            }
            else if (c == '(')
            {
                 calc.push(sign);
            }
            else if (c == ')')
            {
                 calc.pop();
            }
            std::cout << "s[" <<  i << "]: "<< c << std::endl;
            std::cout << "num:" <<  num << ", ";//std::endl;
            std::cout << "sign:" <<  sign << ", "; //std::endl;
            std::cout << "result:" <<  result << std::endl;
            print_stack(calc);
        }
        result += sign * num;
        return result;
    }
};

int main()
{
    Solution a;
    std::string s = "1+1";
    int x =  0;
    std::cout << "s: " << s << std::endl;
    x =  a.calculate(s);
    std::cout << "------------" << "x:" << x << "-----------" << std::endl;

    std::string s1 = " 2-1 + 2 "; //"1+1";
    std::cout << "s1: " << s1 << std::endl;
    x =  a.calculate(s1);
    std::cout << "------------" << "x:" << x << "-----------" << std::endl;

    std::string s2 = "(1+(4+5+2)-3)+(6+8)";
    std::cout << "s2: " << s2 << std::endl;
    x =  a.calculate(s2);
    std::cout << "------------" << "x:" << x << "-----------" << std::endl;

    std::string s3 = "0"; //"1+1";
    std::cout << "s3: " << s3 << std::endl;
    x =  a.calculate(s3);
    std::cout << "------------" << "x:" << x << "-----------" << std::endl;

    std::string s4 = " 30"; //"1+1";
    std::cout << "s4: " << s4 << std::endl;
    x =  a.calculate(s4);
    std::cout << "------------" << "x:" << x << "-----------" << std::endl;

    std::string s5 = "2-4-(8+2-6+(8+4-(1)+8-10))"; 
    std::cout << "s5: " << s5 << std::endl;
    x =  a.calculate(s5);
    std::cout << "------------" << "x:" << x << "-----------" << std::endl;
    return 0;
}

