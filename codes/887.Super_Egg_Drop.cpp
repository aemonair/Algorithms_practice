/*
 * 887. Super Egg Drop
 * Hard
 *
 * You are given K eggs, and you have access to a building with N floors from 1 to N.
 *
 * Each egg is identical in function, and if an egg breaks, you cannot drop it again.
 *
 * You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.
 *
 * Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N).
 *
 * Your goal is to know with certainty what the value of F is.
 *
 * What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?
 *************************************
 *
 * Example 1:
 *
 * Input: K = 1, N = 2
 * Output: 2
 * Explanation:
 * Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
 * Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
 * If it didn't break, then we know with certainty F = 2.
 * Hence, we needed 2 moves in the worst case to know what F is with certainty.
 *************************************
 * Example 2:
 *
 * Input: K = 2, N = 6
 * Output: 3
 *************************************
 * Example 3:
 *
 * Input: K = 3, N = 14
 * Output: 4
 *************************************
 * Note:
 *
 * 1 <= K <= 100
 * 1 <= N <= 10000
 *************************************
 */

#include <algorithm>
#include <iostream>
#include <utility> // std::pair
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>

class Solution {
public:
    //
    //std::unordered_map<std::pair<int,int> , int> memo; need hash
    std::vector<std::vector<int>> memo; //(K +1, std::vector<int>(N+1, -1));
    int dp2(int K, int N)
    {
        // base case 1, only one egg
        if (K == 1)
            return N;
        // base case 2, N floor only 0 or 1
        if (N == 0 || N ==1 )
            return N;
        for (int i =1; i < N ; i++)
        {
            result = std::min( result,
                std::max( dp(K)(N-i) ,dp(K-1)(i-1) ) + 1
                );
        }
    }
    int dp(int K, int N)
    {
        std::cout << "dp start:" << ",K:" << K << ",N:" << N << std::endl;
        if (K==1)
            return N;
        if (N == 0)
            return 0;
        //if (memo.count(std::make_pair(K,N)) > 0)
        if (memo[K][N] > 0)
        {
            std::cout << "memo["<< K << "][" << N << "] exist:" << memo[K][N] << std::endl;;
            return memo[K][N];
            //return memo[std::make_pair(K,N)];
        }
        int result = N + 1;
        for (int i = 1; i< N + 1; i++)
        {
            std::cout << "drop at i:" << i << std::endl;
            result = std::min( result,
                    std::max ( dp(K, N - i), dp( K -1, i -1 )) + 1
                    );
        }
        //memo[std::make_pair(K,N)] = result;
        std::cout << "K:" << K << ",N:" << N << ",result:" << result << std::endl;
        memo[K][N] = result;
        return result;
    }
    int superEggDrop(int K, int N)
    {
        memo.resize(K +1, std::vector<int>(N+1, -1));
        return dp(K, N);
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
void Test(const std::string& testName, int K, int N,int expected)
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

        std::cout << "K:" << K << std::endl;
        std::cout << "N:" << N << std::endl;

        auto result = solution.superEggDrop(K, N);
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
    int K = 1;
    int N = 2;
    Test("Test1",K, N, 2);
}
void Test2()
{
    int K = 2;
    int N = 6;
    Test("Test2",K, N, 3);
}

void Test3()
{
    int K = 3;
    int N = 14;
    Test("Test3",K, N, 4);
}

void Test4()
{
    int K = 2;
    int N = 100;
    //Test("Test4",K, N, 14);
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
