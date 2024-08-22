/*
 ******************************************************************
 * 252. Meeting Rooms
 ******************************************************************
 * Given an array of meeting time intervals consisting of start and end times[[s1,e1],[s2,e2],...](si< ei), determine if a person could attend all meetings.
 ******************************************************************
 * Example 1:
 *
 * Input:
 * [[0,30],[5,10],[15,20]]
 * Output: false
 ******************************************************************
 * Example 2:
 *
 * Input:[[7,10],[2,4]]
 *
 * Output:true
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

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

std::ostream & operator << (std::ostream &out, Interval & a){
    out << "("<<a.start << "," << a.end << ")" << std::endl;
    return out;
}

template <typename T>
class Solution {
public:
    bool canAttendMeetings(std::vector<Interval>& intervals)
    {
        return false;
    }
    bool canAttendMeetings(std::vector<std::vector<int>> &intervals)
    {
        int size = intervals.size();
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < size; ++i) {
            if (i> 0 && intervals[i][0] <= intervals[i-1][1]) {
                return false;
            }
        }
        return true;
    }
    std::vector<std::vector<int>> findAttendMeetings(std::vector<std::vector<int>>& intervals)
    {
        std::vector<std::vector<int>> result;
        return result;
    }
    std::vector<std::vector<Interval>> findAttendMeetings(std::vector<Interval>& intervals)
    {
        std::vector<std::vector<Interval>> result;
        return result;
    }

    //    --- |   -- |    --  |   --  |  --     |f
    // --     | --   |  ----- |    -- |      -- |s
};

// ==================== TEST Codes====================
template <typename T>
void Test(const std::string& testName,
          std::vector<T>& intervals,
          bool expected)
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution<T> solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "intervals:" << intervals << std::endl;
    //solution.printvector(intervals);
    //printvector(intervals);
const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if (TEST_0)
    {
        decltype(expected) result = solution.canAttendMeetings(intervals);
        std::cout << "result:" << std::boolalpha << result << std::endl;
        //auto findresult = solution.findAttendMeetings(intervals);
        //std::cout << "result:" << std::boolalpha << findresult << std::endl;


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

void Test0()
{
    std::vector<Interval> intervals  = {Interval(0,30),Interval(5,10),Interval(15,20)};
    bool               result     = false;
    Test("Test0", intervals, result);
}
void Test1()
{
    std::vector<std::vector<int>> intervals = {{0,30}, {5,10}, {15,20}};
    bool               result     = false;
    Test("Test1", intervals, result);
}

void Test2()
{
    std::vector<std::vector<int>> intervals = {{7,10}, {2,4}};
    bool               result     = true;
    Test("Test2", intervals, result);
}

void Test3()
{
    std::vector<std::vector<int>> intervals  = {{1,4},{2,5},{7,9}};
    bool               result     = false;
    Test("Test3", intervals, result);
}

void Test4()
{
    std::vector<std::vector<int>> intervals  = {{6,7},{2,4},{8,12}};
    bool               result     = true;
    Test("Test4", intervals, result);
}

void Test5()
{
    std::vector<std::vector<int>> intervals  = {{4,5},{2,3},{3,6}};
    bool               result     = false;
    Test("Test5", intervals, result);
}

void Test6()
{
    std::vector<std::vector<int>> intervals = {{4,5}, {2,3}, {5,7},{7,8}};
    bool               result     = false;
    Test("Test6", intervals, result);
}

int main()
{
    Test0();
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;

}
