/*
 ******************************************************************************
 *18. 4Sum
 * Medium
 ******************************************************************************
 * Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *
 * Notice that the solution set must not contain duplicate quadruplets.
 ******************************************************************************
 * Example 1:
 *
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 ******************************************************************************
 * Example 2:
 *
 * Input: nums = [], target = 0
 * Output: []
 ******************************************************************************
 * Constraints:
 *
 * 0 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 ******************************************************************************
 */

// 44yy
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

template<typename T>
int printvector(std::vector<T> v);

template <typename T>
int printstack(std::stack<T> s);

template <typename T1, typename T2>
int printunordered_map(const std::unordered_map<T1,T2> &v);

class Solution
{
public:
///////////////////////////////////////////////////////////////////////////////////////////////////////   
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
    {
        return std::vector<std::vector<int>>();
    }
};

// ==================== TEST Codes====================
//std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
void Test(const std::string& testName,
        std::vector<int>& nums,
        int target,
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

    std::cout << "nums:" << std::endl;
    printvector(nums);

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

        //decltype(expected)
        std::vector<std::vector<int>> && result = solution.fourSum(nums, target);
        std::cout << "result:" << std::endl;
        printvector(result);

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::endl;
            printvector(expected);
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

// 75 yy
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
template<typename T>
int printvector(std::vector<T> v)
{
    if(0 == v.size())
    {
        std::cout << "Empty vector." << std::endl;
        return 0;
    }
    std::cout << "[ " ;
    for(auto i: v)
    {
        std::cout << i << ", ";
    }
    std::cout << "\b\b ]" << std::endl;
    return v.size();
}
template<typename T>
int printstack (std::stack <T> s)
{
    if(s.empty())
    {
        std::cout << "Empty stack ." << std::endl;
        return 0;
    }
    std::cout <<  "The stack size is: " << s.size() << std::endl;
    std::cout << "[ " ;
    while (!s.empty())
    {
        std::cout << s.top() << ", ";
        s.pop();
    }
    std::cout << "\b\b ]" << std::endl;
    return s.size();
}
template<typename T>
int printvector(std::stack <T> s)
{
    if(s.empty())
    {
        std::cout << "Empty stack ." << std::endl;
        return 0;
    }
    std::cout <<  "The stack size is: " << s.size() << std::endl;
    std::cout << "[ " ;
    while (!s.empty())
    {
        std::cout << s.top() << ", ";
        s.pop();
    }
    std::cout << "\b\b ]" << std::endl;
    return s.size();
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

void Test1()
{
    int target = 0;
    std::vector<int> nums   = {1,0,-1,0,-2,2};
    std::vector<std::vector<int>> expect = {{-2,-1,1,2},{-2,0,0,2},{-1,0,0,1}};
    Test("Test1", nums, target, expect);
}
void Test2()
{
    int target = 0;
    std::vector<int> nums   = {};
    std::vector<std::vector<int>> expect = {};
    Test("Test2", nums, target, expect);
}

void Test3()
{
    int target = 1;
    std::vector<int> nums   = {4, 1, 2, -1, 1, -3};
    std::vector<std::vector<int>> expect = {{-3, -1, 1, 4}, {-3, 1, 1, 2}};
    Test("Test3", nums, target, expect);
}

void Test4()
{
    int target = 2;
    std::vector<int> nums   = {2, 0, -1, 1, -2, 2};
    std::vector<std::vector<int>> expect = {{-2, 0, 2, 2}, {-1, 0, 1, 2}};
    Test("Test4", nums, target, expect);
}

void Test5()
{
    int target = 2;
    std::vector<int> nums   = {2, 0, -1, -1, 1, 2, 0, -2, 2};
    std::vector<std::vector<int>> expect = {{-2, 0, 2, 2},{-1,-1,2,2},{-1, 0, 1, 2}};
    Test("Test5", nums, target, expect);
}

void Test6()
{
    int target = 0;
    std::vector<int> nums   = {1000000000,1000000000,1000000000,1000000000};
    std::vector<std::vector<int>> expect = {};
    Test("Test6", nums, target, expect);
}

void Test7()
{
    int target = -294967296;
    std::vector<int> nums   = {1000000000,1000000000,1000000000,1000000000};
    std::vector<std::vector<int>> expect = {};
    Test("Test7", nums, target, expect);
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
