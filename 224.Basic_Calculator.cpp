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

class Solution {
public:
    int calculate(std::string s) {
        std::stack<int> number;
        std::stack<char> calc;

        //for (auto i : s )
        int size = s.length();
        std::cout << "size: " << size << std::endl;
        for (int ii = 0; ii < size; ++ii )
        {
            auto i = s[ii];
            std::cout << "string[" << ii << "]: " << i << std::endl;
            if (i > '0' && i < '9')
            {
                std::cout << "push:" << i << " to number" << std::endl;
                number.push(atoi(&i));
            }
            else if (i == '(')
            {
                calc.push(i);
            }
            else if (i == '+' || i == '-')
            {
                calc.push(i);
            }
            if ( i == ')' || ii == size-1)
            {
                std::cout << "End" << std::endl;
                std::cout << calc.top() << std::endl;
                while (calc.top() != '(')
                {
                    int result = 0;
                    int x = number.top();
                    number.pop();
                    int y = number.top();
                    number.pop();
                    char c = calc.top();
                    calc.pop();
                    std::cout << x << c << y << std::endl;
                    if (c == '+')
                    {
                        result = x + y;
                    }
                    else if (c == '-')
                    {
                        result = x - y;
                    }
                    std::cout << result << std::endl;
                    number.push(result);
                    std::cout << number.top() << std::endl;
                    std::cout <<   calc.top() << std::endl;
                    calc.pop();
                }
                //if (calc.top() == '(')
                //{
                //    calc.pop();
                //}
            }
        }
        return number.top();
    }
};

/*
 * 
 * "(1+(4+5+2)-3)+(6+8)"
 *
 * ( 1 + ( 4 + 5 + 2
 * ) 
 *
 *
 * ( 1 + ( 4 + 5 + 2
 * 11
 *
 *
 * ( 1 + 11 - 3)
 *
 * 9 + ( 6 + 
 *
 * "(1+(4+5+2)-3)+(6+8)"
 * 1 4 5 2 )
 * ( + ( + + 
 *
 * 1 4 5 2 )
 * ( + ( + + 
 *
 * 1 11 3 )
 * ( + -
 *
 * 1 8     
 * ( + 
 *
 * 9 6 8 )
 * + ( +  
 *
 * 9 14
 * +
 */
int main()
{
    Solution a;
    std::string s = "1+1";
    int x =  a.calculate(s);
    std::cout << "x:" << x << std::endl;
    std::cout << a.calculate(s) << std::endl;
    return 0;
}
