/*
 * 45. Jump Game II
 * Hard
 * Given an array of non-negative integers,
 * you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *********************************************
 * 定一个非负整数数组，你最初位于数组的第一个位置。
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 *********************************************
 * Example:
 *
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation:
 *     The minimum number of jumps to reach the last index is 2.
 *     Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *     跳到最后一个位置的最小跳跃数是 2。  
 *     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 ******************************************
 * Note:
 *
 * 假设你总是可以到达数组的最后一个位置。
 * You can assume that you can always reach the last index.
 ******************************************
 * Constraints:
 *
 * 1 <= nums.length <= 3 * 104
 * 0 <= nums[i] <= 105
 ******************************************
 */

#include <stack>
#include <queue>
#include <chrono>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <algorithm>

class Solution {
public:
    template <typename T>
    int printvector(std::vector<T> v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";
        }
        std::cout << std::endl;
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

/////////////////////////////////////////////////////////////
    int jump0(std::vector<int> &nums)
    {
        int ans = 0;
        int start = 0;
        int end = 1;
        while (end < nums.size())
        {
            int maxPos = 0;
            for (int i = start; i < end; i++)
            {
                // 能跳到最远的距离
                maxPos = std::max(maxPos, i + nums[i]);
                std::cout << "i+nums[i](" << i << "+nums[" << i << "]): " << i +nums[i] << std::endl;
            }
            std::cout << "maxPos:" << maxPos << std::endl;
            start = end;      // 下一次起跳点范围开始的格子
            end = maxPos + 1; // 下一次起跳点范围结束的格子
            ans++;            // 跳跃次数
            std::cout << "start:" << start  << " , end:" << end << std::endl;
            sleep(1);
        }
        return ans;
    }
/////////////////////////////////////////////////////////////
    int jump1(std::vector<int>& nums)
    {
        if (nums.size() < 2)
        {
            return 0;
        }
        int current_max_index = nums[0];
        int pre_max_max_index = nums[0];
        int jump_min = 1;
        for (int i= 1; i < nums.size(); i++)
        {
            std::cout << "i:" << i << ",nums[" << i << "]:" << nums[i]<<std::endl;
            std::cout << "current_max_index:" << current_max_index << std::endl;
            if (i > current_max_index)
            {
                jump_min++;
                std::cout << "jump_min++:" << jump_min << std::endl;
                current_max_index = pre_max_max_index;
            }
            std::cout << "pre_max_max_index:" << pre_max_max_index<< std::endl;
            std::cout << "nums[i]+i:" << nums[i]+i << std::endl;
            if (pre_max_max_index < nums[i] + i)
            {
                // 更新pre_max_max_index
                pre_max_max_index = nums[i] + i;
                std::cout << "更新pre_max_max_index:" << pre_max_max_index <<std::endl;
            }
        }
        return jump_min;
    }
/////////////////////////////////////////////////////////////
    int jump2(std::vector<int> &nums)
    {
        int n = nums.size();
        memo= std::vector<int>(n,n);
        return dp(nums, 0);
    }
    std::vector<int> memo;
    int dp(std::vector<int> &nums, int p)
    {
        int n = nums.size();
        if (p >= n-1)
        {
            return 0;
        }
        if (memo[p] != n)
        {
            return memo[p];
        }
        int steps = nums[p];
        for (int i = 1; i <= steps; i++)
        {
            int subproblem = dp(nums, p+i);
            memo[p] = std::min(memo[p], subproblem);
        }
        return memo[p];
    }
/////////////////////////////////////////////////////////////
    int jump3(std::vector<int> &nums)
    {
        int n = nums.size();
        int end = 0;
        int farthest = 0;
        int jumps = 0;
        for (int i= 0; i < n-1; i++)
        {
            farthest = std::max(farthest, nums[i] + i);
            if (end == i)
            {
                jumps ++;
                end = farthest;
            }
        }
        return jumps;
    }

};
// 2, 3, 1, 1, 4
// 2  4  2  3  8
//
// 3  2  1  0  4
// 3  3  3  0  8

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int> &nums,
        int  expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printvector(nums);
    // getpermutataion
const static int TEST_TIME = 1;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.jump0(nums);
        // bool result = true;
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
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.jump1(nums);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
            std::cout << "Solution1 passed." << std::endl;
        else
            std::cout << "Solution1 failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.jump2(nums);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
            std::cout << "Solution2 passed." << std::endl;
        else
            std::cout << "Solution2 failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution2 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.jump3(nums);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
            std::cout << "Solution3 passed." << std::endl;
        else
            std::cout << "Solution3 failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution3 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    std::cout << "---------------------------------------------------" << std::endl;
}

void Test1()
{
    std::vector<int> nums = {2,3,1,1,4};
    int result = 2;
    Test("Test1", nums , result);
}

void Test2()
{
    std::vector<int> nums = {3,2,0,1,4};
    int result = 2;
    Test("Test2", nums , result);
}

void Test3()
{
    std::vector<int> nums = {2,3,1,1,0,1,4};
    int result = 2;
    Test("Test3", nums , result);
}

void Test4()
{
    std::vector<int> nums = {1,2,3};
    int result = 2;
    Test("Test4", nums , result);
}

void Test5()
{
    std::vector<int> nums = {1};
    int result = 1;
    Test("Test5", nums , result);
}

void Test6()
{
    std::vector<int> nums = {1,0};
    int result = 1;
    Test("Test6", nums , result);
}

void Test7()
{
    std::vector<int> nums = {3,2,1};
    int result = 1;
    Test("Test7", nums , result);
}

int main()
{
    Solution solution;

    Test1();
    Test2();
    //Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
