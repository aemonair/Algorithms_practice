/*
 *************************************
 * 260. Single Number III
 * Medium
 *************************************
 * Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
 *
 * You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
 *************************************
 * Example 1:
 *
 * Input: nums = [1,2,1,3,2,5]
 * Output: [3,5]
 * Explanation:  [5, 3] is also a valid answer.
 *************************************
 * Example 2:
 *
 * Input: nums = [-1,0]
 * Output: [-1,0]
 *************************************
 * Example 3:
 *
 * Input: nums = [0,1]
 * Output: [1,0]
 *************************************
 * Constraints:
 *
 * 2 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each integer in nums will appear twice, only two integers will appear once.
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
#include <map>
#include <set>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
class Solution {
public:
    //
    std::vector<int> singleNumber(std::vector<int>& nums)
    {
        return std::vector<int>{};
    }
   
    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        //std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  " ;//<< std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";//<<std::endl;
        }
        std::cout << "\b\b]" << std::endl;
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
        std::vector<int> & nums,
        std::vector<int>   expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;
    solution.printvector(nums);

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }


        std::vector<int> && result = solution.singleNumber(nums);
        std::cout << "result:" <<  std::endl;
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
    std::cout << "-----------------------------" << std::endl;
}
void Test1()
{
    std::vector<int> nums ={1,2,1,3,2,5};
    Test("Test1",nums, std::vector<int>{3,5});
}
void Test2()
{
    std::vector<int> nums ={-1,0};
    Test("Test2",nums, std::vector<int> {-1,0});
}

void Test3()
{
    std::vector<int> nums ={0, 1};
    Test("Test3",nums, std::vector<int> {1,0});
}

void Test4()
{
    std::vector<int> nums ={5,7,7,8,8,10};
    Test("Test4",nums, std::vector<int> {5,10});
}

void Test5()
{
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
