/*
 * std::vector<int> smallestRange(std::vector<std::vector<int>>& nums)
 ******************************************************************************************
 * 632. Smallest Range Covering Elements from K Lists
 * Hard
 ******************************************************************************************
 * You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
 * 
 * We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
 ******************************************************************************************
 * Example 1:
 * 
 * Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
 * Output: [20,24]
 * Explanation: 
 * List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
 * List 2: [0, 9, 12, 20], 20 is in range [20,24].
 * List 3: [5, 18, 22, 30], 22 is in range [20,24].
 ******************************************************************************************
 * Example 2:
 * 
 * Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
 * Output: [1,1]
 ******************************************************************************************
 * Example 3:
 * 
 * Input: nums = [[10,10],[11,11]]
 * Output: [10,11]
 ******************************************************************************************
 * Example 4:
 * 
 * Input: nums = [[10],[11]]
 * Output: [10,11]
 ******************************************************************************************
 * Example 5:
 * 
 * Input: nums = [[1],[2],[3],[4],[5],[6],[7]]
 * Output: [1,7]
 ******************************************************************************************
 * Constraints:
 * 
 * nums.length == k
 * 1 <= k <= 3500
 * 1 <= nums[i].length <= 50
 * -10^5 <= nums[i][j] <= 10^5
 * nums[i] is sorted in non-decreasing order.
 ******************************************************************************************
 */
#include <iostream>
#include <limits>
#include <chrono>
#include <vector>
#include <queue>

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

class Solution {
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums)
    {
        return {};
    }
    
};


// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<std::vector<int>>& nums,
        std::vector<int> expected)
{
    std::cout << std::endl;
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
    {
        printvector(nums);
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.smallestRange(nums);

        std::cout << "result: " << result  << " " << std::endl;
        //if(result == expected)
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
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
}

int Test1()
{
    // Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
    // Output: [20,24]
    std::vector<std::vector<int>> nums{{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    std::vector<int> result1 = {20,24};
    Test("Test1", nums, result1);
    return 0;
}
int Test2()
{
    // Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
    // Output: [1,1]
    std::vector<std::vector<int>> v{{1,2,3},{1,2,3},{1,2,3}};
    std::vector<int> result2 = {1,1};
    Test("Test2", v, result2);
    return 0;
}
int Test3()
{
    // Input: nums = [[10,10],[11,11]]
    // Output: [10,11]
    std::vector<std::vector<int>> v{
        {10,10},{11,11}
    };
    std::vector<int> result3 = {10,11};
    Test("Test3", v, result3);
    return 0;
}
int Test4()
{
    // Input: nums = [[10],[11]]
    // Output: [10,11]
    std::vector<std::vector<int>> v{
        {10},{11}
    };
    std::vector<int> result4 = {10,11};
    Test("Test4", v, result4);
    return 0;
}
int Test5()
{
    // Input: nums = [[1],[2],[3],[4],[5],[6],[7]]
    // Output: [1,7]
    std::vector<std::vector<int>> v{
        {1},{2},{3},{4},{5},{6},{7}
    };
    std::vector<int> result5 = {1,7};
    Test("Test5", v, result5);
    return 0;
}
int Test6()
{
    // Input: L1=[1, 5, 8], L2=[4, 12], L3=[7, 8, 10]
    // Output: [4, 7]
    std::vector<std::vector<int>> v{
        {1, 5, 8}, {4, 12}, {7, 8, 10}
    };
    std::vector<int> result1 = {4,7};
    Test("Test1", v, result1);
    return 0;
}
int Test7()
{
    // Input: L1=[1, 9], L2=[4, 12], L3=[7, 10, 16]
    // Output: [9, 12]
    std::vector<std::vector<int>> v{
        {1, 9}, {4, 12}, {7, 10, 16}
    };
    std::vector<int> result2 = {9,12};
    Test("Test2", v, result2);
    return 0;
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
