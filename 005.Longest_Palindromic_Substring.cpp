/*
 * 5. Longest Palindromic Substring
 * Medium
 * 
 * Given a string s, return the longest palindromic substring in s.
 ************************************************************
 *  Example 1:
 * 
 * Input: s = "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 ************************************************************ 
 *  Example 2:
 * 
 * Input: s = "cbbd"
 * Output: "bb"
 ************************************************************
 *  Example 3:
 * 
 * Input: s = "a"
 * Output: "a"
 ************************************************************ 
 *  Example 4:
 * 
 * Input: s = "ac"
 * Output: "a"
 ************************************************************ 
 *  Constraints:
 * 
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters (lower-case and/or upper-case),
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
    std::string palindrome(std::string &s, int l, int r)
    {
        while (l >=0 && r < s.size()
            && s[l] == s[r])
        {
            l--;
            r++;
        }
        return s.substr(l + 1, r- l - 1);

    }
    std::string longestPalindrome(std::string s)
    {
        std::string res;
        for (int i = 0; i < s.size(); i++)
        {
            std::string s1 = palindrome(s, i, i);
            std::string s2 = palindrome(s, i, i+1);
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;
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
        std::string expected)
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

        decltype(expected) result = solution.longestPalindrome(s);
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
    std::string s = "babad";
    Test("Test1", s, "aba");
}

void Test2()
{
    std::string s = "cbbd";
    Test("Test2", s, "bb");
}

void Test3()
{
    std::string s = "a";
    Test("Test3", s, "a");
}

void Test4()
{
    std::string s = "ac";
    Test("Test4", s, "a");
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
