/*
 ******************************************************************************
 * 15. 3Sum
 * Medium
 ******************************************************************************
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Notice that the solution set must not contain duplicate triplets.
 ******************************************************************************
 * Example 1:
 *
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 ******************************************************************************
 * Example 2:
 *
 * Input: nums = []
 * Output: []
 ******************************************************************************
 * Example 3:
 *
 * Input: nums = [0]
 * Output: []
 ******************************************************************************
 * Constraints:
 *
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 ******************************************************************************
 */

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <climits>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define     RESET   "\033[0m"
#define     RED     "\033[31m"             /*      Red     */
#define     CYAN    "\033[36m"             /*      Cyan    */
#define     BLUE    "\033[34m"             /*      Blue    */
#define     GREEN   "\033[32m"             /*      Green   */
#define     WHITE   "\033[37m"             /*      White   */
#define     BLACK   "\033[30m"             /*      Black   */
#define     YELLOW  "\033[33m"             /*      Yellow  */
#define     MAGENTA "\033[35m"             /*      Magenta */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow  */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black   */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White   */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green   */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue    */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan    */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red     */

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

class Solution
{
public:
///////////////////////////////////////////////////////////////////////////////////////////////////////
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        int left = 0;
        int right = nums.size()-1;
        std::vector<std::vector<int>> resultv;
        return resultv;
    }
    std::vector<std::vector<int>> threeSum0(std::vector<int>& nums)
    {
    }
};

// ==================== TEST Codes====================
//std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
void Test(const std::string& testName,
        std::vector<int>& nums,
        std::vector<std::vector<int>> expected
        )
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "nums:" << nums << std::endl;

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

        //decltype(expected)
        std::vector<std::vector<int>> && result = solution.threeSum(nums);
        std::cout << "result:" << result << std::endl;

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
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
    std::vector<int> nums   = {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> expect = {{-1,-1,2},{-1,0,1}};
    Test("Test1", nums, expect);
}
void Test2()
{
    std::vector<int> nums   = {};
    std::vector<std::vector<int>> expect = {};
    Test("Test2", nums, expect);
}

void Test3()
{
    std::vector<int> nums   = {0};
    std::vector<std::vector<int>> expect = {};
    Test("Test3", nums, expect);
}

void Test4()
{
    std::vector<int> nums   = {-3,0,1,2,-1,1,-2};
    std::vector<std::vector<int>> expect = {{-3,1,2},{-2,0,2},{-2,1,1},{-1,0,1}};
    Test("Test4", nums, expect);
}

void Test5()
{
    std::vector<int> nums   = {-5,2,-1,-2,3};
    std::vector<std::vector<int>> expect = {{-5,2,3},{-2,-1,3}};
    Test("Test5", nums, expect);
}

void Test6()
{
    std::vector<int> nums   = {-2,0,0,2,2};
    std::vector<std::vector<int>> expect = {{-2,0,2}};
    Test("Test6", nums, expect);
}

void Test7()
{
    std::vector<int> nums   = {{-1,-1,-1,0,0,0,1,1,1}};
    std::vector<std::vector<int>> expect = {{-1,0,1},{0,0,0}};
    Test("Test7", nums, expect);
}
int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
