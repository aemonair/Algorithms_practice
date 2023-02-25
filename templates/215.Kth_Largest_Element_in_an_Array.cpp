/*
///////////////////////////////////////////////////////////////
 * 215. Kth Largest Element in an Array
 * Medium
///////////////////////////////////////////////////////////////
 * Given an integer array nums and an integer k, return the kth largest element in the array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
///////////////////////////////////////////////////////////////
 * Example 1:
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
///////////////////////////////////////////////////////////////
 * Example 2:
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
///////////////////////////////////////////////////////////////
 * Constraints:
 *
 * 1  <= k <= nums.length <= 104
 * -10^4 <= nums[i] <= 10^4
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
    int findKthLargest(std::vector<int>& nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for(auto num: nums)
        {
            pq.push(num);
            std::cout <<  " push" << num << "top:" << pq.top() <<std::endl;
            if(!pq.empty() )
            {
                if(pq.size() > k)
                {
                    std::cout << pq.top() << " pop" << std::endl;
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
    int findKthLargest1(std::vector<int>& nums, int k)
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

        decltype(expected) result = solution.findKthLargest(nums, k);
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
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.findKthLargest1(nums, k);
        std::cout << "result:" << result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha  << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }

    }
}
void Test1()
{
    std::vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    int expect = 5;
    Test("Test1", nums, k, expect);
}
void Test2()
{
    std::vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    int expect = 4;
    Test("Test2", nums, k, expect);
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

