/*
 * 877. Stone Game
 * Medium
 * 
 * Alex and Lee play a game with piles of stones.  
 * There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
 * 
 * The objective of the game is to end with the most stones.  
 * The total number of stones is odd, so there are no ties.
 * 
 * Alex and Lee take turns, with Alex starting first.  
 * Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  
 * This continues until there are no more piles left, at which point the person with the most stones wins.
 * 
 * Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
 ******************************************************************
 * Example 1:
 * 
 * Input: piles = [5,3,4,5]
 * Output: true
 * Explanation:
 * Alex starts first, and can only take the first 5 or the last 5.
 * Say he takes the first 5, so that the row becomes [3, 4, 5].
 * If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
 * If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
 * This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
 *******************************************************************
 * Constraints:
 * 
 * 2 <= piles.length <= 500
 * piles.length is even.
 * 1 <= piles[i] <= 500
 * sum(piles) is odd.
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
    bool stoneGame(std::vector<int>& piles)
    {
        int size = piles.size();
        std::vector<std::vector<std::pair<int,int>>> dp(size, std::vector<std::pair<int,int>>(size, std::pair<int,int>(0,0)));
        printvvvector(dp);
        
        for (int i = 0; i < size; i++)
        {
            dp[i][i].first = piles[i];
            dp[i][i].second= 0;
        }
        for (int x =1; x < size; x++)
        {
            for (int i = 0; i + x <size; i++)
            {
                int j = i+ x;
                int left  = piles[i] + dp[i+1][j].second;
                int right = piles[j] + dp[i][j-1].second;

                if (left > right)
                {
                    dp[i][j].first =left;
                    dp[i][j].second = dp[i+1][j].first;
                }
                else
                {
                    dp[i][j].first =right;
                    dp[i][j].second = dp[i][j-1].first ;
                }
            }
        }
        std::pair<int,int> result = dp[0][size-1];
        printvvvector(dp);
        return result.first - result.second;
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
        std::vector<int>& piles,
        bool expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printvector(piles);
    // getpermutataion
const static int TEST_TIME = 0;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        int result = solution.stoneGame(piles);
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
}

void Test1()
{
    std::vector<int> nums = {5, 3, 4, 5}; 
    bool result = true;
    Test("Test1", nums, result);
}

void Test2()
{
    std::vector<int> nums = {3, 9, 1, 2}; 
    bool result = true;
    Test("Test2", nums, result);
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
