/*
/*
 * 416. Partition Equal Subset Sum
 * Medium
 *
 * Given a non-empty array containing only positive integers, 
 * find if the array can be partitioned into two subsets such that 
 * the sum of elements in both subsets is equal.
 * 
 * Note:
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * Example 1:
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
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
//    bool 
    bool canPartition(std::vector<int>& nums)
    {
        int sum = 0;
        for (auto num: nums)
        {
            sum += num;
        }
        if (sum % 2 == 1)
            return false;
        int size = nums.size();
        std::vector<std::vector<bool>> dp(size + 1,std::vector<bool>(sum/2+1,false));
        for (int i = 0; i <= size ; i++)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= sum/2; j++)
            {
                std::cout << "i:" << i << ",nums[" << i << "]:"<< nums[i]
                    << ",j:" << j << std::endl;
                std::cout << "dp[i-1][j]:dp["<<i-1<<"]["<<j<<"]:" << std::boolalpha << dp[i-1][j] ;//<< std::endl;
                if (j - nums[i-1] < 0)
                {
                    dp[i][j] = dp[i-1][j];
                    std::cout << std::endl;
                }
                else
                {
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i-1]];
                    //std::cout << "dp[i-1][j]:dp["<<i-1<<"]["<<j<<"]:" <<dp[i-1][j] << ;
                    std::cout << " | dp[i-1][j-nums[i-1]]:" << "dp["<<i-1<<"][" << j - nums[i-1] << "]:" << std::boolalpha << dp[i-1][j-nums[i-1]] << std::endl;
                }
                std::cout << "get dp["<<i<<"]["<<j<<"]" << std::boolalpha << dp[i][j] << std::endl;
            }
        }
        std::cout << "dp[" << size << "][" << sum/2 << "]:" << dp[size][sum/2] << std::endl;
        return dp[size][sum/2];
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
void Test(const std::string& testName, std::vector<int> & nums,bool expected)
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

        std::cout << "nums:";
        solution.printvector(nums);

        decltype(expected) result = solution.canPartition(nums);
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
    std::vector<int> nums = {1, 5, 11, 5};
    Test("Test1",nums, true);
}
void Test2()
{
    std::vector<int> nums = {1, 2,  3, 5};
    Test("Test2",nums, false);
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
