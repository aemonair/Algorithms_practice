/*
 * 452. Minimum Number of Arrows to Burst Balloons 
 * Medium
 *
 *********************************************
 * There are some spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. 
 * Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. 
 * The start is always smaller than the end.
 * 
 * An arrow can be shot up exactly vertically from different points along the x-axis. 
 * A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. 
 * There is no limit to the number of arrows that can be shot. 
 * An arrow once shot keeps traveling up infinitely.
 * 
 * Given an array points where points[i] = [xstart, xend], return the minimum number of arrows that must be shot to burst all balloons.
 * 
 * 
 *********************************************
 * 在二维空间中有许多球形的气球。
 * 对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。
 * 由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。
 * 开始坐标总是小于结束坐标。平面内最多存在104个气球。
 * 
 * 一支弓箭可以沿着x轴从不同点完全垂直地射出。
 * 在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。
 * 可以射出的弓箭的数量没有限制。 
 * 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。
 * 
 *********************************************
 * Example1:
 * 
 * Input: 
 * points = [[10,16], [2,8], [1,6], [7,12]]
 * Output: 2
 * Explanation: 
 * One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
 * 对于该样例，我们可以在x = 6（射爆[2,8],[1,6]两个气球）和 x = 11（射爆另外两个气球）。
 * 
 ******************************************
 * Example 2:
 * 
 * Input: points = [[1,2],[3,4],[5,6],[7,8]]
 * Output: 4
 ******************************************
 * Example 3:
 * 
 * Input: points = [[1,2],[2,3],[3,4],[4,5]]
 * Output: 2
 ******************************************
 * Example 4:
 * 
 * Input: points = [[1,2]]
 * Output: 1
 ******************************************
 * Example 5:
 * 
 * Input: points = [[2,3],[2,3]]
 * Output: 1
 ******************************************
 * Constraints:
 * 
 * 0 <= points.length <= 104
 * points[i].length == 2
 * -231 <= xstart < xend <= 231 - 1
 ******************************************
 */

#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <chrono>
#include <cstring>
#include <iostream>
#include <algorithm>

class Solution {
public:
    template <typename T>
    int printvectorvector(std::vector<T> v)
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
    int printvector(const std::vector<T> &v)
    {
        std::cout << "(" ;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";
        }
        std::cout << "\b\b) " ; 
        return v.size();
    }

    template <typename T>
    int printstack(std::stack<T> s)
    {
        if (s.empty())
        {
            std::cout << "The stack is empty." << std::endl;
            return 0;
        }
        std::cout <<  "The stack size is: " << s.size() << std::endl;
        std::stack<T> tmp;
        while (!s.empty())
        {
            std::cout << s.top() << ", ";
            s.pop();
        }
        std::cout <<  std::endl;
        return s.size();
    }

    int findMinArrowShots(std::vector<std::vector<int>>& points) 
    {
        if (points.size()  == 0)
        {
            return 0;
        }
        std::sort(begin(points), end(points),
             [](const std::vector<int> &o1, const std::vector<int> &o2) {
                 return (o1[1] < o2[1]);
             });
        int count = 1;
        int x_end = points[0][1];
        for (int i = 0; i < points.size(); i++)
        {
            int start = points[i][0];
            if(start > x_end)
            {
                count ++;
                x_end = points[i][1];
            } 
        }

        return count;
    }

};


// ==================== TEST Codes====================
void Test(const std::string& testName, 
        std::vector<std::vector<int>> &points,
        int expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printvectorvector(points);
    // getpermutataion
const static int TEST_TIME = 0;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        int result = solution.findMinArrowShots(points);
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
    std::vector<std::vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    int result = 2;
    Test("Test1", points , result);
}

void Test2()
{
    std::vector<std::vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};
    int result = 4;
    Test("Test2", points , result);
}

void Test3()
{
    std::vector<std::vector<int>> points = {{1,2},{2,3},{3,4},{4,5}};
    int result = 2;
    Test("Test3", points , result);
}

void Test4()
{
    std::vector<std::vector<int>> points = {{1,2}};
    int result = 1;
    Test("Test4", points , result);
}

void Test5()
{
    std::vector<std::vector<int>> points = {{2,3},{2,3}};
    int result = 1;
    Test("Test5", points , result);
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
