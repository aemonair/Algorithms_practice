/*
 * 10. Regular Expression Matching
 * Hard
 *
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 * 
 ************************************* 
 * Note:
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like . or *.
 ************************************* 
 * Example 1:
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 ************************************* 
 * Example 2:
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 ************************************* 
 * Example 3:
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 ************************************* 
 * Example 4:
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
 ************************************* 
 * Example 5:
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 ************************************* 
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
#include <unordered_map>
 
class Solution {
public:
    // 
    bool isMatch(std::string s, std::string p) 
    {
        return dp(s,0,p,0);
    }
    std::unordered_map<std::string, bool> memo;
    bool dp(std::string& s,int i, std::string &p, int j) 
    {
        int m = s.size();
        int n = p.size();
        if( j == n)
        {
            return i == m; // j匹配结束
        }
        if (i == m) 
        {
            // 如果能匹配空串，一定是字符和 * 成对儿出现
            if ((n - j) % 2 == 1) 
            {
                return false;
            }
            // 检查是否为 x*y*z* 这种形式
            for (; j + 1 < n; j += 2) 
            {
                if (p[j + 1] != '*') 
                {
                    return false;
                }
            }
            return true;
        }


        // 记录状态 (i, j)，消除重叠子问题
        std::string key = std::to_string(i) + "," + std::to_string(j);
        if (memo.count(key)) 
        {
            return memo[key];
        }
        bool res = false;
        if(s[i] ==p[j] || p[j] == '.')
        {
            if(j < p.size() -1 && p[j+1] == '*')
            {
                // 有 * 通配符，可以匹配 0 次或多次
                res =  dp(s, i, p, j+2) 
                    || dp(s, i+1, p, j);
            }
            else
            {
                res =  dp(s, i+1, p, j+1) ;
                //i++;j++;
            }
        }
        else
        {
            if(j < p.size() -1 && p[j+1] == '*')
            {
                // 有 * 通配符，只能匹配 0 次
                res =  dp(s, i, p, j+2) ;
            }
            else
            {
                res =  false;
            }
        }
        // 将当前结果记入备忘录
        memo[key] = res;
        return res;

    }
    bool isMatch2_point(std::string s, std::string p) 
    {
        int i =0;
        int j =0;
        while ( i < s.size() && j < p.size())
        {
            if(s[i] ==p[j] || p[j] == '.')
            {
                if(j < p.size() -1 && p[j+1] == '*')
                {
                    // 有 * 通配符，可以匹配 0 次或多次
                }
                else
                {
                    i++;j++;
                }
            }
            else
            {
                if(j < p.size() -1 && p[j+1] == '*')
                {
                    // 有 * 通配符，只能匹配 0 次
                }
                else
                {
                    return false;
                }
            }
        }
        if (i == s.size() -1 && j == p.size()-1)
        {
            return true;
        }
    }
    bool isMatch1_onlypoint(std::string s, std::string p) 
    {
        int i = 0;
        int j = 0;
        while ( i < s.size() && j < p.size())
        {
            if(s[i] ==p[j] || p[j] == '.')
            {
                i++;j++;
            }
            else
            {
                return false;
            }
        }
        if (i == s.size() -1 && j == p.size()-1)
        {
            return true;
        }
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
void Test(const std::string& testName, std::string &s, std::string &p, bool expected)
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

        std::cout << "s:" << s << std::endl;
        std::cout << "p:" << s << std::endl;

        auto result = solution.isMatch(s, p);
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
    std::string s = "aa";
    std::string p = "a";
    Test("Test1",s, p, false);
}
void Test2()
{
    std::string s = "aa";
    std::string p = "a*";
    Test("Test2",s, p, true );
}

void Test3()
{
    std::string s = "ab";
    std::string p = ".*";
    Test("Test3",s, p, true );
}

void Test4()
{
    std::string s = "aab";
    std::string p = "c*a*b";
    Test("Test4",s, p, true );
}

void Test5()
{
    std::string s = "mississippi";
    std::string p = "mis*is*p*.";
    Test("Test5",s, p, false);
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
