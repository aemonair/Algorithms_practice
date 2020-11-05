/*
 * 494. Target Sum
 * Medium
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. 
 * Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to target S.
 * 
 ************************************************************************
 *  Example 1:
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3.
 * Output: 5
 * Explanation:
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 **********************************************************************
 *  Constraints:
 * 
 * The length of the given array is positive and will not exceed 20.
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
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
    void backtrack(std::vector<int> &nums, int i, int res)
    {
        if (i == nums.size())
        {
            if (0 == res)
            {
                result++;
            }
            return;
        }
        res += nums[i];
        backtrack(nums, i+1, res);
        res -= nums[i];

        res -= nums[i];
        backtrack(nums, i+1, res);
        res += nums[i];
    }
    int findTargetSumWays0(std::vector<int>& nums, int S) 
    {
        result = 0;
        backtrack(nums ,0, S);
        return result;
    }
    //////////////////////////////////////////////////////////////
    int findTargetSumWays1(std::vector<int>& nums, int S) 
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        return dp(nums, 0, S);
    }
    int dp(std::vector<int> & nums, int i , int rest)
    {
        if (i == nums.size())
        {
            if (rest == 0)
            {
                return 1;
            }
            return 0;
        }
        int result = dp(nums, i+1, rest - nums[i]) +
                     dp(nums, i+1, rest + nums[i]);
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
        int S,
        int expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printvector(nums);
    std::cout << "S:" << S << std::endl;
    // getpermutataion
const static int TEST_TIME = 1;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        int result = solution.findTargetSumWays0(nums, S);
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

        int result = solution.findTargetSumWays1(nums, S);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            std::cout << "Solution1 passed." << std::endl;
        }
        else
        {
            std::cout << "Solution1 failed." << std::endl;
        }
        if (TEST_TIME)
        {
            end = std::chrono::system_clock::now();
            elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
}

void Test1()
{
    std::vector<int> nums = {1, 1, 1, 1, 1}; 
    int S= 3;
    int result = 5;
    Test("Test1", nums, S, result);
}

void Test2()
{
}

void Test3()
{
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
