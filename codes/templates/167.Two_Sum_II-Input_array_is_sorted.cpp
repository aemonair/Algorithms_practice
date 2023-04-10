/*
 * 167. Two Sum II - Input array is sorted
 * Easy
 ************************************************************************************************* 
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
 ************************************************************************************************* 
 * Note:
 * 
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may not use the same element twice.
 ************************************************************************************************* 
 * Example 1:
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 ************************************************************************************************* 
 * Example 2:
 * 
 * Input: numbers = [2,3,4], target = 6
 * Output: [1,3]
 ************************************************************************************************* 
 * Example 3:
 * 
 * Input: numbers = [-1,0], target = -1
 * Output: [1,2]
 ************************************************************************************************* 
 * Constraints:
 * 
 * 2 <= nums.length <= 3 * 10^4
 * -1000 <= nums[i] <= 1000
 * nums is sorted in increasing order.
 * -1000 <= target <= 1000
 ************************************************************************************************* 
 * 
 */
#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        return std::vector<int>(-1,-1);
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
        std::vector<int>& numbers, int target
        ,std::vector<int> expected
        )
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "numbers:" << std::endl;
    solution.printvector(numbers);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    // getpermutataion
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.twoSum(numbers, target);
        std::cout << "result:" << std::endl;
        solution.printvector(result);

        if(result == expected)
            std::cout << "Solution0 passed." << std::endl;
        else
            std::cout << "Solution0 failed." << std::endl;
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

        decltype(expected) result = solution.twoSum(numbers, target);
        std::cout << "result:" << std::endl;
        solution.printvector(result);

        if(result == expected)
            std::cout << "Solution1 passed." << std::endl;
        else
            std::cout << "Solution1 failed." << std::endl;
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
    std::vector<int> numbers   = {2,7,11,15};
    int target = 9;
    std::vector<int> expect = {1,2};
    Test("Test1", numbers, target, expect);
}
void Test2()
{
    std::vector<int> numbers   = {2,3,4};
    int target = 6;
    std::vector<int> expect = {1,3};
    Test("Test2", numbers, target, expect);
}

void Test3()
{
    std::vector<int> numbers   = {-1,0};
    int target = -1;
    std::vector<int> expect = {1,2};
    Test("Test3", numbers, target, expect);
}

void Test4()
{
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
