/*
 * 239. Sliding Window Maximum
 * Hard
 ****************************************************************************** 
 * You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 * 
 * Return the max sliding window.
 * 
 ****************************************************************************** 
 * Example 1:
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation:
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 ****************************************************************************** 
 * Example 2:
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 ****************************************************************************** 
 * Example 3:
 * 
 * Input: nums = [1,-1], k = 1
 * Output: [1,-1]
 ****************************************************************************** 
 * Example 4:
 * 
 * Input: nums = [9,11], k = 2
 * Output: [11]
 ****************************************************************************** 
 * Example 5:
 * 
 * Input: nums = [4,-2], k = 2
 * Output: [4]
 ****************************************************************************** 
 * Constraints:
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 ****************************************************************************** 
 */

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
 
class MonotonicQueue
{
    std::list<int> q;
public:
    void push(int n)
    {
        while(!q.empty() && q.back() < n)
        {
            q.pop_back();
        }
        q.push_back(n);
    }
    int max()
    {
        return q.front();
    }
    void pop(int n)
    {
        if (n== max())
        {
            q.erase(q.begin());
        }
    }
};
class Solution 
{
public:
    // 
    std::vector<int> maxSlidingWindow( 
            std::vector<int>& nums, int k
            )
    {
        std::vector<int> ans;
        return ans;
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

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << "| ";//<<std::endl;
        }
        std::cout << std::endl;
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
        std::vector<int>& nums, int k
       ,std::vector<int>& expected
        )
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // getpermutataion
    {
        //start = std::chrono::system_clock::now();

        std::cout << "nums:" << std::endl;
        solution.printvector(nums);

        //decltype(expected) 
        std::vector<int> && result = solution.maxSlidingWindow(nums, k);
        std::cout << "result:" << std::endl;
        solution.printvector(result);

        if(result == expected)
            std::cout << "Solution0 passed." << std::endl;
        else
            std::cout << "Solution0 failed." << std::endl;
        //end = std::chrono::system_clock::now();
        //elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        //std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
    }
}
void Test1()
{
    std::vector<int> nums   = {1,3,-1,-3,5,3,6,7};
    std::vector<int> expect = {3,3,5,5,6,7};
    Test("Test1", nums, 3, expect);
}
void Test2()
{
    std::vector<int> nums   = {1};
    std::vector<int> expect = {1};
    Test("Test2", nums, 1, expect);
}

void Test3()
{
    std::vector<int> nums   = {1,-1};
    std::vector<int> expect = {1,-1};
    Test("Test3", nums, 1, expect);
}

void Test4()
{
    std::vector<int> nums   = {9,11};
    std::vector<int> expect = {11};
    Test("Test4", nums, 2, expect);
}

void Test5()
{
    std::vector<int> nums   = {4,-2};
    std::vector<int> expect = {4};
    Test("Test5", nums, 2, expect);
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
