/*
 *********************************************
 * 46. Permutations
 * Medium
 *********************************************
 * Given a collection of distinct integers, return all possible permutations.@20201210
 * Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 *********************************************
 * Example 1:
 *
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 *********************************************
 * Example 2:
 *
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 *********************************************
 * Example 3:
 *
 * Input: nums = [1]
 * Output: [[1]]
 *********************************************
 * Constraints:
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
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
    std::vector<std::vector<int>> permute (std::vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        do{res.push_back(nums);} while(std::next_permutation(nums.begin(), nums.end()));
        return res;
    }
    ////////////////////////////////////////////////////////////////////////////////
    std::vector<int> path;
    std::vector<std::vector<int>> res;
    void dfs(std::vector<int>& nums, std::vector<bool> &used)
    {
        int size = nums.size();
        if (path.size() == size) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < size; ++i) {
            if (used[i]) {
                continue;
            }
            path.push_back(nums[i]);
            used[i]=true;
            dfs(nums, used);
            path.pop_back();
            used[i]=false;
        }
    }
    std::vector<std::vector<int>> permute1(std::vector<int>& nums)
    {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        std::vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;
    }
    std::vector<std::vector<int>> permute2(std::vector<int>& nums)
    {
        int size = nums.size();
        std::vector<int> path(size, 0);
        std::vector<bool> used(size, false);
        std::vector<std::vector<int>> ans;
        sort(nums.begin(), nums.end());
        auto dfs = [&](auto &&dfs, int i){
            if (i == size) {
                ans.push_back(path);
                return;
            }
            for (int j = 0; j < size; ++j) {
                if (!used[j]) {
                    path[i] = nums[j];
                    used[j]= true;
                    dfs(dfs, i+1);
                    used[j]= false;
                }
            }
        };
        dfs(dfs, 0);
        return ans;
    }
    std::vector<std::vector<int>> permute3(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> result;
        std::queue<std::vector<int>> queue;
        queue.push({});
        // 第一个 for 遍历nums;
        for (int i = 0; i < nums.size(); ++i) {
            int queuesize = queue.size();
            // 第二个 for 遍历queue;
            for (int k = 0; k < queuesize; ++k) {
                auto oldpermupution = queue.front();
                //std::cout << oldpermupution << std::endl;
                queue.pop();
                int size = oldpermupution.size();
                // 第三个for遍历当前vector可插入的位置
                for (int j = 0; j <= size; ++j) {
                    auto temp(oldpermupution);
                    temp.insert(temp.begin()+j, nums[i]);
                    //std::cout << temp << std::endl;
                    if (temp.size() == nums.size()) {
                        result.push_back(temp);
                    } else {
                        queue.push(temp);
                    }
                }
            }
        }
        return result;
    }
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
    //std::cout << " expected by getpermutataion: " << expected << std::endl;
    solution.getpermutataion(nums, expected);

const static int TEST_TIME = 1;
const static int TEST__    = 1;
const static int TEST_1    = 1;
const static int TEST_2    = 1;
const static int TEST_3    = 1;
    if (TEST__)
    {
        std::cout << "Solution start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::vector<std::vector<int>> &&result = solution.permute (nums);
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

        std::vector<std::vector<int>> &&result = solution.permute1(nums);
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

        std::vector<std::vector<int>> &&result = solution.permute2(nums);
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

        std::vector<std::vector<int>> &&result = solution.permute3(nums);
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
void Test1()
{
    Test("Test1", std::vector<int> {1,2,5},{{}});
}
void Test2()
{
    Test("Test2", std::vector<int> {3}, {{}});
}

void Test3()
{
    Test("Test3", std::vector<int> {186,419,83,408},{{}});
}

void Test4()
{
    Test("Test4", std::vector<int> {1,2,3,4},{{}});
}



int main()
{
    Test1();
    Test2();
    //Test3();
    Test4();

    return 0;

}
