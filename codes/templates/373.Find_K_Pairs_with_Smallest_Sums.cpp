/*
 ******************************************************************************************
 * 373. Find K Pairs with Smallest Sums
 * Medium
 ******************************************************************************************
 * You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
 * Define a pair (u, v) which consists of one element from the first array and one element from the second array.
 * Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
 ******************************************************************************************
 * Example 1:
 *
 * Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * Output: [[1,2],[1,4],[1,6]]
 * Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 ******************************************************************************************
 * Example 2:
 *
 * Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * Output: [[1,1],[1,1]]
 * Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 ******************************************************************************************
 * Example 3:
 *
 * Input: nums1 = [1,2], nums2 = [3], k = 3
 * Output: [[1,3],[2,3]]
 * Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
 ******************************************************************************************
 * Constraints:
 *
 * 1 <= nums1.length, nums2.length <= 10^4
 * -10^9 <= nums1[i], nums2[i] <= 10^9
 * nums1 and nums2 both are sorted in ascending order.
 * 1 <= k <= 1000
 ******************************************************************************************
 */
#include <algorithm>
#include <iostream>
#include <limits>
#include <chrono>
#include <vector>
#include <queue>

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

template<typename T>
bool operatorcompare (std::vector<std::vector<T>> &a, std::vector<std::vector<T>> &b);

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int> & nums2, int k)
    {
        return {{}};
    }
   
};


// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int> & nums1,
        std::vector<int> & nums2,
        int k ,
        std::vector<std::vector<int>> expected)
{
    std::cout << std::endl;
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    std::cout << "k:" << k << std::endl;
    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
    {
        printvector(nums1);
        printvector(nums2);
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.kSmallestPairs(nums1, nums2, k);

        std::cout << "result: " << result  << " " << std::endl;
        if(operatorcompare (result ,expected))
        //if(result == expected)
        {
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
}

int Test1()
{
    // Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
    // Output: [[1,2],[1,4],[1,6]]
    std::vector<int> nums1 = {1, 7, 11};
    std::vector<int> nums2 = {2, 4, 6 };
    int k = 3;
    std::vector<std::vector<int>> result1{{1,2},{1,4},{1,6}};
    Test("Test1", nums1, nums2, k, result1);
    return 0;
}
int Test2()
{
    // Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
    // Output: [[1,1],[1,1]]
    std::vector<int> nums1 = {1, 1, 2 };
    std::vector<int> nums2 = {1, 2, 3 };
    int k = 2;
    std::vector<std::vector<int>> result2{{1,1},{1,1}};
    Test("Test2", nums1, nums2, k, result2);
    return 0;
}
int Test3()
{
    // Input: nums1 = [1,2], nums2 = [3], k = 3
    // Output: [[1,3],[2,3]]
    std::vector<int> nums1 = { 1, 2 };
    std::vector<int> nums2 = {  3 };
    int k = 3;
    std::vector<std::vector<int>> result3{{1,3},{2,3}};
    Test("Test3", nums1, nums2, k, result3);
    return 0;
}
// Largest
int Test4()
{
    // Input: L1=[9, 8, 2], L2=[6, 3, 1], K=3
    // Output: [9, 3], [9, 6], [8, 6]
    std::vector<int> nums1 = { 9, 8, 2 };
    std::vector<int> nums2 = { 6, 3, 1 };
    int k = 3;
    std::vector<std::vector<int>> result1{{9,3},{9,6},{8,6}};
    //Test("Test1", nums1, nums2, k, result1);
    return 0;
}
int Test5()
{
    // Input: L1=[5, 2, 1], L2=[2, -1], K=3
    // Output: [5, 2], [5, -1], [2, 2]
    std::vector<int> nums1 = { 5, 2, 1 };
    std::vector<int> nums2 = { 2, -1 };
    int k = 3;
    std::vector<std::vector<int>> result2{{5,2},{5,-1},{2,2}};
    //Test("Test2", nums1, nums2, k, result2);
    return 0;
}
int Test6()
{
    std::vector<int> nums1 = { 5, 5, 5 };
    std::vector<int> nums2 = { -2, -1 };
    int k = 3;
    std::vector<std::vector<int>> result2{{5,-2},{5,-2},{5,-2}};
    Test("Test6", nums1, nums2, k, result2);
    k=5;
    result2={{5,-2},{5,-2},{5,-2},{5,-1},{5,-1}};
    Test("Test6", nums1, nums2, k, result2);
    k=6;
    result2={{5,-2},{5,-2},{5,-2},{5,-1},{5,-1},{5,-1}};
    Test("Test6", nums1, nums2, k, result2);
    return 0;
}
int Test7()
{
    std::vector<int> nums1 = { 1, 1, 2 };
    std::vector<int> nums2 = { 1, 2, 3 };
    int k = 10;
    std::vector<std::vector<int>> result2{{1,1},{1,1},{2,1},{1,2},{1,2},{2,2},{1,3},{1,3},{2,3}};
    Test("Test7", nums1, nums2, k, result2);

    std::vector<std::vector<int>> result3{{1,1},{1,1},{2,1},{1,2},{1,2},{2,2},{1,3},{1,3},{2,3}};
    std::vector<std::vector<int>> result4{{1,1},{1,1},{2,1},{1,2},{1,3},{1,3},{2,3},{1,2},{2,2}};
    std::vector<std::vector<int>> result5{{1,1},{2,1},{1,2},{1,3},{1,3},{2,3},{1,2},{2,2}};
    //std::cout << std::boolalpha << operatorcompare(result2, result3) << std::endl;
    //std::cout << std::boolalpha << operatorcompare(result4, result3) << std::endl;
    //std::cout << std::boolalpha << operatorcompare(result4, result5) << std::endl;
    return 0;
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
template<typename T>
//bool operator == (std::vector<std::vector<T>> &a, std::vector<std::vector<T>> &b)
bool operatorcompare (std::vector<std::vector<T>> &a, std::vector<std::vector<T>> &b)
{
    std::cout << "operatorcompare:" << std::endl;
    if(a.size() != b.size())
    {
        return false;
    }
    auto /*decltype(a)*/ A(a);
    auto /*decltype(b)*/ B(b);
    printvector(A);
    printvector(B);
    for(auto i= A.end()-1; i != A.begin()-1; i--)
    {
        auto it = std::find(B.begin(), B.end(), *i);
        if(it != B.end())
        {
            B.erase(it);
        }
        else
        {
            std::cout << "not found." << std::endl;
        }
        A.erase(i);
    }
    std::cout << "operatorcompare:" << std::endl;
    printvector(A);
    printvector(B);
    if(!B.empty())
    {
        return false;
    }
    return true;
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
