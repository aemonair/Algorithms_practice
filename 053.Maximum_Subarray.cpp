/*
 * 53. Maximum Subarray
 * Easy
 * 
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 *******************************************************************
 * Example 1:
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *******************************************************************
 * Example 2:
 * 
 * Input: nums = [1]
 * Output: 1
 *******************************************************************
 * Example 3:
 * 
 * Input: nums = [0]
 * Output: 0
 *******************************************************************
 * Example 4:
 * 
 * Input: nums = [-1]
 * Output: -1
 *******************************************************************
 * Example 5:
 * 
 * Input: nums = [-2147483647]
 * Output: -2147483647
 *******************************************************************
 * Constraints:
 * 
 * 1 <= nums.length <= 2 * 104
 * -231 <= nums[i] <= 231 - 1
 ******************************************************************* 
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
 
class Solution {
public:
    int result = 0;
    //////////////////////////////////////////////////////////////
    int maxSubArray(std::vector<int>& nums) 
    {
        int size = nums.size();
        std::vector<int> dp(size, 0);
        dp[0] = nums[0];
        for (int i = 1; i < size; i++)
        {
            dp[i] = std::max(dp[i-1]+nums[i], dp[i]);
        }
        int result = nums[0];
        for (auto num: dp)
        {
            result = std::max(num, result);
        }
        return result;
    }

    //////////////////////////////////////////////////////////////
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
        std::vector<int>& nums,
        int expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printvector(nums);
    // getpermutataion
const static int TEST_TIME = 0;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        int result = solution.maxSubArray(nums);
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
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int result = 6;
    Test("Test1", nums, result);
}

void Test2()
{
    std::vector<int> nums = {1};
    int result = 1;
    Test("Test2", nums, result);
}

void Test3()
{
    std::vector<int> nums = {0};
    int result = 0;
    Test("Test3", nums, result);
}

void Test4()
{
    std::vector<int> nums = {-1};
    int result = -1;
    Test("Test4", nums, result);
}

void Test5()
{
    std::vector<int> nums = {-2147483647};
    int result = -2147483647;
    Test("Test5", nums, result);
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
