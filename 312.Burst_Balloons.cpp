/*
 * 312. Burst Balloons
 * Hard
 ******************************************************************* 
 * Given n balloons, indexed from 0 to n-1. 
 * Each balloon is painted with a number on it represented by array nums. 
 * You are asked to burst all the balloons. 
 * If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. 
 * Here left and right are adjacent indices of i. 
 * After the burst, the left and right then becomes adjacent.
 * 
 * Find the maximum coins you can collect by bursting the balloons wisely.
 * 
 ******************************************************************* 
 * Note:
 * 
 * You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
 * 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 ******************************************************************* 
 * Example:
 * 
 * Input: [3,1,5,8]
 * Output: 167
 * Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
 *              coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 ******************************************************************* 
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
 
class Solution {
public:
    //////////////////////////////////////////////////////////////
    int result0 = 0;
    void backtrack0(std::vector<int> &nums, int score)
    {
        if (nums.size() <=2)
        {
            result0 = std::max(result0, score);
            //std::cout << "result0:" << result0 << "score:" << score;//<< std::endl;
            return ;
        }
        for (int i = 1; i < nums.size() -1; i++)
        {
            int point = nums[i-1] * nums[i] * nums[i+1];
            int temp = nums[i];
            // delete tmp
            nums.erase(nums.begin() + i);
            //std::cout << "point:" << point <<",score:" << score;//<< std::endl;
            //printvector(nums);
            backtrack0(nums, score + point);
            nums.insert(nums.begin() + i, temp);
            // add temp
        }

    }
    int maxCoins0(std::vector<int> &nums)
    {
        std::vector<int> nums_new(nums);
        nums_new.push_back(1);
        nums_new.insert(nums_new.begin(),1);
        printvector(nums_new);
        backtrack0(nums_new, 0);
        return result0;
    }
    int maxCoins1(std::vector<int> &nums)
    {
        int size = nums.size();
        std::vector<int> points(size +2);
        for(int i =1; i <= size; i++)
        {
            points[i] = nums[i-1];
        }
        points[0] = 1;
        points[size+1] = 1;
        std::vector<std::vector<int>> dp(size+2, std::vector<int>(size+2));
        for (int i = size; i >= 0; i--)
        {
            for (int j = i+1; j < size+2; j++)
            {
                for (int k = i+1; k < j; k++)            
                {
                    dp[i][j] = std::max(
                            dp[i][j],
                            dp[i][k] + dp[k][j] + points[i]*points[j]*points[k]
                            );
                }
            }
        }
        return dp[0][size+1];
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
    template <typename T1, typename T2>
    int printvector(const std::pair<T1,T2> &v)
    {
        std::cout << "(" << v.first <<","<< v.second << ") ";//<<std::endl;
        return 0;
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
    template <typename T>
    int printvvvector(const std::vector<T> &v)
    {
        std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvectorvector( *iter );
        }
        std::cout << std::endl;
        return v.size();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName, 
        std::vector<int> &nums,
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
const static int TEST_TIME = 1;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        int result = solution.maxCoins0(nums);
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

        int result = solution.maxCoins1(nums);
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
}

void Test1()
{
    std::vector<int> nums = {3, 1, 5, 8};
    int result = 167;
    Test("Test1", nums, result);
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
