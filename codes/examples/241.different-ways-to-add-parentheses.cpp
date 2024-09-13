/*
 ******************************************************************
 * 241. Different Ways to Add Parentheses
 * Medium
 ******************************************************************
 * Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
 * Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
 ******************************************************************
 * Example 1:
 *
 * Input: "2-1-1"
 * Output: [0, 2]
 * Explanation:
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 ******************************************************************
 * Example 2:
 *
 * Input: "2*3-4*5"
 * Output: [-34, -14, -10, -10, 10]
 * Explanation:
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 ******************************************************************
 * Constraints:
 *
 * 1 <= expression.length <= 20
 * expression consists of digits and the operator '+', '-', and '*'.
 ******************************************************************
 *
 */

#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <chrono>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);
class Solution {
public:
///////////////////////////////////////////////////////////////
//2*3-4*5
//(2 * 3)-4*5   2 * (3-4*5)
//((2*3)- 4)*5 (2*3)-(4*5)   2*((3-4)*5) 2*(3-(4*5))
//
//(2*(3-(4*5))) = -34  4
//((2*3)-(4*5)) = -14   2
//((2*(3-4))*5) = -10
//(2*((3-4)*5)) = -10  3
//(((2*3)-4)*5) = 10  1
//
    std::vector<int> diffWaysToCompute(std::string input)
    {
        int size = input.size();
        int num = 0;
        std::vector<int> result;
        for (int i = 0; i < size; ++i) {
            if (isdigit(input[i])) {
                if (num != 0) {
                    num *= 10;
                }
                //num += std::stoi(input[i]);
                num += (input[i] - '0');
            } else {
                auto left = diffWaysToCompute(input.substr(0, i));
                auto right= diffWaysToCompute(input.substr(i+1));
                for (auto l: left) {
                    for(auto r: right) {
                        std::cout << l << input[i] << r << " ";
                        switch (input[i]) {
                            case '+':
                                result.push_back(l+r);
                                break;
                            case '-':
                                result.push_back(l-r);
                                break;
                            case '*':
                                result.push_back(l*r);
                                break;
                            case '/':
                                //result.push_back(l/r);
                                break;
                        }

                    }
                }
            }
        }
        if (result.empty()) {
            result.push_back(num);
        }
        return result;
    }
    std::vector<int> dfs(std::string input, int left, int right) {
        std::vector<int> res;
        for(int i=left; i < right; ++i) {
            if (input[i]>='0' && input[i] <='9') {
                continue;
            }
            auto lres = dfs(input, left, i-1);
            auto rres = dfs(input, i+1, right);
            for (auto &l : lres) {
                for (auto &r: rres) {
                    if(input[i] == '+') { res.push_back(l+r); }
                    if(input[i] == '*') { res.push_back(l*r); }
                    if(input[i] == '-') { res.push_back(l-r); }
                }
            }
        }
        if (res.empty()) {
            int temp = 0;
            for (int i =left; i < right; ++i) {
                temp = temp * 10 + (input[i] - '0');
            }
            res.push_back(temp);
        }
        return res;
    }
    std::vector<int> diffWaysToCompute1(std::string input)
    {
        int len = input.size();
        return dfs(input, 0, len -1);
        return {};
    }
};
// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::string input,
        std::vector<int>& expected
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

    std::cout << "input:"<< input << std::endl;
    // std::cout << "expected:" << expected << std::endl;
    sort(expected.begin(), expected.end());

const static int TEST_TIME = 1;
const static int TEST__    = 1;
const static int TEST_1    = 1;
    if (TEST__)
    {
        std::cout << "Solution start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::vector<int> result = solution.diffWaysToCompute(input);
        std::sort(result.begin(), result.end());
        std::cout << "result:" << result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << RESET << std::endl;
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

        std::vector<int> result = solution.diffWaysToCompute(input);
        std::sort(result.begin(), result.end());
        std::cout << "result:" << result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
}
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
void Test1()
{
    std::string input = "2-1-1";
    std::vector<int> expect = {0,2};
    Test("Test1", input, expect);
}
void Test2()
{
    std::string input = "2*3-4*5";
    std::vector<int> expect = {-34, -14, -10, -10, 10};
    Test("Test2", input, expect);
}

void Test3()
{
    std::string input = "1+1+1+1+1";
    std::vector<int> expect = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    Test("Test2", input, expect);
}

void Test4()
{
    std::string input = "10*3-4+5";
    std::vector<int> expect =// {-60, -5, 21, 31, 40};
     {10 * (3 - (4+5)),  10 * ((3-4) +5 ),(10*3) - (4+5) ,10 * (3-4) + 5 ,(10 * 3-4)+5 };
    Test("Test2", input, expect);
    // 10
    // 3
    // 4
    // 5
    // 4+5=9
    // 3-9=-6
    // 3
    // 4
    // 3-4=-1
    // 5
    // -1+5=4
    // 10*-6=-60   10 * (3 - (4+5))
    // 10*4=40     10 * ((3-4) +5 )
    // 10
    // 3
    // 10*3=30
    // 4
    // 5
    // 4+5=9
    // 30-9=21    (10*3) - (4+5)
    // 10
    // 3
    // 4
    // 3-4=-1
    // 10*-1=-10
    // 10
    // 3
    // 10*3=30
    // 4
    // 30-4=26
    // 5
    // -10+5=-5  10 * (3-4) + 5
    // 26+5=31   (10 * 3-4)+5
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
