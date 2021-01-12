/*
 ****************************************************************************** 
 * 1004. Max Consecutive Ones III
 * Medium
 ****************************************************************************** 
 * Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
 * Return the length of the longest (contiguous) subarray that contains only 1s. 
 ****************************************************************************** 
 * Example 1:
 * 
 * Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
 * Output: 6
 * Explanation: 
 * [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
 ****************************************************************************** 
 * Example 2:
 * 
 * Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
 * Output: 10
 * Explanation: 
 * [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
 ****************************************************************************** 
 * Note:
 * 
 * 1 <= A.length <= 20000
 * 0 <= K <= A.length
 * A[i] is 0 or 1
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
    int longestOnes(std::vector<int> &A, int K)
    {
        int longest = 0;
        int max_one = 0;
        int size = A.size();
        for (int end = 0, start = 0; end < size; end++)
        {
            int i = A[end];
            if (i == 1)
            {
                max_one ++;
            }
            if (end - start - max_one >= K)
            {
                if (A[start] == 1)
                {
                    max_one --;
                }
                start ++;
            }
            longest = std::max(longest, end - start + 1);
            //std::cout << "max_one:" << max_one << ",start:" << start << ",end:" << end << ";longest:"<< longest << std::endl;
        }
        return longest;
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
void Test(const std::string& testName, 
        std::vector<int> &A, int K,
        int expected
        )
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "K: " << K << ";"; //<< std::endl;
    solution.printvector(A);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.longestOnes(A, K);
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
    std::vector<int> A= {1,1,1,0,0,0,1,1,1,1,0};
    int K = 2;
    int expect = 6;
    Test("Test1", A, K, expect);
}
void Test2()
{
    std::vector<int> A= {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int K = 3;
    int expect = 10;
    Test("Test2", A, K, expect);
}

void Test3()
{
    std::vector<int> A= {0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1};
    int K = 2;
    int expect = 6;
    Test("Test3", A, K, expect);
}

void Test4()
{
    std::vector<int> A= {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1};
    int K = 3;
    int expect = 9;
    Test("Test4", A, K, expect);
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
