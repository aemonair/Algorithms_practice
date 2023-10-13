/*
 *********************************************
 * 784. Letter Case Permutation
 * Medium
 *********************************************
 * Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
 *
 * Return a list of all possible strings we could create. Return the output in any order.
 *********************************************
 * Example 1:
 *
 * Input: s = "a1b2"
 * Output: ["a1b2","a1B2","A1b2","A1B2"]
 *********************************************
 * Example 2:
 *
 * Input: s = "3z4"
 * Output: ["3z4","3Z4"]
 *********************************************
 * Example 3:
 *
 * Input: S = "12345"
 * Output: ["12345"]
 *********************************************
 * Example 4:
 *
 * Input: S = "0"
 * Output: ["0"]
 *********************************************
 * Constraints:
 *
 * 1 <= s.length <= 12
 * s consists of lowercase English letters, uppercase English letters, and digits.
 *********************************************
 */
// 44 yy
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <climits>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <cctype>
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
std::ostream & operator << (std::ostream &out, const std::queue <T> &_queue)
{
    auto Q(_queue);
    out << "queue :[  ";
    while (!Q.empty()) {
        out << Q.front() << ", ";
        Q.pop();
    }
    out << "\b\b ]" ;
    return out;
}
template<typename T>
std::ostream & operator << (std::ostream &out, const std::vector<T> &_vec)
{
    out << "[  ";
    for(auto v: _vec)
    {
        out << v << ", ";
    }
    out << "\b\b ]" ;
    return out;
}
class Solution {
public:
    std::vector<std::string> letterCasePermutation(std::string s) {
        std::vector<std::string> res;
        std::queue<std::string> queue;
        for (auto ch : s) {
            std::vector<char> curr;
            if (std::isdigit(ch)) {
                std::cout << ch << "是数字" << std::endl;
                // 遍历并添加到每个中
            } else if (std::islower(ch)) {
                // 将小写字母转换为大写字母
                //char uppercase = toupper(character);
                curr.push_back(toupper(ch));
            } else if (std::isupper(ch)) {
                // 将大写字母转换为小写字母
                //char lowercase = tolower(character);
                curr.push_back(tolower(ch));
            }
            // 添加 大小字母 到每个中
            curr.push_back(ch);
            std::cout << "curr:" << curr << std::endl;
            if (res.empty()){
                for (int j = 0; j < curr.size(); j++) {
                    std::cout << (curr[j]) << std::endl;
                    res.push_back(std::string(1,curr[j]));
                }
                std::cout << "empty" <<res << std::endl;
                continue;
            }
            std::cout << "res:" <<res << std::endl;
            int size = res.size();
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < curr.size(); j++) {
                    auto temp(res[i]);
                    temp += (curr[j]);
                    res.push_back(temp);
                    std::cout << res << std::endl;
                }
                // res.erase(res.begin());
            }
            res.erase(res.begin(), res.begin()+size);
            std::cout << res << std::endl;
        }
        return res;
    }
    std::vector<std::string> letterCasePermutation1(std::string s) {
        // 针对每个字符,添加到已有的字符串中;
        std::vector<std::string> res({s});
        for (int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i]) ) {
                int size = res.size();
                for (int j = 0; j < size; ++j) {
                    std::string temp(res[j]);
                    if(isupper(s[i])) {
                        temp[i] = tolower(temp[i]);
                    }
                    if (islower(s[i])) {
                        temp[i] = toupper(temp[i]);
                    }
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::string s,
        std::vector<std::string> expected)
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << " s: "<< s << std::endl;
    std::sort(expected.begin(), expected.end());

const static int TEST_TIME = 1;
const static int TEST_0    = 0;
const static int TEST_1    = 1;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) &&result = solution.letterCasePermutation(s);
        std::cout << "result:" << result << std::endl;

        std::sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
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

        decltype(expected) &&result = solution.letterCasePermutation1(s);
        std::cout << "result:" << result << std::endl;
        std::sort(result.begin(), result.end());

        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            // solution.printvectorvector(expected);
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
void Test1()
{
    Test("Test1", "a1b2", {"a1b2","a1B2","A1b2","A1B2"});
}
void Test2()
{
    Test("Test2", "3z4", {"3z4","3Z4"});
}

void Test3()
{
    std::string S = "12345";
    Test("Test3", S, std::vector<std::string> {"12345"});
}

void Test4()
{
    std::string S = "0";
    Test("Test4", S, std::vector<std::string> {"0"});
}

void Test5()
{
    std::string S = "0";
    Test("Test5", S, std::vector<std::string> {"0"});
}

int main()
{
    Solution solution;

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;

}
