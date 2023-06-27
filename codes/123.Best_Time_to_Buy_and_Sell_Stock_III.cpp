/*
 * 123. Best Time to Buy and Sell Stock III
 * Hard
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit.
 * You may complete at most two transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 *
 **********************************************************
 *  Example 1:
 *
 * Input: prices = [3,3,5,0,0,3,1,4]
 * Output: 6
 *
 * Explanation:
 * Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
 **********************************************************
 *  Example 2:
 *
 * Input: prices = [1,2,3,4,5]
 * Output: 4
 *
 * Explanation:
 * Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time.
 * You must sell before buying again.
 *
 **********************************************************
 * Example 3:
 *
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation:
 * In this case, no transaction is done, i.e. max profit = 0.
 **********************************************************
 * Example 4:
 *
 * Input: prices = [1]
 * Output: 0
 *********************************************************
 * Constraints:
 *
 * 1 <= prices.length <= 10 ^ 5
0 <= prices[i] <= 10 ^ 5
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
        std::cout << std::endl;
        for (auto& x: memo)
            std::cout << "(" << x.first << "): " <<
                x.second << ";";// std::endl;

        return result;
    }
    int maxProfit(std::vector<int>& prices)
    {
        std::unordered_map<std::string       ,int> memo;
        return dp(prices , 0, memo, 2);
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
#if 0
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
    std::vector<int> prices = {3,3,5,0,0,3,1,4};
    Test("Test1", prices, 6);
}
void Test2()
{
    std::vector<int> prices = {1,2,3,4,5};
    Test("Test2", prices, 4);
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
    std::vector<int> prices = {3,2,6,5,0,3};
    Test("Test5", prices, 7);
}

void Test6()
{
    std::vector<int> prices = {1,0,1,0,1,0,1};
    Test("Test6", prices, 2);
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
