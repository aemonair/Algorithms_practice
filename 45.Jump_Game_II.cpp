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
 * 
 */

#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
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

    int jump1(std::vector<int> &nums)
    {
// 2 3 1 1 4
// 2 4 3 5 8
// 2 4 4 5 8
// 0 1 1 2 

// 1 2 3
// 1 3 5
// 0 1 

// 1 0
// 1 1

// 3 2 1
// 3 3 3
    }
    int jump(std::vector<int> &nums)
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
        }
        return ans;
    }
    int jump2(std::vector<int>& nums) 
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

};
// 2, 3, 1, 1, 4
// 2  4  2  3  8
//
// 3  2  1  0  4
// 3  3  3  0  8

int main()
{
    int k = 0;
    Solution a;
    int result;

    std::vector<int> v= {2,3,1,1,4};
    a.printvector(v);
    result = a.jump(v);
    std::cout << "want 2, result :" << result << std::endl <<std::endl;
    //result = a.jump1(v);
    //std::cout << "result 1:" << result << std::endl;

    //v = {3,2,1,0,4};
    //a.printvector(v);
    //result = a.jump(v);
    //std::cout << "result :" << result << std::endl;
    //result = a.jump1(v);
    //std::cout << "result 1:" << result << std::endl;

    //v = {2,3,1,1,0,1,4};
    //a.printvector(v);
    //result = a.jump(v);
    //std::cout << "result :" << result << std::endl;
    //result = a.jump1(v);
    //std::cout << "result1 :" << result << std::endl;

    v = {1,2,3};
    a.printvector(v);
    result = a.jump(v);
    std::cout << "want 2, result :" << result << std::endl <<std::endl;
    //result = a.jump1(v);
    //std::cout << "result1 :" << result << std::endl;

    v = {0}; // 0
    a.printvector(v);
    result = a.jump(v);
    std::cout << "want 0, result :" << result << std::endl <<std::endl;
    //result = a.jump1(v);
    //std::cout << "result1 :" << result << std::endl;
    //
    v = {1}; // 0
    a.printvector(v);
    result = a.jump(v);
    std::cout << "want 0, result :" << result << std::endl <<std::endl;
    //result = a.jump1(v);
    //std::cout << "result1 :" << result << std::endl;
    //
    v = {1,0}; // 1
    a.printvector(v);
    result = a.jump(v);
    std::cout << "want 1, result :" << result << std::endl <<std::endl;
    //result = a.jump1(v);
    //std::cout << "result1 :" << result << std::endl;
    //
    v = {3,2,1};
    a.printvector(v);
    result = a.jump(v);
    std::cout << "want 1, result :" << result << std::endl <<std::endl;
    //result = a.jump1(v);
    //std::cout << "result1 :" << result << std::endl;
    return 0;
}
