/*
 **************************************************************
 * 154. Find Minimum in Rotated Sorted Array II
 * Hard
 **************************************************************
 * Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:
 *
 * [4,5,6,7,0,1,4] if it was rotated 4 times.
 * [0,1,4,4,5,6,7] if it was rotated 7 times.
 * Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
 *
 * Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
 *
 * You must decrease the overall operation steps as much as possible.
 **************************************************************
 * Example 1:
 *
 * Input: nums = [1,3,5]
 * Output: 1
 **************************************************************
 * Example 2:
 *
 * Input: nums = [2,2,2,0,1]
 * Output: 0
 **************************************************************
 * Constraints:
 *
 * n == nums.length
 * 1 <= n <= 5000
 * -5000 <= nums[i] <= 5000
 * nums is sorted and rotated between 1 and n times.
 * Follow up: This problem is similar to Find Minimum in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?
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
    int findMin(std::vector<int>& nums)
    {
        return 0;
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
        int expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;
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

        decltype(expected) result = solution.findMin(nums);
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
    std::vector<int> nums ={3, 4, 5, 1, 2, 3};
    Test("Test1",nums, 1 );
}
void Test2()
{
    std::vector<int> nums ={4, 5, 6, 7, 0, 0, 1, 2};
    Test("Test2",nums, 0 );
}

void Test3()
{
    std::vector<int> nums ={11, 13, 15, 17, 11};
    Test("Test3", nums, 11);
}

void Test4()
{
    std::vector<int> nums ={15};
    Test("Test4", nums, 15);
}

void Test5()
{
    std::vector<int> nums ={2, 0, 2, 2, 2};
    Test("Test5", nums, 0);
}

void Test6()
{
    std::vector<int> nums ={2, 2, 2, 2, 1};
    Test("Test6", nums, 1);
}

void Test7()
{
    std::vector<int> nums ={2, 7, 2, 2, 2};
    Test("Test7", nums, 2);
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
