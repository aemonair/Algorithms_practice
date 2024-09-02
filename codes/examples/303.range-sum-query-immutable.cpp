/*
 ******************************************************************************
 * 303. Range Sum Query - Immutable
 * Easy
 ******************************************************************************
 *
 * Given an integer array nums, handle multiple queries of the following type:
 *
 * Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
 * Implement the NumArray class:
 *
 * NumArray(int[] nums) Initializes the object with the integer array nums.
 * int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 *
 *
 ******************************************************************************
 * Example 1:
 *
 * Input
 * ["NumArray", "sumRange", "sumRange", "sumRange"]
 * [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
 * Output
 * [null, 1, -1, -3]
 *
 * Explanation
 * NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
 * numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
 * numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
 * numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
 *
 ******************************************************************************
 *
 * Constraints:
 *
 * 1 <= nums.length <= 10⁴
 * -10⁵ <= nums[i] <= 10⁵
 * 0 <= left <= right < nums.length
 * At most 10⁴ calls will be made to sumRange.
 *
 ******************************************************************************
 */

#include <unordered_map>
#include <algorithm>
#include <iostream>
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

///////////////////////////////////////////////////////////////////////////////////////////////////////
class NumArray {
public:
    std::vector<int> pre;
    NumArray(std::vector<int>& nums) {
        pre.resize(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); i++) {
            pre[i+1] = pre[i]+nums[i];
        }
    }

    int sumRange(int left, int right) {
        return pre [right+1] - pre [left];
    }
};
class NumArray1{
public:
    std::vector<int> v;
    NumArray1(std::vector<int>& nums) {
        v = nums;
        std::cout << "v:" << v << std::endl;
    }

    int sumRange(int left, int right) {
        return std::accumulate(v.begin()+left,v.begin()+right+1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// ==================== TEST Codes====================
template <typename T>
void Test1(T * numArray, std::vector<int> & arr, std::vector<int> & expected)
{
    numArray = new T(arr);
    std::cout << " numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1 " << std::endl;
    std::vector<int> result;
    result.push_back(numArray->sumRange(0, 2)); // return (-2) + 0 + 3 = 1

    std::cout << " numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1 " << std::endl;
    result.push_back(numArray->sumRange(2, 5)); // return 3 + (-5) + 2 + (-1) = -1

    std::cout << " numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3 " << std::endl;
    result.push_back(numArray->sumRange(0, 5)); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

    std::cout << "result:" << result << std::endl;
    if (result == expected) {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
    } else {
        std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
        std::cout << RED << "expected:" << expected << std::endl;
        std::cout << RESET << std::endl;
    }
    delete numArray;
    numArray = nullptr;
}
template<typename T>
void Test2(T* numArray, std::vector<int> &arr,std::vector<int> & expected)
{
    numArray = new T(arr);
    std::cout << " numArray.sumRange(1, 4); // return (5) + (2) + (-2) + 4 = 9 " << std::endl;
    std::vector<int> result;
    result.push_back(numArray->sumRange(1, 4)); // return (5) + 2 + (-2) + 4 = 9

    std::cout << "result:" << result << std::endl;
    if (result == expected) {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
    } else {
        std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
        std::cout << RED << "expected:" << expected << std::endl;
        std::cout << RESET << std::endl;
    }
    delete numArray;
    numArray = nullptr;
}

void Test3()
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
template<typename T>
void call(T* numArray) // , std::vector<int> &arr, std::vector<int> &expected
{
    {
        std::vector<int> arr = {-2, 0, 3, -5, 2, -1};
        std::vector<int> expect = {1, -1, -3};
        std::cout << "arr:" << arr << std::endl;
        Test1(numArray, arr , expect);
    }
    {
        std::vector<int> arr = {3, 5, 2, -2, 4, 1};
        std::vector<int> expect = {9};
        std::cout << "arr:" << arr << std::endl;
        Test2(numArray, arr , expect);
    }
}
void Test()
{
    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    //std::vector<int> arr = {-2, 0, 3, -5, 2, -1};
    //std::vector<int> expect = {1, -1, -3};
    //std::cout << "arr:" << arr << std::endl;

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
        NumArray * pointer = nullptr;
        call(pointer); //, arr, expect);

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
        NumArray1 * pointer = nullptr;
        call(pointer); //, arr, expect);

        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
}

int main()
{
    Test();

    return 0;
}
