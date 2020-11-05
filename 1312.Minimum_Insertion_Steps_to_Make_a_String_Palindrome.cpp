/*
 * 1312. Minimum Insertion Steps to Make a String Palindrome
 * Hard
 * 
 * Given a string s. 
 * In one step you can insert any character at any index of the string.
 * 
 * Return the minimum number of steps to make s palindrome.
 * 
 * A Palindrome String is one that reads the same backward as well as forward.
 *********************************************************************
 * Example 1:
 * 
 * Input: s = "zzazz"
 * Output: 0
 * Explanation: The string "zzazz" is already palindrome we don't need any insertions.
 *******************************************************************
 *  Example 2:
 * 
 * Input: s = "mbadm"
 * Output: 2
 * Explanation: String can be "mbdadbm" or "mdbabdm".
 *******************************************************************
 *  Example 3:
 * 
 * Input: s = "leetcode"
 * Output: 5
 * Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 ******************************************************************* 
 *  Example 4:
 * 
 * Input: s = "g"
 * Output: 0
 ****************************************************************** 
 *  Example 5:
 * 
 * Input: s = "no"
 * Output: 1
 ******************************************************************* 
 * Constraints:
 * 
 * 1 <= s.length <= 500
 * All characters of s are lower case English letters.
 ******************************************************************* 
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
    //    if s[i] == s[j]
    // dp[i][j] = dp[i+1][j-1]
    //    else
    // dp[i][j] = std::min(dp[i+1][j], dp[i][j-1]) + 1
    //
    // (i,j-1)   (i,j)
    // (i+1,j-1) (i+1, j)
    int minInsertions(std::string s)
    {
        int n = s.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        for (int i = n-2; i>= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i+1][j-1];
                }
                else
                {
                    dp[i][j] = std::min(dp[i+1][j], dp[i][j-1]) + 1;
                }
            }
        }
        return dp[0][n-1];
        return 0;
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

        //std::cout << typeid(decltype(expected)).name() << std::endl;
        //std::cout << typeid(expected).name() << std::endl;
        //decltype(expected) 
        int result = solution.minInsertions(s);
        std::cout << "result:" << std::boolalpha << result << std::endl;

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
    std::string s = "zzazz";
    int result = 0;
    Test("Test1", s, result);
}

void Test2()
{
    std::string s = "mbadm";
    int result = 2;
    Test("Test2", s, result);
}

void Test3()
{
    std::string s = "leetcode";
    int result = 5;
    Test("Test3", s, result);
}

void Test4()
{
    std::string s = "g";
    int result = 0;
    Test("Test4", s, result);
}

void Test5()
{
    std::string s = "no";
    int result = 1;
    Test("Test5", s, result);
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
