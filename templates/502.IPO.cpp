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
 * Initially, you have W capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
 * 
 * To sum up, pick a list of at most k distinct projects from given projects to maximize your final capital, and output your final maximized capital.
 ****************************************************************************** 
 * Example 1:
 * Input: k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].
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

//const bool PRINT = false;
const bool PRINT = true ;
class Solution 
{
public:
    // 
    int findMaximizedCapital( int k, int W, std::vector<int>& Profits, std::vector<int> &Capital ) 
    {
        return 0;
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
    template <typename T1, typename T2>
    int printunordered_map(const std::unordered_map<T1,T2> &v)
    {
        std::cout << "unordered_map size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << "(" << iter->first << "," << iter->second<< "), ";//<<std::endl;
        }
        std::cout << std::endl;
        return v.size();
    }


    template <typename ...T>
    //int printqueue(std::priority_queue<T...> big_queue)
    //{
    //    std::priority_queue<T...> Big_queue = big_queue;
    //    int bsize = Big_queue.size();
    //    if (Big_queue.empty())
    //    {
    //        std::cout << "The big queue is empty. "<< std::endl;
    //    }
    //    std::cout << " | ";
    //    while (bsize--)
    //    {
    //        std::cout << Big_queue.top() << ", " ;
    //        Big_queue.pop();
    //    }
    //    std::cout << std::endl ;
    //    return bsize;
    //}
    int printqueue(std::priority_queue<T... > big_queue)
    {
        std::priority_queue<T...> Big_queue = big_queue;
        int bsize = Big_queue.size();
        if (Big_queue.empty())
        {
            std::cout << "The big queue is empty. "<< std::endl;
        }
        std::cout << " | ";
        while (bsize--)
        {
            std::cout << "(" << Big_queue.top().first << " ," << Big_queue.top().second << "), " ;
            Big_queue.pop();
        }
        std::cout << std::endl ;
        return bsize;
    }

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << "| ";//<<std::endl;
        }
        std::cout << std::endl;
        return v.size();
    }

    template <typename T>
    int printvectorvector(const std::vector<T> &v)
    {
        std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvector( *iter );
        }
        std::cout << std::endl;
        return v.size();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName, 
        int k, 
        int W,
        std::vector<int>& Profits, 
        std::vector<int>& Capital,
        int expected
        )
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    std::cout << "k:" << k << " , W:" << W << std::endl;
    std::cout << "Profits:" << std::endl;
    solution.printvector(Profits);
    std::cout << "Capital:" << std::endl;
    solution.printvector(Capital);

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

        decltype(expected) result = solution.findMaximizedCapital(k, W, Profits, Capital);
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
    }
    std::cout << "-----------------------------" << std::endl;
}
void Test1()
{
    int k = 2;
    int W = 0;
    std::vector<int> Profits = {1, 2, 3};
    std::vector<int> Capital = {0, 1, 1};
    int expected = 4;
    Test("Test1", k, W, Profits, Capital, expected);
}
void Test2()
{
}

void Test3()
{
}

void Test4()
{
}

void Test5()
{
}

int main()
{
    Solution solution;

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;

}
