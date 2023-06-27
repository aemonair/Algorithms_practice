/*
 **********************************************************************
 * 494. Target Sum
 * Medium
 **********************************************************************
 * You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
 ************************************************************************
 * Example 1:
 *
 * Input: nums is [1, 1, 1, 1, 1], target is 3.
 * Output: 5
 * Explanation:
 *
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 *
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 **********************************************************************
 * Example 2:
 * Input: nums = [1], target = 1
 * Output: 1
 **********************************************************************
 * Constraints:
 *
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
 *******************************************************************
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
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

class Solution {
public:
    int findTargetSumWays0(std::vector<int>& nums, int S)
    {
        int result = 0;
        return result;
    }
    //////////////////////////////////////////////////////////////
    int findTargetSumWays1(std::vector<int>& nums, int S)
    {
        return 0;
    }

    //////////////////////////////////////////////////////////////
};

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

template<typename T>
int printvector(std::vector<T> v);

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int>& nums,
        int target,
        int expected)
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "target:" << target << " , nums:";
    printvector(nums);
    // getpermutataion
const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        int result = solution.findTargetSumWays0(nums,target);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
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
    if(TEST_1)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        int result = solution.findTargetSumWays1(nums, target);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
            end = std::chrono::system_clock::now();
            elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
}

void Test1()
{
    std::vector<int> nums = {1, 1, 1, 1, 1};
    int target= 3;
    int result = 5;
    Test("Test1", nums, target, result);
}

void Test2()
{
    std::vector<int> nums = {1};
    int target= 1;
    int result = 1;
    Test("Test2", nums, target, result);
}

void Test3()
{
    std::vector<int> nums = {1, 1, 2, 3};
    int target= 1;
    int result = 3;
    Test("Test3", nums, target, result);
}

void Test4()
{
    std::vector<int> nums = {1, 2, 7, 1};
    int target= 9;
    int result = 2;
    Test("Test4", nums, target, result);
}

void Test5()
{
    //[0,0,0,0,0,0,0,0,1]
    //1
    std::vector<int> nums = {0,0,0,0,0,0,0,0,1};
    int target= 1;
    int result = 256;
    Test("Test5", nums, target, result);
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
