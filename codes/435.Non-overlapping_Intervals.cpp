/*
 * 435. Non-overlapping Intervals
 * Medium
 *
 * Given a collection of intervals,
 * find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 *******************************************************************
 * Example 1:
 *
 * Input: [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
 *******************************************************************
 * Example 2:
 *
 * Input: [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
 *******************************************************************
 * Example 3:
 *
 * Input: [[1,2],[2,3]]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 *******************************************************************
 * Note:
 *
 * You may assume the interval's end point is always bigger than its start point.
 * Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
 *******************************************************************
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

class Solution {
public:
    static bool compare(const std::vector<int> &int1, const std::vector<int> &int2)
    {
        return int1[1] < int2[1];
    }
    //////////////////////////////////////////////////////////////
    int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end(), Solution::compare);
        //printvectorvector(intervals);
        int count = 1;
        int x_end = intervals[0][1];
        for (auto interval: intervals)
        {
            int start = interval[0];
            if (start >= x_end)
            {
                count ++;
                x_end = interval[1];
            }
        }
        return intervals.size() - count;
    }

    //////////////////////////////////////////////////////////////
    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        //std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "(" ;//<< std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";//<<std::endl;
        }
        std::cout << "\b\b) " ; //<< std::endl;
        //std::cout << std::endl;
        return v.size();
    }
    template <typename T1, typename T2>
    int printvector(const std::pair<T1,T2> &v)
    {
        std::cout << "(" << v.first <<","<< v.second << ") ";//<<std::endl;
        return 0;
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
    template <typename T>
    int printvvvector(const std::vector<T> &v)
    {
        std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvectorvector( *iter );
        }
        std::cout << std::endl;
        return v.size();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<std::vector<int>> &intervals,
        int expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printvectorvector(intervals);
    // getpermutataion
const static int TEST_TIME = 0;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        int result = solution.eraseOverlapIntervals(intervals);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
            std::cout << "Solution0 passed." << std::endl;
        else
            std::cout << "Solution0 failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
}

void Test1()
{
    std::vector<std::vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    std::cout << "012345"<< std::endl;
    std::cout << " _.   "<< std::endl;
    std::cout << "  _.  "<< std::endl;
    std::cout << "   _. "<< std::endl;
    std::cout << " __.  "<< std::endl;
    int result = 1;
    Test("Test1", intervals , result);
}

void Test2()
{
    std::vector<std::vector<int>> intervals = {{1,2},{1,2},{1,2}};
    int result = 2;
    Test("Test2", intervals , result);
}

void Test3()
{
    std::vector<std::vector<int>> intervals = {{1,2},{2,3}};
    int result = 0;
    Test("Test3", intervals , result);
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
