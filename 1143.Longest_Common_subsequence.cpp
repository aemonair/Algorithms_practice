/*
 * 1143. Longest Common Subsequence
 * Medium
 * Given two strings text1 and text2, return the length of their longest common subsequence.
 * 
 * A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. 
 * (eg, "ace" is a subsequence of "abcde" while "aec" is not). 
 * A common subsequence of two strings is a subsequence that is common to both strings.
 * 
 * 
 * 
 * If there is no common subsequence, return 0.
 ******************************************************* 
 *  Example 1:
 * 
 * Input: text1 = "abcde", text2 = "ace"
 * Output: 3
 * Explanation: The longest common subsequence is "ace" and its length is 3.
 ******************************************************* 
 * Example 2:
 * 
 * Input: text1 = "abc", text2 = "abc"
 * Output: 3
 * Explanation: The longest common subsequence is "abc" and its length is 3.
 ******************************************************* 
 * Example 3:
 * 
 * Input: text1 = "abc", text2 = "def"
 * Output: 0
 * Explanation: There is no such common subsequence, so the result is 0.
 ******************************************************* 
 *  Constraints:
 * 
 * 1 <= text1.length <= 1000
 * 1 <= text2.length <= 1000
 * The input strings consist of lowercase English characters only.
 ****************************************************** 
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
    int dp(std::string &t1, std::string &t2, int m, int n)
    {
        if (m == -1 || n == -1)
        {
            return 0;
        }
        if (t1[m]  == t2[n])
        {
            return dp(t1, t2, m-1, n-1) + 1;
        }
        else
        {
            return std::max(dp(t1, t2, m-1, n), dp(t1, t2, m ,n -1));
        }
    }

    int longestCommonSubsequence(std::string text1, std::string text2)
    {
        int m = text1.length();
        int n = text2.length();

        // return dp(text1, text2, m-1, n-1); //暴力解
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j =1; j <= n; j++)
            {
                if (text1[i-1] == text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = std::max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
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
        std::string text1, std::string text2,
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
        std::cout << "text1:" << text1 << std::endl;
        std::cout << "text2:" << text2 << std::endl;

        decltype(expected) result = solution.longestCommonSubsequence(text1, text2);
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
    std::string text1 = "abcde";
    std::string text2 = "ace";
    Test("Test1", text1, text2, 3);
}
void Test2()
{
    std::string text1 = "abc";
    std::string text2 = "ace";
    Test("Test2", text1, text2, 2);
}

void Test3()
{
    std::string text1 = "abc";
    std::string text2 = "def";
    Test("Test3", text1, text2, 0);
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
