/*
 ****************************************************************************** 
 * 424. Longest Repeating Character Replacement
 * Medium
 ****************************************************************************** 
 * Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.
 * 
 * In one operation, you can choose any character of the string and change it to any other uppercase English character.
 * 
 * Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.
 * 
 * Note:
 * Both the string's length and k will not exceed 104.
 ****************************************************************************** 
 * Example 1:
 * 
 * Input:
 * s = "ABAB", k = 2
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the two 'A's with two 'B's or vice versa.
 ****************************************************************************** 
 * Example 2:
 * 
 * Input:
 * s = "AABABBA", k = 1
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
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
    int characterReplacement(std::string s, int k)
    {
        int currentmax = 0;
        int maxlength = 0;
        std::unordered_map<char ,int> umap;
        int left = 0;
        for (int end = 0; end < s.length(); end++)
        {
            char ch = s[end];
            umap[ch] ++;
            currentmax = std::max(currentmax, umap[ch]);
            std::cout << "end:" << end << ",currentmax:" << currentmax << std::endl;
            if (end - left - currentmax >= k )
            {
                umap[s[left]]--;
                left++;
                //continue;
            }
            maxlength = std::max(maxlength, end - left +1);
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
        std::string s, int k,
        int expected
        )
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "s:" << s << " ,k: " << k << std::endl;

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.characterReplacement(s, k);
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
    }
}
void Test1()
{
    std::string s = "ABAB";
    int k = 2;
    int expect = 4;
    Test("Test1", s, k, expect);
}
void Test2()
{
    std::string s = "AABABBA";
    int k = 1;
    int expect = 4;
    Test("Test2", s, k, expect);
}

void Test3()
{
    std::string s = "aabccbb";
    int k = 2;
    int expect = 5;
    Test("Test3", s, k, expect);
}

void Test4()
{
    std::string s = "abbcb";
    int k = 1;
    int expect = 4;
    Test("Test4", s, k, expect);
}

void Test5()
{
    std::string s = "abccde";
    int k = 1;
    int expect = 3;
    Test("Test5", s, k, expect);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
