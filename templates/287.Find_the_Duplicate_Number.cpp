/*
 ************************************************************************************************* 
 * 287. Find the Duplicate Number
 * Medium
 ************************************************************************************************* 
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 * There is only one repeated number in nums, return this repeated number.
 ************************************************************************************************* 
 * Example 1:
 * 
 * Input: nums = [1,3,4,2,2]
 * Output: 2
 ************************************************************************************************* 
 * Example 2:
 * 
 * Input: nums = [3,1,3,4,2]
 * Output: 3
 ************************************************************************************************* 
 * Example 3:
 * 
 * Input: nums = [1,1]
 * Output: 1
 ************************************************************************************************* 
 * Example 4:
 * 
 * Input: nums = [1,1,2]
 * Output: 1
 ************************************************************************************************* 
 * Constraints:
 * 
 * 2 <= n <= 3 * 10^4
 * nums.length == n + 1
 * 1 <= nums[i] <= n
 * All the integers in nums appear only once except for precisely one integer which appears two or more times.
 ************************************************************************************************* 
 * Follow up:
 * 
 * How can we prove that at least one duplicate number must exist in nums?
 * Can you solve the problem without modifying the array nums?
 * Can you solve the problem using only constant, O(1) extra space?
 * Can you solve the problem with runtime complexity less than O(n2)?
 ************************************************************************************************* 
 * 
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
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

class Solution {
public:
    int findDuplicate (std::vector<int>& nums)
    {
        int i = 0;
        return 0;
    }
    int findDuplicate1(std::vector<int>& nums)
    {
        return 0;
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

        decltype(expected) solution_result = solution.findDuplicate(nums);
        std::cout << "solution result:" << solution_result << std::endl;

        if(solution_result == expected)
            std::cout << GREEN << "Solution0 passed." << WHITE <<  std::endl;
        else
        {
            std::cout << RED << "Solution0 failed." <<  WHITE << std::endl;
            std::cout << RED << "expected:" << expected <<  WHITE << std::endl;
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

        decltype(expected) solution_result = solution.findDuplicate1(nums);
        std::cout << "solution result:" << solution_result << std::endl;

        if(solution_result == expected)
            std::cout << GREEN << "Solution1 passed." << WHITE <<  std::endl;
        else
        {
            std::cout << RED << "Solution1 failed." <<  WHITE << std::endl;
            std::cout << RED << "expected:" << expected <<  WHITE << std::endl;
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
    std::vector<int> nums   = {1, 3, 4, 2, 2};
    int expect = 2;
    Test("Test1", nums, expect);
}
void Test2()
{
    std::vector<int> nums   = {3, 1, 3, 4, 2};
    int expect = 3;
    Test("Test2", nums, expect);
}

void Test3()
{
    std::vector<int> nums   = {1, 1};
    int expect = 1;
    Test("Test3", nums, expect);
}

void Test4()
{
    std::vector<int> nums   = {1, 1, 2};
    int expect = 1;
    Test("Test4", nums, expect);
}

void Test5()
{
    std::vector<int> nums   = {1, 4, 4, 3, 2};
    int expect = 4;
    Test("Test1", nums, expect);
}

void Test6()
{
    std::vector<int> nums   = {2, 1, 3, 3, 5, 4};
    int expect = 3;
    Test("Test2", nums, expect);
}
void Test7()
{
    std::vector<int> nums   = {2, 4, 1, 4, 4};
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
    Test7();

    return 0;

}
