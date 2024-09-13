/*
 *********************************************
 *  47. Permutations II
 * Medium
 *********************************************
 * Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
 *********************************************
 * Example 1:
 *
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 *  [1,2,1],
 *  [2,1,1]]
 *********************************************
 * Example 2:
 *
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *********************************************
 * Constraints:
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 *********************************************
 *
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

template<typename T>
std::ostream & operator << (std::ostream &out, const std::queue <T> &_queue);

template<typename T>
std::ostream & operator << (std::ostream &out, const std::vector<T> &_vec);

class Solution {
public:
    //
    ////////////////////////////////////////////////////////////////////////////////
    void dfs(std::vector<int> &nums, std::vector<bool> &used) {
        int size = nums.size();
        if (path.size() == size) {
            res.push_back(path);
        }
        for (int i = 0; i < size; ++i) {
            if (i > 0 && nums[i] == nums[i-1] && used[i-1] ) {
                continue;
            }
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i]=true;
                dfs(nums, used);
                path.pop_back();
                used[i]=false;
            }
        }
    }
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    std::vector<std::vector<int>> permuteUnique (std::vector<int>& nums)
    {
        path.clear();
        res.clear();
        sort(nums.begin(), nums.end());
        std::vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;
    }
    ////////////////////////////////////////////////////////////////////////////////
    std::vector<std::vector<int>> permuteUnique1(std::vector<int>& nums)
    {
        path.clear();
        int size = nums.size();
        std::vector<std::vector<int>> ans;
        std::vector<bool> used(size, false);
        sort(nums.begin(), nums.end());
        auto dfs = [&](auto &&dfs) {
            //std::cout << path << std::endl;
            if (path.size() == size) {
                ans.push_back(path);
                return;
            }
            for (int i = 0; i < size; ++i) {
                if (used[i]) {
                    continue;
                }
                if (i> 0 && nums[i]==nums[i-1] && used[i-1]) {
                    continue;
                }
                path.push_back(nums[i]);
                used[i] = true;
                dfs(dfs);
                used[i] = false;
                path.pop_back();
            }
        };
        dfs(dfs);
        return ans;
    }
    ////////////////////////////////////////////////////////////////////////////////
    std::vector<std::vector<int>> permuteUnique2(std::vector<int>& nums)
    {
        return {};
    }
    ////////////////////////////////////////////////////////////////////////////////
    std::vector<std::vector<int>> permuteUnique3(std::vector<int>& nums)
    {
        return {};
    }
    ////////////////////////////////////////////////////////////////////////////////
    int getpermutataion(std::vector<int> nums, std::vector<std::vector<int>> & permutation)
    {
        std::sort(nums.begin(), nums.end());
        permutation.clear();
        do
        {
            permutation.push_back(std::vector<int>{nums});
        } while ( std::next_permutation(nums.begin(), nums.end() ));
        return permutation.size();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int>  nums ,
        std::vector<std::vector<int>> expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << " nums: "<< std::endl;
    std::vector<std::vector<int>> permutation;
    solution.getpermutataion(nums, permutation);
    std::cout << permutation << std::endl;

const static int TEST_TIME = 1;
const static int TEST__    = 0;
const static int TEST_1    = 1;
const static int TEST_2    = 0;
const static int TEST_3    = 0;
    if (TEST__)
    {
        std::cout << "Solution start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::vector<std::vector<int>> &&result = solution.permuteUnique (nums);
        std::cout << "result:" << result << std::endl;

        std::sort(result.begin(), result.end());
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

        std::vector<std::vector<int>> &&result = solution.permuteUnique1(nums);
        std::cout << "result:" << result << std::endl;
        std::sort(result.begin(), result.end());

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

        std::vector<std::vector<int>> &&result = solution.permuteUnique2(nums);
        std::cout << "result:" << result << std::endl;
        std::sort(result.begin(), result.end());

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

        std::vector<std::vector<int>> &&result = solution.permuteUnique3(nums);
        std::cout << "result:" << result << std::endl;
        std::sort(result.begin(), result.end());

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
std::ostream & operator << (std::ostream &out, const std::queue <T> &_queue)
{
    auto Q(_queue);
    out << "queue :[  ";
    while (!Q.empty()) {
        out << Q.front() << ", ";
        Q.pop();
    }
    out << "\b\b ]" ;
    return out;
}
template<typename T>
std::ostream & operator << (std::ostream &out, const std::vector<T> &_vec)
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
    Test("Test1", std::vector<int> {1,1,2},
        {{1,1,2},{1,2,1},{2,1,1}}
    );
}
void Test2()
{
    Test("Test2", std::vector<int> {3}, {{3}});
}

void Test3()
{
    Test("Test3", std::vector<int> {1,2,3},
            {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}}
            );
}



int main()
{
    Test1();
    Test2();
    Test3();

    return 0;

}
