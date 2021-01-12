/*
 ****************************************************************************** 
 * 340. Longest Substring with K Distinct Characters
 ****************************************************************************** 
 * Given a string, find the length of the longest substring in it with no more than K distinct characters.
 ****************************************************************************** 
 * Example 1:
 *
 * Input: String="araaci", K=2
 * Output: 4
 * Explanation: The longest substring with no more than '2' distinct characters is "araa".
 ****************************************************************************** 
 * Example 2:
 * 
 * Input: String="araaci", K=1
 * Output: 2
 * Explanation: The longest substring with no more than '1' distinct characters is "aa".
 ****************************************************************************** 
 * Example 3:
 * 
 * Input: String="cbbebi", K=3
 * Output: 5
 * Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".
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
    int LongestSubstringDistinct0(std::string & s, int k)
    {
        int size = s.size();
        std::unordered_map<char, int> umap;
        int left = 0;
        int longest = -1;
        for (int i =0; i < size; i++)
        {
            char c = s[i];
            if ( umap.count(c) > 0)
            {
                umap[c] += 1;
            }
            else
            {
                while (umap.size() >= k)
                {
                    char l = s[left];
                    umap[l] -- ;
                    if (umap[l] == 0)
                    {
                        umap.erase(l);
                    }
                    left ++;
                }
                umap[c] += 1;
            }
            int lon = i -left + 1;
            //std::cout << "c:" << c << " , umap[" << c <<"]:" << umap[c] << std::endl;
            //std::cout << "i:" << i << " ,left:" << left << std::endl;
            longest = std::max(longest, lon);
        }
        return longest;
    }
    int LongestSubstringDistinct1(std::string & str, int k)
    {
        int windowstart = 0;
        int maxlength   = 0;
        std::unordered_map<char ,int> charFrequencyMap;
        for (int windowend = 0; windowend < str.length(); windowend++)
        {
            char rightChar = str[windowend];
            charFrequencyMap[rightChar] ++;
            while (charFrequencyMap.size() > k)
            {
                char leftChar = str[windowstart];
                charFrequencyMap[leftChar] --;
                if (charFrequencyMap[leftChar] == 0)
                {
                    charFrequencyMap.erase(leftChar);
                }
                windowstart++;
            }
            maxlength = std::max(maxlength, windowend - windowstart + 1);
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

    std::cout << "s:" << s << " ,K: " << k << std::endl;

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.LongestSubstringDistinct0(s, k);
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

        decltype(expected) result = solution.LongestSubstringDistinct1(s, k);
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
    std::string s = "araaci";
    int K = 2;
    int expect = 4;
    Test("Test1", s, K, expect);
}
void Test2()
{
    std::string s = "araaci";
    int K = 1;
    int expect = 2;
    Test("Test2", s, K, expect);
}

void Test3()
{
    std::string s = "cbbebi";
    int K = 3;
    int expect = 5;
    Test("Test3", s, K, expect);
}

void Test4()
{
}

void Test5()
{
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
