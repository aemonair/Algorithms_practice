/*
 *************************************
 * 476. Number Complement
 * Easy
 *************************************
 * Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.
 *************************************
 * Example 1:
 *
 * Input: num = 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 *************************************
 * Example 2:
 *
 * Input: num = 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 *************************************
 * Constraints:
 *
 * The given integer num is guaranteed to fit within the range of a 32-bit signed integer.
 * num >= 1
 * You could assume no leading zero bit in the integer’s binary representation.
 * This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/
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
#include <cmath>
#include <map>
#include <set>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
class Solution {
public:
    //
    int findComplement(int num)
    {
        return 0;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        int   num,
        int   expected)
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
const static int TEST__    = 1;
const static int TEST_1    = 1;
    if(TEST__)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }


        std::cout << "num:" << num << " (" << std::bitset<8*sizeof(num)>(num) << ")" <<  std::endl;
        int result = solution.findComplement(num);
        std::cout << "result:" << result <<  std::endl;

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
    std::cout << "-----------------------------" << std::endl;
}
void Test1()
{
    Test("Test1", 5, 2);
}
void Test2()
{
    Test("Test2", 1, 0);
}

void Test3()
{
    Test("Test3", pow(2,16) -1, 0);
}

void Test4()
{
    Test("Test4", pow(2,31)-1, 0);
}

void Test5()
{
    Test("Test5", pow(2,10)-pow(2,6)-pow(2,3), pow(2,0) + pow(2,1) + pow(2,2)+pow(2,6) );
    // 0001000111
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
