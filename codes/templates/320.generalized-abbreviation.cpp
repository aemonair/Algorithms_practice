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
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> _vec);

class Solution {
public:
////////////////////////////////////////////////////////////////////////
    std::vector<std::string> generateAbbreviations (std::string word)
    {
        return {};
    }
    std::vector<std::string> generateAbbreviations1(std::string word)
    {
        return {};
    }
    std::vector<std::string> generateAbbreviations2(std::string word)
    {
        return {};
    }
    std::vector<std::string> generateAbbreviations3(std::string word)
    {
        return {};
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
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::sort(expected.begin(), expected.end());
    std::cout << "word: "<< word << std::endl;

const static int TEST_TIME = 1;
const static int TEST__    = 1;
const static int TEST_1    = 0;
const static int TEST_2    = 0;
const static int TEST_3    = 0;
    if (TEST__)
    {
        std::cout << "Solution start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        auto result = solution.generateAbbreviations(word);
        std::cout << "solution result:" << result << std::endl;

        std::sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << RESET << std::endl;
            //std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if (TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        auto result = solution.generateAbbreviations1(word);
        std::cout << "solution result:" << result << std::endl;

        std::sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << RESET << std::endl;
            //std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if (TEST_2)
    {
        std::cout << "Solution2 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        auto result = solution.generateAbbreviations2(word);
        std::cout << "solution result:" << result << std::endl;

        std::sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution2 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution2 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << RESET << std::endl;
            //std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution2 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if (TEST_3)
    {
        std::cout << "Solution3 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        auto result = solution.generateAbbreviations3(word);
        std::cout << "solution result:" << result << std::endl;

        std::sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution3 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution3 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << RESET << std::endl;
            //std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution3 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
}

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> _vec)
{
    out << "[  ";
    for (auto &x: _vec) {
        std::cout << x << ", ";
    }
    out << "\b\b ]" << std::endl;
    return out;
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
