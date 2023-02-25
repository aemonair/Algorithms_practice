/*
 * 875. Koko Eating Bananas
 * Medium
 ****************************************************************************** 
 * 
 * Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.  The guards have gone and will come back in H hours.
 * 
 * Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas, and eats K bananas from that pile.  If the pile has less than K bananas, she eats all of them instead, and won't eat any more bananas during this hour.
 * 
 * Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.
 * 
 * Return the minimum integer K such that she can eat all the bananas within H hours.
 * 
 ****************************************************************************** 
 * Example 1:
 * 
 * Input: piles = [3,6,7,11], H = 8
 * Output: 4
 ****************************************************************************** 
 * Example 2:
 * 
 * Input: piles = [30,11,23,4,20], H = 5
 * Output: 30
 ****************************************************************************** 
 * Example 3:
 * 
 * Input: piles = [30,11,23,4,20], H = 6
 * Output: 23
 ****************************************************************************** 
 * Constraints:
 * 
 * 1 <= piles.length <= 10^4
 * piles.length <= H <= 10^9
 * 1 <= piles[i] <= 10^9
 ****************************************************************************** 
 */

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
 
class Solution 
{
public:
    // 
    int minEatingSpeed0(
            std::vector<int>& piles, int H
            )
    {
    }
    int minEatingSpeed1(
            std::vector<int>& piles, int H
            )
    {
    }

    int getmax(std::vector<int>& piles)
    {
        int max = piles[0];
        for(int x: piles)
        {
            max = std::max(x, max);
        }
        return max;
    }
    int timeof(int n, int speed)
    {
    }
    bool canFinish(std::vector<int>& piles, int speed, int H)
    {
    }
    template <typename T>
    int printstack(std::stack<T> s)
    {
        if (s.empty())
        {
            std::cout << "The stack is empty." << std::endl;
            return 0;
        }
        std::cout <<  "The stack size is: " << s.size() << std::endl;
        std::stack<T> tmp;
        while (!s.empty())
        {
            std::cout << s.top() << ", ";
            s.pop();
        }
        std::cout <<  std::endl;
        return s.size();
    }

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << "| ";//<<std::endl;
        }
        std::cout << std::endl;
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
        std::vector<int>& piles, int H
        ,int expected
        )
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "piles:" << std::endl;
    solution.printvector(piles);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
    // getpermutataion
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.minEatingSpeed0(piles, H);
        std::cout << "result:" << result << std::endl;

        if(result == expected)
            std::cout << "Solution0 passed." << std::endl;
        else
            std::cout << "Solution0 failed." << std::endl;
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

        decltype(expected) result = solution.minEatingSpeed1(piles, H);
        std::cout << "result:" << result << std::endl;

        if(result == expected)
            std::cout << "Solution1 passed." << std::endl;
        else
            std::cout << "Solution1 failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
}
void Test1()
{
    std::vector<int> piles   = {3,6,7,11};
    int expect = 4;
    Test("Test1", piles, 8, expect);
}
void Test2()
{
    std::vector<int> piles   = {30,11,23,4,20};
    int expect = 30;
    Test("Test2", piles, 5, expect);
}

void Test3()
{
    std::vector<int> piles   = {30,11,23,4,20};
    int expect = 23;
    Test("Test3", piles, 6, expect);
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
