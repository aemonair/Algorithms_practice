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

template<typename T1,typename T2>
std::ostream & operator << (std::ostream &out, const std::pair<T1,T2> &_pair);
template<typename T>
std::ostream & operator << (std::ostream &out, const std::vector<T> &_vec);
template <typename ...T>
std::ostream & operator << (std::ostream &out, std::priority_queue<T...> big_queue);

class Solution
{
public:
    std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals)
    {
        std::cout << intervals << std::endl;
        std::vector<int> ans(intervals.size(), -1);
        std::vector<std::pair<int, int> > startInterval;
        for (int i=0; i< intervals.size(); ++i) {
            startInterval.emplace_back(intervals[i][0], i);
        }
        std::cout << startInterval << std::endl;
        sort(startInterval.begin(), startInterval.end());
        std::cout << startInterval << std::endl;
        for (int i=0; i< startInterval.size(); ++i) {
            auto it = std::lower_bound(startInterval.begin(), startInterval.end(), std::make_pair(intervals[i][1], 0));
            if (it != startInterval.end()) {
                ans[i] = it->second;
                std::cout << "ans[i] " << i << " " << it->second;
            }
        }

        return ans;
    }
    std::vector<int> findRightInterval1(std::vector<std::vector<int>>& intervals)
    {
        std::vector<std::pair<int, int>> startIntervals;
        std::vector<std::pair<int, int>> endIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            startIntervals.emplace_back(intervals[i][0], i);
            endIntervals.emplace_back(intervals[i][1], i);
        }
        std::cout << startIntervals << std::endl;
        std::cout << endIntervals << std::endl;
        sort(startIntervals.begin(), startIntervals.end());
        sort(endIntervals.begin(), endIntervals.end());
        std::cout << startIntervals << std::endl;
        std::cout << endIntervals << std::endl;

        std::vector<int> ans(n, -1);
        for (int i = 0, j = 0; i < n && j < n; i++) {
            std::cout << "i:" << i << "j:" << j << " " << endIntervals[i] << " "<< startIntervals[j];
            while (j < n && endIntervals[i].first > startIntervals[j].first) {
                j++;
            }
            std::cout << "i:" << i << "j:" << j << " " << endIntervals[i]<<" " << startIntervals[j] << std::endl;
            if (j < n) {
                ans[endIntervals[i].second] = startIntervals[j].second;
                std::cout << "ans[" << endIntervals[i].second << "=" << startIntervals[j].second << std::endl;
            }
        }
        return ans;
    }
    std::vector<int> findRightInterval2(std::vector<std::vector<int>>& intervals)
    {
        auto com0 = [](std::vector<int> &a, std::vector<int> &b){return a[0] < b[0];};
        auto com1 = [](std::vector<int> &a, std::vector<int> &b){return a[1] < b[1];};
        std::unordered_map<int,int> hash;
        std::vector<int> result(intervals.size(), 0);
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(com0)> pq1(com0);
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(com1)> pq2(com1);
        for (int i = 0; i< intervals.size(); ++i) {
            pq1.push(intervals[i]);
            pq2.push(intervals[i]);
            hash[intervals[i][0]] = i;
        }

        while (!pq2.empty() && !pq1.empty()) {
            if (pq2.top()[1] > pq1.top()[0]) {
                result [ hash[pq2.top()[0]] ] = -1;
            } else {
                auto topstart = pq1.top();
                while (!pq1.empty() && pq2.top()[1] <= pq1.top()[0]) {
                    result [ hash[pq2.top()[0]] ] = hash[pq1.top()[0]];
                    topstart = pq1.top();
                    pq1.pop();
                }
                pq1.push(topstart); // 有可能是其他区间的右侧区间,加回来
            }
            pq2.pop();
            //std::cout << pq1 << pq2 << std::endl;
            std::cout <<  pq2 << std::endl;
        }
        return result;
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

    std::cout << "intervals:" << intervals << std::endl;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
const static int TEST_2    = 1;

    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        auto  result = solution.findRightInterval(intervals);
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
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        auto  result = solution.findRightInterval1(intervals);
        std::cout << "result:" << result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if(TEST_2)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        auto  result = solution.findRightInterval2(intervals);
        std::cout << "result:" << result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution2 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution2 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution2 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    std::cout << "-----------------------------" << std::endl;
}
template<typename T1,typename T2>
std::ostream & operator << (std::ostream &out, const std::pair<T1,T2> &_pair)
{
    out << "( " << _pair.first << ", " << _pair.second << ") ";
    return out;
}
template<typename T>
std::ostream & operator << (std::ostream &out, const std::vector<T> &_vec)
{
    out << "[  ";
    for(auto v: _vec)
    {
        out << v << ", ";
    }
    out << "\b\b ]" ;
    return out;
}
template <typename ...T>
std::ostream & operator << (std::ostream &out, std::priority_queue<T...> big_queue)
{
    std::priority_queue<T...> Big_queue = big_queue;
    int bsize = Big_queue.size();
    if (Big_queue.empty())
    {
        out << "The big queue is empty. "<< std::endl;
    }
    std::cout << " | ";
    while (bsize--)
    {
        out << Big_queue.top() << ", " ;
        Big_queue.pop();
    }
    out << std::endl ;
    return out;
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
