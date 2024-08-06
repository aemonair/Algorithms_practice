/*
 **************************************************************
 * 1167 Minimum Cost to Connect Sticks
 **************************************************************
 * You have some number of sticks with positive integer lengths. These lengths are given as an array sticks, where sticks[i] is the length of the ith stick.
 *
 * You can connect any two sticks of lengths x and y into one stick by paying a cost of x + y. You must connect all the sticks until there is only one stick remaining.
 *
 * Return the minimum cost of connecting all the given sticks into one stick in this way.
 **************************************************************
 * Example 1:
 *
 * Input: sticks = [2,4,3]
 * Output: 14
 * Explanation: You start with sticks = [2,4,3].
 * 1. Combine sticks 2 and 3 for a cost of 2 + 3 = 5. Now you have sticks = [5,4].
 * 2. Combine sticks 5 and 4 for a cost of 5 + 4 = 9. Now you have sticks = [9].
 * There is only one stick left, so you are done. The total cost is 5 + 9 = 14.
 **************************************************************
 * Example 2:
 *
 * Input: sticks = [1,8,3,5]
 * Output: 30
 * Explanation: You start with sticks = [1,8,3,5].
 * 1. Combine sticks 1 and 3 for a cost of 1 + 3 = 4. Now you have sticks = [4,8,5].
 * 2. Combine sticks 4 and 5 for a cost of 4 + 5 = 9. Now you have sticks = [9,8].
 * 3. Combine sticks 9 and 8 for a cost of 9 + 8 = 17. Now you have sticks = [17].
 * There is only one stick left, so you are done. The total cost is 4 + 9 + 17 = 30.
 **************************************************************
 * Example 3:
 *
 * Input: sticks = [5]
 * Output: 0
 * Explanation: There is only one stick, so you don't need to do anything. The total cost is 0.
 **************************************************************
 * Constraints:
 *
 * 1 <= sticks.length <= 10^4
 * 1 <= sticks[i] <= 10^4
 **************************************************************
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
class Solution {
public:
    //
    int connectSticks(std::vector<int>& sticks)
    {
        return 0;
    }
   
    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  " ;//<< std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", "; // <<std::endl;
        }
        std::cout << "\b\b]" << std::endl;
        return v.size();
    }

    template <typename T>
    int printvectorvector(const std::vector<T> &v)
    {
        std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvector( *iter );
        }
        std::cout << std::endl;
        return v.size();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int> & sticks,
        int expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;
    std::cout << "sticks:" << std::endl;
    solution.printvector(sticks);

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.connectSticks(sticks);
        std::cout << "result:" << std::boolalpha << result << std::endl;

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
    }
    std::cout << "-----------------------------" << std::endl;
}
void Test1()
{
    std::vector<int> sticks ={2, 4, 3};
    Test("Test1",sticks, 14);
}
void Test2()
{
    std::vector<int> sticks ={1, 8, 3, 5};
    Test("Test2",sticks, 30);
}

void Test3()
{
    std::vector<int> sticks ={11};
    Test("Test3", sticks, 0 );
}

void Test4()
{
}

void Test5()
{
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
