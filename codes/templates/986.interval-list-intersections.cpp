/*
 ******************************************************************
 * 986. Interval List Intersections
 * Medium
 ******************************************************************
 *
 * You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.
 *
 * Return the intersection of these two interval lists.
 *
 * (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b. 
 * The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval. 
 * For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
 *
 ******************************************************************
 * Example 1:
 *  A  [ ]  [    ]  [         ][]
 *  B   [   ]  [   ]  [        ][]
 *
 *ans   []  |  [ ]    [       ]|| 
 *     0   4   8   C   16      24
 *
 * Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
 * Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 ******************************************************************
 * Example 2:
 *
 * Input: firstList = [[1,3],[5,9]], secondList = []
 * Output: []
 ******************************************************************
 * Example 3:
 *
 * Input: firstList = [], secondList = [[4,8],[10,12]]
 * Output: []
 ******************************************************************
 * Example 4:
 *
 * Input: firstList = [[1,7]], secondList = [[3,10]]
 * Output: [[3,7]]
 ******************************************************************
 * Constraints:
 *
 * 0 <= firstList.length, secondList.length <= 1000
 * firstList.length + secondList.length >= 1
 * 0 <= start[i] < endi <= 10^9
 * end[i] < start[i+1]
 * 0 <= start[j] < end[j] <= 10^9
 * end[j] < start[j+1]
 ***************************************************************
 *
 */

// 44 yy
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <climits>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define     RESET   "\033[0m"
#define     RED     "\033[31m"             /*      Red     */
#define     CYAN    "\033[36m"             /*      Cyan    */
#define     BLUE    "\033[34m"             /*      Blue    */
#define     GREEN   "\033[32m"             /*      Green   */
#define     WHITE   "\033[37m"             /*      White   */
#define     BLACK   "\033[30m"             /*      Black   */
#define     YELLOW  "\033[33m"             /*      Yellow  */
#define     MAGENTA "\033[35m"             /*      Magenta */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow  */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black   */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White   */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green   */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue    */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan    */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red     */

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

template<typename T>
int printvector(std::vector<T> v);

template <typename T>
int printstack(std::stack<T> s);

template <typename T1, typename T2>
int printunordered_map(const std::unordered_map<T1,T2> &v);

class Solution {
public:
    std::vector<std::vector<int>> intervalIntersection(
            std::vector<std::vector<int>>& firstList,
            std::vector<std::vector<int>>& secondList)
    {
        return std::vector<std::vector<int>>();
    }

    std::vector<std::vector<int>> intervalIntersection1(
            std::vector<std::vector<int>>& firstList,
            std::vector<std::vector<int>>& secondList)
    {
        return std::vector<std::vector<int>>();
    }

    //    --- |   -- |    --  |   --  |  --     |f
    // --     | --   |  ----- |    -- |      -- |s
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
            std::vector<std::vector<int>>& firstList,
            std::vector<std::vector<int>>& secondList,
        std::vector<std::vector<int>> & expected)
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "firstList:" <<  std::endl;
    printvector(firstList);
    std::cout << "secondList:" <<  std::endl;
    printvector(secondList);
const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if (TEST_0)
    {
        std::vector<std::vector<int>>&& result =
            solution.intervalIntersection(firstList, secondList);
        std::cout << "result:" << std::boolalpha << std::endl;
        printvector(result);

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if (TEST_1)
    {
        std::vector<std::vector<int>>&& result =
            solution.intervalIntersection1(firstList, secondList);
        std::cout << "result:" << std::boolalpha << std::endl;
        printvector(result);

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
}

// 76 yy
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
template<typename T>
int printvector(std::vector<T> v)
{
    if(0 == v.size())
    {
        std::cout << "Empty vector." << std::endl;
        return 0;
    }
    std::cout << "[ " ;
    for(auto i: v)
    {
        std::cout << i << ", ";
    }
    std::cout << "\b\b ]" << std::endl;
    return v.size();
}
template<typename T>
int printstack (std::stack <T> s)
{
    if(s.empty())
    {
        std::cout << "Empty stack ." << std::endl;
        return 0;
    }
    std::cout <<  "The stack size is: " << s.size() << std::endl;
    std::cout << "[ " ;
    while (!s.empty())
    {
        std::cout << s.top() << ", ";
        s.pop();
    }
    std::cout << "\b\b ]" << std::endl;
    return s.size();
}
template<typename T>
int printvector(std::stack <T> s)
{
    if(s.empty())
    {
        std::cout << "Empty stack ." << std::endl;
        return 0;
    }
    std::cout <<  "The stack size is: " << s.size() << std::endl;
    std::cout << "[ " ;
    while (!s.empty())
    {
        std::cout << s.top() << ", ";
        s.pop();
    }
    std::cout << "\b\b ]" << std::endl;
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

void Test1()
{
    std::vector<std::vector<int>> firstList  = {{0,2},{5,10},{13,23},{24,25}};
    std::vector<std::vector<int>> secondList = {{1,5},{8,12},{15,24},{25,26}};
    std::vector<std::vector<int>> result     =
    {{1,2},{5,5},{8,10},{15,23},{24,24},{25,25}};
    Test("Test1", firstList, secondList, result);
}

void Test2()
{
    std::vector<std::vector<int>> firstList  = {{1,3},{5,9}};
    std::vector<std::vector<int>> secondList = {};
    std::vector<std::vector<int>> result     = {};
    Test("Test2", firstList, secondList, result);
}

void Test3()
{
    std::vector<std::vector<int>> firstList  = {};
    std::vector<std::vector<int>> secondList = {{4,8},{10,12}};
    std::vector<std::vector<int>> result     = {};
    Test("Test3", firstList, secondList, result);
}

void Test4()
{
    std::vector<std::vector<int>> firstList  = {{1,7}};
    std::vector<std::vector<int>> secondList = {{3,10}};
    std::vector<std::vector<int>> result     = {{3,7}};
    Test("Test4", firstList, secondList, result);
}

void Test5()
{
    std::vector<std::vector<int>> firstList  = {{1,3},{5,6},{7,9}};
    std::vector<std::vector<int>> secondList = {{2,3},{5,7}};
    std::vector<std::vector<int>> result     = {{2,3},{5,6},{7,7}};
    Test("Test5", firstList, secondList, result);
}

void Test6()
{
    std::vector<std::vector<int>> firstList  = {{1,3},{5,7},{9,12}};
    std::vector<std::vector<int>> secondList = {{5,10}};
    std::vector<std::vector<int>> result     = {{5,7},{9,10}};
    Test("Test6", firstList, secondList, result);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;

}
