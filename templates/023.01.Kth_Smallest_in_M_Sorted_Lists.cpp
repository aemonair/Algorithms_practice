/*
 * int findKthSmallest(std::vector<int>& lists, int k)
 ******************************************************************************************
 * 23. Merge k Sorted Lists
 * > Kth Smallest Number in M Sorted Lists (Medium)
 * Hard
 ******************************************************************************************
 * Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays.
 ******************************************************************************************
 * Example 1:
 * 
 * Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4], K=5
 * Output: 4
 * Explanation: The 5th smallest number among all the arrays is 4, this can be verified from the merged
 * list of all the arrays: [1, 2, 3, 3, 4, 6, 6, 7, 8]
 ******************************************************************************************
 * Example 2:
 * 
 * Input: L1=[5, 8, 9], L2=[1, 7], K=3
 * Output: 7
 * Explanation: The 3rd smallest number among all the arrays is 7.
 ******************************************************************************************
 */
#include <iostream>
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

class Solution {
public:
    int findKthSmallest(std::vector<std::vector<int>>& lists, int k)
    {
        return 0;
    }
    
};


// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<std::vector<int>>& lists,
        int k,
        int expected)
{
    std::cout << std::endl;
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
    {
        std::cout << "k:" << k << std::endl;
        printvector(lists);
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.findKthSmallest(lists, k);

        std::cout << "result: " << result  << " " << std::endl;
        //if(result == expected)
        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::endl;
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
    std::vector<int> p {2,6,8};
    std::vector<int> q {3,6,7};
    std::vector<int> r {1,3,4};
    int k = 5;
    std::vector<std::vector<int>> lists{p, q, r};
    //Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4], K=5
    //Output: 4
    int result1 = 4;
    Test("Test0", lists, k, result1);
    return 0;
}
int Test2()
{
    std::vector<std::vector<int>> v{{5,8,9},{1,7}};
    int k = 3;
    int result = 7;
    Test("Test2", v, k, result);
    return 0;
}
int Test3()
{
    return 0;
}
int Test4()
{
    return 0;
}
int Test5()
{
    return 0;
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
