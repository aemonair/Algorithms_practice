/*
 * 122. Best Time to Buy and Sell Stock II
 * Easy
 *
 * Say you have an array prices for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit.
 * You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
 *
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 *
 *********************************************************
 * Example 1:
 *
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
 *              Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
 *********************************************************
 * Example 2:
 *
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 *              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
 *              engaging multiple transactions at the same time. You must sell before buying again.
 *********************************************************
 * Example 3:
 *
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *********************************************************
 * Constraints:
 *
 * 1 <= prices.length <= 3 * 10 ^ 4
 * 0 <= prices[i] <= 10 ^ 4
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
    int dp(std::vector<int> &prices, int start, std::vector<int> &memo)
    {
        int size = prices.size();
        if (start > prices.size())
        {
            return 0;
        }
        if (memo[start] != -1)
        {
            return memo[start];
        }
        int result = 0;
        int curmin = prices[start];
        for (int i = start + 1; i< size; i++)
        {
            curmin = std::min(curmin, prices[i]);
            result = std::max(result,
                    dp(prices, i+1,memo) + prices[i] - curmin);
        }
        memo[start] = result;
        return result;
    }
    int maxProfit(std::vector<int>& prices)
    {
        std::vector<int> memo(prices.size(), -1);
        return dp(prices , 0, memo);
    }
    int maxProfit1(std::vector<int>& prices)
    {
        int result = 0;
        int size = prices.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                std::vector<int> newvector = std::vector<int>(prices.begin() + j+1, prices.end());
                result = std::max(result,
                        maxProfit1(newvector) + prices[j] - prices[i]);
            }
        }
        return result;
    }
    int maxProfit2(std::vector<int>& prices)
    {
        int size = prices.size();
        int dp_i_0 = 0;
        int dp_i_1 = -100000;
        for (int i = 0; i < size; i++)
        {
            int temp = dp_i_0;
            dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = std::max(dp_i_1, temp   - prices[i]);
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
    {
        start = std::chrono::system_clock::now();

        decltype(expected) result = solution.maxProfit2(prices);
        std::cout << "result:" << std::boolalpha << result <<  std::endl;

        if(result == expected)
            std::cout << "Solution2 passed." << std::endl;
        else
            std::cout << "Solution2 failed." << std::endl;
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Solution2 costs " << elapsed.count() <<"micros" << std::endl;
    }
}
void Test1()
{
    std::vector<int> prices = {7,1,5,3,6,4};
    Test("Test1", prices, 7);
}
void Test2()
{
    std::vector<int> prices = {1,2,3,4,5};
    Test("Test2", prices, 4);
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
