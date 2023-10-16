/*
 * 704. Binary Search
 * Easy
 **************************************************************
 * Given a sorted (in ascending order) integer array nums of n elements and a target value @20200924
 * write a function to search target in nums. If target exists, then return its index, otherwise return -1.
 *
 * Given an array of integers nums which is sorted in ascending order, and an integer target,  @20210425
 * write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
 **************************************************************
 * Example 1:
 *
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 **************************************************************
 * Example 2:
 *
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
 **************************************************************
 * Note:
 *
 * You may assume that all elements in nums are unique.
 * n will be in the range [1, 10000].
 * The value of each element in nums will be in the range [-9999, 9999].
 **************************************************************
 * Constraints:
 *
 * 1 <= nums.length <= 104
 * -9999 <= nums[i], target <= 9999
 * All the integers in nums are unique.
 * nums is sorted in an ascending order.
 **************************************************************
 */

#include <algorithm>
#include <iostream>
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
        int left = 0;
        int right = nums.size()-1;
        bool isAsc = (nums[left] < nums[right]) ;
        int result = -1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            if (nums[mid] == target) {
                right = mid -1;
                result = mid;
                // return mid;
            }

            if (isAsc){
                if (nums[mid] < target) {
                    left = mid +1;
                } else {
                    right = mid-1;
                }
            } else {
                if (nums[mid] > target) {
                    left = mid +1;
                } else {
                    right = mid-1;
                }
            }
        }
        return result;
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
    std::cout << "target:" << target << " nums:" << std::endl;
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
    std::vector<int> nums ={-1,0,3,5,9,12};
    Test("Test1.1",nums, 9,4);
    Test("Test1.2",nums, 2,-1);
}
void Test2()
{
    std::vector<int> nums ={-1,0,1,2,2,4};
    Test("Test2",nums, 2,3);
}

void Test3()
{
    std::vector<int> nums ={4,5,10};
    Test("Test3", nums, 10, 2);
}

void Test4()
{
    std::vector<int> nums ={1,2,3,4,5,6,7};
    int target = 5;
    Test("Test4", nums, target, 4);
}

void Test5()
{
    int target = -1;
    std::vector<int> nums ={10, 6, 4};
    target = 10;
    Test("Test5.1", nums, target, 0);
    target = 4;
    Test("Test5.2", nums, target, 2);
}

void Test6()
{
    int target = -1;
    std::vector<int> nums ={10, 6, 4, 4, 2, 2};
    target = 10;
    Test("Test6.1", nums, target, 0);
    target = 4;
    Test("Test6.2", nums, target, 2);
    target = 2;
    Test("Test6.3", nums, target, 4);
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

    return 0;

}
