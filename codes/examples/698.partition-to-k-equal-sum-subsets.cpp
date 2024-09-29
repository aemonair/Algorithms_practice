/*
 ******************************************************************************
 *  698. Partition to K Equal Sum Subsets
 * Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
 ******************************************************************************
 * Example 1:
 *
 * Input: nums = [4,3,2,3,5,2,1], k = 4
 * Output: true
 * Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 ******************************************************************************
 * Example 2:
 *
 * Input: nums = [1,2,3,4], k = 3
 * Output: false
 ******************************************************************************
 * Constraints:
 *
 * 1 <= k <= nums.length <= 16
 * 1 <= nums[i] <= 104
 * The frequency of each element is in the range [1, 4].
 ******************************************************************************
 */

// 44 yy
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define     RESET   "\033[0m"
#define     RED     "\033[31m"             /*      Red     */
#define     CYAN    "\033[36m"             /*      Cyan    */
#define     BLUE    "\033[34m"             /*      Blue    */
#define     GREEN   "\033[32m"             /*      Green   */
#define     WHITE   "\033[37m"             /*      White   */
#define     BLACK   "\033[30m"             /*      Black   */
#define     YELLOW  "\033[33m"             /*      Yellow  */
#define     MAGENTA "\033[35m"             /*      Magenta */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow  */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black   */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White   */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green   */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue    */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan    */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red     */

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

class Solution {
public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k) {
        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        int size = nums.size();
        std::vector<bool> used(size, false);
        std::vector<int> path;
        sort(nums.begin(), nums.end());
        //sort(nums.begin(), nums.end(), std::greater<int>());

        // 递归函数
        //std::function<bool(int, int, int)> dfs = [&](int start, int currentSum, int count) {
        auto dfs = [&](auto &&dfs, int start, int currentSum, int count) {
            if (count == k) {
                return true;  // 已经找到了 k 个子集
            }
            if (currentSum == target) {
                // 找到一个子集，继续找下一个
                return dfs(dfs, 0, 0, count + 1);
            }
            for (int i = start; i < size; ++i) {
                if (used[i]) {
                    continue;
                }
                if (currentSum + nums[i] > target) {
                    continue;
                }
                if (i>0 && nums[i] == nums[i-1] && !used[i-1]) {
                    continue;
                }
                // 选择当前元素
                used[i] = true;
                path.push_back(nums[i]);

                if (dfs(dfs, i + 1, currentSum + nums[i], count)) {
                    return true;
                }
                // 回溯
                used[i] = false;
                path.pop_back();
            }
            return false;
        };
        return dfs(dfs, 0, 0, 0);
    }

    bool backtrack(std::vector<int> nums, int index, std::vector<int> bucket, int k, int target) {
        // 结束条件：已经处理完所有球
        if (index == nums.size()) {
            // 判断现在桶中的球是否符合要求 -> 路径是否满足要求
            for (int i = 0; i < k; i++) {
                if (bucket[i] != target) return false;
            }
            return true;
        }
        // nums[index] 开始做选择
        for (int i = 0; i < k; i++) {
                if (i > 0 && bucket[i] == bucket[i - 1]) continue;
            // 剪枝：放入球后超过 target 的值，选择一下桶
            if (bucket[i] + nums[index] > target) continue;

            // 做选择：放入 i 号桶
            bucket[i] += nums[index];

            // 处理下一个球，即 nums[index + 1]
            if (backtrack(nums, index + 1, bucket, k, target)) return true;

            // 撤销选择：挪出 i 号桶
            bucket[i] -= nums[index];
        }

        // k 个桶都不满足要求
        return false;
    }
     bool canPartitionKSubsets1(std::vector<int>& nums, int k) {
        // 求总和
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        // 不能刚好分配的情况
        if (sum % k != 0) return false;
        // target 即每个子集所需要满足的和
        int target = sum / k;
        std::vector<int> bucket (k + 1, 0);
        return backtrack(nums, 0, bucket, k, target);
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int> &nums,
        int k,
        bool expected
        )
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "nums: " << nums << " k:" << k << std::endl;

const static int TEST_TIME = 1;
const static int TEST__    = 1;
const static int TEST_1    = 1;
    if (TEST__)
    {
        std::cout << "Solution start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.canPartitionKSubsets(nums, k);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if (TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.canPartitionKSubsets1(nums, k);
        std::cout << "result:" << result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
}
void Test1()
{
    std::vector<int> nums = {4,3,2,3,5,2,1};
    int k= 4;
    bool expected = true;
    Test("Test1", nums, k, expected);
}
void Test2()
{
    std::vector<int> nums = {1,2,3,4};
    int k = 3;
    bool expect = false;
    Test("Test2", nums, k, expect);
}

void Test3()
{
    std::vector<int> nums = {2,2,2,2,3,4,5};
    int k = 4;
    bool expect = false;
    Test("Test3", nums, k, expect);
}

void Test4()
{
    std::vector<int> nums = {3,2,1,3,6,1,4,8,10,8,9,1,7,9,8,1};
    int k = 9;
    bool expect = false;
    Test("Test4", nums, k, expect);
}

void Test5()
{
    std::vector<int> nums = {1,1,1,1,2,2,2,2};
    int k = 2;
    bool expect = true;
    Test("Test4", nums, k, expect);
}

void Test6()
{
    std::vector<int> nums = {10,1,10,9,6,1,9,5,9,10,7,8,5,2,10,8};
    int k = 11;
    bool expect = false;
    Test("Test4", nums, k, expect);
}

void Test7()
{
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

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
