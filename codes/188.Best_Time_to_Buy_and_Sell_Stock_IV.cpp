/*
 * 188. Best Time to Buy and Sell Stock IV
 * Hard
 * 
 * You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most k transactions.
 * 
 * Notice that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 * 
 *************************************************************
 *  Example 1:
 * 
 * Input: k = 2, prices = [2,4,1]
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
 *************************************************************
 *  Example 2:
 * 
 * Input: k = 2, prices = [3,2,6,5,0,3]
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 **********************************************************
 * Example 3:
 * Input: prices = [1]
 * Output: 0
 *********************************************************
 * Example 4:
 * Input: k=3, prices = [1,0,1,0,1,0,1]
 * Output: 3
 *********************************************************
 * Constraints:
 * 
 * 0 <= k <= 10 ^ 9
 * 1 <= prices.length <= 10 ^ 4
 * 0 <= prices[i] <= 1000  
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
            std::unordered_map<std::string       ,int> &memo, int k)
    {
        int size = prices.size();
        if (start > prices.size())
        {
            return 0;
        }
        if (k == 0)
        {
            return 0;
        }
        std::string key = std::to_string(start)+","+std::to_string(k);
        std::cout << "key:" << key << std::endl;
        auto got = memo.find(key); //
        //std::to_string(start)+","+std::to_string(k));
        {
            if (got == memo.end())
            {
                std::cout << "not found.";
            }
            else
            {
                std::cout << got->first << " is " << got->second;
                return got->second;
            }
        }
        int result = 0;
        int curmin = prices[start];
        for (int i = start + 1; i< size; i++)
        {
            curmin = std::min(curmin, prices[i]);
            result = std::max(result, 
                    dp(prices, i+1,memo, k-1) + prices[i] - curmin);
        }
        //memo[std::pair(start,k)] = result;
        //memo[std::to_string(start)+","+std::to_string(k)] = result;
        memo[key] = result;
        //std::cout << std::endl;
        //for (auto& x: memo)
        //    std::cout << "(" << x.first << "): " << 
        //        x.second << ";";// std::endl;

        return result;
    }
    int maxProfit(int k, std::vector<int>& prices)
    {
        std::unordered_map<std::string       ,int> memo;
        return dp(prices , 0, memo, k);
    }
    int maxProfit1(int K, std::vector<int>& prices)
    {
        int size = prices.size();
        std::vector<std::vector<std::vector<int>>> dp(size,
                std::vector<std::vector<int>>(K + 1,
                    std::vector<int>(2, 0)
                    )
                );
        for (int i = 0; i < size; i++)
        {
            for (int k = K; k >= 1; k--)
            {
                if (i -1 == -1)
                {
                    //
                    dp[0][k][0] = 0;
                    dp[0][k][1] = -10000;
                    continue;
                }
                dp[i][k][0] = std::max(dp[i-1][k][0], dp[i-1][k][1]   + prices[i]);
                dp[i][k][1] = std::max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
            }
        }
        return dp[size-1][K][0];
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
        int k,
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

        decltype(expected) result = solution.maxProfit(k ,prices);
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

        decltype(expected) result = solution.maxProfit1(k, prices);
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
    std::vector<int> prices = {2, 4, 1};
    Test("Test1", prices, 2, 2);
}
void Test2()
{
    std::vector<int> prices = {3, 2, 6, 5, 0, 3};
    Test("Test2", prices, 2, 7);
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
    Test("Test4", prices, 3, 3);
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
