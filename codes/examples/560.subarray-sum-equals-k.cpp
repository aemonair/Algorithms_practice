/*
 *************************************************************************************************
 * 560. Subarray Sum Equals K
 * Medium
 *************************************************************************************************
 * Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
 *************************************************************************************************
 * Example 1:
 *
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 *************************************************************************************************
 * Example 2:
 *
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 *************************************************************************************************
 * Constraints:
 *
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 *************************************************************************************************
 *
 */
// 44 yy
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
template <typename T1, typename T2>
std::ostream & operator << (std::ostream &out, std::unordered_map<T1,T2> &v);

class Solution {
public:
    int subarraySum0(std::vector<int>& nums, int k)
    {
        int size = nums.size() ;
        std::vector<int> preSum(size+1);
        preSum[0] = 0;
        for(int i=0; i < size; i++)
        {
            preSum[i+1] = preSum[i] + nums[i];
        }
        int ans = 0;
        for (int i = 1; i <=size; i++)
        {
            for(int j=0; j < i; j++)
            {
                if(preSum[i] - preSum[j] == k)
                {
                    ans ++;
                }
            }
        }
        return ans;
    }
    int subarraySum(std::vector<int>& nums, int k)
    {
        int count = 0;
        for (int i=0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j =i; j >= 0; --j) {
                std::cout << "sum:" << sum << " + nums[" << j << "]:" << nums[j] << " " << sum + nums[j] << " ";
                sum += nums[j];
                if (sum ==k) {
                    count++;
                }
            }
            std::cout << std::endl;;
        }
        return count;
    }
    int subarraySum1(std::vector<int>& nums, int k)
    {
        int size = nums.size();
        std::vector<int> pre(size+1, 0);
        for (int i=0; i< size; i++) {
            pre[i+1] = pre[i] + nums[i];
        }
        std::cout << pre << std::endl;
        int ans = 0;
        std::unordered_map<int, int> cnt;
        for (int sj : pre) {
            // 注意不要直接 += cnt[sj-k]，如果 sj-k 不存在，会插入 sj-k
            ans += cnt.count(sj - k) ? cnt[sj - k] : 0;
            cnt[sj]++;
            std::cout << std::boolalpha << sj -k << " ";// << cnt.count(sj - k) << " ";
            std::cout << std::boolalpha << cnt.count(sj - k) << " ";
            std::cout << sj << " " <<cnt << std::endl;
        }
        return ans;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int>& nums,
        int k,
        int expected
        )
{
    if(testName.length() > 0) {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "find " << k << " in nums:" << nums << std::endl;

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(k) result = solution.subarraySum(nums, k);
        std::cout << "solution result:" << result << std::endl;

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
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

        decltype(k) result = solution.subarraySum1(nums, k);
        std::cout << "solution result:" << result << std::endl;

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
template <typename T1, typename T2>
std::ostream & operator << (std::ostream &out, std::unordered_map<T1,T2> &v)
{
    // out << "unordered_map size: " << v.size() << std::endl;
    for (auto iter = v.begin(); iter != v.end(); iter++ )
    {
        out << "(" << iter->first << "," << iter->second<< "), ";//<<std::endl;
    }
    out << std::endl;
    return out ;
}

void Test1()
{
    std::vector<int> nums   = {1,1,1};
    int k = 2;
    int expect = 2;
    Test("Test1", nums, k, expect);
}
void Test2()
{
    std::vector<int> nums   = {1,2,3};
    int k = 3;
    int expect = 2;
    Test("Test2", nums, k, expect);
}

void Test3()
{
    std::vector<int> nums   = {1,1,-1,1,-1};
    int k = 1;
    int expect = 6;
    Test("Test3", nums, k, expect);
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
