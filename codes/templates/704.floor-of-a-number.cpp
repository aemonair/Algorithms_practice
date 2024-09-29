/*
 * 704. Binary Search - Floor in a sorted array
 * Easy
 **************************************************************
 * Given an array of numbers sorted in ascending order, find the floor of a given number ‘key’. The floor of the ‘key’ will be the biggest element in the given array smaller than or equal to the ‘key’
 *
 * Write a function to return the index of the floor of the ‘key’. If there isn’t a floor, return -1.
 **************************************************************
 * Example 1:
 *
 * Input: nums = [4,6,10], key = 6
 * Output: 1
 * Explanation: The smallest number greater than or equal to '6' is '6' having index '1'.
 **************************************************************
 * Example 2:
 *
 * Input: nums = [1,3,8,10,15], key = 12
 * Output: 3
 * Explanation: The smallest number greater than or equal to '12' is '15' having index '4'.
 **************************************************************
 * Example 3:
 *
 * Input: nums = [4,6,10], key = 17
 * Output: 2
 * Explanation: There is no number greater than or equal to '17' in the given array.
 **************************************************************
 * Example 4:
 *
 * Input: nums = [4,6,10], key = -1
 * Output: -1
 * Explanation: The smallest number greater than or equal to '-1' is '4' having index '0'.
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

template< typename T>
std::ostream &operator<< (std::ostream &out , std::vector<T> _vec) {
    out << "[" ;
    for (auto x: _vec) {
        out << x << " ";
    }
    out << "]" << std::endl;
    return out ;
}
class Solution {
public:
    //
    int search(std::vector<int>& nums, int key)
    {
        return -1;
    }
    int search0(std::vector<int>& nums, int key)
    {
        return -1;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int> & nums,
        int key,
        int expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;
    std::cout << "Ceiling " << key <<  " in nums:" << nums << std::endl;

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

        decltype(expected) result = solution.search(nums, key);
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
    std::vector<int> nums ={4, 6, 8, 10};
    int key = 6;
    int expected = 1;
    Test("Test1",nums, key, expected);
}
void Test2()
{
    std::vector<int> nums ={1, 3, 8, 10, 15};
    int key = 12;
    int expected = 3;
    Test("Test2",nums, key, expected);
}

void Test3()
{
    std::vector<int> nums ={4, 6, 10};
    int key = 17;
    int expected = 2;
    Test("Test3",nums, key, expected);
}

void Test4()
{
    std::vector<int> nums ={4, 6, 10};
    int key = -1;
    int expected = -1;
    Test("Test4",nums, key, expected);
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
