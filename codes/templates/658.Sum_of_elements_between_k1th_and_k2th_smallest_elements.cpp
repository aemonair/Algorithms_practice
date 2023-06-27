/*
///////////////////////////////////////////////////////////////
 * Sum of elements between k1'th and k2'th smallest elements
 * Easy
///////////////////////////////////////////////////////////////
 * Given an array of positive integers and two positive integers K1 and K2. Find sum of all elements greater tha K1th and smaller than K2th smallest elements of array.
///////////////////////////////////////////////////////////////
 * Example 1:
 *
 * Input:
 * 7
 * 20 8 22 4 12 10 14
 * 3 6
 * Output:
 * 26
 * Explanation:
 * 3rd smallest element is 10
 * 6th smallest element is 20
 * Sum of all element between
 * K1 & K2 is 12 + 14 = 26
///////////////////////////////////////////////////////////////
 * Example 2:
 *
 * Input
 * 6
 * 10 2 50 12 48 13
 * 2 6
 * Output:
 * 73
///////////////////////////////////////////////////////////////
 * Your Task: 
 * You don't need to read input or print anything. Your task is to complete the function sumBetweenTwoKth() which takes the array A[], its size N and two integers K1 and K2 as inputs and returns the sum of all the elements between K1th and K2th smallest elements.
 * Expected Time Complexity: O(N. log(N))
 * Expected Auxiliary Space: O(N)
///////////////////////////////////////////////////////////////
 * Constraints:
 * 1 ≤ N ≤ 10^5
 * 1 ≤ K1, K2 ≤ 10^9
///////////////////////////////////////////////////////////////
 */

#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <chrono>
#include <iostream>
#include <queue>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

class Solution {
public:
///////////////////////////////////////////////////////////////
    int sumBetweenTwoKth(std::vector<int>& nums, int k1, int k2)
    {
        return 0;
    }
///////////////////////////////////////////////////////////////
    template <typename T>
    int printvector(std::vector<T> v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";
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
    template <typename T>
    int printstack(std::stack<T> s)
    {
        if (s.empty())
        {
            std::cout << "The stack is empty." << std::endl;
            return 0;
        }
        std::cout <<  "The stack size is: " << s.size() << std::endl;
        std::stack<T> tmp;
        while (!s.empty())
        {
            std::cout << s.top() << ", ";
            s.pop();
        }
        std::cout <<  std::endl;
        return s.size();
    }
///////////////////////////////////////////////////////////////
};
// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int>& nums,
        int k1, int k2,
        int expected
        )
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "k1:" << k1 << ",k2:" << k2 << ",nums:" << std::endl;
    solution.printvector(nums);

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

        decltype(expected) result = solution.sumBetweenTwoKth(nums, k1, k2);
        std::cout << "result:" << result << std::endl;

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
    if (TEST_1)
    {
    }
}
void Test1()
{
    std::vector<int> nums = {20,8,22,4,12,10,14};
    int k1 = 3;
    int k2 = 6;
    int expect = 26;
    Test("Test1", nums, k1, k2, expect);
}
void Test2()
{
    std::vector<int> nums = {10,2,50,12,48,13};
    int k1 = 2;
    int k2 = 6;
    int expect = 73;
    Test("Test2", nums, k1, k2, expect);
}

void Test3()
{
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

