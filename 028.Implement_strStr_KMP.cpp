/*
 * 28. Implement strStr()
 * Easy
 * 
 ************************************** 
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, 
 * or -1 if needle is not part of haystack.
 * 
 * Example 1:
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 ************************************* 
 * Example 2:
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 ************************************* 
 * Clarification:
 * 
 * What should we return when needle is an empty string? 
 * This is a great question to ask during an interview.
 * 
 * For the purpose of this problem, 
 * we will return 0 when needle is an empty string. 
 * This is consistent to C's strstr() and Java's indexOf().
 * 
 ************************************* 
 * Constraints:
 * 
 * haystack and needle consist only of lowercase English characters.
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
class Solution;
class KMP
{
public:
    //Ctor
    KMP(std::string & pat)
    {
        this->pat = pat;
        int M = pat.size();
        dp.resize(M, std::vector<int>(256, 0));
        // base case
        dp[0][pat[0]] = 1;
        std::cout << "dp[0][" << pat[0] << "] --> " << dp[0][pat[0]] <<std::endl;
        int X = 0;
        // j == 1
        for (int j = 1; j < M; j++)
        {
            for (int c = 0; c < 256; c++)
            {
                if (pat[j] == c)
                {
                    dp[j][c] = j + 1;
                    std::cout << "dp[j][c]:dp[" << j << "][" << char(c) << "] ----> " << dp[j][c] << "," << std::endl;
                }
                else
                {
                    dp[j][c] = dp[X][c];
                    if (dp[X][c] != 0)
                    {
                        std::cout << "dp["<<j<<"][" << char(c) << "] = ";
                        std::cout << "dp[X][c]: dp[" << X << "][" << char(c) << "]:";
                        std::cout  << dp[X][c] <<std::endl;
                    }
                }
            }
            //std::cout << std::endl;
            std::cout << "X:" << X << std::endl;
            std::cout << "j:" << j << std::endl;
            std::cout << "X = dp[X][pat[j]]: dp[" << X << "][" << pat[j] << "]:" << dp[X][pat[j]] <<std::endl;
            X = dp[X][pat[j]];
            std::cout << "j+1:" << j+1 << std::endl;
        }
        this->printvector();
    }
    int search(std::string & txt)
    {
        int M = pat.size();
        int N = txt.size();
        int j = 0;
        for (int i = 0; i < N; i++)
        {
            j = dp[j][txt[i]];
            if(j == M)
            {
                return i - M + 1;
            }
        }
        return -1;
    }
    int printvector()
    {
        ::printvectorvector(dp);
    }
private:
    std::vector<std::vector<int>> dp;
    std::string pat;
};

class Solution {
public:
    friend class KMP;
    // 
    int strStr(std::string haystack, std::string needle)
    {
        KMP *kmp = new KMP(needle);
        int position = kmp->search(haystack);
        return position;
    }
    int strStr_old(std::string haystack, std::string needle)
    {
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            for (j = 0; j < m; j++)
            {
                if (haystack[i+j] != needle[j])
                {
                    break;
                }
            }
            if (j == m)
            {
                return i;
            }
        }
        return -1;
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
void Test(const std::string& testName, std::string  &haystack, std::string & needle,int expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // 
    {
        start = std::chrono::system_clock::now();

        std::cout << "haystack: " << haystack << std::endl;
        std::cout << "needle  : " << needle   << std::endl;

        auto result = solution.strStr(haystack, needle);
        std::cout << "result:" << result <<  std::endl;

        if(result == expected)
            std::cout << "Solution0 passed." << std::endl;
        else
            std::cout << "Solution0 failed." << std::endl;
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
    }
}
void Test1()
{
    std::string haystack = "hello";
    std::string needle = "ll";
    Test("Test1",haystack, needle, 2);
    // dp[0][l] =1
    // dp[0][l] =2
    //
    //      l      l
    //  0 ----> 1 ----> 2
}
void Test2()
{
    std::string haystack = "aaaaa";
    std::string needle = "bba";
    Test("Test2",haystack, needle, -1);

    //
    //
    //       b        b       a
    //    0 ----> 1 ----> 2 ----> 3
    //                   / \
    //                   \ / 
    //                    b
}

void Test3()
{
    std::string haystack = "aaacaaab";
    std::string needle = "aaab";
    Test("Test3",haystack, needle, 4);
    //       a        a       a      b
    //    0 ----> 1 ----> 2 ----> 3 ---> 4
    //                           / \
    //                           \ / 
    //                            a
}

void Test4()
{
    std::string haystack = "ABABC";
    std::string needle = "ABABA";
    Test("Test4",haystack, needle, -1);
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
