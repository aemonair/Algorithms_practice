/*
 *********************************************
 * 90. Subsets II
 * Medium
 *********************************************
 * Given a collection of integers that might contain duplicates, nums,
 * return all possible subsets (the power set). @20200410
 *
 * Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in any order. @20210412
 *********************************************
 * Example 1:
 *
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * [
 *  [2],
 *  [1],
 *  [1,2,2],
 *  [2,2],
 *  [1,2],
 *  []
 * ]
 *********************************************
 * Example 2:
 *
 * Input: nums = [0]
 * Output: [[],[0]]
 *********************************************
 * Constraints:
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 *********************************************
 * Note:
 * The solution set must not contain duplicate subsets. // @20200410
 ******************************************
 *
 */

#include <set>
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
    std::vector<std::vector<int>> subsetsWithDup (std::vector<int>& nums)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result ={{}};
        int end = 0;
        int start = 0;
        for (int i = 0; i< size; ++i) {
            int n = result.size();
            start = 0;
            if (i >= 1 && nums[i] == nums[i-1]) {
                start = end;
            }
            end = n;
            for (int j = start; j < n; ++j) {
                auto temp(result[j]);
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }
        return result;
    }
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    void backtracking(std::vector<int>& nums, int startIndex, std::vector<bool>& used) {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 而我们要对同一树层使用过的元素进行跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> subsetsWithDup1(std::vector<int>& nums) {
        result.clear();
        path.clear();
        std::vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end()); // 去重需要排序
        dfs(nums, path, 0, used);
        //backtracking(nums, 0, used);
        return result;
    }
    void dfs(std::vector<int> &nums, std::vector<int> &curr, int index , std::vector<bool> &used)
    {
        result.push_back(curr);
        int size = nums.size();
        std::cout << "curr:" << curr << "used:" << used << std::endl;
        for (int i = index; i < size; ++i) {
            if (i>0 && nums[i] == nums[i-1] && used[i-1] == false) {
                std::cout << " " <<  nums[i] << "==" <<  nums[i-1] << "used:" << used[i-1] << std::endl;
                continue;
            }
            curr.push_back(nums[i]);
            used[i] = true;
            dfs(nums, curr, i+1, used);
            used[i] = false;
            curr.pop_back();
        }
    }
    void backtracking(std::vector<int> &nums, int index)
    {
        result.push_back(path);
        for (int i = index; i < nums.size(); ++i) {
            if (i>index &&nums[i] == nums[i-1]) {
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
    std::vector<std::vector<int>> subsetsWithDup2(std::vector<int>& nums) {
        path.clear();
        result.clear();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
    void backtrack(std::vector<std::vector<int>>& res, std::vector<int>& path, std::vector<int>& nums, int index) {
        if (index > nums.size()) return;
        res.push_back(path);
        for (int i = index; i < nums.size(); ++i) {
            if (i != index && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backtrack(res, path, nums, i + 1);
            path.pop_back();
        }
    }
    std::vector<std::vector<int>> subsetsWithDup3(std::vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        backtrack(res, path, nums, 0);
        return res;
    }

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
    for (auto &x: expected) {
        std::sort(x.begin(), x.end());
    }
    std::sort(expected.begin(), expected.end());

const static int TEST_TIME = 1;
const static int TEST__    = 1;
const static int TEST_1    = 1;
const static int TEST_2    = 1;
const static int TEST_3    = 1;
    if (TEST__)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) result = solution.subsetsWithDup(numbers);
        std::cout << "solution result:" << result << std::endl;

        std::cout << "expect numbers:" << std::endl;
        std::sort(result.begin(), result.end());
        std::cout << "solution result:" << result << std::endl;
        if(result == expected)
        {
            std::cout << GREEN << "Solution passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if (TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }
        decltype(expected) result = solution.subsetsWithDup1(numbers);
        std::cout << "solution1 result:" << result << std::endl;

        std::cout << "expect numbers:" << std::endl;
        std::sort(result.begin(), result.end());
        std::cout << "solution result:" << result << std::endl;
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
        decltype(expected) result = solution.subsetsWithDup2(numbers);
        std::cout << "solution2 result:" << result << std::endl;

        std::cout << "expect numbers:" << std::endl;
        std::sort(result.begin(), result.end());
        std::cout << "solution result:" << result << std::endl;
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
        decltype(expected) result = solution.subsetsWithDup3(numbers);
        std::cout << "solution3 result:" << result << std::endl;

        std::cout << "expect numbers:" << std::endl;
        std::sort(result.begin(), result.end());
        std::cout << "solution result:" << result << std::endl;
        if(result == expected)
        {
            std::cout << GREEN << "Solution3 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution3 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution3 costs " << elapsed.count() <<"micros" << std::endl;
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
    std::vector<int> numbers   = {1,2,2};
    std::vector<std::vector<int>> expect = {{},{1},{1,2},{1,2,2},{2},{2,2}};
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
    std::vector<int> numbers   = {1, 3, 3};
    std::vector<std::vector<int>> expect = {{}, {1}, {3}, {1,3}, {3,3}, {1,3,3}};
    Test("Test3", numbers, expect);
}

void Test4()
{
    std::vector<int> numbers   = {1, 5, 3, 3};
    std::vector<std::vector<int>> expect = {{}, {1}, {5}, {3}, {1,5}, {1,3}, {5,3}, {1,5,3}, {3,3}, {1,3,3}, {3,3,5}, {1,5,3,3} };
    Test("Test4", numbers, expect);
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
