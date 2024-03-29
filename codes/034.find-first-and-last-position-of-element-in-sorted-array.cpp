/*
 *************************************
 * 34. Find First and Last Position of Element in Sorted Array
 * Medium
 *************************************
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1]. @20200925
 *
 * If target is not found in the array, return [-1, -1].
 * Follow up: Could you write an algorithm with O(log n) runtime complexity? @20210426
 *************************************
 * Example 1:
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *************************************
 * Example 2:
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *************************************
 * Example 3:
 *
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 *************************************
 * Constraints:
 *
 * *0 <= nums.length <= 10^5
 * * -10^9 <= nums[i] <= 10^9
 * *nums is a non decreasing array.
 * *-10^9 <= target <= 10^9
 *************************************
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
    std::vector<int> searchRange(std::vector<int>& nums, int target)
    {
        if (nums.size() == 0) {
            return {-1,-1};
        }
        return std::vector<int>{bounds(nums,target,true),bounds(nums,target,false)};
    }
    int bounds(std::vector<int> &nums, int target, bool findleft) {
        int size = nums.size();
        int result = -1;
        int left = 0;
        int right = size-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] < target) {
                left = mid+1;
            } else if (nums[mid] > target){
                right = mid -1;
            } else { // (nums[mid] == target)
                result = mid;
                if (findleft) {   // 找左边界,向左
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
        }
        return result;
    }
    std::vector<int> searchRange1(std::vector<int>& nums, int target)
    {
        if (nums.size() == 0) {
            return {-1,-1};
        }
        return std::vector<int>{left_bound(nums,target),right_bound(nums,target)};
    }

    int left_bound(std::vector<int>& nums, int target)
    {
        int left = 0;
        int result = -1;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] < target) {
                left = mid+1;
            } else {
                if (nums[mid] == target) {
                    result = mid;
                }
                right = mid -1;
            }
        }
        return result;
        return left;
    }
    int right_bound(std::vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;
        int result = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] > target) {
                right = mid -1;
            } else if(nums[mid] < target){
                left = mid+1;
            } else {
                result = mid;
                left = mid+1;
            }
        }
        return result;
        return 0;
    }
    int right_bound_old(std::vector<int> &nums, int target)
    {
        return 0;
    }
    int left_bound_old(std::vector<int>& nums, int target)
    {
        return 0;
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
void Test(const std::string& testName, std::vector<int> & nums,int target, std::vector<int> expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;
    std::cout << "target " << target << " in nums:" << std::endl;
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

        std::cout << "find target:" << target << std::endl;
        int left_result  = solution.left_bound(nums, target);
        std::cout << "left_result:" << left_result << std::endl;
        int right_result = solution.right_bound(nums, target);
        std::cout << "right_result:" << right_result << std::endl;

        std::vector<int> && result = solution.searchRange(nums, target);
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
    std::vector<int> nums ={-1,0,3,5,9,12};
    Test("Test1",nums, 9,std::vector<int>{4,4});
}
void Test2()
{
    std::vector<int> nums ={-1,0,3,5,9,12};
    Test("Test2",nums, 2,std::vector<int> {-1,-1});
}

void Test3()
{
    std::vector<int> nums ={5,7,7,8,8,10};
    Test("Test3",nums, 8,std::vector<int> {3,4});
}

void Test4()
{
    std::vector<int> nums ={5,7,7,8,8,10};
    Test("Test4",nums, 6,std::vector<int> {-1,-1});
}

void Test5()
{
    std::vector<int> nums = {1};
    Test("Test5", nums, 1, std::vector<int>{0,0});
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
