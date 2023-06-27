/*
 *************************************************************************************************
 * 41. First Missing Positive
 * Hard
 *************************************************************************************************
 * Given an unsorted integer array nums, find the smallest missing positive integer.
 *************************************************************************************************
 * Example 1:
 *
 * Input: nums = [1,2,0]
 * Output: 3
 *************************************************************************************************
 * Example 2:
 *
 * Input: nums = [3,4,-1,1]
 * Output: 2
 *************************************************************************************************
 * Example 3:
 *
 * Input: nums = [7,8,9,11,12]
 * Output: 1
 *************************************************************************************************
 * Constraints:
 *
 * 0 <= nums.length <= 300
 * -2^31 <= nums[i] <= 2^31 - 1
 * Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space?
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
    int firstMissingPositive (std::vector<int>& nums)
    {
        int i =0;
        printvector(nums);
        return nums.size()+1;
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
        int expected
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

        decltype(expected) solution_result = solution.firstMissingPositive(nums);
        std::cout << "solution result:" << solution_result << std::endl;

        if(solution_result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
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
    std::vector<int> nums   = {1, 2, 0};
    int expect = 3;
    Test("Test1", nums, expect);
}
void Test2()
{
    std::vector<int> nums   = {3, 4, -1, 1};
    int expect = 2;
    Test("Test2", nums, expect);
}

void Test3()
{
    std::vector<int> nums   = {7, 8, 9, 11, 12};
    int expect = 1;
    Test("Test3", nums, expect);
}

void Test4()
{
    std::vector<int> nums   = {-3, 1, 5, 4, 2};
    int expect = 3;
    Test("Test1", nums, expect);
}

void Test5()
{
    std::vector<int> nums   = {3, -2, 0, 1, 2};
    int expect = 4;
    Test("Test2", nums, expect);
}

void Test6()
{
    std::vector<int> nums   = {3, 2, 5, 1};
    int expect = 4;
    Test("Test3", nums, expect);
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
