/*
 * int countSubsets(std::vector<int>& nums, int sum)
 *^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*
 * Count of Subset Sum (hard)
 * Given a set of positive numbers, find the total number of subsets whose sum is equal to a given number ‘S’.
 *^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*
 * Example 1:
 *
 * Input: {1, 1, 2, 3}, S=4
 * Output: 3
 * The given set has '3' subsets whose sum is '4': {1, 1, 2}, {1, 3}, {1, 3}
 * Note that we have two similar sets {1, 3}, because we have two '1' in our input.
 *^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*
 * Example 2:
 *
 * Input: {1, 2, 7, 1, 5}, S=9
 * Output: 3
 * The given set has '3' subsets whose sum is '9': {2, 7}, {1, 7, 1}, {1, 2, 1, 5}
 *^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*
 */

#include <unordered_map>
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
    int countSubsets(std::vector<int>& nums, int sum)
    {
        return 0;
    }
};

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int> & nums,
        int sum,
        int target,
        std::vector<std::vector<int>>& expected)
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "sum:" <<  sum << " , nums:" << nums << std::endl;

    const static int TEST_TIME = 1;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(target) result = solution.countSubsets(nums, sum);
        std::cout << "result:" << std::boolalpha << result <<  std::endl;

        if(result == target)
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
void Test1()
{
    std::vector<int> nums = {1, 1, 2, 3 };
    int sum = 4;
    int target = 3;
    std::vector<std::vector<int>> expected = {{1,1,2},{1,3},{1,3}};
    Test("Test1",nums, sum, target, expected);
}
void Test2()
{
    std::vector<int> nums = {1, 2, 7, 1, 5};
    int sum = 9;
    int target = 3;
    std::vector<std::vector<int>> expected = {{2,7},{1,7,1},{1,2,1,5}};
    Test("Test2", nums, sum, target, expected);
}

void Test3()
{
    std::vector<int> nums = {7, 5, 1, 2, 1};
    int sum = 9;
    int target = 3;
    std::vector<std::vector<int>> expected = {{2,7},{1,7,1},{1,2,1,5}};
    Test("Test2", nums, sum, target, expected);
}

void Test4()
{
}

void Test5()
{
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

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;

}
