/*
 * int knapsack(int W, int N, std::vector<int>& wt, std::vector<int>& val)
 *************************************
 * Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
 * In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively.
 * Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
 * You cannot break an item, either pick the complete item or don’t pick it (0-1 property)
 *
 * 给你一个可装载重量为W的背包和N个物品，每个物品有重量和价值两个属性。其中第i个物品的重量为wt[i]，价值为val[i]，现在让你用这个背包装物品，最多能装的价值是多少？
 *
 *************************************
 * Example 1:
 *
 * Input:
 * N = 3, W = 4, wt = [2, 1, 3], val = [4, 2, 3]
 *
 * Output: 6
 *************************************
 * Example 2:
 *
 * Input:
 * N = 3, W = 50, wt = [10, 20, 30],val = [60, 100, 120]
 * Output: 220
 *************************************
 * Example 3:
 *
 * Input:
 * N = 4, W = 8, wt = [2, 3, 4, 5],val = [3, 4, 5, 6]
 * Output: 10
 *************************************
 * N = wt.size() == val.size()
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

    int knapsack(int bagweight, int N, std::vector<int>& weight, std::vector<int>& value)
    {
        return 0;
    }
    int knapsack2(int W, int N, std::vector<int>& wt, std::vector<int>& val)
    {
        return 0;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName, int W, int N, std::vector<int> & wt, std::vector<int>& val, int expected)
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

    std::cout << "W:" << W << ",N:" << N << std::endl;
    std::cout << "weight:";
    std::cout << wt << std::endl;
    //printvector(wt);
    std::cout << "value :";
    //printvector(val);
    std::cout << val << std::endl;

    const static int TEST_TIME = 1;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.knapsack(W, N, wt, val);
        std::cout << "result:" << result <<  std::endl;

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
    out << std::endl;
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
    //for (int i = 0; i< v.size(); i++) {
        //std::cout << " " << i ;
    //}
    //std::cout << std::endl;
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

int Test1()
{
    std::vector<int> wt  = {2, 1, 3};
    std::vector<int> val = {4, 2, 3};
    Test("Test1",4, 3, wt, val, 6);
    return 0;
}
int Test2()
{
    std::vector<int> wt  = {10, 20, 30};
    std::vector<int> val = {60, 100, 120};
    Test("Test2",50, 3, wt, val, 220);
    return 0;
}

int Test3()
{
    std::vector<int> wt  = {2, 3, 4, 5};
    std::vector<int> val = {3, 4, 5, 6};
    Test("Test3",8, 4, wt, val, 10);
    return 0;
}

int Test4()
{
}

int Test5()
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
