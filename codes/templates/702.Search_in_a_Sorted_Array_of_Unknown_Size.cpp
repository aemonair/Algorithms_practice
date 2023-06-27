/*
 *************************************
 * 702. Search in a Sorted Array of Unknown Size
 * Medium
 *************************************
 * Given an integer array sorted in ascending order, write a function to search target in nums.  If target exists, then return its index, otherwise return -1. However, the array size is unknown to you. You may only access the array using an ArrayReader interface, where ArrayReader.get(k) returns the element of the array at index k (0-indexed).
 *
 * You may assume all integers in the array are less than 10000, and if you access the array out of bounds, ArrayReader.getwill return 2147483647.
 *************************************
 * Example 1:
 *
 * Input: array = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 *************************************
 * Example 2:
 *
 * Input: array = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
 *************************************
 * Example 1:
 *
 * Input: [1, 3, 6, 9, 21, …], target = 3
 * Output: 1
 *************************************
 * Example 2:
 *
 * Input: [1, 3, 6, 9, 21, …], target = 4
 * Output: -1
 *************************************
 * Note:
 * You may assume that all elements in the array are unique.
 * The value of each element in the array will be in the range[-9999, 9999].
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
class ArrayReader
{
private:
    std::vector<int> v;
public:
    ArrayReader(const std::vector<int> &v)
    {
       this->v = v;
    }
    int get(int i)
    {
        if(i >= v.size())
        {
            return std::numeric_limits<int>::max();
        }
        return v[i];
    }
    friend std::ostream &operator << (std::ostream & in, ArrayReader &a)
    {
        //std::cout
        in << "vector size: " << a.v.size() << std::endl;
        for (auto iter = a.v.begin(); iter != a.v.end(); iter++ )
        {
            in << *iter << "| ";//<<std::endl;
        }
        //std::cout << std::endl;
        return in ;//v.size();
    }
};
class Solution {
public:
    //
    int search(ArrayReader & reader, int target)
    {
        return -1;
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
void Test(const std::string& testName, ArrayReader & reader ,int target, int expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;
    std::cout << "target " << target << " in nums:" << std::endl;
    std::cout << reader << std::endl;

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
        int result  = solution.search(reader, target);

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
    ArrayReader reader(nums);
    int target = 9;
    int expected = 4;
    Test("Test1", reader, 9, 4);
    Test("Test2", reader, 2, -1);
}
void Test2()
{
    std::vector<int> nums ={1, 3, 6, 9, 21};
    ArrayReader reader(nums);
    Test("Test1", reader, 3, 1);
    Test("Test1", reader, 4, -1);
}

void Test3()
{
    /*Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 16
    Output: 6
    Explanation: The key is present at index '6' in the array.
    */
    std::vector<int> nums ={4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
    ArrayReader reader(nums);
    Test("Test1", reader, 16, 6);
    Test("Test1", reader, 11, -1);
}

void Test4()
{
    std::vector<int> nums ={1,3, 8, 10, 15};
    ArrayReader reader(nums);
    Test("Test1", reader, 15, 4);
    Test("Test1", reader, 200, -1);
}

void Test5()
{
    //Test("Test5", deadends, target, -1);
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
