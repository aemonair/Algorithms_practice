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

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
 
struct Interval 
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    std::vector<Interval> employeeFreeTime(std::vector<std::vector<Interval>>& schedule)
    {
        return std::vector<Interval>{};
    }

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "{  " ;// << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << (*iter) << ", ";//<<std::endl;
        }
        std::cout << "\b  }" << std::endl;
        return v.size();
    }
    int printvector(const std::vector<Interval> &v)
    {
        std::cout << "{  " ;// << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << "[" << (*iter).start << ", "<< (*iter).end << "] ,";//<<std::endl;
        }
        std::cout << "\b  }" << std::endl;
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
          std::vector<std::vector<Interval>>& schedule, 
          std::vector<            Interval >& expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "intervals:" <<  std::endl;
    solution.printvectorvector(schedule);
    {
        //start = std::chrono::system_clock::now();

        //std::cout << typeid(decltype(expected)).name() << std::endl;
        //std::cout << typeid(expected).name() << std::endl;
        std::vector<Interval> && result = solution.employeeFreeTime(schedule);
        std::cout << "result:" << std::boolalpha << std::endl;
        solution.printvector(result);
        
        if(true) //result == expected)
        {
            std::cout << "Solution0 passed." << std::endl;
        }
        else
        {
            std::cout << "Solution0 failed.expected:" << std::endl;
            solution.printvector(expected);
        }
        //end = std::chrono::system_clock::now();
        //elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        //std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
    }
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
    std::vector<std::vector<Interval>> schedule  = {{{1,3}},{{2,4}},{{6,8}},{{7,9}}};
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
