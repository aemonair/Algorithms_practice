/*
 * 354. Russian Doll Envelopes
 * Hard
 ******************************************************************* 
 * You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
 * One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
 * 
 * What is the maximum number of envelopes can you Russian doll? (put one inside other)
 ******************************************************************* 
 * Note:
 * Rotation is not allowed.
 ******************************************************************* 
 * Example:
 * 
 * Input: [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3
 * Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
 ******************************************************************* 
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
 
class Compare_vector
{
public:
    bool operator () (const std::vector<int> env1, const std::vector<int> env2)
    {
        return env1[0] == env2[0] ?
                env1[1] > env2[1] : env1[0] <env2[0];
    }
};
class Solution {
public:
    //////////////////////////////////////////////////////////////
    static bool compare(const std::vector<int> env1, const std::vector<int> env2)
    {
#if 0
        return env1[0] == env2[0] ?
                env1[1] > env2[1] : env1[0] <env2[0];
#else
        if (env1[0] == env2[0])
        {
            return env1[1] > env2[1];
        }
        else
        {
            return env1[0] < env2[0];
        }
#endif
    }
    int maxEnvelopes(std::vector<std::vector<int>> &envelopes)
    {
        std::sort(envelopes.begin(), envelopes.end(), Compare_vector());
        //std::sort(envelopes.begin(), envelopes.end(), Solution::compare);
        printvectorvector(envelopes);

        std::vector<int> nums(envelopes.size());
        for(int i=0; i< envelopes.size(); i++)
        {
            nums[i] = envelopes[i][1];
        }

        return lengthOfLIS0(nums);
        return 0;
    }

    int lengthOfLIS0(std::vector<int>& nums) 
    {
        int size = nums.size();
        std::vector<int> dp(size, 1);

        dp[0] =1;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = std::max(dp[i], dp[j]+1);
                }
            }
            // error: 
            // dp[i] = nums[i-1] < nums[i] ? dp[i-1] + 1 : dp[i-1];
        }
        printvector(dp);

        int result = 0;
        for (auto it : dp)
        {
            result = std::max(it, result);
        }
        
        return result;
    }
    //////////////////////////////////////////////////////////////
    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        //std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "(" ;//<< std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";//<<std::endl;
        }
        std::cout << "\b\b)" << std::endl;
        //std::cout << std::endl;
        return v.size();
    }
    template <typename T1, typename T2>
    int printvector(const std::pair<T1,T2> &v)
    {
        std::cout << "(" << v.first <<","<< v.second << ") ";//<<std::endl;
        return 0;
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
    template <typename T>
    int printvvvector(const std::vector<T> &v)
    {
        std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvectorvector( *iter );
        }
        std::cout << std::endl;
        return v.size();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName, 
        std::vector<std::vector<int>> &envelopes,
        int expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printvectorvector(envelopes);
    // getpermutataion
const static int TEST_TIME = 0;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        int result = solution.maxEnvelopes(envelopes);
        std::cout << "result:" << std::boolalpha << result << std::endl;

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
}

void Test1()
{
    std::vector<std::vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    int result = 3;
    Test("Test1", envelopes , result);
}

void Test2()
{
    std::vector<std::vector<int>> envelopes = {{1,8},{5,4},{6,7},{2,3},{5,2},{6,4}};
    int result = 3;
    Test("Test1", envelopes , result);
}

void Test3()
{
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
