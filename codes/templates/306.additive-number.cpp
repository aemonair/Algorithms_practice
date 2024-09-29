/*
 *
 *********************************************************
 *  306. Additive Number
 *********************************************************
 306. Additive Number
 * An additive number is a string whose digits can form an additive sequence.
 *
 * A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
 *
 * Given a string containing only digits, return true if it is an additive number or false otherwise.
 *
 * Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
 *********************************************************
 * Example 1:
 *
 * Input: "112358"
 * Output: true
 * Explanation:
 * The digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 *********************************************************
 * Example 2:
 *
 * Input: "199100199"
 * Output: true
 * Explanation:
 * The additive sequence is: 1, 99, 100, 199.
 * 1 + 99 = 100, 99 + 100 = 199
 *********************************************************
 * Constraints:
 *
 * 1 <= num.length <= 35
 * num consists only of digits.
 *********************************************************
 * Follow up: How would you handle overflow for very large input integers?
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

class Solution {
public:
    bool isAdditiveNumber(std::string num)
    {
        return false;
    }
    bool isAdditiveNumber1(std::string num)
    {
        return false;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::string & num,
        bool expected)
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "num:" << num << std::endl;
const static int TEST_TIME = 1;
const static int TEST__    = 1;
const static int TEST_1    = 1;
    if (TEST__)
    {
        std::cout << "Solution  start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.isAdditiveNumber(num);
        std::cout << "result:" << std::boolalpha << result <<  std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution costs " << elapsed.count() <<"micros" << std::endl;
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

        decltype(expected) result = solution.isAdditiveNumber1(num);
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

void Test1()
{
    std::string  num = "112358" ;
    Test("Test1", num, true );
}

void Test2()
{
    std::string  num = "199100199" ;
    Test("Test2", num, true );
}

void Test3()
{
    std::string  num = "11235814" ;
    Test("Test2", num, false);
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
