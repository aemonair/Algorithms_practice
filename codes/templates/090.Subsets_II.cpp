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

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup0(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> result;
        return result;
    }
    std::vector<std::vector<int>> subsetsWithDup1(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> result;
        return result;
    }

    template <typename T>
    int printvector(std::vector<T> v)
    {
        //std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  " ; //<< v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";
        }
        std::cout << "\b\b]"; //<< std::endl;
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
        std::cout << "{";
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvector( *iter );
        }
        std::cout << "}";
        std::cout <<  std::endl;
        return v.size();
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

    std::cout << "numbers:" << std::endl;
    solution.printvector(numbers);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) solution_result = solution.subsetsWithDup0(numbers);
        std::cout << "solution0 result:" << std::endl;
        solution.printvectorvector(solution_result);

        std::cout << "expect numbers:" << std::endl;
        if(solution_result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            solution.printvectorvector(expected);
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
        decltype(expected) solution_result = solution.subsetsWithDup1(numbers);
        std::cout << "solution1 result:" << std::endl;
        solution.printvectorvector(solution_result);

        std::cout << "expect numbers:" << std::endl;
        if(solution_result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            solution.printvectorvector(expected);
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
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
