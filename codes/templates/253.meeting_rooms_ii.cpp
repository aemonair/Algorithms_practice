/*
 ******************************************************************
 * 253. Meeting Rooms II
 ******************************************************************
 * Given an array of meeting time intervals consisting of start and end times[[s1,e1],[s2,e2],...](si< ei), find the minimum number of conference rooms required.
 ******************************************************************
 * Example 1:
 *
 * Input:
 * [[0,30],[5,10],[15,20]]
 * Output: 2
 ******************************************************************
 * Example 2:
 *
 * Input:[[7,10],[2,4]]
 *
 * Output: 1
 ***************************************************************
 * Meetings: [[4,5], [2,3], [2,4], [3,5]]
 * Output: 2
 * Explanation: We will need one room for [2,3] and [3,5], and another room for [2,4] and [4,5].
 *
 * Here is a visual representation of Example :
 *
 * _1_2_3_4_5_6_7_
 *         __
 *     __
 *     ____
 *       ___
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

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
template<>
int printvector(std::vector<Interval> v);

class Solution {
public:
    int minMeetingRooms(std::vector<Interval>& intervals)
    {
        return 0;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
          std::vector<Interval>& intervals,
          int  expected)
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
const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if (TEST_0)
    {
        decltype(expected) result = solution.minMeetingRooms(intervals);
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
template<>
int printvector(std::vector<Interval> v)
{
    std::cout << "{  " ;// << std::endl;
    for (auto iter = v.begin(); iter != v.end(); iter++ )
    {
        std::cout << "[" << (*iter).start << ", "<< (*iter).end << "] ,";//<<std::endl;
    }
    std::cout << "\b  }" << std::endl;
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
    std::vector<Interval> intervals  = {Interval(0,30),Interval(5,10),Interval(15,20)};
    int                result     = 2;
    Test("Test1", intervals, result);
}

void Test2()
{
    std::vector<Interval> intervals  = {Interval(7,10),Interval(2,4)};
    int                result     = 1;
    Test("Test2", intervals, result);
}

void Test3()
{
    std::vector<Interval> intervals  = {Interval(1,4),Interval(2,5),Interval(7,9)};
    int                result     = 2;
    Test("Test3", intervals, result);
}

void Test4()
{
    std::vector<Interval> intervals  = {Interval(6,7),Interval(2,4),Interval(8,12)};
    int                result     = 1;
    Test("Test4", intervals, result);
}

void Test5()
{
    std::vector<Interval> intervals  = {Interval(1,4),Interval(2,3),Interval(3,6)};
    int                result     = 2;
    Test("Test5", intervals, result);
}

void Test6()
{
    std::vector<Interval> intervals  = {{4,5},{2,3},{2,4},{3,5}};
    //std::vector<Interval> intervals  = {Interval(4,5),Interval(2,3),Interval(2,4),Interval(3,5)};
    int                result     = 2;
    Test("Test6", intervals, result);
}

void Test7()
{
    std::vector<Interval> intervals  = {{4,5},{2,3},{2,4},{2,5}};
    //std::vector<Interval> intervals  = {Interval(4,5),Interval(2,3),Interval(2,4),Interval(3,5)};
    int                result     = 3;
    Test("Test7", intervals, result);
}


int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;

}
