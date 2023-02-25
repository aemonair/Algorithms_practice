/*
///////////////////////////////////////////////////////////////
 * Maximum distinct elements after removing K elements 
 * Easy
///////////////////////////////////////////////////////////////
 * Given an array containing N elements. The task is to find the maximum number of distinct elements after removing K elements from the array.
///////////////////////////////////////////////////////////////
 * Example 1:
 * 
 * Input : Arr[] = {5, 7, 5, 5, 1, 2, 2}, K = 3
 * Output : 4
 * Explanation:
 * Remove 2 occurrences of element 5 and 
 * 1 occurrence of element 2.
///////////////////////////////////////////////////////////////
 * Example 2:
 * 
 * Input : Arr[] = {1, 2, 3, 4, 5, 6, 7}, K = 5
 * Output : 2
///////////////////////////////////////////////////////////////
 * Your Task:
 * This is a function problem. The input is already taken care of by the driver code. You only need to complete the function maxDistinctNum() that takes an array (arr), sizeOfArray (n), integer value K, and return the maximum distinct elements after removing K elements. The driver code takes care of the printing.
 * 
 * Expected Time Complexity: O(K*logD)  where D is the number of distinct elements in the given array.
 * Expected Auxiliary Space: O(N).
///////////////////////////////////////////////////////////////
 * Constraints:
 * 1 ≤ K ≤ N ≤ 10^6
 * 1 ≤ A[i] ≤ 10^5
///////////////////////////////////////////////////////////////
 */

#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <chrono>
#include <queue>
#include <iostream>
#include <unordered_map>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

class Solution {
public:
///////////////////////////////////////////////////////////////
    int maxDistinctNum(std::vector<int>& nums, int k)
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
        int k,
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

    std::cout << "k:" << k << ",nums:" << std::endl;
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

        decltype(expected) result = solution.maxDistinctNum(nums, k);
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
    std::vector<int> nums = {5, 7, 5, 5, 1, 2, 2};
    int k = 3;
    int expect = 4;
    Test("Test1", nums, k, expect);
}
void Test2()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 5;
    int expect = 2;
    Test("Test2", nums, k, expect);
}

void Test3()
{
    std::vector<int> nums = {1, 2, 2, 2};
    int k = 1;
    int expect = 2;
    Test("Test3", nums, k, expect);
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

