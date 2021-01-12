/*
 ****************************************************************************** 
 ****************************************************************************** 
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
    int minSubArrayLen(int s, std::vector<int> nums)
    {
        int left = 0;
        int right = 0;
        int size = nums.size();
        int result = std::numeric_limits<int>::max();
        //int result = INT_MAX;
        int sum = 0;
        for (int i=0; i < size; i++)
        {
            sum += nums[i];
            while(sum >= s)
            {
                std::cout << "i:" << i << " , sum:" << sum << " , "; //<< std::endl;
                if( i - left + 1 <= result)
                {
                    result = std::min(result, i-left+1);
                }
                std::cout << "left:" << left << " , ";
                sum -= nums[left];
                left++;
                std::cout << "result:" << result << std::endl;
            }
        }
        return result == INT_MAX ? 0: result;
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
        int s, std::vector<int> &nums,
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
    std::cout << "s:" << s << std::endl;

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

        decltype(expected) result = solution.minSubArrayLen(s, nums);
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
    int s      = 7 ;
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};
    int expect = 2;
    Test("Test1", s, nums, expect);
}
void Test2()
{
    int s      = 7 ;
    std::vector<int> nums = {2, 1, 5, 2, 8};
    int expect = 1;
    Test("Test1", s, nums, expect);
}

void Test3()
{
    int s      = 8 ;
    std::vector<int> nums = {3, 4, 1, 1, 6};
    int expect = 3;
    Test("Test1", s, nums, expect);
}

void Test4()
{
    int s      = 7 ;
    std::vector<int> nums = {2, 1, 5, 2, 3, 2};
    int expect = 2;
    Test("Test1", s, nums, expect);
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
