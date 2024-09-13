/*
 *********************************************
 * 78. Subsets
 * Medium
 *********************************************
 * Given a set of distinct integers, nums, return all possible subsets (the power set). @20201210
 *
 * Given an integer array nums of unique elements, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in any order.
 *********************************************
 * Example1:
 *
 * Input: nums = [1,2,3]
 * Output:  [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 ******************************************
 *  Example 2:
 *
 * Input: nums = [0]
 * Output: [[],[0]]
 ******************************************
 * Note:
 * The solution set must not contain duplicate subsets.
 ******************************************
 * Constraints:
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 *  All the numbers of nums are unique.
 ******************************************
 *
 */

#include <stack>
#include <queue>
#include <chrono>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

class Solution {
public:
////////////////////////////////////////////////////////////////////////
    std::vector<std::vector<int>> subsets0(std::vector<int> nums)
    {
        std::vector<std::vector<int>> results = {{}};
        // []
        // [] [1]
        // [] [1] [2] [12]
        for (int i = 0; i < nums.size(); ++i) {
            int size = results.size();
            for (int j =0; j < size; ++j)
            {
                std::vector<int> temp(results[j]);
                temp.push_back(nums[i]);
                results.push_back(temp);
            }
        }
        return results;
    }
////////////////////////////////////////////////////////////////////////
    std::vector<std::vector<int>> subsets1(std::vector<int>& nums_)
    {
        std::vector<int> nums(nums_);
        if (nums.empty()){
            return {{}};
        }
        auto x = nums.back();
        nums.pop_back();
        auto result = subsets1(nums);
        int size = result.size();
        for (int i =0; i< size; ++i) {
            auto temp(result[i]);
            temp.push_back(x);
            result.push_back(temp);
        }
        return result;
    }
    /*
    {
        if (nums.empty()){
            return {{}};
        }
        auto x = nums.front();
        nums.erase(nums.begin());
        auto result = subsets1(nums);
        int size = result.size();
        for (int i =0; i< size; ++i) {
            auto temp(result[i]);
            temp.push_back(x);
            result.push_back(temp);
        }
        return result;
        return {};
    }
    */

////////////////////////////////////////////////////////////////////////
    std::vector<std::vector<int>> subsets2(std::vector<int>& nums)
    {
        std::vector<int> path;
        int n = nums.size();
        std::vector<std::vector<int>> ans;
        auto dfs = [&](auto &&dfs, int i) -> void {
            if (i == n) {
                ans.push_back(path);
                return;
            }
            dfs(dfs,i+1); // path不选

            path.push_back(nums[i]);
            dfs(dfs,i+1); // path中选当前
            path.pop_back(); // 恢复现场
        };
        dfs(dfs, 0);
        return ans;
    }
////////////////////////////////////////////////////////////////////////
    std::vector<int> path;
    std::vector<std::vector<int>> result;
    void backtracking(std::vector<int> &nums, int index)
    {
        result.push_back(path);
        if (index > nums.size()) {return;}
        for (int i =index; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
    std::vector<std::vector<int>> subsets3(std::vector<int>& nums)
    {
        path.clear();
        result.clear();
        backtracking(nums, 0);
        return result;
    }
    void dfs(std::vector<int> &nums, int index)
    {
        result.push_back(path);
        for (int i = index; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
    }
    std::vector<std::vector<int>> subsets4(std::vector<int>& nums)
    {
        result.clear();
        path.clear();
        dfs(nums, 0);
        return result;
    }
    std::vector<std::vector<int>> subsets5(std::vector<int>& nums)
    {
        int mask = 0;
        int n = nums.size();
        std::vector<std::vector<int>> res;
        for (int i=0; i< (1<<n); ++i) {
            std::vector<int> curr;
            for (int j = 0; j < n; ++j) {
                if ((1<<j) & i ) {
                    curr.push_back(nums[j]);
                }
            }
            res.push_back(curr);
        }
        return res;
    }
////////////////////////////////////////////////////////////////////////
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int>& numbers,
        std::vector<std::vector<int>> expected
        )
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "numbers:" << numbers << std::endl;
    sort(expected.begin(), expected.end());

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
const static int TEST_2    = 1;
const static int TEST_3    = 1;
const static int TEST_4    = 1;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) result = solution.subsets0(numbers);
        std::cout << "solution0 result:" << result << std::endl;

        std::cout << "expect numbers:" << std::endl;
        sort(result.begin(), result.end());
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
    if (TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) result = solution.subsets1(numbers);
        std::cout << "solution1 result:" << result << std::endl;

        std::cout << "expect numbers:" << std::endl;
        sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if (TEST_2)
    {
        std::cout << "Solution2 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) result = solution.subsets2(numbers);
        std::cout << "solution2 result:" << result << std::endl;

        std::cout << "expect numbers:" << std::endl;
        sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution2 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution2 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution2 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if (TEST_3)
    {
        std::cout << "Solution3 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) result = solution.subsets3(numbers);
        std::cout << "solution result:" << result << std::endl;

        std::cout << "expect numbers:" << std::endl;
        sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution3 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution3 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution3 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if (TEST_4)
    {
        std::cout << "Solution4 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) result = solution.subsets4(numbers);
        std::cout << "solution result:" << result << std::endl;

        std::cout << "expect numbers:" << std::endl;
        sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution4 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution4 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution4 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
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
void Test1()
{
    std::vector<int> numbers   = {1,2,3};
    std::vector<std::vector<int>> expect = {{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}};
    Test("Test1", numbers, expect);
}
void Test2()
{
    std::vector<int> numbers   = {0};
    std::vector<std::vector<int>> expect = {{},{0}};
    Test("Test2", numbers, expect);
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
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
