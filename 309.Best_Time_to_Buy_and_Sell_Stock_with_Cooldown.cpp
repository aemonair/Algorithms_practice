/*
 * 309. Best Time to Buy and Sell Stock with Cooldown
 * Medium
 * 
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
 * 
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 * 
 ****************************************************************
 *  Example:
 * 
 * Input: [1,2,3,0,2]
 * Output: 3
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 *************************************************************
 ********************************************************* 
 */

#include <unordered_map>
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
    int dp(std::vector<int> &prices, int start, 
            std::unordered_map<std::string ,int> &memo, int k)
    {
        int size = prices.size();
        if (start >= size)
        {
            //std::cout << "start:"<< start << ",result:" << 0 << std::endl;
            return 0;
        }
        int result = 0;
        int cur_min = prices[start];
        for (int i = start+1; i < size ;i ++)
        {
            cur_min = std::min(cur_min, prices[i]);
            result = std::max( result
                    , dp(prices, i + 2, memo, k) + prices[i] - cur_min
                   );
        }
        //std::cout << "start:"<< start << ",result:" << result << std::endl;
        return result;
    }
    int maxProfit( std::vector<int>& prices)
    {
        std::unordered_map<std::string , int> memo;
        return dp(prices, 0, memo, 0);
    }
    int maxProfit1( std::vector<int>& prices)
    {
        int size = prices.size();
        int dp_i_0 = 0;
        int dp_i_1 = -10000;
        int dp_pre_0 = 0;
        for (int i = 0; i < size; i++)
        {
            int temp = dp_i_0;
            dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = std::max(dp_i_1, dp_pre_0 - prices[i]);
            dp_pre_0 = temp;
        }
        return dp_i_0;
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
        std::vector<int>& prices,
        int expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "prices:" << std::endl;
    solution.printvector(prices);
    // getpermutataion
    {
        start = std::chrono::system_clock::now();

        decltype(expected) result = solution.maxProfit(prices);
        std::cout << "result:" << std::boolalpha << result <<  std::endl;

        if(result == expected)
            std::cout << "Solution0 passed." << std::endl;
        else
            std::cout << "Solution0 failed." << std::endl;
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
    }
#if 1
    {
        start = std::chrono::system_clock::now();

        decltype(expected) result = solution.maxProfit1(prices);
        std::cout << "result:" << std::boolalpha << result <<  std::endl;

        if(result == expected)
            std::cout << "Solution1 passed." << std::endl;
        else
            std::cout << "Solution1 failed." << std::endl;
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
    }
#endif
}
void Test1()
{
    //std::vector<int> prices = {2, 4, 1};
    //Test("Test1", prices,  0);
}
void Test2()
{
    //std::vector<int> prices = {3, 2, 6, 5, 0, 3};
    //Test("Test2", prices, 3);
}

void Test3()
{
    std::vector<int> prices = {7,6,4,3,1};
    Test("Test3", prices, 0);
}

void Test4()
{
    std::vector<int> prices = {1};
    Test("Test4", prices, 0);
}

void Test5()
{
    //std::vector<int> prices = {1,0,1,0,1,0,1};
    //Test("Test5", prices, 1);
}

void Test6()
{
    std::vector<int> prices = {1,2,3,0,2};
    Test("Test6", prices, 3);
}

int main()
{
    Solution solution;

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;

}
