/*
 *
 ************************************************************
 * 131. Palindrome Partitioning
 ************************************************************
 * Given a string s, partition s such that every
 * substring
 *  of the partition is a
 * palindrome
 * . Return all possible palindrome partitioning of s.
 ************************************************************
 * Example 1:
 *
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 ************************************************************
 * Example 2:
 *
 * Input: s = "a"
 * Output: [["a"]]
 ************************************************************
 * Constraints:
 *
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 ************************************************************
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
    std::vector<std::vector<std::string>> partition(std::string s)
    {

        std::vector<std::vector<std::string>> res;
        int size = s.size();
        std::vector<std::string> path;

        auto ispali = [](auto&& ispali, std::string str, int left,
                         int right) -> bool {
            if (left == right) {
                return true;
            }
            while (left < right) {
                if (str[left] != str[right]) {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        };
        auto dfs = [&](auto&& dfs, int i, int start) {
            if (i==size) {
                res.push_back(path);
                return;
            }
             // 不选 i 和 i+1 之间的逗号（i=n-1 时一定要选）
             //  i == size-1 时 再+1 会越界
             //  因为 n-1 一定是子串的右端点，所以一定要选。
            if (i < size-1) {
                dfs(dfs, i+1, start);
            }
            if (ispali(ispali, s, start, i)) {
                path.push_back(s.substr(start, i-start+1));
                dfs(dfs, i+1, i+1);
                path.pop_back();
            }
        };
        dfs(dfs, 0, 0);
        return res;
    }
    std::vector<std::vector<std::string>> partition1(std::string s)
    {
        std::vector<std::vector<std::string>> res;
        int size = s.size();
        std::vector<std::string> path;

        auto ispali = [](auto&& ispali, std::string str, int left,
                         int right) -> bool {
            if (left == right) {
                return true;
            }
            while (left < right) {
                if (str[left] != str[right]) {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        };
        auto dfs = [&](auto&& dfs, int start) {
            if (start == size){
                res.push_back(path);
                return;
            }
            for (int i = start; i < size; ++i) {
                if (ispali(ispali, s, start, i)) {
                    path.push_back(s.substr(start, i - start + 1));
                    dfs(dfs, i + 1 );
                    path.pop_back();
                }
            }
        };
        dfs(dfs, 0);
        return res;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::string s,
        std::vector<std::vector<std::string>> expected)
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    sort(expected.begin(), expected.end());
    std::cout << "s:" << s << std::endl;
const static int TEST_TIME = 1;
const static int TEST__    = 1;
const static int TEST_1    = 1;
    if (TEST__)
    {
        std::cout << "Solution start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.partition(s);
        sort(result.begin(), result.end());
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

        decltype(expected) result = solution.partition1(s);
        sort(result.begin(), result.end());
        std::cout << "result:" << std::boolalpha << result <<  std::endl;

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
    std::string s = "aab";
    Test("Test1", s, {{"a","a","b"},{"aa","b"}});
}

void Test2()
{
}

void Test3()
{
    std::string s = "a";
    Test("Test3", s, {{"a"}});
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
