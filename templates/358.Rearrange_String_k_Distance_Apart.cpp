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
class Solution {
public:
    // 
    std::string rearrangeString(std::string s, int k)
    {
        return "";
    }
    
    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        //std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  " ;//<< std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";//<<std::endl;
        }
        std::cout << "\b\b]" << std::endl;
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
    template <typename ...T>
    int printqueue(std::priority_queue<T... > big_queue)
    {
        std::priority_queue<T...> Big_queue = big_queue;
        int bsize = Big_queue.size();
        if (Big_queue.empty())
        {
            std::cout << "The big queue is empty. "<< std::endl;
        }
        std::cout << " | ";
        while (bsize--)
        {
            std::cout << "(" << Big_queue.top().first << " ," << Big_queue.top().second << "), " ;
            Big_queue.pop();
        }
        std::cout << std::endl ;
        return bsize;
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

        std::cout << "s  :" << s  << ",k:" << k << std::endl;
        std::string result = solution.rearrangeString( s, k );
        std::cout << "result:" << result <<  std::endl;

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
