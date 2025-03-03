/*
 * 268. Missing Number
 * Easy
 * Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
 ******************************************************************
 * Example 1:
 *
 * Input: nums = [3,0,1]
 * Output: 2
 * Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
 ******************************************************************
 * Example 2:
 *
 * Input: nums = [0,1]
 * Output: 2
 * Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
 ******************************************************************
 * Example 3:
 *
 * Input: nums = [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
 ******************************************************************
 * Constraints:
 *
 * n == nums.length
 * 1 <= n <= 104
 * 0 <= nums[i] <= n
 * All the numbers of nums are unique.
 ******************************************************************
 * Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
*/
// 44 yy
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <climits>
#include <chrono>
#include <vector>
#include <string>
#include <thread>
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

template<typename T>
int printvector(std::vector<T> v);

template <typename T>
int printstack(std::stack<T> s);

template <typename T1, typename T2>
int printunordered_map(const std::unordered_map<T1,T2> &v);

class Solution {
public:
    // CyclicSort
    int missingNumber(std::vector<int>& nums)
    {
        int i = 0;
        auto swap = [&](int i, int j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        };
        for (i=0; i < nums.size(); ++i) {
            // i = 0; do while and swap until nums[0] == 0;
            while (nums[i] < nums.size() && nums[i] != nums[nums[i]]) {
                swap(i, nums[i]);
            }
        }
        std::cout << nums << std::endl;
        for (int i =0; i < nums.size(); i++) {
            if (i != nums[i]) {
                return i;
            }
        }
        return nums.size();
    }
    int missingNumber0(std::vector<int>& nums)
    {
        auto swap = [&](int i,int j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        };
        int i = 0;
        while (i < nums.size()) {
            if (i == nums[i] || nums[i] >= nums.size()){
                ++i;
            } else {
                swap(i, nums[i]);
            }
            std::cout << nums << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        for (i = 0; i < nums.size(); ++i) {
            if (i != nums[i]) {
                return i;
            }
        }
        return nums.size();
    }
    int missingNumber1(std::vector<int> &nums )
    {
        std::cout << nums << std::endl;
        int n = nums.size();
        int res = 0;
        res ^= n;
        std::cout <<  0 << "^" << n << " res:" << res << std::endl;
        for (int i =0;i < n; i++)
        {
            res ^= i ^ nums[i];
            std::cout <<  i << "^" << nums[i] << "^res:" << res << std::endl;
        }
        return res;
    }
    int missingNumber2(std::vector<int> &nums )
    {
        std::cout << nums << std::endl;
        int n = nums.size();
        int expect = (0+n)*(n+1)/2;
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        std::cout << "expect" << expect << "sum:" << sum << std::endl;
        return expect-sum;
    }
    int missingNumber3(std::vector<int> &nums )
    {
        std::cout << nums << std::endl;
        int n = nums.size();
        int res = 0;
        res += n;
        for (int i =0; i< n; i++) {
            res += i - nums[i];
            std::cout << "+" << i << " -" << nums[i] << " res:" << res << std::endl;
        }
        return res;
    }
};
// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int> & nums,
        int expected)
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "nums:" <<  std::endl;
    printvector(nums);
const static int TEST_TIME = 1;
const static int TEST_0    = 0;
const static int TEST_1    = 1;
const static int TEST_2    = 1;
const static int TEST_3    = 1;
    if (TEST_0) {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        int result = solution.missingNumber(nums);
        std::cout << "result:" << std::boolalpha << result << std::endl;

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
    if (TEST_1) {
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        int result = solution.missingNumber1(nums);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            //10yy
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
    if (TEST_2) {
        std::cout << "Solution2 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        int result = solution.missingNumber2(nums);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution2 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution2 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution2 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if (TEST_3) {
        std::cout << "Solution3 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        int result = solution.missingNumber3(nums);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution3 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution3 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution3 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
}
// 76 yy
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
template<typename T>
int printvector(std::vector<T> v)
{
    if(0 == v.size())
    {
        std::cout << "Empty vector." << std::endl;
        return 0;
    }
    std::cout << "[ " ;
    for(auto i: v)
    {
        std::cout << i << ", ";
    }
    std::cout << "\b\b ]" << std::endl;
    return v.size();
}
template<typename T>
int printstack (std::stack <T> s)
{
    if(s.empty())
    {
        std::cout << "Empty stack ." << std::endl;
        return 0;
    }
    std::cout <<  "The stack size is: " << s.size() << std::endl;
    std::cout << "[ " ;
    while (!s.empty())
    {
        std::cout << s.top() << ", ";
        s.pop();
    }
    std::cout << "\b\b ]" << std::endl;
    return s.size();
}
template<typename T>
int printvector(std::stack <T> s)
{
    if(s.empty())
    {
        std::cout << "Empty stack ." << std::endl;
        return 0;
    }
    std::cout <<  "The stack size is: " << s.size() << std::endl;
    std::cout << "[ " ;
    while (!s.empty())
    {
        std::cout << s.top() << ", ";
        s.pop();
    }
    std::cout << "\b\b ]" << std::endl;
    return s.size();
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

void Test1()
{
    std::vector<int> nums = {3,0,1};
    int result = 2;
    Test("Test1", nums, result);
}

void Test2()
{
    std::vector<int> nums = {0,1};
    int result = 2;
    Test("Test2", nums, result);
}

void Test3()
{
    std::vector<int> nums = {9,6,4,2,3,5,7,0,1};
    int result = 8;
    Test("Test3", nums, result);
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
