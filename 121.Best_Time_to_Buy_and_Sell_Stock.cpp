/*
 * 121. Best Time to Buy and Sell Stock
 * Easy
 * 
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 *********************************************************
 * Example 1:
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 *              Not 7-1 = 6, as selling price needs to be larger than buying price.
 *********************************************************
 * Example 2:
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
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
    int maxProfit(std::vector<int>& prices)
    {
        int max = 0;
        int minprice = prices[1];
        for (int i = 1; i < prices.size(); i++)
        {
            minprice =std::min( prices[i] , minprice);
            max = std::max(max , prices[i] - minprice);
        }
        return max;
    }
    int maxProfit1(std::vector<int>& prices)
    {
        int max = 0 ;
        for (int i = 0; i < prices.size() ; i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                if(prices[j] - prices[i] > max)
                    max = prices[j] - prices[i];
            }
        }
        return max;
    }
    int maxProfit2(std::vector<int>& prices)
    {
        int size = prices.size();
        std::vector<std::vector<int>> dp(size , std::vector<int>(2,0));
        for (int i = 0; i < size; i++)
        {
            if (i - 1 == -1)
            {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = std::max(dp[i-1][1],- prices[i]);
        }
        return dp[size-1][0];
    }
    int maxProfit3(std::vector<int>& prices)
    {
        int size = prices.size();
        //std::vector<std::vector<int>> dp(size , std::vector<int>(2,0));
        int dp_i_0 = 0;
        int dp_i_1 = -100000;
        for (int i = 0; i < size; i++)
        {
            dp_i_0   = std::max(dp_i_0, dp_i_1  + prices[i]);
            dp_i_1   = std::max(dp_i_1,- prices[i]);
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

        decltype(expected) result = solution.maxProfit1(prices);
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

        decltype(expected) result = solution.maxProfit(prices);
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
    {
        start = std::chrono::system_clock::now();

        decltype(expected) result = solution.maxProfit3(prices);
        std::cout << "result:" << std::boolalpha << result <<  std::endl;

        if(result == expected)
            std::cout << "Solution3 passed." << std::endl;
        else
            std::cout << "Solution3 failed." << std::endl;
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Solution3 costs " << elapsed.count() <<"micros" << std::endl;
    }
}
void Test1()
{
    std::vector<int> prices = {7,1,5,3,6,4};
    Test("Test1", prices, 5);
}
void Test2()
{
    std::vector<int> prices = {7,6,4,3,1};
    Test("Test2", prices, 0);
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
