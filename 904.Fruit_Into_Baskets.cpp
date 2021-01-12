/*
 ****************************************************************************** 
 * 904. Fruit Into Baskets
 * Medium
 ****************************************************************************** 
 * In a row of trees, the i-th tree produces fruit with type tree[i].
 * 
 * You start at any tree of your choice, then repeatedly perform the following steps:
 * 
 * 1. Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
 * 2. Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
 *
 * Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.
 * 
 * You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.
 * 
 * What is the total amount of fruit you can collect with this procedure?
 ****************************************************************************** 
 * Example 1:
 * 
 * Input: [1,2,1]
 * Output: 3
 * Explanation: We can collect [1,2,1].
 ****************************************************************************** 
 * Example 2:
 * 
 * Input: [0,1,2,2]
 * Output: 3
 * Explanation: We can collect [1,2,2].
 * If we started at the first tree, we would only collect [0, 1].
 ****************************************************************************** 
 * Example 3:
 * 
 * Input: [1,2,3,2,2]
 * Output: 4
 * Explanation: We can collect [2,3,2,2].
 * If we started at the first tree, we would only collect [1, 2].
 ****************************************************************************** 
 * Example 4:
 * 
 * Input: [3,3,3,1,2,1,1,2,3,3,4]
 * Output: 5
 * Explanation: We can collect [1,2,1,1,2].
 * If we started at the first tree or the eighth tree, we would only collect 4 fruits.
 ****************************************************************************** 
 * Note:
 * 
 * 1 <= tree.length <= 40000
 * 0 <= tree[i] < tree.length
 ****************************************************************************** 
 */

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
 
class Solution 
{
public:
    // 
    template <typename T>
    int totalFruit(std::vector<T> nums)
    {
        int k = 2;
        int end = 0;
        int maxtotal = 0;
        int size = nums.size();

        std::unordered_map<T, int> umap;
        for (int start = 0; end < size; end ++)
        {
            T cur = nums[end];
            umap[cur] += 1;
            while ( umap.size() > k )
            {
                T del = nums[start];
                umap[del] --;
                if (umap[del] == 0)
                {
                    umap.erase(del);
                }
                start++;
            }
            maxtotal = std::max( maxtotal ,end - start + 1);
        }
        return maxtotal;
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
        std::cout << "[   "  ;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << "'" << *iter << "', ";//<<std::endl;
        }
        std::cout <<"\b\b  ]" <<  std::endl;
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
};

// ==================== TEST Codes====================
template <typename T>
void Test(const std::string& testName, 
        std::vector<T> &nums,
        int expected
        )
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printvector(nums);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    // getpermutataion
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.totalFruit(nums);
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
    }
}
void Test1()
{
    std::vector<int> tree = {1, 2, 1};
    int expect = 3;
    Test("Test1", tree, expect);
}
void Test2()
{
    std::vector<int> tree = {0, 1, 1, 2};
    int expect = 3;
    Test("Test2", tree, expect);
}

void Test3()
{
    std::vector<int> tree = {1, 2, 3, 2, 2};
    int expect = 4;
    Test("Test3", tree, expect);
}

void Test4()
{
    std::vector<char> fruit = {'A', 'B', 'C', 'A', 'C'};
    int expect = 3;
    Test("Test4", fruit, expect);
}

void Test5()
{
    std::vector<char> fruit = {'A', 'B', 'C', 'B', 'B', 'C'};
    int expect = 5;
    Test("Test5", fruit, expect);
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
