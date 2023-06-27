/*
 ******************************************************************************
 * 436. Find Right Interval
 * Medium
 ******************************************************************************
 * You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.
 *
 * The right interval for an interval i is an interval j such that startj >= endi and startj is minimized.
 *
 * Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.
 ******************************************************************************
 * Example 1:
 *
 * Input: intervals = [[1,2]]
 * Output: [-1]
 * Explanation: There is only one interval in the collection, so it outputs -1.
 ******************************************************************************
 * Example 2:
 *
 * Input: intervals = [[3,4],[2,3],[1,2]]
 * Output: [-1,0,1]
 * Explanation: There is no right interval for [3,4].
 * The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
 * The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.
 ******************************************************************************
 * Example 3:
 *
 * Input: intervals = [[1,4],[2,3],[3,4]]
 * Output: [-1,2,-1]
 * Explanation: There is no right interval for [1,4] and [3,4].
 * The right interval for [2,3] is [3,4] since start2 = 3 is the smallest start that is >= end1 = 3.
 * 
 ******************************************************************************
 *
 * Constraints:
 *
 * 1 <= intervals.length <= 2 * 10^4
 * intervals[i].length == 2
 * -10^6 <= starti <= endi <= 10^6
 * The start point of each interval is unique.
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

class Solution
{
public:
    //
    std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals)
    {
        std::vector<int> medians(intervals.size(), 0);

        return medians;
    }
    std::vector<int> findRightInterval1(std::vector<std::vector<int>>& intervals)
    {
        std::vector<int> ans;
        return ans;
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
    int printqueue(std::priority_queue<T...> big_queue)
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
            printvector(Big_queue.top() ); //<< ", " ;
            //std::cout << Big_queue.top() << ", " ;
            Big_queue.pop();
        }
        std::cout << std::endl ;
        return bsize;
    }

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        //std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "(  " ;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";//<<std::endl;
        }
        std::cout << "\b\b)  " ; //<< std::endl;
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
        std::vector<std::vector<int>>& intervals,
        std::vector<int>& expected
        )
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    std::cout << "intervals:" << std::endl;
    solution.printvectorvector(intervals);

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

        auto  result = solution.findRightInterval(intervals);
        std::cout << "result:" << std::endl;
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
    if(TEST_1)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        auto  result = solution.findRightInterval1(intervals);
        std::cout << "result:" << std::endl;
        solution.printvector(result);

        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            solution.printvector(expected);
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
void Test1()
{
    std::vector<std::vector<int>> intervals   = {{1, 2}};
    std::vector<int> expect = {-1};
    Test("Test2", intervals, expect);
}
void Test2()
{
    std::vector<std::vector<int>> intervals   = {{3,4},{2,3},{1,2}};
    std::vector<int> expect = {-1, 0, 1};
    Test("Test1", intervals, expect);
}
void Test3()
{
    std::vector<std::vector<int>> intervals   = {{1,4},{2,3},{3,4}};
    std::vector<int> expect = {-1,2,-1};
    Test("Test3", intervals, expect);
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
