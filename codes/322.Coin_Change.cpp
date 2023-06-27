/*
 *
 * 322. Coin Change
 * Medium
 * You are given coins of different denominations and a total amount of money amount.
 * Write a function to compute the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return -1.
 ********************************************
 * Example 1:
 *
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 ********************************************
 * Example 2:
 *
 * Input: coins = [2], amount = 3
 * Output: -1
 *******************************************
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 */

#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>

//using std::vector;

class Solution {
public:
    std::vector<int> dp = std::vector<int>(100,0);
    int coinChange(std::vector<int>& coins, int amount)
    {
        if (0 == amount )
            return 0;
        if (0 >  amount )
            return -1;
        int subproblem = -1;
        int result = amount + 1;
        int maxresult = amount + 1;
        for (auto coin :  coins)
        {
            subproblem = coinChange(coins, amount - coin);
            if (subproblem == -1)
            {
                continue;
            }
            result = std::min(result, subproblem + 1);
        }
        return (result == maxresult ? -1: result );
    }
    // 使用 dp 保存子问题
    int coinChange1(std::vector<int>& coins, int amount)
    {
        if (amount == 0) return 0;
        if (amount <  0) return -1;
        if (dp.size() <= amount ) dp.resize(amount +1);
        if (dp[amount] != 0) return dp[amount];

        int result = amount + 1;
        for (auto coin : coins)
        {
            int subproblem = coinChange1(coins, amount - coin);
            if (subproblem == -1)
                continue;
            result = std::min(result, subproblem + 1);
        }
        dp[amount] = (result == amount + 1 ? -1 : result);
        return dp[amount];
        return 0;
    }
    // @ 09/23/2020 10:35
    //Runtime: 148 ms, faster than 25.40% of C++ online submissions for Coin Change.
    //Memory Usage: 15.3 MB, less than 17.45% of C++ online submissions for Coin Change.

    int coinChange2(std::vector<int>& coins, int amount)
    {
        if (amount == 0) return 0;
        std::vector<int> dptable(amount + 1, amount +1);
        dptable[0] = 0;

        for (int i = 0; i < amount + 1 ; ++i)
        {
            for (auto coin : coins)
            {
                if (i - coin < 0)
                {
                    continue;
                }
                dptable[i] = std::min( dptable[i],  1 + dptable[ i - coin] );
            }
        }
        return dptable[amount] == amount + 1 ? -1 : dptable[amount];
    }
    // @ 09/23/2020 14:50
    //Runtime: 112 ms, faster than 49.94% of C++ online submissions for Coin Change.
    //Memory Usage: 14.1 MB, less than 51.69% of C++ online submissions for Coin Change.
    template <typename T>
    int printvector(std::vector<T> v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << "| ";
        }
        std::cout << std::endl;
        return v.size();
    }
//private:
    //std::vector<int> dp;//(100, 1);

    //std::vector<int> dp2(100, 1);
    //std::vector<int> foo (3,100);   // three ints with a value of 100
    //int dp[100] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

};
// ====================测试代码====================
void Test(const char* testName, std::vector<int> coins , int amount, int expected, int index = 0)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    switch (index)
    {
    case 0:
        {
            start = std::chrono::system_clock::now();
            if(solution.coinChange (coins, amount) == expected)
                std::cout << "Solution0 passed." << std::endl;
            else
                std::cout << "Solution0 failed." << std::endl;
            end = std::chrono::system_clock::now();
            elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }


    case 1:
        {
    start = std::chrono::system_clock::now();
    if(solution.coinChange1(coins, amount) == expected)
        std::cout << "Solution1 passed." << std::endl;
    else
        std::cout << "Solution1 failed." << std::endl;
    end = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }

    case 2:
        {
    auto start2 = std::chrono::system_clock::now();
    if(solution.coinChange2(coins, amount) == expected)
        std::cout << "Solution2 passed." << std::endl;
    else
        std::cout << "Solution2 failed." << std::endl;
    auto end2 = std::chrono::system_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
    std::cout << "Solution2 costs " << elapsed2.count() <<"micros" << std::endl;
        }
    }

}
void Test1()
{
    Test("Test1", std::vector<int> {1,2,5},11, 3);
}
void Test2()
{
    Test("Test2", std::vector<int> {3}, 5, -1);
}

void Test3()
{
    Test("Test3", std::vector<int> {186,419,83,408}, 6249, 20, 1);
}

void Test4()
{
    //Test("Test4", 6, 6, 3);
}



int main()
{
    Solution solution;
    std::vector<int> coins = {1,2,5};
    std::vector<int> coins2 = {3};
    std::vector<int> coins3 = {186,419,83,408};

    Test1();
    Test2();
    Test3();

    return 0;

}
