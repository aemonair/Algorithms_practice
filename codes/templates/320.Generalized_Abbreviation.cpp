/*
 *********************************************
 * 320. Generalized Abbreviation
 * Write a function to generate the generalized abbreviations of a word.
 *********************************************
 * Example:
 *
 * Given word ="word", return the following list (order does not matter):
 *
 * ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 *********************************************
 *
 */

#include <stack>
#include <queue>
#include <tuple>
#include <chrono>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

class Solution {
public:
////////////////////////////////////////////////////////////////////////
    std::vector<std::string> generateAbbreviations(std::string word)
    {
        std::vector<std::string> res;
        return res;
    }
////////////////////////////////////////////////////////////////////////
    template <typename ...T>
    int printqueue(std::queue<T... > big_queue)
    {
        std::queue<T...> Big_queue = big_queue;
        int bsize = Big_queue.size();
        if (Big_queue.empty())
        {
            std::cout << "The big queue is empty. "<< std::endl;
        }
        std::cout << " | ";
        while (bsize--)
        {
            std::cout << "(";
            std::cout << "\"" << std::get<0>(Big_queue.front()) << "\" ," ;
            std::cout << std::get<1>(Big_queue.front()) << " ," ;
            std::cout << std::get<2>(Big_queue.front()) << "  " ;
            std::cout << "), " ;
            Big_queue.pop();
        }
        std::cout << std::endl ;
        return bsize;
    }
    template <typename T>
    int printvector(std::vector<T> v)
    {
        //std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[";
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";
        }
        std::cout << "\b\b]";
        std::cout << std::endl;
        return v.size();
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
    int printvectorvector(std::vector<T> v)
    {
        std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvector( *iter );
        }
        std::cout <<  std::endl;
        return v.size();
    }
////////////////////////////////////////////////////////////////////////
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::string &word,
        std::vector<std::string> &expected
        )
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::sort(expected.begin(), expected.end());

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        //decltype(expected)&&
        auto result = solution.generateAbbreviations(word);
        std::cout << "solution result:" << std::endl;
        solution.printvector(result);

        std::sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            solution.printvector(expected);
            std::cout << RESET << std::endl;
        }
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
    std::string word = "word";
    std::vector<std::string> expect = {"word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"};
    Test("Test1", word, expect);
}
void Test2()
{
    std::string word = "BAT";
    std::vector<std::string> expect = {"BAT", "BA1", "B1T", "B2", "1AT", "1A1", "2T", "3"};
    Test("Test2", word, expect);
}

void Test3()
{
    std::string word = "code";
    std::vector<std::string> expect = {"code", "cod1", "co1e", "co2", "c1de", "c1d1", "c2e", "c3", "1ode", "1od1", "1o1e", "1o2", "2de", "2d1", "3e", "4"};
    Test("Test3", word, expect);
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
