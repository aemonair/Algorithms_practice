/*
 *************************************************************************************************
 * 16. 3Sum Closest
 * Medium
 *************************************************************************************************
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *************************************************************************************************
 * Example 1:
 *
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *************************************************************************************************
 * Constraints:
 *
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 *************************************************************************************************
 *
 */
#include <unordered_map>
#include <algorithm>
#include <iostream>
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

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target)
    {
        int size = nums.size();
        std::sort(nums.begin(), nums.end());
        std::cout << nums << std::endl;
        int sum = 0;
        int mindiff = std::numeric_limits<int>::max();
        int diff = 0;
        for (int i =0; i < size-2; ++i) {
            int j = i+1;
            int k = size-1;
            while (j < k) {

                sum = nums[i]+nums[j]+nums[k];
                diff = sum - target;
                //if (abs(diff) > abs(mindiff)) {
                    //return sum;
                //}
                if (abs(mindiff) > abs(diff)) {
                    mindiff = diff;
                }
                //mindiff = std::min(abs(mindiff), abs(diff));
                std::cout << "[" << i << "] [" << j << "] ["<< k << "]: " << nums[i] << " " << nums[j] << " " << nums[k] << " ";
                std::cout << "diff:" << diff << "mindiff:" << mindiff << " ";
                std::cout << "min:" << mindiff << ",sum:" << sum << std::endl;
                if (diff < 0) {
                    j++;
                } else if (diff  > 0) {
                    k--;
                } else {
                    return sum;
                }
            }
        }
        return mindiff+target;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int>& nums,
        int target,
        int expected
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

    std::cout << "target:" << target << " ,nums:" << nums << std::endl;

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

        decltype(expected) solution_result = solution.threeSumClosest(nums, target);
        std::cout << "solution result:" << solution_result << std::endl;

        if(solution_result == expected)
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

// 75yy
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
    std::vector<int> nums   = {-1, 2, 1, -4};
    int target = 1;
    int expect = 2;
    Test("Test1", nums, target, expect);
}
void Test2()
{
    std::vector<int> nums   = {-2, 0, 1, 2};
    int target = 2;
    int expect = 1;
    Test("Test2", nums, target, expect);
}

void Test3()
{
    std::vector<int> nums   = {-3, -1, 1, 2};
    int target = 1;
    int expect = 0;
    Test("Test3", nums, target, expect);
}

void Test4()
{
    std::vector<int> nums   = {1, 0, 1, 1};
    int target = 100;
    int expect = 3;
    Test("Test4", nums, target, expect);
}

void Test5()
{
    std::vector<int> nums   = {1, 1, -1, -1, 3};
    int target = -1;
    int expect = -1;
    Test("Test5", nums, target, expect);
}

void Test6()
{
    std::vector<int> nums   = {1, 2, 5, 10, 11};
    int target = 12;
    int expect = 13;
    Test("Test6", nums, target, expect);
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
