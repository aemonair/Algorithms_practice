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

class Solution
{
public:
    bool backspaceCompare0(std::string S, std::string T) {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (S[i] == '#') {
                    skipS++, i--;
                } else if (skipS > 0) {
                    skipS--, i--;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (T[j] == '#') {
                    skipT++, j--;
                } else if (skipT > 0) {
                    skipT--, j--;
                } else {
                    break;
                }
            }
            std::cout << i << ":" << S[i] << " " << j << ":" << T[j] << std::endl;
            if (i >= 0 && j >= 0) {
                if (S[i] != T[j]) {
                    return false;
                }
            } else {
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }
            i--, j--;
        }
        return true;
    }

    bool backspaceCompare1(std::string S, std::string T)
    {
        int end1 = S.size() -1;
        int end2 = T.size() -1;

        while (end1 >= 0 || end2 >= 0) {
            int index1 = getnext(S, end1);
            int index2 = getnext(T, end2);
            if (index1 >= 0 && index2 >= 0) {
                if (S[index1] != T[index2]) {
                    return false;
                }
            } else {
                if (index1 >= 0 || index2 >= 0) {
                    return false;
                }
            }
            end1 = index1 -1;
            end2 = index2 - 1;
           // if (index1 < 0 && index2 < 0) {
           //     return true;
           // }
           // if (index1 < 0 || index2 < 0) {
           //     return false;
           // }
           // if (S[index1] == T[index2]) {
           //     end1 = index1 - 1;
           //     end2 = index2 - 1;
           // } else {
           //     return false;
           // }
        }
        //if (end1 < 0 && end2< 0) {
        //    return true;
        //}
        //if (end1 < 0 || end2< 0) {
        //    std::cout << end1 << " "<< end2 << std::endl;
        //    return false;
        //}
        return true;
    }
    int getnext(std::string & str, int end)
    {
        int backsize = 0;
        while (end >= 0) {
            if (str[end] == '#') {
                backsize ++;
                end --;
            } else if (backsize > 0) {
                backsize --;
                end --;
            } else {
                break;
            }
        }
        std::cout << str << " " << end << std::endl;
        return end;
    }
    bool backspaceCompare(std::string S, std::string T)
    {
        return false;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::string S, std::string T,
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

    std::cout << "S: \"" << S << "\""<< std::endl;
    std::cout << "T: \"" << T << "\""<< std::endl;

const static int TEST_TIME = 0;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.backspaceCompare0(S, T);
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

        decltype(expected) result = solution.backspaceCompare1(S, T);
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
template<typename T>
int printvector(std::vector<T> v)
{
    if(0 == v.size())
    {
        std::cout << "[ ] Empty vector." << std::endl;
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
    std::string S = "ab#c";
    std::string T = "ad#c";
    bool expect = true ;
    Test("Test1", S, T, expect);
}
void Test2()
{
    std::string S = "ab##";
    std::string T = "c#d#";
    bool expect = true;
    Test("Test2", S, T, expect);
}

void Test3()
{
    std::string S = "a##c";
    std::string T = "#a#c";
    bool expect = true;
    Test("Test3", S, T, expect);
}

void Test4()
{
    std::string S = "a#c";
    std::string T = "b";
    bool expect = false;
    Test("Test4", S, T, expect);
}

void Test5()
{
    std::string S = "xy#z";
    std::string T = "xzz#";
    bool expect = true;
    Test("Test5", S, T, expect);
}

void Test6()
{
    std::string S = "xy#z";
    std::string T = "xyz#";
    bool expect = false;
    Test("Test6", S, T, expect);
}

void Test7()
{
    std::string S = "###z####";
    std::string T = "";
    bool expect = true;
    Test("Test7", S, T, expect);
}

void Test8()
{
    std::string S = "bbbextm";
    std::string T = "bbb#extm";
    bool expect = false;
    Test("Test8", S, T, expect);
}
void Test9()
{
    std::string S = "nzp#o#g";
    std::string T = "b#nzp#o#g";
    bool expect = true;
    Test("Test9", S, T, expect);
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
