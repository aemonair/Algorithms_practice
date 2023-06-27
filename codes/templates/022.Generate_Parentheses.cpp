/*
 *********************************************
 *  22. Generate Parentheses
 * Medium
 *********************************************
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *********************************************
 * Example 1:
 *
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 *********************************************
 * Example 2:
 *
 * Input: n = 1
 * Output: ["()"]
 *********************************************
 * Constraints:
 *
 * 1 <= n <= 8
 *********************************************
 *
 */

#include <stack>
#include <queue>
#include <chrono>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

class Solution {
public:
////////////////////////////////////////////////////////////////////////
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> res;
        return res;
    }
////////////////////////////////////////////////////////////////////////
    template <typename T>
    int printvector(std::vector<T> v)
    {
        //std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[";
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";
        }
        std::cout << "\b\b]";
        std::cout << std::endl;
        return v.size();
    }

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
    template <typename T>
    int printvectorvector(std::vector<T> v)
    {
        std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvector( *iter );
        }
        std::cout <<  std::endl;
        return v.size();
    }
////////////////////////////////////////////////////////////////////////
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        int n,
        std::vector<std::string> expected
        )
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) result = solution.generateParenthesis(n);
        std::cout << "solution result:" << std::endl;
        solution.printvector(result);

        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            solution.printvector(expected);
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if (TEST_1)
    {
    }
}

void Test1()
{
    int n = 3;
    std::vector<std::string> expect = {"((()))","(()())","(())()","()(())","()()()"};
    Test("Test1", n, expect);
}
void Test2()
{
    int n = 1;
    std::vector<std::string> expect = {"()"};
    Test("Test2", n, expect);
}

void Test3()
{
    int n = 2;
    std::vector<std::string> expect = {"(())","()()"};
    Test("Test3", n, expect);
}

void Test4()
{
}

void Test5()
{
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
