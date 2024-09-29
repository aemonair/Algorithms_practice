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

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

class Solution {
public:
    //
    std::vector<int> searchRange(std::vector<int>& nums, int target)
    {
        int size = nums.size();
        auto leftbound = [&](){
            int left = 0;
            int right = size-1;
            while (left <= right) {
                int mid = left+(right-left)/2;
                if (nums[mid] < target) {
                    left =mid+1;
                }
                else if (nums[mid] >= target) {
                    right = mid-1;
                }
            }
            return left;
        };
        auto rightbound = [&](){
            int left = 0;
            int right = size-1;
            while (left <= right) {
                int mid = left+(right-left)/2;
                if (nums[mid] <= target) {
                    left =mid+1;
                }
                else if (nums[mid] > target) {
                    right = mid-1;
                }
            }
            return right;
        };
        int left = leftbound();
        int right = rightbound();
        if (left <= right) {
            return {left, right};
        }
        return {-1, -1};
    }
    std::vector<int> searchRange1(std::vector<int>& nums, int target)
    {
        return {};
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
    std::cout << "target " << target << " in nums:" << nums << std::endl;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST__    = 1;
const static int TEST_1    = 1;
    if(TEST__)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::cout << "find target:" << target << std::endl;
        //int left_result  = solution.left_bound(nums, target);
        //std::cout << "left_result:" << left_result << std::endl;
        //int right_result = solution.right_bound(nums, target);
        //std::cout << "right_result:" << right_result << std::endl;

        std::vector<int> && result = solution.searchRange(nums, target);
        std::cout << "result:" <<  result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    std::cout << "-----------------------------" << std::endl;
}
template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec)
{
    out << "[  ";
    for(auto v: _vec)
    {
        out << v << ", ";
    }
    out << "\b\b ]" ;
    return out;
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
