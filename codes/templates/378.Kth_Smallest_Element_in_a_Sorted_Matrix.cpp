/*
 * int kthSmallest(std::vector<std::vector<int>>& matrix, int k)
 ******************************************************************************************
 * 378. Kth Smallest Element in a Sorted Matrix
 *Medium
 ******************************************************************************************
 *Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.
 *
 *Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 ******************************************************************************************
 *Example 1:
 *
 *Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 *Output: 13
 *Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
 ******************************************************************************************
 *Example 2:
 *
 *Input: matrix = [[-5]], k = 1
 *Output: -5
 ******************************************************************************************
 *Constraints:
 *
 *n == matrix.length
 *n == matrix[i].length
 *1 <= n <= 300
 *-10^9 <= matrix[i][j] <= 10^9
 *All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
 *1 <= k <= n^2
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
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k)
    {
        return 0;
    }
   
};


// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<std::vector<int>>& matrix,
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
        printvector(matrix);
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.kthSmallest(matrix, k);

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
    // Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
    // Output: 13
    int k = 8;
    std::vector<std::vector<int>> matrix{{1,5,9},{10,11,13},{12,13,15}};
    int result1 = 13;
    Test("Test1", matrix, k, result1);
    return 0;
}
int Test2()
{
    // Input: matrix = [[-5]], k = 1
    std::vector<std::vector<int>> v{{-5}};
    int k = 1;
    int result2 = -5;
    Test("Test2", v, k, result2);
    return 0;
}
int Test3()
{
    std::vector<std::vector<int>> v{
        {2,6,8},{3,7,10},{5,8,11}
    };
    int k = 5;
    int result3 = 7;
    Test("Test3", v, k, result3);
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
