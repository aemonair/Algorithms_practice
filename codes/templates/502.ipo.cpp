/*
 ******************************************************************************
 * 502. IPO
 * Hard
 ******************************************************************************
 * Suppose LeetCode will start its IPO soon.
 * In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO.
 * Since it has limited resources, it can only finish at most k distinct projects before the IPO.
 * Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
 *
 * You are given several projects.
 * For each project i, it has a pure profit Pi and a minimum capital of Ci is needed to start the corresponding project.
 * Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
 *
 * To sum up, pick a list of at most k distinct projects from given projects to maximize your final capital, and output your final maximized capital.
 ******************************************************************************
 * Example 1:
 * Input: k=2, w=0, profits=[1,2,3], capital=[0,1,1].
 *
 * Output: 4
 *
 * Explanation: Since your initial capital is 0, you can only start the project indexed 0.
 *              After finishing it you will obtain profit 1 and your capital becomes 1.
 *              With capital 1, you can either start the project indexed 1 or the project indexed 2.
 *              Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
 *              Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
 * Note:
 * 1. You may assume all numbers in the input are non-negative integers.
 * 2. The length of Profits array and Capital array will not exceed 50,000.
 * 3. The answer is guaranteed to fit in a 32-bit signed integer.
 ******************************************************************************
 * 1 <= k <= 10⁵
 * 0 <= w <= 10⁹
 * n == profits.length
 * n == capital.length
 * 1 <= n <= 10⁵
 * 0 <= profits[i] <= 10⁴
 * 0 <= capital[i] <= 10⁹
 ******************************************************************************
 */

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

template<typename T1,typename T2>
std::ostream & operator << (std::ostream &out, const std::pair<T1,T2> &_pair);
template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);
template <typename ...T>
std::ostream & operator << (std::ostream &out, std::priority_queue<T...> big_queue);
//const bool PRINT = false;
const bool PRINT = true ;
class Solution
{
public:
    int findMaximizedCapital( int k, int w, std::vector<int>& profits, std::vector<int> &capital )
    {
        return w;
    }
    int findMaximizedCapital1( int k, int w, std::vector<int>& profits, std::vector<int> &capital )
    {
        return w;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        int k,
        int w,
        std::vector<int>& profits,
        std::vector<int>& capital,
        int expected
        )
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    std::cout << "k:" << k << " , w:" << w << std::endl;
    std::cout << "profits:" << profits << std::endl;
    std::cout << "capital:" << capital <<std::endl;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;

    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.findMaximizedCapital(k, w, profits, capital);
        std::cout << "result:" << result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if(TEST_1)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.findMaximizedCapital1(k, w, profits, capital);
        std::cout << "result:" << result << std::endl;

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
    std::cout << "-----------------------------" << std::endl;
}
template<typename T1,typename T2>
std::ostream & operator << (std::ostream &out, const std::pair<T1,T2> &_pair)
{
    out << "( " << _pair.first << ", " << _pair.second << ") ";
    return out;
}
template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec)
{
    out << "[  ";
    for(auto v: _vec)
    {
        out << v << ", ";
    }
    out << "\b\b ]" ;
    return out;
}
template <typename ...T>
std::ostream & operator << (std::ostream &out, std::priority_queue<T...> big_queue)
{
    std::priority_queue<T...> Big_queue = big_queue;
    int bsize = Big_queue.size();
    if (Big_queue.empty())
    {
        out << "The big queue is empty. "<< std::endl;
    }
    std::cout << " | ";
    while (bsize--)
    {
        out << Big_queue.top() << ", " ;
        Big_queue.pop();
    }
    out << std::endl ;
    return out;
}
void Test1()
{
    int k = 2;
    int w = 0;
    std::vector<int> profits = {1, 2, 3};
    std::vector<int> capital = {0, 1, 1};
    int expected = 4;
    Test("Test1", k, w, profits, capital, expected);
}
void Test2()
{
    int k = 3;
    int w = 0;
    std::vector<int> profits = {1, 2, 3};
    std::vector<int> capital = {0, 1, 2};
    int expected = 6;
    Test("Test2", k, w, profits, capital, expected);
}

void Test3()
{
    int k = 1;
    int w = 0;
    std::vector<int> profits = {1, 2, 3};
    std::vector<int> capital = {1, 1, 2};
    int expected = 0;
    Test("Test3", k, w, profits, capital, expected);
}

void Test4()
{
    int k = 10;
    int w = 0;
    std::vector<int> profits = {1, 2, 3};
    std::vector<int> capital = {0, 1, 2};
    int expected = 6;
    Test("Test4", k, w, profits, capital, expected);
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
