/*
 *********************************************
 * 448. Find All Numbers Disappeared in an Array
 * Easy
 *********************************************
 * Given an numsay of integers where 1 ≤ a[i] ≤ n (n = size of numsay), some elements appear twice and others appear once.
 * 
 * Find all the elements of [1, n] inclusive that do not appear in this numsay.
 * 
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 *********************************************
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [5,6]
 *********************************************
 */

#include <stack>
#include <queue>
#include <chrono>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

class Solution {
public:
////////////////////////////////////////////////////////////////////////
    std::vector<int> res;
    int missingNumber1(std::vector<int> &nums ) 
    {
        int n = nums.size();
        int res = 0;
        res ^= n;
        for (int i =0;i < n; i++)
        {
            res ^= i ^ nums[i];
        }
        return res;
    }
    int missingNumber2(std::vector<int> &nums ) 
    {
        int n = nums.size();
        int expect = (0+n)*(n+1)/2;
        int sum = 0;
        for (int x : nums)
            sum += x;
        return expect-sum;
    }
    int missingNumber3(std::vector<int> &nums ) 
    {
        int n = nums.size();
        int res = 0;
        res += 0;
        for (int i =0; i< n; i++)
            res += i - nums[i];
        return res;
    }
    std::vector<int> findDisappearedNumbers(std::vector<int> &nums ) 
    {
        std::vector<int> results;
        return results;
    }
////////////////////////////////////////////////////////////////////////
    template <typename T>
    int printvector(std::vector<T> v)
    {
        //std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  ";
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";
        }
        std::cout << "\b\b  ]";
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
    template <typename T>
    int printvectorvector(std::vector<T> v)
    {
        std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << "[";
            printvector( *iter );
        }
        std::cout <<  std::endl;
        return v.size();
    }
////////////////////////////////////////////////////////////////////////
};

// ==================== TEST Codes====================
void Test(const std::string& testName, 
        std::vector<int>& nums,
        std::vector<int> expected
        )
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "nums:" << std::endl;
    solution.printvector(nums);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
const static int TEST_2    = 0;
const static int TEST_3    = 0;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        //decltype(expected)
        std::vector<int> solution_result = solution.findDisappearedNumbers(nums);
        std::cout << "solution result:" << std::endl;
        solution.printvector(solution_result);

        if(solution_result == expected)
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
    }
    if (TEST_2)
    {
    }
    if (TEST_3)
    {
    }
}

void Test1()
{
    std::vector<int> nums   = {1,2,3,5};
    std::vector<int> expect = {4};
    Test("Test1", nums, expect);
}
void Test2()
{
    std::vector<int> nums   = {4,3,2,7,8,2,3,1};
    std::vector<int> expect = {5,6};
    Test("Test2", nums, expect);
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
