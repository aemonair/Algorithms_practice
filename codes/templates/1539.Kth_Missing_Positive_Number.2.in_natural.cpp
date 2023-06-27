/*
 *************************************************************************************************
 * 1539. Kth Missing Positive Number
 * Find first k natural numbers missing in given array
 * Easy
 *************************************************************************************************
 * Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
 * Find the kth positive integer that is missing from this array.
 *
 * Given an array of size n and a number k, we need to print first k natural numbers that are not there in the given array.
 *************************************************************************************************
 * Example 1:
 *
 * Input: arr = [2,3,4], k = 3
 * Output: [1,5,6]
 *************************************************************************************************
 * Example 2:
 *
 * Input: arr = [-2,-3,4], k = 2
 * Output: [1, 2]
 *************************************************************************************************
 */
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
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
    std::vector<int> res;
    std::vector<int> findKthPositive (std::vector<int>& nums, int k)
    {
        std::vector<int> result;
        return result;
        return std::vector<int>{};
    }
    template<typename T>
    void swap(std::vector<T> &nums, int i, int j)
    {
        int temp = nums[i];
        nums[i]=nums[j];
        nums[j]= temp;
    }

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << "| ";//<<std::endl;
        }
        std::cout << std::endl;
        return v.size();
    }

    template <typename T>
    int printvectorvector(const std::vector<T> &v)
    {
        std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvector( *iter );
        }
        std::cout << std::endl;
        return v.size();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int>& nums,
        int k,
        std::vector<int>& expected
        )
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printvector(nums);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
const static int TEST_2    = 1;
const static int TEST_3    = 1;
    // getpermutataion
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        //decltype(expected)
        std::vector<int>&& solution_result = solution.findKthPositive(nums, k);
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
    std::vector<int> nums   = {2, 3, 4};
    int k = 3;
    std::vector<int> expect = {1,5,6};
    Test("Test1", nums, k, expect);
}
void Test2()
{
    std::vector<int> nums   = {-2, -3, 4};
    int k = 2;
    std::vector<int> expect = {1, 2};
    Test("Test2", nums, k, expect);
}

void Test3()
{
    std::vector<int> nums   = {1, 2 };
    int k = 1;
    std::vector<int> expect = {3};
    Test("Test3", nums, k, expect);
}

void Test4()
{
}

void Test5()
{
}

void Test6()
{
}
int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;

}
