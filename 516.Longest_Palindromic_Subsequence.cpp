/*
 * 516. Longest Palindromic Subsequence
 * Medium
 * 
 * Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
 ***************************************************************
 *  Example 1:
 * Input:
 * 
 * "bbbab"
 * Output:
 * 4
 * One possible longest palindromic subsequence is "bbbb".
 *  
 ************************************************************** 
 * Example 2:
 * Input:
 * 
 * "cbbd"
 * Output:
 * 2
 * One possible longest palindromic subsequence is "bb".
 ************************************************************
 *  Constraints:
 * 
 * 1 <= s.length <= 1000
 * s consists only of lowercase English letters.
 ************************************************************ 
 ************************************************************ 
 * 
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
    int longestPalindromeSubseq(std::string s) 
    {
        int size = s.size();
        std::vector<std::vector<int>> dp( size, std::vector<int>(size, 0));

        for (int i = 0; i < size; i++)
        {
            dp[i][i] = 1;
        }
        // dp[i][j] = dp[i+1][j-1] + 2
        // dp[i][j] = std::max(dp[i+1][j] , dp[i][j-1])
        //  (i  , j-1)   (i  ,j)
        //  (i+1, j-1)   (i+1,j)
        for (int i = size -1; i >= 0; i--)
        {
            for (int j = i+1; j <size; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else
                {
                    dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][size-1];
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
        std::string s,
        int expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "s:" << s << std::endl;
    // getpermutataion
    {
        //start = std::chrono::system_clock::now();

        decltype(expected) result = solution.longestPalindromeSubseq(s);
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
    std::string s = "bbbab";
    Test("Test1", s, 4);
}

void Test2()
{
    std::string s = "cbbd";
    Test("Test2", s, 2);
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
