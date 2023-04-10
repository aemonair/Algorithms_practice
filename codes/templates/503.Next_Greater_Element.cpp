/*
 * 503. Next Greater Element ?
 *
 ********************************************************* 
 * Given a not circular array (the next element of the last element is not the first element of the array), print the Next Greater Number for every element. 
 * The Next Greater Number of a number x is not the first greater number to its traversing-order next in the array, which means you could not search circularly to find its next greater number. 
 * If it doesn't exist, output -1 for this number.
 * 
 * Example 1:
 * 
 * Input: [2,1,2,4,3]
 * Output: [4,2,4,-1,-1]
 * Explanation: The first 2's next greater number is 4;
 * The number 4 can't find next greater number;
 * The second 2's next greater number , which is also 4.
 ********************************************************* 
 * Note: The length of given array won't exceed 10000.
 ********************************************************* 
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
 
class Solution {
public:
    // 
    std::vector<int> nextGreaterElement(
            std::vector<int>& nums
            )
    {
        std::vector<int> ans(nums.size());
        return ans;
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
        std::vector<int>& nums,
        std::vector<int>& expected
        )
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // getpermutataion
    {
        //start = std::chrono::system_clock::now();

        std::cout << "nums:" << std::endl;
        solution.printvector(nums);

        //decltype(expected) 
        std::vector<int> && result = solution.nextGreaterElement(nums);
        std::cout << "result:" << std::endl;
        solution.printvector(result);

        if(result == expected)
            std::cout << "Solution0 passed." << std::endl;
        else
            std::cout << "Solution0 failed." << std::endl;
        //end = std::chrono::system_clock::now();
        //elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        //std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
    }
}
void Test1()
{
    std::vector<int> nums   = {2, 1 , 2,  4,  3} ;
    std::vector<int> expect = {4, 2 , 4, -1, -1} ;
    Test("Test1", nums, expect);
}
void Test2()
{
    std::vector<int> nums   = {1, 2, 1} ;
    std::vector<int> expect = {2,-1, 2} ;
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
