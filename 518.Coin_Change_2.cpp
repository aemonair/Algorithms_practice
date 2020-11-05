/*
 * 518. Coin Change 2
 * Medium
 * 
 * You are given coins of different denominations and a total amount of money. 
 * Write a function to compute the number of combinations that make up that amount. 
 * You may assume that you have infinite number of each kind of coin.
 * 
 ****************************************************** 
 * Example 1:
 * 
 * Input: amount = 5, coins = [1, 2, 5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 ****************************************************** 
 * Example 2:
 * 
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 ****************************************************** 
 * Example 3:
 * 
 * Input: amount = 10, coins = [10]
 * Output: 1
 ****************************************************** 
 * Note:
 * 
 * You can assume that
 * 
 * 0 <= amount <= 5000
 * 1 <= coin <= 5000
 * the number of coins is less than 500
 * the answer is guaranteed to fit into signed 32-bit integer
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
    int change(int amount, std::vector<int>& coins)
    {
        int size = coins.size();
        std::vector<std::vector<int>> dp(size + 1, std::vector<int>(amount + 1, 0));

        for (int i = 1; i <= size; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= amount ; j++)
            {
                std::cout << "dp[i-1][j] :" <<"dp["<< i-1<< "]["<<j<<"]:"<< dp[i-1][j];
                if (j - coins[i-1] >= 0)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                    std::cout << ",dp[i][j-coins[i-1]] :"<<
                  " dp[" << i << "][" << j -coins[i-1] << "]:" << dp[i][j-coins[i-1]];
                }
                else
                {
                    dp[i][j] = dp[i-1][j] ;
                }
                std::cout << std::endl;
                std::cout << "get dp[i][j]:" << "dp["<<i<<"]["<<j<<"]:" <<
                    dp[i][j] << std::endl;
            }
        }
        return dp[size][amount];
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
        int amount, std::vector<int> & coins,
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
        //start = std::chrono::system_clock::now();

        std::cout << "amount:" << amount << std::endl;
        std::cout << "coins:";
        solution.printvector(coins);

        decltype(expected) result = solution.change(amount, coins);
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
    int amount = 5;
    std::vector<int> coins = {1, 2, 5};
    Test("Test1", amount, coins, 4);
}
void Test2()
{
    int amount = 3;
    std::vector<int> coins = { 2 };
    Test("Test2", amount, coins, 0);
}

void Test3()
{
    int amount = 10;
    std::vector<int> coins = { 10 };
    Test("Test3", amount, coins, 1);
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
