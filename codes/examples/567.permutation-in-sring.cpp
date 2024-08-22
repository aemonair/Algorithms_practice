/*
 ******************************************************************************
 * 567. Permutation in String
 * Medium
 ******************************************************************************
 * Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
 ******************************************************************************
 * Example 1:
 *
 * Input: s1 = "ab" s2 = "eidbaooo"
 * Output: True
 * Explanation: s2 contains one permutation of s1 ("ba").
 ******************************************************************************
 * Example 2:
 *
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 ******************************************************************************
 * Constraints:
 *
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
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

template<typename T>
int printvector(std::vector<T> v);

template <typename T>
int printstack(std::stack<T> s);

template <typename T1, typename T2>
int printunordered_map(const std::unordered_map<T1,T2> &v);

class Solution
{
public:
    bool checkInclusion(std::string s1, std::string s2)
    {
        std::unordered_map<char, int> umap;
        for (auto ch: s1) {
            umap[ch] ++;
        }
        int match = 0;
        for (int i =0; i < s1.size(); ++i) {
            if (umap.count(s2[i]) > 0) {
                umap[s2[i]] --;
                if (umap[s2[i]] ==0) {
                    match++;
                }
            }
        }
        if (match == umap.size()) {
            return true;
        }
        for (int i = 0, j = s1.size(); j < s2.size(); ++j, ++i) {
            if (umap.count(s2[j]) > 0) {
                umap[s2[j]]--;
                if (umap[s2[j]] ==0) {
                    match++;
                }
            }
            if (umap.count(s2[i]) > 0) {
                if (umap[s2[i]] ==0) {
                    -- match;
                }
                umap[s2[i]]++;
            }
            if (match == umap.size()) {
                printunordered_map (umap);
                return true;
            }
        }
        return false;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::string s1, std::string s2,
        bool expected
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

    std::cout << "s1: \"" << s1 << "\""<< std::endl;
    std::cout << "s2: \"" << s2 << "\""<< std::endl;

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

        decltype(expected) result = solution.checkInclusion(s1, s2);
        std::cout << std::boolalpha << result << std::endl;

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
    std::string s1 = "ab";
    std::string s2 = "eidbaooo";
    bool expect = true ;
    Test("Test1", s1, s2, expect);
}
void Test2()
{
    std::string s1 = "ab";
    std::string s2 = "eidboaoo";
    bool expect = false;
    Test("Test2", s1, s2, expect);
}

void Test3()
{
    std::string s1 = "abc";
    std::string s2 = "oidbcaf";
    bool expect = true;
    Test("Test3", s1, s2, expect);
}

void Test4()
{
    std::string s1 = "dc";
    std::string s2 = "odicf";
    bool expect = false;
    Test("Test4", s1, s2, expect);
}

void Test5()
{
    std::string s1 = "bcdyabcdx";
    std::string s2 = "bcdxabcdy";
    bool expect = true;
    Test("Test5", s1, s2, expect);
}

void Test6()
{
    std::string s1 = "abc";
    std::string s2 = "aaacb";
    bool expect = true;
    Test("Test6", s1, s2, expect);
}

void Test7()
{
}

void Test8()
{
}
// 75 yy
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
