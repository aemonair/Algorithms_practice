/*
 *************************************************************************************************
 * 75. Sort Colors
 * Medium
 *************************************************************************************************
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
 *
 * We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 *************************************************************************************************
 * Example 1:
 *
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 *************************************************************************************************
 * Example 2:
 *
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 *************************************************************************************************
 * Example 3:
 *
 * Input: nums = [0]
 * Output: [0]
 *************************************************************************************************
 * Example 4:
 *
 * Input: nums = [1]
 * Output: [1]
 *************************************************************************************************
 * Constraints:
 *
 * - n == nums.length
 * - 1 <= n <= 300
 * - nums[i] is 0, 1, or 2.
 *************************************************************************************************
 * Follow up:
 *
 * Could you solve this problem without using the library's sort function?
 * Could you come up with a one-pass algorithm using only O(1) constant space?
 *************************************************************************************************
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
    void sortColors(std::vector<int>& nums)
    {
        int size = nums.size();
        int i = 0;
        for (int left =0, right = size-1; i <=  right;) {
            if (nums[i] == 0) {
                std::swap(nums[i], nums[left]);
                ++left;
                ++i;
            } else if (nums[i] == 2) {
                std::swap(nums[i], nums[right]);
                --right;
                ++i;
            } else {
                ++i;
            }
        }
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int>& numbers,
        std::vector<int>& expected
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

    std::cout << "numbers:" << numbers << std::endl;

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

        solution.sortColors(numbers);
        std::cout << "Solution0 result:" << numbers << std::endl;

        if(numbers == expected)
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

void Test1()
{
    std::vector<int> numbers   = {2, 0, 2, 1, 1, 0};
    std::vector<int> expect    = {0, 0, 1, 1, 2, 2};
    Test("Test1", numbers, expect);
}
void Test2()
{
    std::vector<int> numbers   = {2, 0, 1};
    std::vector<int> expect    = {0, 1, 2};
    Test("Test2", numbers, expect);
}

void Test3()
{
    std::vector<int> numbers   = {0};
    std::vector<int> expect    = {0};
    Test("Test3", numbers, expect);
}

void Test4()
{
    std::vector<int> numbers   = {1};
    std::vector<int> expect    = {1};
    Test("Test4", numbers, expect);
}

void Test5()
{
    std::vector<int> numbers   = {1,1,1,2,1,1,1};
    std::vector<int> expect    = {1,1,1,1,1,1,2};
    Test("Test5", numbers, expect);
}

void Test6()
{
    std::vector<int> numbers   = {1,2,0,2,1};
    std::vector<int> expect    = {0,1,1,2,2};
    Test("Test6", numbers, expect);
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
