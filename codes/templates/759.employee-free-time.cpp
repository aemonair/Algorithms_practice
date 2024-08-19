/*
 ******************************************************************
 * 759. Employee Free Time
 * hard
 ******************************************************************
 * We are given a list schedule of employees, which represents the working time for each employee.
 * Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.
 * Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.
 ******************************************************************
 * Example 1:
 *
 * Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
 * Output: [[3,4]]
 * Explanation:
 * There are a total of three employees, and all common
 * free time intervals would be [-inf, 1], [3, 4], [10, inf].
 * We discard any intervals that contain inf as they aren't finite.
 * _1_2_3_4_5_6_7_8_9_10_
 *  __      __         [1,2][5,6]
 *  ____               [1,3]
 *        ____________ [4,10]
 *      ** free        [3,4]
 *  __
 *  ____
 *          __
 *        ____________
 *      ** free
 ******************************************************************
 * Example 2:
 *
 * Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
 * Output: [[5,6],[7,9]]
 *
 * (Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined.)
 *
 * Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.
 * _1_2_3_4_5_6_7_8_9_A_B_C_D_E
 *  ____      __           [1,3][6,7]
 *    ____                 [2,4]
 *    ______        ______ [2,5][9,12]
 *          **  ***        [5,6][7,9]
 *  ____
 *  ____
 *    ____
 *    ______
 *            __
 *                  ______
 *          **  **** free
 *
 ******************************************************************
 * Note:
 *
 * 1.schedule and schedule[i] are lists with lengths in range [1, 50].
 * 2.0 <= schedule[i].start < schedule[i].end <= 10^8.
 ******************************************************************
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

template <typename ...T>
int printqueue(std::priority_queue<T... > big_queue);

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
    bool operator == (Interval const& other) const {
        return this->start == other.start && this->end == other.end;
    }
    friend std::ostream & operator << (std::ostream &out, const Interval & a) {
        out << "(" << a.start << "," << a.end << ") " ;
        return out;
    }
};


bool operator == (Interval &a, Interval & b) {
    return a.start == b.start && a.end == b.end;
}

template <typename T>
int printvector(std::vector<T> _vec) {
    for(int i=0; i< _vec[0]; ++i) {
        std::cout << "  " ; //<< std::endl;
    }
    for(int i= _vec[0]; i< _vec[1]; ++i) {
        std::cout << "- " ; //<< std::endl;
    }
    std::cout << std::endl;
}
int printvector(Interval _vec) {
    for(int i=0; i< _vec.start; ++i) {
        std::cout << "  " ; //<< std::endl;
    }
    for(int i= _vec.start; i< _vec.end; ++i) {
        std::cout << "- " ; //<< std::endl;
    }
    std::cout << std::endl;
}
int printvector(std::pair<int,int> _vec) {
    for(int i=0; i< _vec.first; ++i) {
        std::cout << "  " ; //<< std::endl;
    }
    for(int i= _vec.first; i< _vec.second; ++i) {
        std::cout << "- " ; //<< std::endl;
    }
    std::cout << std::endl;
}
class Solution {
public:
    std::vector<std::vector<int>> employeeFreeTime0(std::vector<std::vector<std::vector<int>>>& schedule)
    {
        return {{}};
    }
    std::vector<std::vector<int>> employeeFreeTime1(std::vector<std::vector<std::vector<int>>>& schedule)
    {
        return {{}};
    }
    std::vector<std::pair<int,int>> employeeFreeTime0(std::vector<std::vector<std::pair<int,int>>>& schedule)
    {
        return {{}};
    }
    std::vector<Interval> employeeFreeTime0(std::vector<std::vector<Interval>>& schedule)
    {
        return std::vector<Interval>{};
    }
};

// ==================== TEST Codes====================
template<typename T>
void Test(const std::string& testName,
          std::vector<std::vector<T>>& schedule,
          std::vector<            T>& expected)
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "intervals:" << schedule << std::endl;
    for (auto i: schedule) {
        for (auto j: i) {
            printvector(j);
        }
    }
const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if (TEST_0)
    {
        if (TEST_TIME) {
            start = std::chrono::system_clock::now();
        }
        std::vector<T>  result = solution.employeeFreeTime0(schedule);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
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
        if (TEST_TIME)
        {
           start = std::chrono::system_clock::now();
        }
        std::vector<T> result = solution.employeeFreeTime0(schedule);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
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
//std::ostream & operator << (std::ostream &out, const Interval & a)
//{
//    out << "(" << a.start << "," << a.end << ") " ;
//    return out;
//}
std::ostream & operator << (std::ostream &out, const std::pair<int,int> & a)
{
    out << "[" << a.first << "," << a.second << "] " ;
    return out;
}

template <typename T1, typename T2>
std::ostream & operator << (std::ostream &out, const std::unordered_map<T1,T2> &v)
{
    out << "unordered_map size: " << v.size() << std::endl;
    for (auto iter = v.begin(); iter != v.end(); iter++ )
    {
        out << "{" << iter->first << "," << iter->second<< "}, ";//<<std::endl;
    }
    out << std::endl;
    return out;
}

template <typename ...T>
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
        std::cout << "{" << Big_queue.top().first << " ," << Big_queue.top().second << "}, " ;
        Big_queue.pop();
    }
    std::cout << std::endl ;
    return bsize;
}

void Test0()
{
    std::vector<std::vector<std::pair<int, int>>> schedule  = {{{1,3},{5,6}},{{2,3},{6,8}}};
    std::vector<std::pair<int,int>> result    = {{3,5}};
    Test("Test0", schedule, result);
}

void Test1()
{
    //std::vector<std::vector<Interval>> schedule  = {{{1,3},{5,6}},{{2,3},{6,8}}};
    //std::vector<            Interval > result    = {{3,5}};
    //std::vector<std::vector<std::vector<int>>> schedule  = {{{1,3},{5,6}},{{2,3},{6,8}}};
    //std::vector<            std::vector<int> > result    = {{3,5}};
    std::vector<std::vector<std::pair<int,int>>> schedule  = {{{1,3},{5,6}},{{2,3},{6,8}}};
    std::vector<            std::pair<int,int> > result    = {{3,5}};
    Test("Test1", schedule, result);
 /* _1_2_3_4_5_6_7_8_9_A_B_C_D_E
  *  ____
  *    __
  *          __
  *            ____
  *      ****    free
  */
}

