/*
 *********************************************
 * 645. Set Mismatch
 * Easy
 *********************************************
 * The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.
 *
 * Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.
 *********************************************
 * Example 1:
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 *********************************************
 * Note:
 * 1. The given array size will in the range [2, 10000].
 * 2. The given array's numbers won't have any order.
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
    template <typename T>
    void swap(std::vector<T> &nums, int i, int j)
    {
        T temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    std::vector<int> findErrorNums (std::vector<int> &nums )
    {
        std::vector<int> result;
        return result;
    }
    std::vector<int> findErrorNums1(std::vector<int> &nums )
    {
        return std::vector<int>{};
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
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int>& nums,
        std::vector<int> expected
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
const static int TEST_1    = 1;
const static int TEST_2    = 0;
const static int TEST_3    = 0;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        //decltype(expected)
        std::vector<int> solution_result = solution.findErrorNums(nums);
        std::cout << "solution result:" << std::endl;
        solution.printvector(solution_result);

        if(solution_result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::endl;
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
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        //decltype(expected)
        std::vector<int> solution_result = solution.findErrorNums1(nums);
        std::cout << "solution result:" << std::endl;
        solution.printvector(solution_result);

        if(solution_result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::endl;
            solution.printvector(expected);
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
    }
    if (TEST_3)
    {
    }
}

void Test1()
{
    std::vector<int> nums   = {1,2,3,3};
    std::vector<int> expect = {3,4};
    Test("Test1", nums, expect);
}
void Test2()
{
    std::vector<int> nums   = {1,2,2,4};
    std::vector<int> expect = {2,3};
    Test("Test2", nums, expect);
}

void Test3()
{
    std::vector<int> nums   = {3,1,2,5,2};
    std::vector<int> expect = {2,4};
    Test("Test1", nums, expect);
}

void Test4()
{
    std::vector<int> nums   = {3,1,2,3,6,4};
    std::vector<int> expect = {3,5};
    Test("Test2", nums, expect);
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
