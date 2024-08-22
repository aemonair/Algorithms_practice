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

class Solution {
public:
    std::vector<std::vector<int>> intervalIntersection(
            std::vector<std::vector<int>>& firstList,
            std::vector<std::vector<int>>& secondList)
    {
        int size1 = firstList.size();
        int size2 = secondList.size();
        std::vector<std::vector<int>> result;
        for (int i = 0, j = 0; i < size1 && j  < size2;) {
            if (firstList[i][0] > secondList[j][1]) {
                j++;
                continue;
            }
            if (firstList[i][1] < secondList[j][0]) {
                i++;
                continue;
            }
            result.push_back({std::max(firstList[i][0], secondList[j][0]),
                              std::min(firstList[i][1], secondList[j][1])});
            if (firstList[i][1] < secondList[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return result;
        return std::vector<std::vector<int>>();
    }

    std::vector<std::vector<int>> intervalIntersection1(
            std::vector<std::vector<int>>& firstList,
            std::vector<std::vector<int>>& secondList)
    {
        int size1 =firstList.size();
        int size2 = secondList.size();
        int i = 0;
        int j = 0;
        int left = 0;
        int right =0;
        std::vector<std::vector<int>> result;
        while (i<size1 && j < size2) {
            left= std::max(firstList[i][0], secondList[j][0]);
            right = std::min(secondList[j][1], firstList[i][1]);
            if (left <= right) {
                result.push_back({left, right});
            }
            if(firstList[i][1] < secondList[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return result;
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

    std::cout << "firstList:" << firstList << std::endl;
    std::cout << "secondList:" << secondList << std::endl;
const static int TEST_TIME = 1;
const static int TEST_0    = 0;
const static int TEST_1    = 1;
    if (TEST_0)
    {
        std::vector<std::vector<int>>&& result =
            solution.intervalIntersection(firstList, secondList);
        std::cout << "result:" << std::boolalpha << result << std::endl;

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
        std::cout << "result:" << std::boolalpha << result << std::endl;

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
