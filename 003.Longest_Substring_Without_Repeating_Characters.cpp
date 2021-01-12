/*
 ****************************************************************************** 
 * 3. Longest Substring Without Repeating Characters
 * Medium
 ****************************************************************************** 
 * Given a string s, find the length of the longest substring without repeating characters.
 ****************************************************************************** 
 * Example 1:
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 ****************************************************************************** 
 * Example 2:
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 ****************************************************************************** 
 * Example 3:
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 ****************************************************************************** 
 * Example 4:
 * 
 * Input: s = ""
 * Output: 0
 ****************************************************************************** 
 * Constraints:
 * 
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 ****************************************************************************** 
 */

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <climits>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
 
class Solution 
{
public:
    // 
    int lengthOfLongestSubstring0(std::string s)
    {
        std::unordered_map<char ,int> umap;
        int end = 0;
        int start = 0;
        int curmax = 0;
        int size = s.size();
        for (start = 0; end < size; end++)
        {
            char c = s[end];
            if( umap.count(c) > 0)
            {
                while(umap.count(c) > 0 && start < end)
                {
                    umap.erase(s[start]);
                    start ++;
                }
            }
            else
            {
                curmax = std::max(curmax, end - start + 1);
            }
            umap[c] += 1;
        }
        std::cout << "s[ " << start << "] " << s[start] << std::endl;
        return curmax;
    }
    int lengthOfLongestSubstring1(std::string s)
    {
        int start = 0;
        int maxlength = 0;
        std::unordered_map<char ,int> umap;
        for (int end = 0; end < s.length(); end++)
        {
            char ch = s[end];
            if (umap.count(ch) > 0)
            {
                start = std::max(start, umap[ch]+1);
            }
            umap[ch] = end;
            maxlength = std::max(maxlength, end - start + 1);
        }
        return maxlength;
    }
    template <typename T>
    int printstack(std::stack<T> s)
    {
        if (s.empty())
        {
            std::cout << "The stack is empty." << std::endl;
            return 0;
        }
        std::cout <<  "The stack size is: " << s.size() << std::endl;
        std::stack<T> tmp;
        while (!s.empty())
        {
            std::cout << s.top() << ", ";
            s.pop();
        }
        std::cout <<  std::endl;
        return s.size();
    }

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[   "  ;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << "'" << *iter << "', ";//<<std::endl;
        }
        std::cout <<"\b\b  ]" <<  std::endl;
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
    template <typename T1, typename T2>
    int printunordered_map(const std::unordered_map<T1,T2> &v)
    {
        std::cout << "unordered_map size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << "(" << iter->first << "," << iter->second<< "), ";//<<std::endl;
        }
        std::cout << std::endl;
        return v.size();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName, 
        std::string s, 
        int expected
        )
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "s: \"" << s << "\""<< std::endl;

const static int TEST_TIME = 1;
const static int TEST_0    = 0;
const static int TEST_1    = 1;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.lengthOfLongestSubstring0(s);
        std::cout << "result:" << result << std::endl;

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
    if (TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.lengthOfLongestSubstring1(s);
        std::cout << "result:" << result << std::endl;

        if(result == expected)
            std::cout << "Solution1 passed." << std::endl;
        else
            std::cout << "Solution1 failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
}
void Test1()
{
    std::string s = "abcabcbb";
    int expect = 3;
    Test("Test1", s, expect);
}
void Test2()
{
    std::string s = "bbbbb";
    int expect = 1;
    Test("Test2", s, expect);
}

void Test3()
{
    std::string s = "pwwkew";
    int expect = 3;
    Test("Test3", s, expect);
}

void Test4()
{
    std::string s = "";
    int expect = 0;
    Test("Test4", s, expect);
}

void Test5()
{
    std::string s = "aabccbb";
    int expect = 3;
    Test("Test5", s, expect);
}

void Test6()
{
    std::string s = "abccde";
    int expect = 3;
    Test("Test6", s, expect);
}

void Test7()
{
    std::string s = "dvdf";
    int expect = 3;
    Test("Test6", s, expect);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