void Test2()
{
    //std::vector<std::vector<Interval>> schedule  = {{{1,3},{9,12}},{{2,4}},{{6,8}}};
    //std::vector<            Interval > result    = {{4,6},{8,9}};
    //std::vector<std::vector<std::vector<int>>> schedule  = {{{1,3},{9,12}},{{2,4}},{{6,8}}};
    //std::vector<            std::vector<int> > result    = {{4,6},{8,9}};
    std::vector<std::vector<std::pair<int,int>>> schedule  = {{{1,3},{9,12}},{{2,4}},{{6,8}}};
    std::vector<            std::pair<int,int> > result    = {{4,6},{8,9}};
    Test("Test2", schedule, result);
}

void Test3()
{
    //std::vector<std::vector<Interval>> schedule  = {{{1,3}},{{2,4}},{{3,5}},{{7,9}}};
    //std::vector<            Interval > result    = {{5,7}};
    //std::vector<std::vector<std::vector<int>>> schedule  = {{{1,3}},{{2,4}},{{3,5}},{{7,9}}};
    //std::vector<            std::vector<int> > result    = {{5,7}};
    std::vector<std::vector<std::pair<int,int>>> schedule  = {{{1,3}},{{2,4}},{{3,5}},{{7,9}}};
    std::vector<            std::pair<int,int> > result    = {{5,7}};
    Test("Test3", schedule, result);
}

void Test4()
{
    //std::vector<std::vector<Interval>> schedule  = {{{1,2}},{{5,6}},{{1,3}},{{4,10}}};
    //std::vector<            Interval > result    = {{3,4}};
    std::vector<std::vector<std::pair<int,int>>> schedule  = {{{1,2}},{{5,6}},{{1,3}},{{4,10}}};
    std::vector<            std::pair<int,int> > result    = {{3,4}};
    Test("Test4", schedule, result);
}

void Test5()
{
    //std::vector<std::vector<Interval>> schedule  = {{{1,3}},{{6,7}},{{2,4}},{{2,5},{9,12}}};
    //std::vector<            Interval > result    = {{5,6},{7,9}};
    //std::vector<std::vector<std::vector<int>>> schedule  = {{{1,3}},{{6,7}},{{2,4}},{{2,5},{9,12}}};
    //std::vector<            std::vector<int> > result    = {{5,6},{7,9}};
    std::vector<std::vector<std::pair<int,int>>> schedule  = {{{1,3}},{{6,7}},{{2,4}},{{2,5},{9,12}}};
    std::vector<            std::pair<int,int> > result    = {{5,6},{7,9}};
    Test("Test5", schedule, result);
}

void Test6()
{
}

void Test7()
{
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
    Test7();

    return 0;

}
