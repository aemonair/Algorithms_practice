/*
 * 213. House Robber II
 * Medium
 *
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed.
 * All houses at this place are arranged in a circle.
 * That means the first house is the neighbor of the last one.
 * Meanwhile, adjacent houses have a security system connected,
 * and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the police.
 *
 *********************************************************
 * Example 1:
 *
 * Input: nums = [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
 *********************************************************
 * Example 2:
 *
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *********************************************************
 * Example 3:
 *
 * Input: nums = [0]
 * Output: 0
 *********************************************************
 * Constraints:
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 *********************************************************
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
    //
    int dp(std::vector<int> &nums, int start, int end)
    {
        int a = 0;
        int b = 0;
        int max = 0;

        for (int i = end; i >= start; i--)
        {
            max = std::max(a, b + nums[i]);
            b = a;
            a = max;
        }
        return max;
    }
    int rob(std::vector<int>& nums)
    {
        int size  = nums.size();

        return std::max(
               dp(nums, 0, size-2) ,
               dp(nums, 1, size-1) );
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
        std::vector<int> & nums,
        int expected)
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

        decltype(expected) result = solution.rob(nums);
        std::cout << "result:" << std::boolalpha << result <<  std::endl;

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
    std::vector<int> nums = {2, 3, 2} ;
    Test("Test1", nums , 3);
}
void Test2()
{
    std::vector<int> nums = {1, 2, 3, 1} ;
    Test("Test2", nums , 4);
}

void Test3()
{
    std::vector<int> nums = {0} ;
    Test("Test3", nums , 0);
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
