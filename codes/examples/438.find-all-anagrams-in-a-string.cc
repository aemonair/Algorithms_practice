/*
 ******************************************************************************
 * 438. Find All Anagrams in a String
 * Medium
 ******************************************************************************
 * Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 *
 * Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
 *
 * The order of output does not matter.
 ******************************************************************************
 *
 * Example 1:
 *
 * Input:
 * s: "cbaebabacd" p: "abc"
 *
 * Output:
 * [0, 6]
 *
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 ******************************************************************************
 * Example 2:
 *
 * Input:
 * s: "abab" p: "ab"
 *
 * Output:
 * [0, 1, 2]
 *
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
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

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define     RESET   "\033[0m"
#define     RED     "\033[31m"             /*      Red     */
#define     CYAN    "\033[36m"             /*      Cyan    */
#define     BLUE    "\033[34m"             /*      Blue    */
#define     GREEN   "\033[32m"             /*      Green   */
#define     WHITE   "\033[37m"             /*      White   */
#define     BLACK   "\033[30m"             /*      Black   */
#define     YELLOW  "\033[33m"             /*      Yellow  */
#define     MAGENTA "\033[35m"             /*      Magenta */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow  */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black   */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White   */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green   */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue    */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan    */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red     */

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

template<typename T1, typename T2>
std::ostream & operator << (std::ostream &out, std::unordered_map<T1, T2> &_umap);

template<typename T>
int printvector(std::vector<T> v);

template <typename T>
int printstack(std::stack<T> s);

template <typename T1, typename T2>
int printunordered_map(const std::unordered_map<T1,T2> &v);

class Solution
{
public:
    std::vector<int> findAnagrams(std::string s, std::string p)
    {
        int match = 0;
        std::unordered_map<char ,int> umap;
        for (auto c: p) {
            ++umap[c];
        }
        int matchcount = umap.size();
        int left = 0;
        std::vector<int> result;
        for(int right = 0; right < s.size(); ++right) {
            if (umap.count(s[right]) > 0) {
                --umap[s[right]];
                if (umap[s[right]] == 0) {
                    ++ match ;
                }
            }
            if (right - left +1 == p.size()) {
                if (match == matchcount) {
                    result.emplace_back(left);
                }
                if (umap.count(s[left]) > 0) {
                    if (umap[s[left]] == 0) {
                        -- match;
                    }
                    ++umap[s[left]];
                }
                ++left;
            }
        }
        return result;
    }
    std::vector<int> findAnagrams1(std::string s, std::string p)
    {
        int match = 0;
        std::unordered_map<char, int> hash;
        for (auto c: p) {
           hash[c]++;
        }
        std::cout << hash << std::endl;
        std::vector<int> result;
        for (int i =0, j = 0; j < s.size(); ++j) {
            auto c = s[j];
            if (hash.count(c) > 0) {
                --hash[c];
                if (hash[c]==0) {
                    ++match;
                }
            }
            if (j < p.size()) {
                if (match == hash.size()) {
                    result.emplace_back(i);
                }
            }
            if (j >= p.size()) {
                if(hash.count(s[i]) > 0) {
                    if (hash[s[i]] == 0) {
                        match--;
                    }
                    ++ hash[s[i]];
                }
                ++i;
                if (match == hash.size()) {
                    result.emplace_back(i);
                }
            }
            //std::cout << hash << std::endl;
        }
        return result;
        return std::vector<int>{};
    }
    std::vector<int> findAnagrams2(std::string s, std::string p) {
        std::unordered_map<char, int> hash;
        for (auto c : p) {
            hash[c]++;
        }

        std::vector<int> result;
        int match = 0;
        int requiredMatch = hash.size();
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            auto c = s[right];
            if (hash.count(c) > 0) {
                if (--hash[c] == 0) {
                    ++match;
                }
            }

            // When the window size matches the length of p
            if (right - left + 1 == p.size()) {
                if (match == requiredMatch) {
                    result.emplace_back(left);
                }

                // Move the left pointer to shrink the window
                if (hash.count(s[left]) > 0) {
                    if (++hash[s[left]] == 1) {
                        --match;
                    }
                }
                ++left;
            }
        }

        return result;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::string s, std::string p,
        std::vector<int> & expected
        )
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "s: \"" << s << "\""<< std::endl;
    std::cout << "p: \"" << p << "\""<< std::endl;

const static int TEST_TIME = 0;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::vector<int> && result = solution.findAnagrams(s, p);
        printvector(result);

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if (TEST_1)
    {
    }
}
void Test1()
{
    std::string s = "cbaebabacd";
    std::string p = "abc";
    std::vector<int> expect = {0, 6};
    Test("Test1", s, p, expect);
}
void Test2()
{
    std::string s = "abab";
    std::string p = "ab";
    std::vector<int> expect = {0, 1, 2};
    Test("Test2", s, p, expect);
}

void Test3()
{
    std::string s = "ppqp";
    std::string p = "pq";
    std::vector<int> expect = {1, 2};
    Test("Test3", s, p, expect);
}

void Test4()
{
    std::string s = "abbcabc";
    std::string p = "abc";
    std::vector<int> expect = {2, 3, 4};
    Test("Test4", s, p, expect);
}

void Test5()
{
    std::string s = "";
    std::string p = "a";
    std::vector<int> expect = {};
    Test("Test4", s, p, expect);
}

void Test6()
{
}

void Test7()
{
}

void Test8()
{
}
// 75yy
template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec)
{
    out << "[  ";
    for(auto v: _vec)
    {
        out << v << ", ";
    }
    out << "\b\b ]" ;
    return out;
}
template<typename T1, typename T2>
std::ostream & operator << (std::ostream &out, std::unordered_map<T1, T2> &_umap)
{
    std::cout << "unordered_map size: " << _umap.size() << std::endl;
    out << "[  ";
    for (auto iter = _umap.begin(); iter != _umap.end(); iter++ )
    {
        out << "(" << iter->first << "," << iter->second<< "), ";//<<std::endl;
    }
    out << "\b\b ]" ;
    return out;
}
template<typename T>
int printvector(std::vector<T> v)
{
    if(0 == v.size())
    {
        std::cout << "Empty vector." << std::endl;
        return 0;
    }
    std::cout << "[ " ;
    for(auto i: v)
    {
        std::cout << i << ", ";
    }
    std::cout << "\b\b ]" << std::endl;
    return v.size();
}
template<typename T>
int printstack (std::stack <T> s)
{
    if(s.empty())
    {
        std::cout << "Empty stack ." << std::endl;
        return 0;
    }
    std::cout <<  "The stack size is: " << s.size() << std::endl;
    std::cout << "[ " ;
    while (!s.empty())
    {
        std::cout << s.top() << ", ";
        s.pop();
    }
    std::cout << "\b\b ]" << std::endl;
    return s.size();
}
template<typename T>
int printvector(std::stack <T> s)
{
    if(s.empty())
    {
        std::cout << "Empty stack ." << std::endl;
        return 0;
    }
    std::cout <<  "The stack size is: " << s.size() << std::endl;
    std::cout << "[ " ;
    while (!s.empty())
    {
        std::cout << s.top() << ", ";
        s.pop();
    }
    std::cout << "\b\b ]" << std::endl;
    return s.size();
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

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    Test8();

    return 0;
}
