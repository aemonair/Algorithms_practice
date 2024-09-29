/*
 *********************************************
 * 90. Subsets II
 * Medium
 *********************************************
 * Given a collection of integers that might contain duplicates, nums,
 * return all possible subsets (the power set). @20200410
 *
 * Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in any order. @20210412
 *********************************************
 * Example 1:
 *
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * [
 *  [2],
 *  [1],
 *  [1,2,2],
 *  [2,2],
 *  [1,2],
 *  []
 * ]
 *********************************************
 * Example 2:
 *
 * Input: nums = [0]
 * Output: [[],[0]]
 *********************************************
 * Constraints:
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 *********************************************
 * Note:
 * The solution set must not contain duplicate subsets. // @20200410
 ******************************************
 *
 */

#include <set>
#include <stack>
#include <queue>
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
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup (std::vector<int>& nums)
    {
        return {};
    }
    std::vector<std::vector<int>> subsetsWithDup1(std::vector<int>& nums)
    {
        return {};
    }
    std::vector<std::vector<int>> subsetsWithDup2(std::vector<int>& nums)
    {
        return {};
    }
    std::vector<std::vector<int>> subsetsWithDup3(std::vector<int>& nums)
    {
        return {};
    }

};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int>& numbers,
        std::vector<std::vector<int>> expected
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

    std::cout << "numbers:" << numbers << std::endl;
    for (auto &x: expected) {
        std::sort(x.begin(), x.end());
    }
    std::sort(expected.begin(), expected.end());

const static int TEST_TIME = 1;
const static int TEST__    = 1;
const static int TEST_1    = 1;
const static int TEST_2    = 0;
const static int TEST_3    = 0;
    if (TEST__)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) result = solution.subsetsWithDup(numbers);
        std::cout << "solution result:" << result << std::endl;

        std::cout << "expect numbers:" << std::endl;
        std::sort(result.begin(), result.end());
        std::cout << "solution result:" << result << std::endl;
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
        decltype(expected) result = solution.subsetsWithDup1(numbers);
        std::cout << "solution1 result:" << result << std::endl;

        std::cout << "expect numbers:" << std::endl;
        std::sort(result.begin(), result.end());
        std::cout << "solution result:" << result << std::endl;
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
        decltype(expected) result = solution.subsetsWithDup2(numbers);
        std::cout << "solution2 result:" << result << std::endl;

        std::cout << "expect numbers:" << std::endl;
        std::sort(result.begin(), result.end());
        std::cout << "solution result:" << result << std::endl;
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
        decltype(expected) result = solution.subsetsWithDup3(numbers);
        std::cout << "solution3 result:" << result << std::endl;

        std::cout << "expect numbers:" << std::endl;
        std::sort(result.begin(), result.end());
        std::cout << "solution result:" << result << std::endl;
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
    std::vector<int> numbers   = {1,2,2};
    std::vector<std::vector<int>> expect = {{},{1},{1,2},{1,2,2},{2},{2,2}};
    Test("Test1", numbers, expect);
}
void Test2()
{
    std::vector<int> numbers   = {0};
    std::vector<std::vector<int>> expect = {{},{0}};
    Test("Test2", numbers, expect);
}

void Test3()
{
    std::vector<int> numbers   = {1, 3, 3};
    std::vector<std::vector<int>> expect = {{}, {1}, {3}, {1,3}, {3,3}, {1,3,3}};
    Test("Test3", numbers, expect);
}

void Test4()
{
    std::vector<int> numbers   = {1, 5, 3, 3};
    std::vector<std::vector<int>> expect = {{}, {1}, {5}, {3}, {1,5}, {1,3}, {5,3}, {1,5,3}, {3,3}, {1,3,3}, {3,3,5}, {1,5,3,3} };
    Test("Test4", numbers, expect);
}

void Test5()
{
    std::vector<int> numbers   = {1, 2, 2, 2};
    std::vector<std::vector<int>> expect = {{}, {1}, {2}, {1,2}, {1,2,2}, {2,2}, {2,2,2}, {1,2,2,2} };
    Test("Test5", numbers, expect);
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
