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
#include <tuple>
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

template<typename T>
std::ostream & operator << (std::ostream &out, const std::vector<T> &_vec)
{
    out << "[  ";
    for(auto v: _vec)
    {
        out << v << ", ";
    }
    out << "\b\b ]" ;
    return out;
}
class Solution {
public:
////////////////////////////////////////////////////////////////////////
    struct parentheses{
        std::string str;
        int left ;
        int right;

    };
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> res;
        std::queue<std::tuple<std::string,int,int>> queue;
        queue.push(std::make_tuple(std::string("("), 1, 0));
        while (!queue.empty()){
            auto curr = queue.front();
            queue.pop();
            int left = std::get<1>(curr);
            int right= std::get<2>(curr);
            auto str = std::get<0>(curr);
            if (left  == n && right == n) {
                res.push_back(str);
            }
            if (left > right) {
                queue.push(std::make_tuple(str + ")", left , right + 1));
            }
            if (left < n ) {
                queue.push(std::make_tuple(str + ("("), left + 1, right));
            }
        }
        return res;
    }
    std::vector<std::string> generateParenthesis1(int n)
    {
        // (
        // (( ()
        // ((( ()( (()
        // ((() ()(( ()() (()( (())
        // ((()) ()(() ()()( (()() (())(
        // ((())) ()(()) ()()() (()()) (())()
        std::vector<std::string> res;
        std::queue <parentheses> parenthes;
        parenthes.push(parentheses{"(", 1, 0});
        int size = parenthes.size();
        while (!parenthes.empty()) {
            // default: left < n && left >= right
            // auto _temppar(parenthes[j]);
            auto par = parenthes.front();
            parenthes.pop();
            if (par.left < n) {
                if (par.left > par.right) {
                    parenthes.push({par.str+")", par.left, par.right+1});
                }
                parenthes.push({par.str+"(", par.left+1, par.right});
                //  left <n left ==right (
                //  left <n ,left > right )
                // insert )
            } else {
                if (par.left > par.right) {
                    parenthes.push({par.str+")", par.left, par.right+1});
                }
                if (par.left == n && par.right==n) {
                    res.push_back(par.str);
                }
            }
        }
        return res;
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
    sort(expected.begin(), expected.end());

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
        std::cout << "solution result:" << result << std::endl;
        // solution.printvector(result);

        sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            // solution.printvector(expected);
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
