/*
 *********************************************
 * 136. Single Number
 * Easy
 *********************************************
 * Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
 * Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?
 *********************************************
 * Example 1:
 *
 * Input: nums = [2,2,1]
 * Output: 1
 *********************************************
 * Example 2:
 *
 * Input: nums = [4,1,2,1,2]
 * Output: 4
 *********************************************
 * Example 3:
 *
 * Input: nums = [1]
 * Output: 1
 *********************************************
 * Constraints:
 *
 * 1 <= nums.length <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4
 * Each element in the array appears twice except for one element which appears only once.
 *********************************************
 */

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

class Solution {
public:
////////////////////////////////////////////////////////////////////////
    int singleNumber(std::vector<int> &nums)
    {
        int res = 0;
        return res;
    }
////////////////////////////////////////////////////////////////////////
    template <typename T>
    int printvector(std::vector<T> v)
    {
        //std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  ";
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";
        }
        std::cout << "\b\b  ]";
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
            std::cout << "[";
            printvector( *iter );
        }
        std::cout <<  std::endl;
        return v.size();
    }
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int>& nums,
        int expected
        )
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "nums:" << std::endl;
    solution.printvector(nums);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
const static int TEST_2    = 0;
const static int TEST_3    = 0;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) solution_result = solution.singleNumber(nums);
        std::cout << "solution result:" << solution_result << std::endl;

        if(solution_result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
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
    if (TEST_2)
    {
    }
    if (TEST_3)
    {
    }
}

void Test1()
{
    std::vector<int> nums   = {2,2,1};
    int expect = 1;
    Test("Test1", nums, expect);
}
void Test2()
{
    std::vector<int> nums   = {4,1,2,1,2};
    int expect = 4;
    Test("Test2", nums, expect);
}

void Test3()
{
    std::vector<int> nums   = {1};
    int expect = 1;
    Test("Test3", nums, expect);
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
