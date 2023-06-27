/*
 * 714. Best Time to Buy and Sell Stock with Transaction Fee
 * Medium
 *
 * Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.
 *
 * You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)
 *
 * Return the maximum profit you can make.
 ****************************************************************
 *  Example 1:
 *
 * Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
 * Output: 8
 * Explanation: The maximum profit can be achieved by:
 * Buying at prices[0] = 1
 * Selling at prices[3] = 8
 * Buying at prices[4] = 4
 * Selling at prices[5] = 9
 * The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 *
 ************************************************************
 *  Note:
 *
 * 0 < prices.length <= 50000.
 * 0 < prices[i] < 50000.
 * 0 <= fee < 50000.
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
            std::unordered_map<std::string,int> &memo, int fee)
    {
        int size = prices.size();
        if (start >= size)
        {
            return 0;
        }
        int result = 0;
        int cur_min = prices[start];
        for (int i = start + 1; i < size; i++)
        {
            cur_min = std::min(cur_min, prices[i]);
            result = std::max( result,
                    dp(prices, i + 1, memo, fee) + prices[i] - cur_min - fee);
        }
        return result;
    }
    int maxProfit(std::vector<int>& prices, int fee)
    {
        std::unordered_map<std::string ,int> memo;
        return dp(prices , 0, memo, fee);
    }
    int maxProfit1(std::vector<int>& prices, int fee)
    {
        int size = prices.size();
        int dp_i_0 = 0;
        int dp_i_1 = -10000;
        for (int i =0; i < size; i++)
        {
            int temp = dp_i_0;
            dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = std::max(dp_i_1, temp - prices[i] - fee);
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
        int fee,
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

        decltype(expected) result = solution.maxProfit(prices, fee);
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

        decltype(expected) result = solution.maxProfit1(prices, fee);
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
    //Test("Test1", prices, 1, 1);
}
void Test2()
{
    std::vector<int> prices = {1, 3, 2, 8, 4, 9};
    Test("Test2", prices, 2, 8);
}

void Test3()
{
    std::vector<int> prices = {7,6,4,3,1};
    Test("Test3", prices, 2, 0);
}

void Test4()
{
    std::vector<int> prices = {1};
    Test("Test4", prices, 2, 0);
}

void Test5()
{
    std::vector<int> prices = {1,0,1,0,1,0,1};
    Test("Test4", prices, 3, 0);
}

void Test6()
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
    Test6();

    return 0;

}
