/*
 * Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
 * In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. 
 * Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
 * You cannot break an item, either pick the complete item or don’t pick it (0-1 property)
 *
 * 给你一个可装载重量为W的背包和N个物品，每个物品有重量和价值两个属性。其中第i个物品的重量为wt[i]，价值为val[i]，现在让你用这个背包装物品，最多能装的价值是多少？
 * 
 ************************************* 
 * Example 1:
 * 
 * Input: 
 * N = 3, W = 4, wt = [2, 1, 3], val = [4, 2, 3]
 *
 * Output: 6
 ************************************* 
 * Example 2:
 * 
 * Input: 
 * N = 3, W = 50, wt = [10, 20, 30],val = [60, 100, 120]
 * Output: 220
 ************************************* 
 * Example 3:
 * 
 * Input: 
 * N = 4, W = 8, wt = [2, 3, 4, 5],val = [3, 4, 5, 6] 
 * Output: 10
 ************************************* 
 * N = wt.size() == val.size()
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
    int knapsack(int W, int N, std::vector<int>& wt, std::vector<int>& val) 
    {
        std::vector<std::vector<int>> dp(N+1, std::vector<int>(W+1, 0));
        for (int i = 1; i <= N; i++)
        {
            for (int w = 1; w <= W; w++)
            {
                //当前背包的容量为w时，这种情况下可以装下的最大价值是dp[i][w]。
                if(w - wt[i-1] < 0)
                {
                    dp[i][w] = dp[i-1][w];
                }
                else
                {
                    dp[i][w] = std::max (dp[i-1][w],
                            dp[i-1][w - wt[i-1]] + val[i-1]);
                }
            }
        }
        return dp[N][W];
    }

    int knapsack1(int W, int N, std::vector<int>& wt, std::vector<int>& val) 
    {
        std::vector<std::vector<int>> dp(N+1, std::vector<int>(W+1, 0));
        for (int i = 1; i <= N; i++)
        {
            //for (int w = 1; w <= W; w++)
            for (int w = 1; w <= W; w++)
            {
                std::cout << "i:" << i << ",w:" << w << std::endl;
                if(w - wt[i-1] < 0)
                {
                    dp[i][w] = dp[i-1][w];
                }
                else
                {
                    dp[i][w] = std::max( dp[i-1][w-wt[i-1]] + val[i-1],
                                         dp[i-1][w]);
                }
                std::cout << "value of dp[" << i << "][" << w << "]:" << dp[i][w] << std::endl;
            }
        }
        return dp[N][W];
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
void Test(const std::string& testName, int W, int N, std::vector<int> & wt, std::vector<int>& val, int expected)
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

        std::cout << "weight:";
        solution.printvector(wt);
        std::cout << "value :";
        solution.printvector(val);

        int result = solution.knapsack(W, N, wt, val);
        std::cout << "result:" << result <<  std::endl;

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
    std::vector<int> wt  = {2, 1, 3};
    std::vector<int> val = {4, 2, 3};
    Test("Test1",4, 3, wt, val, 6);
}
void Test2()
{
    std::vector<int> wt  = {10, 20, 30};
    std::vector<int> val = {60, 100, 120};
    Test("Test2",50, 3, wt, val, 220);
}

void Test3()
{
    std::vector<int> wt  = {2, 3, 4, 5};
    std::vector<int> val = {3, 4, 5, 6};
    Test("Test3",8, 4, wt, val, 10);
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
