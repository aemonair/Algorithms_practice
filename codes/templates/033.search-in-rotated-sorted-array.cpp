/*
 **************************************************************
 * 33. Search in Rotated Sorted Array
 * Medium
 **************************************************************
 * There is an integer array nums sorted in ascending order (with distinct values).
 *
 * Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 * For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
 *
 * Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 **************************************************************
 * Example 1:
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 **************************************************************
 * Example 2:
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 **************************************************************
 * Example 3:
 *
 * Input: nums = [1], target = 0
 * Output: -1
 **************************************************************
 * Constraints:
 *
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * All values of nums are unique.
 * nums is guaranteed to be rotated at some pivot.
 * -10^4 <= target <= 10^4
 **************************************************************
 */

#include <algorithm>
#include <iostream>
#include <thread>
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
    int search(std::vector<int>& nums, int target)
    {
        return -1;
    }
    int search1(std::vector<int>& nums, int target)
    {
        return -1;
    }

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  " ;//<< std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", "; // <<std::endl;
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
        int target,
        int expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;
    std::cout << "find target:" << target << " in "  ;
    std::cout << "nums:" << std::endl;
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

        decltype(expected) result = solution.search(nums, target);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
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
    std::cout << "-----------------------------" << std::endl;
}
void Test1()
{
    std::vector<int> nums ={4, 5, 6, 7, 0, 1, 2};
    Test("Test1.1",nums, 0, 4);
    Test("Test1.2",nums, 3,-1);
    Test("Test1.3",nums, 1, 5);
}
void Test2()
{
    std::vector<int> nums ={1};
    Test("Test2",nums, 0, -1);
}

void Test3()
{
    std::vector<int> nums ={4, 5, 6, 7};
    Test("Test3",nums, 7, 3);
    Test("Test3",nums, 4, 0);
}

void Test4()
{
    std::vector<int> nums ={5, 1, 3};
    Test("Test4",nums, 3, 2);
}

void Test5()
{
    std::vector<int> nums ={10, 15, 1, 3, 8};
    Test("Test5",nums, 15, 1);
}

void Test6()
{
    std::vector<int> nums ={4, 5, 7, 9, 10, -1, 2};
    Test("Test6",nums, 10, 4);
}

void Test7()
{
    std::vector<int> nums ={3, 1};
    Test("Test6",nums, 1, 1);
}

int main()
{
    Solution solution;

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;

}
