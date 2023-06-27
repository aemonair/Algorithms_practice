/*
 * 300. Longest Increasing Subsequence
 * Medium
 *
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 *
 *********************************************************
 * Example:
 *
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 *********************************************************
 * Note:
 *
 * There may be more than one LIS combination, it is only necessary for you to return the length.
 * Your algorithm should run in O(n2) complexity.
 * Follow up: Could you improve it to O(n log n) time complexity?
 *********************************************************
 *********************************************************
 */

// 44 yy
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

class Solution {
public:
    int lengthOfLIS1(std::vector<int>& nums)
    {
        return 0;
    }
    int lengthOfLIS0(std::vector<int>& nums)
    {
        return 0;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int>& nums,
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

    std::cout << "nums:" << std::endl;
    printvector(nums);
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

        decltype(expected) result = solution.lengthOfLIS0(nums);
        std::cout << "result:" << std::boolalpha << result <<  std::endl;

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
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if (TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.lengthOfLIS1(nums);
        std::cout << "result1:" << std::boolalpha << result <<  std::endl;

        if(result == expected)
        {
            //10yy
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
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
}
// 76 yy
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
    std::vector<int> nums = {10,9,2,5,3,7,101,18};
    Test("Test1", nums, 4);
}

void Test2()
{
    std::vector<int> nums = {1,4,3,4,2,3};
    Test("Test2", nums, 3);
}

void Test3()
{
    std::vector<int> nums = {6,3,5,10,11,2,9,14,13,7,4,8,12};
    Test("Test3", nums, 5);
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
