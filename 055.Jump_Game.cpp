/*
 * 55. Jump Game
 *  Medium
 *  Given an array of non-negative integers,
 *  you are initially positioned at the first index of the array.
 *  Each element in the array represents your maximum jump length at that position.
 *  Determine if you are able to reach the last index.
 ******************************************
 *  给定一个非负整数数组，你最初位于数组的第一个位置。
 *  数组中的每个元素代表你在该位置可以跳跃的最大长度。
 *  判断你是否能够到达最后一个位置。
 ******************************************
 *  Example 1:
 *  
 *  Input: [2,3,1,1,4]
 *  Output: true
 *  Explanation: 
 *      Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *      我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
 ******************************************
 *  Example 2:
 *  
 *  Input: [3,2,1,0,4]
 *  Output: false
 *  Explanation:
 *      You will always arrive at index 3 no matter what. 
 *      Its maximum jump length is 0, 
 *      which makes it impossible to reach the last index.
 *      无论怎样，你总会到达索引为 3 的位置。
 *      但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
 ******************************************
 *  Constraints:
 * 
 * 1 <= nums.length <= 3 * 10^4
 * 0 <= nums[i][j] <= 10^5
 ******************************************
 * 
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

    bool canJump0(std::vector<int>& nums) 
    {
        std::vector<int> index;
        for (int i = 0; i < nums.size(); i++)
        {
            index.push_back(i+nums[i]);
        }
        printvector(index);
        int jump = 0;
        int max_index = index[0];
        // Farest possible location vector
        while (jump < index.size() && jump <= max_index)
        {
            std::cout << " max_index:" << max_index << std::endl;
            std::cout << "index[jump]:" << index[jump] << std::endl;
            if (max_index < index[jump])
            {
                max_index = index[jump];
            }
            jump++;
        }
        if (jump == index.size())
            return true;
        return false;
    }

    bool canJump1(std::vector<int>& nums) 
    {
        // Get the maximum position nums[i] can achieve
        // If the maximum value does not reach the i position, FALSE
        int max = nums[0];
        for (int i = 0; i < nums.size()-1 && i <= max ; ++i)
        {
            std::cout << "max:" << max ;//<< std::endl;
            std::cout << " , i:" << i ;//<< std::endl;
            std::cout << " , nums[i]:" << nums[i] << std::endl;
            std::cout << "i + nums[i]:" << i+nums[i] << std::endl;
            if ( i + nums[i] >= max )
            {
                max = i + nums[i];
                std::cout << "update max:" << max << std::endl;
            }
        }
        std::cout << "final max:" << max ;//<< std::endl;
        std::cout << ",nums.size - 1:" << nums.size()-1 << std::endl;
        if (max >= nums.size() - 1)
        {
            return true;
        }
        return false;
    }
    bool canJump2(std::vector<int>& nums) 
    {
        int i = 0;
        int n = nums.size();
        for (int reach = 0; i < n && i <= reach ; ++i)
        {
            reach = std::max(i + nums[i], reach);
        }
        return i == n;
    }
    bool canJump3(std::vector<int> & nums)
    {
        int n = nums.size();
        int farthest = nums[0];
        for (int i=0; i < n-1;i++)
        {
            farthest = std::max(farthest, i + nums[i]);
            if (farthest <= i)
            {
                return false;
            }
        }
        return farthest >= n-1;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName, 
        std::vector<int> &nums,
        bool expected)
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

        bool result = solution.canJump0(nums);
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

        decltype(expected) result = solution.canJump1(nums);
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

        decltype(expected) result = solution.canJump2(nums);
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

        decltype(expected) result = solution.canJump3(nums);
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
}

void Test1()
{
    std::vector<int> nums = {2,3,1,1,4};
    bool result = true;
    Test("Test1", nums , result);
}

void Test2()
{
    std::vector<int> nums = {3,2,1,0,4};
    bool result = true;
    Test("Test2", nums , result);
}

void Test3()
{
    std::vector<int> nums = {2,3,1,1,0,1,4};
    bool result = true;
    Test("Test3", nums , result);
}

void Test4()
{
    std::vector<int> nums = {1,2,3};
    bool result = true;
    Test("Test4", nums , result);
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
