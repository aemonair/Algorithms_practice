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
        int size = num.size();
        std::vector<std::vector<int>> list;
        auto check = [](std::vector<int> &a, std::vector<int> &b, std::vector<int> &c){
            std::vector<int> res;
            int t = 0;
            for (int i =0; i< a.size() || i < b.size(); ++i) {
                if (i < a.size()) t+=a[i];
                if (i < b.size()) t+=b[i];
                res.push_back (t%10);
                t /=10;
            }
            if (t> 0) {
                res.push_back(1);
            }
            if (res.size() != c.size() ) {
                return false;
            }
            for (int i=0; i< res.size(); ++i) {
                if (res[i] != c[i]) {
                    return false;
                }
            }
            return true;
        };
        auto dfs = [&](auto &&dfs, int start) {
            int m = list.size();
            if (start >= size) {
                return m >=3;
            }
            std::vector<int> temp;
            // 0本身
            int max = num[start] == '0'? start +1: size;

            for (int i = 0; start + i < max; ++i) {
                temp.insert(temp.begin(), num[start+i]-'0');
                if (m < 2 ||check(list[m-2], list[m-1], temp)) {
                    list.push_back(temp);
                    if (dfs(dfs, start+i+1) ) {return true;}
                    list.pop_back();
                }
            }
            return false;
        };
        return dfs(dfs, 0);
    }
    bool isAdditiveNumber1(std::string num)
    {
        auto dfs = [&](auto &&dfs, std::string num, int index, int count,
        long long pprev,long long prev) {
            int len = num.length();
            if (index>=len) {
                return count >=3;
            }
            long long cur = 0;
            auto curC = num[index];
            for (int i = index; i< len;++i) {
                char c = num[i];
                if (curC == '0' && i>index){
                    return false;
                }
                cur = cur*10 + c-'0';
                if (cur > 99999999999999999) {
                    return false;
                }
                if (count >= 2) {
                    long long sum = pprev+prev;
                    if (cur > sum){
                        return false;
                    } else if (cur < sum) {
                        continue;
                    }
                }
                if (dfs(dfs, num, i+1, count+1, prev, cur)){
                    return true;
                }
            }
            return false;
        };
        return dfs(dfs, num, 0, 0, 0, 0);
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
