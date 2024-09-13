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
std::ostream & operator << (std::ostream &out, const std::vector<T> &_vec);

class Solution {
public:
////////////////////////////////////////////////////////////////////////
    std::vector<std::string> generateParenthesis(int n)
    {
        std::queue<std::string> queue;
        queue.push("(");
        std::vector<std::string> res;
        while (!queue.empty()) {
            auto str = queue.front();
            int left = std::count(str.begin(), str.end(), '(');
            int right= std::count(str.begin(), str.end(), ')');
            //std::cout << "left:" << left << ",right:" << right << std::endl;
            if (left == n && right == n) {
                res.push_back(str);
            }
            queue.pop();
            if (left < n ) {
                if (left > right) {
                    std::string temp{str};
                    temp += ")";
                    queue.push(temp);
                    //std::cout << temp << std::endl;
                }
                //if (left == right) {
                    std::string temp{str};
                    std::string temp2{str};
                    temp += "(";
                    queue.push(temp);
                //}
            } else {
                if (left > right) {
                    std::string temp{str};
                    temp += ")";
                    queue.push(temp);
                    //std::cout << temp << std::endl;
                }
            }
        }
        return res;
    }
    std::vector<std::string> generateParenthesis1(int n)
    {
        std::string path;
        std::vector<std::string> res;
        auto dfs = [&](auto && dfs, int left, int right) {
            if (left > n || left < right) {
                return;
            }
            if (path.size() == n*2) {
                res.push_back(path);
                return;
            }
            path.push_back ( '(' );
            dfs(dfs, left+1, right);
            path.pop_back();

            path.push_back ( ')' );
            dfs(dfs, left, right+1);
            path.pop_back();
        };
        dfs(dfs, 0, 0);
        return res;
    }
    std::vector<std::string> generateParenthesis2(int n)
    {
        std::vector<std::string> res;
        std::string path(n*2, 0);
        auto dfs = [&](auto &&dfs, int i, int left) {
            if (n*2 == i) {
                res.push_back(path);
                return;
            }
            if (left < n) {
                path[i] = '(';
                dfs(dfs , i+1, left+1);
            }

            if (left > i - left) {
                path[i] = ')';
                dfs(dfs , i+1, left);
            }
        };
        dfs(dfs, 0, 0);
        return res;
    }
    std::vector<std::string> generateParenthesis3(int n)
    {
        std::vector<std::string> res;
        std::string path(n*2, 0);
        auto dfs = [&](auto &&dfs, int i, int left) {
            if (i == n*2) {
                res.push_back(path);
                return;
            }
            for (int j = 0; j < 2; ++j) {
                if (j==0 && left < n) {
                    path[i] = '(';
                    dfs(dfs , i+1, left+1); //, right);
                }

                if (j==1 && left > i - left) {
                    path[i] = ')';
                    dfs(dfs , i+1, left); // right+1
                }
            }
        };
        dfs(dfs, 0, 0);
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
const static int TEST__    = 1;
const static int TEST_1    = 1;
const static int TEST_2    = 1;
const static int TEST_3    = 1;
    if (TEST__)
    {
        std::cout << "Solution start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) result = solution.generateParenthesis(n);
        std::cout << "solution result:" << result << std::endl;

        sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if (TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) result = solution.generateParenthesis1(n);
        std::cout << "solution1 result:" << result << std::endl;

        sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if (TEST_2)
    {
        std::cout << "Solution2 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) result = solution.generateParenthesis2(n);
        std::cout << "solution2 result:" << result << std::endl;

        sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution2 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution2 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution2 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if (TEST_3)
    {
        std::cout << "Solution3 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) result = solution.generateParenthesis3(n);
        std::cout << "solution3 result:" << result << std::endl;

        sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution3 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution3 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution3 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
}

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
