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

template<typename T>
int printvector(std::vector<T> v);


template <typename T>
int printstack(std::stack<T> s);

template <typename T1, typename T2>
int printunordered_map(const std::unordered_map<T1,T2> &v);

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
};
int printvector(std::vector<Interval> v);
std::ostream & operator << (std::ostream &out, const Interval & a);
bool operator == (Interval &a, Interval & b) {
    return a.start == b.start && a.end == b.end;
}

class Solution {
public:
    std::vector<Interval> employeeFreeTime(std::vector<std::vector<Interval>>& schedule)
    {
        // -----------
        //   -----
        //         ----
        std::vector<Interval> schedules;
        std::vector<Interval> result;
        for (int i = 0; i < schedule.size(); ++i) {
            for (int j = 0; j < schedule[i].size(); ++j) {
                schedules.push_back(schedule[i][j]);
            }
        }
        sort(schedules.begin(), schedules.end(), [](Interval &a, Interval &b){
                return a.start < b.start;
                });
        printvector(schedules);
        for (int i =0; i < schedules.size()-1; ++i) {
            if (schedules[i].end < schedules[i+1].start) {
                result.push_back({schedules[i].end, schedules[i+1].start});
            }
            schedules[i+1].start = std::min(schedules[i+1].start, schedules[i].start);
            schedules[i+1].end   = std::max(schedules[i+1].end  , schedules[i].end  );
        }
        return result;
        return std::vector<Interval>{};
        return std::vector<Interval>{};
    }
    std::vector<Interval> employeeFreeTime1(std::vector<std::vector<Interval>>& schedule)
    {
        auto startcmp = [](std::pair<Interval, std::pair<int,int>> &a,
                           std::pair<Interval, std::pair<int,int>> &b){
            return a.first.start > b.first.start;
        };
        std::priority_queue<std::pair<Interval, std::pair<int,int>>,
            std::vector<std::pair<Interval, std::pair<int,int>>>,
            decltype(startcmp)> pq(startcmp);
        for (int i = 0; i < schedule.size(); ++i) {
            pq.push(std::make_pair(schedule[i][0], std::make_pair(i, 0)));
        }
        printqueue(pq);
        Interval prev = pq.top().first;
        std::vector<Interval> result;
        while (!pq.empty()) {
            std::cout << "prev:" << prev << " " ; //std::endl;
            auto qtop = pq.top();
            pq.pop();
            std::cout << "qtop:" << qtop.first << " pop " << std::endl;
            // --- ___
            if (prev.end < qtop.first.start) {
                result.push_back({prev.end, qtop.first.start});
                std::cout << "push_back" << prev.end<< "~" << qtop.first.start<< std::endl;
                prev = qtop.first;
            } else {
                // --- 交叉(prev换到下一个)   ---- (prev不换)
                //   ---                       --
                if (prev.end < qtop.first.end) {
                    prev = qtop.first;
                }
            }
            std::cout << "prev=:" << prev << std::endl;
            printqueue(pq);
            std::vector<Interval> employeeschedule = schedule[qtop.second.first];
            std::cout << "curr employee:" << " ";
            printvector(employeeschedule);
            if (employeeschedule.size() > qtop.second.second + 1) {
                std::cout << "push:" << " " << qtop.second.first << " " << qtop.second.second << " ";
                pq.push(make_pair(employeeschedule[qtop.second.second+1],
                            std::make_pair(qtop.second.first, qtop.second.second+1)));
            }
        }
        return result;
        return {};
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
          std::vector<std::vector<Interval>>& schedule,
          std::vector<            Interval >& expected)
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
    printvector(schedule);
const static int TEST_TIME = 1;
const static int TEST_0    = 0;
const static int TEST_1    = 1;
    if (TEST_0)
    {
        if (TEST_TIME) {
            start = std::chrono::system_clock::now();
        }
        std::vector<Interval> && result = solution.employeeFreeTime(schedule);
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
        std::vector<Interval> && result = solution.employeeFreeTime1(schedule);
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
std::ostream & operator << (std::ostream &out, const Interval & a)
{
    out << "(" << a.start << "," << a.end << ") " ;
    return out;
}
std::ostream & operator << (std::ostream &out, const std::pair<int,int> & a)
{
    out << "[" << a.first << "," << a.second << "] " ;
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
//template<>
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
        std::cout << "{" << iter->first << "," << iter->second<< "}, ";//<<std::endl;
    }
    std::cout << std::endl;
    return v.size();
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

void Test1()
{
    std::vector<std::vector<Interval>> schedule  = {{{1,3},{5,6}},{{2,3},{6,8}}};
    std::vector<            Interval > result    = {{3,5}};
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
    std::vector<std::vector<Interval>> schedule  = {{{1,3},{9,12}},{{2,4}},{{6,8}}};
    std::vector<            Interval > result    = {{4,6},{8,9}};
    Test("Test2", schedule, result);
}

void Test3()
{
    std::vector<std::vector<Interval>> schedule  = {{{1,3}},{{2,4}},{{3,5}},{{7,9}}};
    std::vector<            Interval > result    = {{5,7}};
    Test("Test3", schedule, result);
}

void Test4()
{
    std::vector<std::vector<Interval>> schedule  = {{{1,2}},{{5,6}},{{1,3}},{{4,10}}};
    std::vector<            Interval > result    = {{3,4}};
    Test("Test4", schedule, result);
}

void Test5()
{
    std::vector<std::vector<Interval>> schedule  = {{{1,3}},{{6,7}},{{2,4}},{{2,5},{9,12}}};
    std::vector<            Interval > result    = {{5,6},{7,9}};
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
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;

}
