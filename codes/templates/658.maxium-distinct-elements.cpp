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
 * Example 3:
 * Input: [7, 3, 5, 8, 5, 3, 3], and K=2
 * Output: 3
 * Explanation: We can remove two occurrences of 3 to be left with 3 distinct numbers [7, 3, 8], we have
 * to skip 5 because it is not distinct and occurred twice.
 * Another solution could be to remove one instance of '5' and '3' each to be left with three
 * distinct numbers [7, 5, 8], in this case, we have to skip 3 because it occurred twice.
///////////////////////////////////////////////////////////////
 * Example 4:
 *
 * Input: [3, 5, 12, 11, 12], and K=3
 * Output: 2
 * Explanation: We can remove one occurrence of 12, after which all numbers will become distinct. Then
 * we can delete any two numbers which will leave us 2 distinct numbers in the result.
///////////////////////////////////////////////////////////////
 * Example 5:
 * Input: [1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5], and K=2
 * Output: 3
 * Explanation: We can remove one occurrence of '4' to get three distinct numbers.
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
#include <unordered_set>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

template<typename T>
std::ostream & operator << (std::ostream &out, std::multiset<T> &_vec);
template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

class Solution {
public:
///////////////////////////////////////////////////////////////
    int maxDistinctNum(std::vector<int>& nums, int k)
    {
        return 0;
    }
    int maxDistinctNum1(std::vector<int>& nums, int k)
    {
        return 0;
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

    std::cout << "k:" << k << ",nums:" << nums << std::endl;

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
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
template<typename T>
std::ostream & operator << (std::ostream &out, std::multiset<T> &_vec)
{
    out << "[  ";
    for(auto v: _vec)
    {
        out << v << ", ";
    }
    out << "\b\b ]" ;
    return out;
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
    int expect = 1;
    Test("Test3", nums, k, expect);
}

void Test4()
{
    std::vector<int> nums = {7, 3, 5, 8, 5, 3, 3};
    int k = 2;
    int expect = 3;
    Test("Test4", nums, k, expect);
}

void Test5()
{
    std::vector<int> nums = {3, 5, 12, 11, 12};
    int k = 3;
    int expect = 2;
    Test("Test5", nums, k, expect);
}

void Test6()
{
    std::vector<int> nums = {1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5};
    int k = 2;
    int expect = 3;
    Test("Test6", nums, k, expect);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;

}

