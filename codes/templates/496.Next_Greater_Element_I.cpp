/*
 * 496. Next Greater Element I
 * Easy
 ********************************************************* 
 * You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
 * 
 * The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.
 ********************************************************* 
 * Example 1:
 * 
 * Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
 * Output: [-1,3,-1]
 * Explanation:
 *     For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
 *     For number 1 in the first array, the next greater number for it in the second array is 3.
 *     For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
 ********************************************************* 
 * Example 2:
 * 
 * Input: nums1 = [2,4], nums2 = [1,2,3,4].
 * Output: [3,-1]
 * Explanation:
 *     For number 2 in the first array, the next greater number for it in the second array is 3.
 *     For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
 ********************************************************* 
 * Note:
 * 
 * 1. All elements in nums1 and nums2 are unique.
 * 2. The length of both nums1 and nums2 would not exceed 1000.
 ********************************************************* 
 */

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
 
class Solution {
public:
    // 
    std::vector<int> nextGreaterElement(std::vector<int>& nums)
    {
        std::vector<int> res(nums.size());
        return res;
    }
    std::vector<int> nextGreaterElement(
            std::vector<int>& nums1, std::vector<int>& nums2
            )
    {
        std::vector<int> res(nums1.size(), -1);
        return res;
    }

    template <typename T1, typename T2>
    int printunordered_map(const std::unordered_map<T1,T2> &v)
    {
        std::cout << "unordered_map size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << "(" << iter->first << "," << iter->second<< "), ";//<<std::endl;
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
        std::vector<int>& nums1, std::vector<int>& nums2,
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

        std::cout << "nums1:" << std::endl;
        solution.printvector(nums1);
        std::cout << "nums2:" << std::endl;
        solution.printvector(nums2);

//        decltype(expected)
            std::vector<int> result = solution.nextGreaterElement(nums1, nums2);
        std::cout << "result:" << std::boolalpha << std::endl;
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
    std::vector<int> nums1  = {4, 1, 2} ;
    std::vector<int> nums2  = {1, 3, 4, 2} ;
    std::vector<int> expect = {-1, 3, -1};
    Test("Test1", nums1, nums2, expect);
    //std::vector<int> nums1  = {4, 1, 2} ;
    //std::vector<int> nums2  = {1, 3, 4, 2} ;
    //
    //[1,]
    //[1,] (1,3)
    //[3,] (1,3)
    //[4] (1,3)(3,4)
    //[2,4] (1,3)(3,4)
    //The stack size is: 2
    //2, 4,
    //unordered_map size: 2
    //(3,4), (1,3),

    // 4,1,2,
    // 4
    // 1, ->3 ,res[1]=3
    // 2-> 
}
void Test2()
{
    std::vector<int> nums1  = {2, 4} ;
    std::vector<int> nums2  = {1, 2, 3, 4} ;
    std::vector<int> expect = {3, -1};
    Test("Test2", nums1, nums2, expect);
    // 1
    // (1,2)
    // (2,3)
    // (3,4)
    // The stack size is: 1
    //4,
    //unordered_map size: 3
    //(3,4), (1,2), (2,3),

}

void Test3()
{
    std::vector<int> nums = {2,1,2,4,2};
    Solution solution;
    auto result = solution.nextGreaterElement(nums);
    solution.printvector(result);
    // [2,1,2,4,3]
    // res[4] = -1
    // push 3 [3,]
    // res[3] = -1
    // push 4 [4,]
    // res[2] = 4
    // push 2 [2,4]
    // res[1] = 2
    // push 1 [1,2,4]
    // pop    [4]
    // res[0] = 4
    //
    // [4,2,4,-1,-1]
}

void Test4()
{
}

void Test5()
{
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
