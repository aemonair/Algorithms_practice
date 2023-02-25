/*
 * 1049. Last Stone Weight II
 * You are given an array of integers stones where stones[i] is the weight of the ith stone.
 * 
 * We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights x and y with x <= y. The result of this smash is:
 * 
 * If x == y, both stones are destroyed, and
 * If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
 * At the end of the game, there is at most one stone left.
 * 
 * Return the smallest possible weight of the left stone. If there are no stones left, return 0.
 * 
 * Example 1:
 * 
 * Input: stones = [2,7,4,1,8,1]
 * Output: 1
 * Explanation:
 * We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
 * we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
 * we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
 * we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.
 * Example 2:
 * 
 * Input: stones = [31,26,33,21,40]
 * Output: 5
 * 
 * Constraints:
 * 
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 100
 */

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
    int lastStoneWeightII(std::vector<int>& stones)
    {
        return 0;
    }
};

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

template<typename T>
int printvector(std::vector<T> v);


// ==================== TEST Codes====================
void Test(const std::string& testName, std::vector<int> & nums,int expected)
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;        
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "nums:";
    printvector(nums);

    const static int TEST_TIME = 1;    
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.lastStoneWeightII(nums);
        std::cout << "result:" << std::boolalpha << result <<  std::endl;

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
void Test1()
{
    std::vector<int> nums = {1, 2, 3, 9};
    Test("Test1",nums, 3);
}
void Test2()
{
    std::vector<int> nums = {1, 2, 7, 1, 5};
    Test("Test2",nums, 0);
}

void Test3()
{
    std::vector<int> nums = {1, 3, 100, 4};
    Test("Test1",nums, 92);
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

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;

}
