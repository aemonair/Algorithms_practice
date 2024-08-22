/*
 ******************************************************************************
 *844. Backspace String Compare
 * Easy
 ******************************************************************************
 * Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
 *
 * Note that after backspacing an empty text, the text will continue empty.
 *
 ******************************************************************************
 * Example 1:
 *
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 ******************************************************************************
 * Example 2:
 *
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 ******************************************************************************
 * Example 3:
 *
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 ******************************************************************************
 * Example 4:
 *
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 ******************************************************************************
 * Note:
 *
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S and T only contain lowercase letters and '#' characters.
 ******************************************************************************
 * Follow up:
 *
 * Can you solve it in O(N) time and O(1) space?
 ******************************************************************************
 */

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>
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
    int getnext(std::string &str, int index)
    {
        int count = 0;
        while (index >= 0) {
            if (str[index] == '#') {
                count++;
                index--;
            } else if (count > 0) {
                index --;
                count --;
            } else {
                break;
            }
        }
        return index;
    }
    int backspaceCompare0(std::string s, std::string t)
    {
        int end1 = s.size()-1;
        int end2 = t.size()-1;
        while (end1 >= 0 || end2 >= 0) {
            auto cur1 = getnext(s, end1);
            auto cur2 = getnext(t, end2);
            if (cur1 < 0 && cur2 < 0) {
                return true;
            }
            if (cur1 < 0 || cur2 < 0) {
                return false;
            }
            if (s[cur1] != t[cur2]) {
                return false;
            }
            end1 = cur1 - 1;
            end2 = cur2 - 1;
        }
        return true;
    }
    bool backspaceCompare(std::string s, std::string t)
    {
        return false;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::string s, std::string t,
        bool expected
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

    std::cout << "s: \"" << s << "\""<< std::endl;
    std::cout << "t: \"" << t << "\""<< std::endl;

const static int TEST_TIME = 0;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.backspaceCompare0(s, t);
        std::cout << std::boolalpha << result << std::endl;

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
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.backspaceCompare(s, t);
        std::cout << std::boolalpha << result << std::endl;

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
    std::string s = "ab#c";
    std::string t = "ad#c";
    bool expect = true ;
    Test("Test1", s, t, expect);
}
void Test2()
{
    std::string s = "ab##";
    std::string t = "c#d#";
    bool expect = true;
    Test("Test2", s, t, expect);
}

void Test3()
{
    std::string s = "a##c";
    std::string t = "#a#c";
    bool expect = true;
    Test("Test3", s, t, expect);
}

void Test4()
{
    std::string s = "a#c";
    std::string t = "b";
    bool expect = false;
    Test("Test4", s, t, expect);
}

void Test5()
{
    std::string s = "xy#z";
    std::string t = "xzz#";
    bool expect = true;
    Test("Test5", s, t, expect);
}

void Test6()
{
    std::string s = "xy#z";
    std::string t = "xyz#";
    bool expect = false;
    Test("Test6", s, t, expect);
}

void Test7()
{
    std::string s = "###z####";
    std::string t = "";
    bool expect = true;
    Test("Test7", s, t, expect);
}

void Test8()
{
    std::string s = "bbbextm";
    std::string t = "bbb#extm";
    bool expect = false;
    Test("Test8", s, t, expect);
}

void Test9()
{
    std::string s = "nzp#o#g";
    std::string t = "b#nzp#o#g";
    bool expect = true;
    Test("Test9", s, t, expect);
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
    Test8();
    Test9();

    return 0;
}
