/*
 *************************************
 * 358. Rearrange String k Distance Apart
 *************************************
 * Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.
 * All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".
 *************************************
 * Example 1:
 *
 * str = "aabbcc", k = 3
 * Result: "abcabc"
 * The same letters are at least distance 3 from each other.
 *************************************
 * Example 2:
 *
 * str = "aaabc", k = 3
 * Answer: ""
 * It is not possible to rearrange the string.
 *************************************
 * Example 3:
 *
 * str = "aaadbbcc", k = 2
 * Answer: "abacabcd"
 * Another possible answer is: "abcabcda"
 *************************************
 * The same letters are at least distance 2 from each other.
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

template <typename T1, typename T2>
std::ostream & operator << (std::ostream &out, std::pair <T1,T2> pair);

template <typename ...T>
std::ostream & operator << (std::ostream &out, std::queue<T... > queue);

template <typename ...T>
std::ostream & operator << (std::ostream &out, std::priority_queue<T... > big_queue);

class Solution {
public:
    //
    std::string rearrangeString(std::string s, int k)
    {
        std::unordered_map<char, int> umap;
        for (auto &c: s) {
            umap[c]++;
        }
        std::priority_queue<std::pair<int,char>> max_heap;
        for (auto [val,cnt] : umap) {
            max_heap.push({cnt, val});
        }
        std::queue<std::pair<int, char>> cooldown_queue;
        std::string result;

        while (!max_heap.empty()) {
            auto [freq, ch] = max_heap.top();
            max_heap.pop();
            // Append the current character to the result string
            result += ch;
            // Decrease the frequency and add character to cooldown queue
            cooldown_queue.push({freq - 1, ch});

            // If cooldown queue size reached k, release the front character from cooldown
            if (cooldown_queue.size() >= k) {
                auto [freq_count, front_char] = cooldown_queue.front();
                cooldown_queue.pop();

                // If the character still has remaining counts, add it back to the max heap
                if (freq_count > 0) {
                    max_heap.push({freq_count, front_char});
                }
            }
        }

        // If result size is different from input string size, rearrangement is not possible
        return result.size() == s.size() ? result : "";
    }
    std::string rearrangeString1(std::string s, int k)
    {
        return "";
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::string   s  ,
        int k,
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
const static int TEST_0    = 1;
const static int TEST_1    = 1;
    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::cout << "s  :\"" << s  << "\",k:" << k << std::endl;
        std::string result = solution.rearrangeString( s, k );
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
    }
    std::cout << "-----------------------------" << std::endl;
}
template <typename T1, typename T2>
std::ostream & operator << (std::ostream &out, std::pair <T1,T2> pair)
{
    out << "{" << pair.first << " ," << pair.second << "}, " ;
    return out;
}

template <typename ...T>
std::ostream & operator << (std::ostream &out, std::queue<T... > queue)
{
    std::queue<T...> _queue = queue;
    int bsize = _queue.size();
    if (_queue.empty())
    {
        out << "The big queue is empty. "<< std::endl;
    }
    out << "<< ";
    while (bsize--)
    {
        out <<  _queue.front();
        _queue.pop();
    }
    out << std::endl ;
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
        out << " " << Big_queue.top() << " " ;
        Big_queue.pop();
    }
    out << std::endl ;
    return out;
}

void Test1()
{
    std::string s = "aabbcc";
    int k = 3;
    std::set<std::string> expect = {"abcabc","acbacb", "bacbac","bcabca", "cabcab", "cbacba"};
    Test("Test1", s, k, expect);
}
void Test2()
{
    std::string s = "aaabc";
    int k = 3;
    std::set<std::string> expect = {""};
    Test("Test2", s, k, expect);
}

void Test3()
{
    std::string s = "aaadbbcc";
    int k = 2;
    std::set<std::string> expect = {"abacabcd","abcabcda","acbadcba"};
    Test("Test3", s, k, expect);
}

void Test4()
{
    std::string s = "mmpp";
    int k = 2;
    std::set<std::string> expect = {"mpmp","pmpm"};
    Test("Test4", s, k, expect);
}

void Test5()
{
    std::string s = "Programming";
    int k = 3;
    std::set<std::string> expect = {"rgmoargmiPn","rgmPrgmiano","gmringmrPoa","gmrPagimnor","rmgronmigaP"};
    Test("Test5", s, k, expect);
}

void Test6()
{
    std::string s = "aab";
    int k = 2;
    std::set<std::string> expect = {"aba"};
    Test("Test6", s, k, expect);
}

void Test7()
{
    std::string s = "aappa";
    int k = 3;
    std::set<std::string> expect = {""};
    Test("Test7", s, k, expect);
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
