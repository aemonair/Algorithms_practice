/*
 ***************************************************************
 * 57. Insert Interval
 * Medium
 ***************************************************************
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 ***************************************************************
 * Example 1:
 *
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 ***************************************************************
 * Example 2:
 *
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 ***************************************************************
 * Example 3:
 *
 * Input: intervals = [], newInterval = [5,7]
 * Output: [[5,7]]
 ***************************************************************
 * Example 4:
 *
 * Input: intervals = [[1,5]], newInterval = [2,3]
 * Output: [[1,5]]
 ***************************************************************
 * Example 5:
 *
 * Input: intervals = [[1,5]], newInterval = [2,7]
 * Output: [[1,7]]
 ***************************************************************
 * Constraints:
 *
 * 0 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= intervals[i][0] <= intervals[i][1] <= 10^5
 * intervals is sorted by intervals[i][0] in ascending order.
 * newInterval.length == 2
 * 0 <= newInterval[0] <= newInterval[1] <= 10^5
 ***************************************************************
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
    std::vector<std::vector<int>> insert(
            std::vector<std::vector<int>>& intervals,
                        std::vector<int> & newInterval)
    {
        return std::vector<std::vector<int>>();
    }
    std::vector<std::vector<int>> insert0(
            std::vector<std::vector<int>>& intervals,
                        std::vector<int> & newInterval)
    {
        return std::vector<std::vector<int>>();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<std::vector<int>> & intervals,
                    std::vector<int>  & newInterval,
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

    std::cout << "intervals:" <<  std::endl;
    printvector(intervals);
    std::cout << "newInterval:" ;
    printvector(newInterval);
    //std::cout <<  std::endl;
const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        std::vector<std::vector<int>>&& result = solution.insert(intervals, newInterval);
        std::cout << "result:" << std::boolalpha << std::endl;
        printvector(result);

        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::endl;
            printvector(expected);
            std::cout << RESET ;//<< std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
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
    std::vector<std::vector<int>> intervals = {{1,3},{6,9}};
    std::vector<int>            newInterval = {2,5};
    std::vector<std::vector<int>>    result = {{1,5},{6,9}};
    Test("Test1", intervals, newInterval, result);
}

void Test2()
{
    std::vector<std::vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    std::vector<int>            newInterval = {4,8};
    std::vector<std::vector<int>>    result = {{1,2},{3,10},{12,16}};
    Test("Test2", intervals, newInterval, result);
}

void Test3()
{
    std::vector<std::vector<int>> intervals = {};
    std::vector<int>            newInterval = {5,7};
    std::vector<std::vector<int>>    result = {{5,7}};
    Test("Test3", intervals, newInterval, result);
}

void Test4()
{
    std::vector<std::vector<int>> intervals = {{1,5}};
    std::vector<int>            newInterval = {2,3};
    std::vector<std::vector<int>>    result = {{1,5}};
    Test("Test4", intervals, newInterval, result);
}

void Test5()
{
    std::vector<std::vector<int>> intervals = {{1,5}};
    std::vector<int>            newInterval = {2,7};
    std::vector<std::vector<int>>    result = {{1,7}};
    Test("Test5", intervals, newInterval, result);
}

void Test6()
{
    std::vector<std::vector<int>> intervals = {{1,5}};
    std::vector<int>            newInterval = {6,8};
    std::vector<std::vector<int>>    result = {{1,5},{6,8}};
    Test("Test6", intervals, newInterval, result);
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
