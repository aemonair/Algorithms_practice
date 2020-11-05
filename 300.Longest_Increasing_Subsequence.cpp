/*
 * 300. Longest Increasing Subsequence
 * Medium
 * 
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 * 
 *********************************************************
 * Example:
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 ********************************************************* 
 * Note:
 * 
 * There may be more than one LIS combination, it is only necessary for you to return the length.
 * Your algorithm should run in O(n2) complexity.
 * Follow up: Could you improve it to O(n log n) time complexity?
 *********************************************************
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
    int lengthOfLIS1(std::vector<int>& nums) 
    {
        int size = nums.size();
        std::vector<int> top(size);
        int piles = 0;
        for (int i =0; i < size;i++)
        {
            int poker = nums[i];

            int left = 0;
            int right = piles;
            while (left < right)
            {
                int mid = (left+right)/2;
                if (top[mid] > poker)
                {
                    right = mid;
                }
                else if(top[mid] < poker)
                {
                    left = mid+1;
                }
                else
                {
                    right = mid;
                }
            }
            if (left == piles)
            {
                piles++;
            }
            top[left] = poker;
            printvector(top);
        }
        return piles;
        return 0;
    }
    int lengthOfLIS0(std::vector<int>& nums) 
    {
        int size = nums.size();
        std::vector<int> dp(size, 1);

        dp[0] =1;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = std::max(dp[i], dp[j]+1);
                }
            }
            // error: 
            // dp[i] = nums[i-1] < nums[i] ? dp[i-1] + 1 : dp[i-1];
        }
        printvector(dp);

        int result = 0;
        for (auto it : dp)
        {
            result = std::max(it, result);
        }
        
        return result;
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
        std::vector<int>& nums,
        int expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "nums:" << std::endl;
    solution.printvector(nums);
    // getpermutataion
    {
        //start = std::chrono::system_clock::now();

        decltype(expected) result = solution.lengthOfLIS0(nums);
        std::cout << "result:" << std::boolalpha << result <<  std::endl;

        if(result == expected)
            std::cout << "Solution0 passed." << std::endl;
        else
            std::cout << "Solution0 failed." << std::endl;
        //end = std::chrono::system_clock::now();
        //elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        //std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
    }
    {
        //start = std::chrono::system_clock::now();

        decltype(expected) result = solution.lengthOfLIS1(nums);
        std::cout << "result:" << std::boolalpha << result <<  std::endl;

        if(result == expected)
            std::cout << "Solution1 passed." << std::endl;
        else
            std::cout << "Solution1 failed." << std::endl;
        //end = std::chrono::system_clock::now();
        //elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        //std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
    }
}
void Test1()
{
    std::vector<int> nums = {10,9,2,5,3,7,101,18};
    Test("Test1", nums, 4);
}

void Test2()
{
    std::vector<int> nums = {1,4,3,4,2,3};
    Test("Test2", nums, 3);
}

void Test3()
{
    std::vector<int> nums = {6,3,5,10,11,2,9,14,13,7,4,8,12};
    Test("Test3", nums, 5);
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
