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
    std::cout << "expected:" << std::endl;
    solution.printvector(expected);
    sort(expected.begin(), expected.end());

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

        std::vector<int> result = solution.diffWaysToCompute(input);
        std::cout << "result:" << std::endl;
        std::sort(result.begin(), result.end());
        solution.printvector(result);

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
