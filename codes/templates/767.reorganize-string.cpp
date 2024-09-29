/*
 *************************************
 * 767. Reorganize String
 * Medium
 *************************************
 * Given a string s, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.
 * If possible, output any possible result.  If not possible, return the empty string.
 *************************************
 * Example 1:
 *
 * Input: s = "aab"
 * Output: "aba"
 *************************************
 * Example 2:
 *
 * Input: s = "aaab"
 * Output: ""
 *************************************
 * Note:
 *
 * s will consist of lowercase letters and have length in range [1, 500].
 *************************************
 */

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
// 76 yy
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
template <typename ...T>
std::ostream & operator << (std::ostream &out, std::priority_queue<T... > big_queue)
{
    std::priority_queue<T...> Big_queue = big_queue;
    int bsize = Big_queue.size();
    if (Big_queue.empty())
    {
        out << "The big queue is empty. "<< std::endl;
    }
    out << " | ";
    while (bsize--)
    {
        out << "{" << Big_queue.top().first << " ," << Big_queue.top().second << "}, " ;
        Big_queue.pop();
    }
    out << std::endl ;
    return out;
}

class Solution {
public:
    //
    std::string reorganizeString(std::string s)
    {
        return "";
    }
    std::string reorganizeString1(std::string s)
    {
        return "";
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::string   s  ,
        std::set<std::string>  expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST_0    = 0;
const static int TEST_1    = 1;
    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::cout << "s  :" << s   << std::endl;
        std::string result = solution.reorganizeString( s );
        std::cout << "result:\"" << result << "\"" << std::endl;

        if(expected.count(result))
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            for(auto exp: expected)
            {
                std::cout << exp << ",";
            }
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    }
    if (TEST_1)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::cout << "s  :" << s   << std::endl;
        std::string result = solution.reorganizeString1( s );
        std::cout << "result:\"" << result << "\"" << std::endl;

        if(expected.count(result))
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            for(auto exp: expected)
            {
                std::cout << exp << ",";
            }
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    }
}
void Test1()
{
    std::string s = "aab";
    std::set<std::string> expect = {"aba"};
    Test("Test1", s, expect);
}
void Test2()
{
    std::string s1 = "aaab";
    std::string s2 = "aaba";
    std::string s3 = "abaa";
    std::string s4 = "baaa";
    std::set<std::string> expect = {""};
    Test("Test2.1", s1, expect);
    Test("Test2.2", s2, expect);
    Test("Test2.3", s3, expect);
    Test("Test2.4", s4, expect);
}

void Test3()
{
    std::string s = "abbabbaaab";
    std::set<std::string> expect = {"bababababa","ababababab"};
    Test("Test3", s, expect);
}

void Test4()
{
    std::string s = "aappp";
    std::set<std::string> expect = {"papap"};
    Test("Test4", s, expect);
}

void Test5()
{
    std::string s = "Programming";
    std::set<std::string> expect = {"rgmoargmiPn","mgrgraioPmn","rgmrgmPiano","rgmoigamrPn","gmringmrPoa","gmrPagimnor"};
    Test("Test5", s, expect);
}

void Test6()
{
    std::string s = "vvvlo";
    std::set<std::string> expect = {"vlvov","vovlv"};
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

    return 0;

}
