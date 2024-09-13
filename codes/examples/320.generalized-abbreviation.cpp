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
template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> _vec);

class Solution {
public:
////////////////////////////////////////////////////////////////////////
    std::vector<std::string> generateAbbreviations (std::string word)
    {
        int size = word.size();
        std::vector<std::string> res;
        auto dfs = [&](auto &&dfs, std::string temp, int i, int count) {
            if (i == size) {
                if (count> 0) {
                    temp += (std::to_string(count));
                }
                res.push_back(temp);
                return;
            }
            dfs(dfs, temp, i+1, count+1);
            if (count > 0) {
                temp += std::to_string(count);
            }
            temp += word[i];
            dfs(dfs, temp, i+1, 0);
        };
        dfs(dfs, "", 0, 0);
        return res;
    }
    std::vector<std::string> generateAbbreviations1(std::string word)
    {
        std::string temp;
        int size = word.size();
        std::vector<std::string> res;
        auto dfs = [&](auto &&dfs, int i, int cnt){
            if (i == size) {
                if (cnt> 0) {
                    temp += std::to_string(cnt);
                }
                res.push_back(temp);
                return;
            }
            size_t oldsize = temp.size();
            dfs(dfs, i+1, cnt+1); // 数字+1
            temp.resize(oldsize);

            if (cnt > 0) {
                temp += std::to_string(cnt);
            }
            temp+= (word[i]);
            dfs(dfs, i+1, 0);
            temp.resize(oldsize);
        };
        dfs(dfs, 0, 0);
        return res;
    }
    std::vector<std::string> generateAbbreviations2(std::string word)
    {
        int n = word.size();
        std::vector<std::string> res;
        auto dfs = [&](auto &&dfs, int i, std::string str) {
            if (i == n) {
                res.push_back(str);
                return;
            }
            // 保持原始字符串不变，创建一个新的字符串进行操作
            std::string temp = str;
            for (int j = i; j < n; ++j) {
                if (j > i) {
                    temp += std::to_string(j - i); // 添加数字
                }
                temp += word[j]; // 添加字符
                dfs(dfs, j + 1, temp); // 递归调用，从下一个位置开始
                temp = str; // 恢复字符串状态
            }
            // 如果到了末尾，则添加剩余字符的数量
            dfs(dfs, n, str + std::to_string(n - i));
        };
        dfs(dfs, 0, "");
        return res;
    }
    void helper( int pos, std::string word, std::vector<std::string>& res) {
        for (int i = pos; i < word.size(); ++i) {
            for (int j = 1; i +j  <= word.size(); ++j) {
                std::string t = word.substr(0, i);
                t += std::to_string(j) + word.substr(i+j);
                res.push_back(t);
                helper(i+1+std::to_string(j).size(), t, res);
            }
        }
    }
    std::vector<std::string> generateAbbreviations3(std::string word)
    {
        std::vector<std::string> res = {word};
        auto dfs = [&](auto &&dfs, int pos, std::string word) -> void {
            for (int i = pos; i < word.size(); ++i) {
                for (int j = 1; i+j <= word.size(); ++j) {
                    std::string t = word.substr(0, i);
                    t += std::to_string(j) + word.substr(i+j);
                    res.push_back(t);
                    dfs(dfs, i+1+std::to_string(j).size(), t);
                }
            }
        };
        dfs(dfs, 0, word);
        //helper(0, word, res);
        return res;
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
    std::cout << "word: "<< word << std::endl;

const static int TEST_TIME = 1;
const static int TEST__    = 1;
const static int TEST_1    = 1;
const static int TEST_2    = 1;
const static int TEST_3    = 1;
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
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution costs " << elapsed.count() <<"micros" << std::endl;
        }
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
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
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
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution2 costs " << elapsed.count() <<"micros" << std::endl;
        }
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
        std::sort(expected.begin(), expected.end());
        std::cout << "solution result:" << result << std::endl;
        std::cout << "expected result:" << expected << std::endl;
        if(result == expected)
        {
            std::cout << GREEN << "Solution3 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution3 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution3 costs " << elapsed.count() <<"micros" << std::endl;
        }
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
